/* Copyright (c) <2003-2019> <Newton Game Dynamics>
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely
*/

// dGeometry.cpp: implementation of the dGeometry class.
//
//////////////////////////////////////////////////////////////////////
#include "ndSandboxStdafx.h"
#include "ndDemoMesh.h"
#include "ndDemoEntity.h"
#include "ndPhysicsWorld.h"
#include "ndPhysicsUtils.h"
#include "ndTargaToOpenGl.h"
#include "ndDemoEntityManager.h"
#include "ndSimpleConvexFracture.h"

#define D_WOODFRACTURE_LISTENER "woodFractureListener"
//#define BREAK_IMPACT_IN_METERS_PER_SECONDS		8.0f
#define BREAK_IMPACT_IN_METERS_PER_SECONDS      10.0f

/*
class dWoodFractureListener: public dCustomParallelListener
{
	class WoodFractureAtom
	{
		public:
		WoodFractureAtom()
			:m_centerOfMass(0.0f)
			,m_momentOfInertia(0.0f)
			,m_mesh(nullptr)
			,m_collision(nullptr)
			,m_massFraction(0.0f)
		{
		}

		dVector m_centerOfMass;
		dVector m_momentOfInertia;
		DemoMesh* m_mesh;
		NewtonCollision* m_collision;
		dFloat32 m_massFraction;
	};

	class ndVoronoidFractureEffect: public dList<WoodFractureAtom>
	{
		public:
		ndVoronoidFractureEffect(NewtonWorld* const world, NewtonMesh* const mesh, dInt32 interiorMaterial)
			:m_body(nullptr)
			,m_isDead(false)
		{
			DemoEntityManager* const scene = (DemoEntityManager*)NewtonWorldGetUserData(world);

			// first we populate the bounding Box area with few random point to get some interior subdivisions.
			// the subdivision are local to the point placement, by placing these points visual ally with a 3d tool
			// and have precise control of how the debris are created.
			// the number of pieces is equal to the number of point inside the Mesh plus the number of point on the mesh 
			dVector size(0.0f);
			dMatrix matrix(dGetIdentityMatrix());
			NewtonMeshCalculateOOBB(mesh, &matrix[0][0], &size.m_x, &size.m_y, &size.m_z);

			dVector points[32];
			points[0] = dVector(-size.m_x * 0.5f, -size.m_y * 0.5f, -size.m_z * 0.5f);
			points[1] = dVector(-size.m_x * 0.5f, -size.m_y * 0.5f, size.m_z * 0.5f);
			points[2] = dVector(-size.m_x * 0.5f, size.m_y * 0.5f, -size.m_z * 0.5f);
			points[3] = dVector(-size.m_x * 0.5f, size.m_y * 0.5f, size.m_z * 0.5f);

			points[4] = dVector(size.m_x * 0.5f, -size.m_y * 0.5f, -size.m_z * 0.5f);
			points[5] = dVector(size.m_x * 0.5f, -size.m_y * 0.5f, size.m_z * 0.5f);
			points[6] = dVector(size.m_x * 0.5f, size.m_y * 0.5f, -size.m_z * 0.5f);
			points[7] = dVector(size.m_x * 0.5f, size.m_y * 0.5f, size.m_z * 0.5f);

			dInt32 count = 8;
			for (dInt32 i = 0; i < count; i ++) {
				dFloat32 x = dGaussianRandom(size.m_x * 0.1f);
				dFloat32 y = dGaussianRandom(size.m_y * 0.1f);
				dFloat32 z = dGaussianRandom(size.m_y * 0.1f);
				points[i] += dVector(x, y, z);
			}

			// add the bounding box as a safeguard area
			points[count + 0] = dVector(size.m_x, size.m_y, size.m_z, dFloat32 (0.0f));
			points[count + 1] = dVector(size.m_x, size.m_y, -size.m_z, dFloat32 (0.0f));
			points[count + 2] = dVector(size.m_x, -size.m_y, size.m_z, dFloat32 (0.0f));
			points[count + 3] = dVector(size.m_x, -size.m_y, -size.m_z, dFloat32 (0.0f));
			points[count + 4] = dVector(-size.m_x, size.m_y, size.m_z, dFloat32 (0.0f));
			points[count + 5] = dVector(-size.m_x, size.m_y, -size.m_z, dFloat32 (0.0f));
			points[count + 6] = dVector(-size.m_x, -size.m_y, size.m_z, dFloat32 (0.0f));
			points[count + 7] = dVector(-size.m_x, -size.m_y, -size.m_z, dFloat32 (0.0f));
			count += 8;

			// create a texture matrix, for applying the material's UV to all internal faces
			dMatrix textureMatrix(dGetIdentityMatrix());
			textureMatrix[0][0] = 1.0f / size.m_x;
			textureMatrix[1][1] = 1.0f / size.m_y;

			// Get the volume of the original mesh
			NewtonCollision* const collision1 = NewtonCreateConvexHullFromMesh(world, mesh, dFloat32 (0.0f), 16);
			dFloat32 volume = NewtonConvexCollisionCalculateVolume(collision1);
			NewtonDestroyCollision(collision1);

			// now we call create we decompose the mesh into several convex pieces 
			NewtonMesh* const debriMeshPieces = NewtonMeshCreateVoronoiConvexDecomposition(world, count, &points[0].m_x, sizeof(dVector), interiorMaterial, &textureMatrix[0][0]);
			dAssert(debriMeshPieces);

			// now we iterate over each pieces and for each one we create a visual entity and a rigid body
			NewtonMesh* nextDebri;
			for (NewtonMesh* debri = NewtonMeshCreateFirstLayer(debriMeshPieces); debri; debri = nextDebri) {
				// get next segment piece
				nextDebri = NewtonMeshCreateNextLayer(debriMeshPieces, debri);

				//clip the voronoi cell convexes against the mesh 
				NewtonMesh* const fracturePiece = NewtonMeshConvexMeshIntersection(mesh, debri);
				if (fracturePiece) {
					// make a convex hull collision shape
					NewtonCollision* const collision = NewtonCreateConvexHullFromMesh(world, fracturePiece, dFloat32 (0.0f), 16);
					if (collision) {
						// we have a piece which has a convex collision  representation, add that to the list
						WoodFractureAtom& atom = Append()->GetInfo();
						atom.m_mesh = new DemoMesh(fracturePiece, scene->GetShaderCache());
						NewtonConvexCollisionCalculateInertialMatrix(collision, &atom.m_momentOfInertia[0], &atom.m_centerOfMass[0]);
						dFloat32 debriVolume = NewtonConvexCollisionCalculateVolume(collision);
						atom.m_massFraction = debriVolume / volume;
						atom.m_collision = collision;
					}
					NewtonMeshDestroy(fracturePiece);
				}
				NewtonMeshDestroy(debri);
			}
			NewtonMeshDestroy(debriMeshPieces);
		}

		ndVoronoidFractureEffect(const ndVoronoidFractureEffect& list)
			:m_body(nullptr)
			,m_isDead(false)
		{
			for (dListNode* node = list.GetFirst(); node; node = node->GetNext()) {
				WoodFractureAtom& atom = Append(node->GetInfo())->GetInfo();
				atom.m_mesh->AddRef();
				atom.m_collision = NewtonCollisionCreateInstance(atom.m_collision);
				NewtonCollisionSetUserID(atom.m_collision, 16);
			}
		}

		~ndVoronoidFractureEffect()
		{
			for (dListNode* node = GetFirst(); node; node = node->GetNext()) {
				WoodFractureAtom& atom = node->GetInfo();
				NewtonDestroyCollision(atom.m_collision);
				atom.m_mesh->Release();
			}
		}

		NewtonBody* m_body;
		bool m_isDead;
	};

	public:
	void PostUpdate(dFloat32 timestep, dInt32 threadID) 
	{
		NewtonWorld* const world = GetWorld();
		const dInt32 threadCount = NewtonGetThreadsCount(world);

		dList<ndVoronoidFractureEffect>::dListNode* node = m_effectList.GetFirst();
		for (dInt32 i = 0; i < threadID; i++) {
			node = node ? node->GetNext() : nullptr;
		}

		if (node) {
			do {
				ndVoronoidFractureEffect& effect = node->GetInfo();
				UpdateEffect(effect, timestep);
				for (dInt32 i = 0; i < threadCount; i++) {
					node = node ? node->GetNext() : nullptr;
				}
			} while (node);
		}
	}

	void PostUpdate(dFloat32 timestep)
	{
		dCustomParallelListener::PostUpdate(timestep);

		NewtonWorld* const world = GetWorld();
		DemoEntityManager* const scene = (DemoEntityManager*)NewtonWorldGetUserData(world);

		dList<ndVoronoidFractureEffect>::dListNode* nextNode;
		for (dList<ndVoronoidFractureEffect>::dListNode* node = m_effectList.GetFirst(); node; node = nextNode) {
			nextNode = node->GetNext();
			ndVoronoidFractureEffect& effect = node->GetInfo();
			if (effect.m_isDead) {
				DemoEntity* const visualEntiry = (DemoEntity*)NewtonBodyGetUserData(effect.m_body);
				NewtonDestroyBody(effect.m_body);
				scene->RemoveEntity(visualEntiry);
				m_effectList.Remove(node);
			}
		}
	}

	void UpdateEffect(ndVoronoidFractureEffect& effect, dFloat32 timestep) 
	{
		// see if the net force on the body comes fr a high impact collision
		dFloat32 breakImpact = 0.0f;
		for (NewtonJoint* joint = NewtonBodyGetFirstContactJoint(effect.m_body); joint; joint = NewtonBodyGetNextContactJoint(effect.m_body, joint)) {
			for (void* contact = NewtonContactJointGetFirstContact(joint); contact; contact = NewtonContactJointGetNextContact(joint, contact)) {
				dVector contactForce;
				const NewtonCollision* const coll0 = NewtonContactGetCollision0(contact);
				const NewtonCollision* const coll1 = NewtonContactGetCollision1(contact);
				const NewtonMaterial* const material = NewtonContactGetMaterial(contact);
				dFloat32 impulseImpact = NewtonMaterialGetContactMaxNormalImpact(material);

				if (NewtonCollisionGetUserID(coll0) == 4) {
					// m_tirePart
					if (impulseImpact > breakImpact) {
						breakImpact = impulseImpact * 20.0f;
					}
					
				} else if (NewtonCollisionGetUserID(coll1) == 8) {
					// m_linkPart
					if (impulseImpact > breakImpact) {
						breakImpact = impulseImpact * 20.0f;
					}
				} else if (impulseImpact > breakImpact) {
					// all othe types
					breakImpact = impulseImpact;
				}
			}
		}

		dFloat32 invMass;
		dFloat32 invIxx;
		dFloat32 invIyy;
		dFloat32 invIzz;
		NewtonBodyGetInvMass(effect.m_body, &invMass, &invIxx, &invIyy, &invIzz);

		// if the force is bigger than N time Gravities, It is considered a collision force
		breakImpact *= invMass;

		if (breakImpact > BREAK_IMPACT_IN_METERS_PER_SECONDS) {
			dMatrix bodyMatrix;
			dVector com(0.0f);
			dVector veloc(0.0f);
			dVector omega(0.0f);
			dFloat32 Ixx;
			dFloat32 Iyy;
			dFloat32 Izz;
			dFloat32 mass;

			NewtonWorld* const world = GetWorld();
			// create the shape and visual mesh as a common data to be re used
			DemoEntityManager* const scene = (DemoEntityManager*)NewtonWorldGetUserData(world);

			NewtonBodyGetVelocity(effect.m_body, &veloc[0]);
			NewtonBodyGetOmega(effect.m_body, &omega[0]);
			NewtonBodyGetCentreOfMass(effect.m_body, &com[0]);
			NewtonBodyGetMatrix(effect.m_body, &bodyMatrix[0][0]);
			NewtonBodyGetMass(effect.m_body, &mass, &Ixx, &Iyy, &Izz);

			NewtonCollisionMaterial material;
			dInt32 defaultMaterialID = NewtonBodyGetMaterialGroupID(effect.m_body);
			NewtonCollisionGetMaterial(NewtonBodyGetCollision(effect.m_body), &material);

			DemoEntity* const visualEntiry = (DemoEntity*)NewtonBodyGetUserData(effect.m_body);

			com = bodyMatrix.TransformVector(com);
			dMatrix matrix(visualEntiry->GetCurrentMatrix());
			dQuaternion rotation(matrix);

			effect.m_isDead = true;

			// we need to lock the world before creation a bunch of bodies
			scene->Lock(m_lock);

			for (ndVoronoidFractureEffect::dListNode* node = effect.GetFirst(); node; node = node->GetNext()) {
				WoodFractureAtom& atom = node->GetInfo();

				DemoEntity* const entity = new DemoEntity(dMatrix(rotation, matrix.m_posit), nullptr);
				entity->SetMesh(atom.m_mesh, dGetIdentityMatrix());
				scene->Append(entity);

				dFloat32 debriMass = mass * atom.m_massFraction;

				//create the rigid body
				NewtonBody* const rigidBody = NewtonCreateDynamicBody(world, atom.m_collision, &matrix[0][0]);

				// calculate debris initial velocity
				dVector center(matrix.TransformVector(atom.m_centerOfMass));
				dVector v(veloc + omega.CrossProduct(center - com));

				// set initial velocity
				NewtonBodySetVelocity(rigidBody, &v[0]);
				NewtonBodySetOmega(rigidBody, &omega[0]);

				// set the debris mass properties, mass, center of mass, and inertia 
				NewtonBodySetMassProperties(rigidBody, debriMass, atom.m_collision);

				dFloat32 mass;
				dFloat32 Ixx;
				dFloat32 Iyy;
				dFloat32 Izz;
				NewtonBodyGetMass(rigidBody, &mass, &Ixx, &Iyy, &Izz);
				if (Iyy > 10.0f * Ixx) {
					Iyy *= 0.25f; 
				}
				if (Izz > 5.0f * Ixx) {
					Izz *= 0.25f; 
				}
				NewtonBodySetMassMatrix(rigidBody, mass, Ixx, Iyy, Izz);

				// save the pointer to the graphic object with the body.
				NewtonBodySetUserData(rigidBody, entity);

				// assign the wood id
				NewtonBodySetMaterialGroupID(rigidBody, defaultMaterialID);

				// set high accuracy simulation
				NewtonBodySetGyroscopicTorque(rigidBody, 1);

				//  set continuous collision mode
				//	NewtonBodySetContinuousCollisionMode (rigidBody, continueCollisionMode);

				// set a destructor for this rigid body
				NewtonBodySetDestructorCallback(rigidBody, PhysicsBodyDestructor);

				// set the transform call back function
				NewtonBodySetTransformCallback(rigidBody, DemoEntity::TransformCallback);

				// set the force and torque call back function
				NewtonBodySetForceAndTorqueCallback(rigidBody, PhysicsApplyGravityForce);

				NewtonCollision* const collision = NewtonBodyGetCollision(rigidBody);
				NewtonCollisionSetMaterial(collision, &material);
			}

			// unlock the work after done with the effect 
			scene->Unlock(m_lock);
		}
	}
	
	dList<ndVoronoidFractureEffect> m_effectList;
	unsigned m_lock;
};
*/

ndSimpleConvexFracture::ndSimpleConvexFracture(ndDemoEntityManager* const scene)
	:ndModel()
{
}

ndSimpleConvexFracture::~ndSimpleConvexFracture()
{
}

void ndSimpleConvexFracture::AddFracturedWoodPrimitive(
	ndDemoEntityManager* const scene, const ndShapeInstance& shape,
	dFloat32 density, const dVector& origin,
	dInt32 xCount, dInt32 zCount, dFloat32 spacing,
	dInt32 type, dInt32 materialID)
{
	// create a newton mesh from the collision primitive
	ndMeshEffect mesh(shape);
	
	// apply a material map
	//dInt32 externalMaterial = LoadTexture("reljef.tga");
	//dInt32 internalMaterial = LoadTexture("concreteBrick.tga");

	// add the interial material;
	mesh.GetMaterials().PushBack(ndMeshEffect::dMaterial());
	ndMeshEffect::dMaterial& material0 = mesh.GetMaterials()[0];
	ndMeshEffect::dMaterial& material1 = mesh.GetMaterials()[1];
	strcpy(material0.m_textureName, "reljef.tga");
	strcpy(material1.m_textureName, "concreteBrick.tga");

	dMatrix aligmentUV(dGetIdentityMatrix());
	//NewtonMeshApplyBoxMapping(mesh, externalMaterial, externalMaterial, externalMaterial, &aligmentUV[0][0]);
	mesh.UniformBoxMapping(0, aligmentUV);

	// make a visual mesh for display
	ndDemoMesh* const visualMesh = new ndDemoMesh("fracture", &mesh, scene->GetShaderCache());
	
	// create a  mesh fracture from the newton mesh primitive
	ndVoronoidFractureEffect fracture(scene, &mesh, 1);
	
	dFloat32 startElevation = 100.0f;
	dMatrix matrix(dGetIdentityMatrix());
	
	ndWorld* const world = scene->GetWorld();
	for (dInt32 i = 0; i < xCount; i++) 
	{
		dFloat32 x = origin.m_x + (i - xCount / 2) * spacing;
		for (dInt32 j = 0; j < zCount; j++) 
		{
			dFloat32 z = origin.m_z + (j - zCount / 2) * spacing;
	
			matrix.m_posit.m_x = x;
			matrix.m_posit.m_z = z;
			dVector floor(FindFloor(*world, dVector(matrix.m_posit.m_x, startElevation, matrix.m_posit.m_z, dFloat32 (0.0f)), 2.0f * startElevation));
			matrix.m_posit.m_y = floor.m_y + 0.5f;

			dFloat32 mass = density * shape.GetVolume();
			ndBodyDynamic* const body = new ndBodyDynamic();
			ndDemoEntity* const entity = new ndDemoEntity(matrix, nullptr);
			entity->SetMesh(visualMesh, dGetIdentityMatrix());

			body->SetNotifyCallback(new ndDemoEntityNotify(scene, entity));
			body->SetMatrix(matrix);
			body->SetCollisionShape(shape);
			body->SetMassMatrix(mass, shape);
			//body->SetAngularDamping(dVector(dFloat32(0.5f)));
			world->AddBody(body);
			scene->AddEntity(entity);

			ndVoronoidFractureEffect& newEffect = m_effectList.Append(fracture)->GetInfo();
			newEffect.m_body = body;
		}
	}
	
	// do not forget to release the assets	
	visualMesh->Release();
}

ndSimpleConvexFracture::ndVoronoidFractureEffect::ndVoronoidFractureEffect(ndDemoEntityManager* const scene, ndMeshEffect* const mesh, dInt32 interiorMaterial)
	:m_body(nullptr)
	,m_isDead(false)
{
	// first we populate the bounding Box area with few random point to get some interior subdivisions.
	// the subdivision are local to the point placement, by placing these points visual ally with a 3d tool
	// and have precise control of how the debris are created.
	// the number of pieces is equal to the number of point inside the Mesh plus the number of point on the mesh 
	dBigVector bigSize;
	dMatrix matrix(mesh->CalculateOOBB(bigSize));
	dVector size(bigSize);

	dVector points[32];
	points[0] = dVector(-size.m_x * 0.5f, -size.m_y * 0.5f, -size.m_z * 0.5f, dFloat32 (0.0f));
	points[1] = dVector(-size.m_x * 0.5f, -size.m_y * 0.5f,  size.m_z * 0.5f, dFloat32 (0.0f));
	points[2] = dVector(-size.m_x * 0.5f,  size.m_y * 0.5f, -size.m_z * 0.5f, dFloat32 (0.0f));
	points[3] = dVector(-size.m_x * 0.5f,  size.m_y * 0.5f,  size.m_z * 0.5f, dFloat32 (0.0f));
	
	points[4] = dVector(size.m_x * 0.5f, -size.m_y * 0.5f, -size.m_z * 0.5f, dFloat32 (0.0f));
	points[5] = dVector(size.m_x * 0.5f, -size.m_y * 0.5f,  size.m_z * 0.5f, dFloat32 (0.0f));
	points[6] = dVector(size.m_x * 0.5f,  size.m_y * 0.5f, -size.m_z * 0.5f, dFloat32 (0.0f));
	points[7] = dVector(size.m_x * 0.5f,  size.m_y * 0.5f,  size.m_z * 0.5f, dFloat32 (0.0f));
	
	dInt32 count = 8;
	for (dInt32 i = 0; i < count; i++) 
	{
		dFloat32 x = dGaussianRandom(size.m_x * 0.1f);
		dFloat32 y = dGaussianRandom(size.m_y * 0.1f);
		dFloat32 z = dGaussianRandom(size.m_y * 0.1f);
		points[i] += dVector(x, y, z, dFloat32 (0.0f));
	}
	
	// add the bounding box as a safeguard area
	size += 1.0f;
	points[count + 0] = dVector(size.m_x, size.m_y, size.m_z, dFloat32 (0.0f));
	points[count + 1] = dVector(size.m_x, size.m_y, -size.m_z, dFloat32 (0.0f));
	points[count + 2] = dVector(size.m_x, -size.m_y, size.m_z, dFloat32 (0.0f));
	points[count + 3] = dVector(size.m_x, -size.m_y, -size.m_z, dFloat32 (0.0f));
	points[count + 4] = dVector(-size.m_x, size.m_y, size.m_z, dFloat32 (0.0f));
	points[count + 5] = dVector(-size.m_x, size.m_y, -size.m_z, dFloat32 (0.0f));
	points[count + 6] = dVector(-size.m_x, -size.m_y, size.m_z, dFloat32 (0.0f));
	points[count + 7] = dVector(-size.m_x, -size.m_y, -size.m_z, dFloat32 (0.0f));
	count += 8;
	
	// create a texture matrix, for applying the material's UV to all internal faces
	dMatrix textureMatrix(dGetIdentityMatrix());
	textureMatrix[0][0] = 1.0f / size.m_x;
	textureMatrix[1][1] = 1.0f / size.m_y;
	
	//// Get the volume of the original mesh
	dFloat32 volume = dFloat32 (mesh->CalculateVolume());

	// now we call create we decompose the mesh into several convex pieces 
	//ndMeshEffect* const debriMeshPieces = NewtonMeshCreateVoronoiConvexDecomposition(world, count, &points[0].m_x, sizeof(dVector), interiorMaterial, &textureMatrix[0][0]);
	ndMeshEffect* const debriMeshPieces = mesh->CreateVoronoiConvexDecomposition(interiorMaterial, &textureMatrix[0][0]);
	dAssert(debriMeshPieces);
	
	// now we iterate over each pieces and for each one we create a visual entity and a rigid body
	ndMeshEffect* nextDebri;
	for (ndMeshEffect* debri = debriMeshPieces->GetFirstLayer(); debri; debri = nextDebri)
	{
		// get next segment piece
		nextDebri = debriMeshPieces->GetNextLayer(debri);
	
		//clip the voronoi cell convexes against the mesh 
	//	NewtonMesh* const fracturePiece = NewtonMeshConvexMeshIntersection(mesh, debri);
	//	if (fracturePiece) {
	//		// make a convex hull collision shape
	//		NewtonCollision* const collision = NewtonCreateConvexHullFromMesh(world, fracturePiece, dFloat32 (0.0f), 16);
	//		if (collision) {
	//			// we have a piece which has a convex collision  representation, add that to the list
	//			WoodFractureAtom& atom = Append()->GetInfo();
	//			atom.m_mesh = new DemoMesh(fracturePiece, scene->GetShaderCache());
	//			NewtonConvexCollisionCalculateInertialMatrix(collision, &atom.m_momentOfInertia[0], &atom.m_centerOfMass[0]);
	//			dFloat32 debriVolume = NewtonConvexCollisionCalculateVolume(collision);
	//			atom.m_massFraction = debriVolume / volume;
	//			atom.m_collision = collision;
	//		}
	//		NewtonMeshDestroy(fracturePiece);
	//	}
	
		delete debri;
	}
	
	delete debriMeshPieces;
}

ndSimpleConvexFracture::ndVoronoidFractureEffect::ndVoronoidFractureEffect(const ndVoronoidFractureEffect& list)
	:m_body(nullptr)
	,m_isDead(false)
{
	for (dListNode* node = list.GetFirst(); node; node = node->GetNext()) 
	{
		dAssert(0);
		//ndFractureAtom& atom = Append(node->GetInfo())->GetInfo();
		//atom.m_mesh->AddRef();
		//atom.m_collision = NewtonCollisionCreateInstance(atom.m_collision);
		//NewtonCollisionSetUserID(atom.m_collision, 16);
	}
}

ndSimpleConvexFracture::ndVoronoidFractureEffect::~ndVoronoidFractureEffect()
{
	for (dListNode* node = GetFirst(); node; node = node->GetNext()) 
	{
		dAssert(0);
	//	WoodFractureAtom& atom = node->GetInfo();
	//	NewtonDestroyCollision(atom.m_collision);
	//	atom.m_mesh->Release();
	}
}

void ndSimpleConvexFracture::Update(const ndWorld* const world, dFloat32 timestep)
{
	//const dInt32 threadCount = world->GetThreadCount();
	
	//dList<ndVoronoidFractureEffect>::dListNode* node = m_effectList.GetFirst();
	//for (dInt32 i = 0; i < threadID; i++) 
	//{
	//	node = node ? node->GetNext() : nullptr;
	//}
	//
	//if (node) {
	//	do {
	//		ndVoronoidFractureEffect& effect = node->GetInfo();
	//		UpdateEffect(effect, timestep);
	//		for (dInt32 i = 0; i < threadCount; i++) {
	//			node = node ? node->GetNext() : nullptr;
	//		}
	//	} while (node);
	//}

	for (dList<ndVoronoidFractureEffect>::dListNode* node = m_effectList.GetFirst(); node; node = node->GetNext())
	{
		ndVoronoidFractureEffect& effect = node->GetInfo();
		UpdateEffect(effect, timestep);
	}

	dList<ndVoronoidFractureEffect>::dListNode* nextNode;
	for (dList<ndVoronoidFractureEffect>::dListNode* node = m_effectList.GetFirst(); node; node = nextNode)
	{
		nextNode = node->GetNext();
		ndVoronoidFractureEffect& effect = node->GetInfo();
		if (effect.m_isDead)
		{
			dAssert(0);
			//DemoEntity* const visualEntiry = (DemoEntity*)NewtonBodyGetUserData(effect.m_body);
			//NewtonDestroyBody(effect.m_body);
			//scene->RemoveEntity(visualEntiry);
			//m_effectList.Remove(node);
		}
	}
}

void ndSimpleConvexFracture::UpdateEffect(ndVoronoidFractureEffect& effect, dFloat32 timestep)
{
	// see if the net force on the body comes fr a high impact collision
	//dFloat32 breakImpact = 0.0f;
	//for (NewtonJoint* joint = NewtonBodyGetFirstContactJoint(effect.m_body); joint; joint = NewtonBodyGetNextContactJoint(effect.m_body, joint)) {
	//	for (void* contact = NewtonContactJointGetFirstContact(joint); contact; contact = NewtonContactJointGetNextContact(joint, contact)) {
	//		dVector contactForce;
	//		const NewtonCollision* const coll0 = NewtonContactGetCollision0(contact);
	//		const NewtonCollision* const coll1 = NewtonContactGetCollision1(contact);
	//		const NewtonMaterial* const material = NewtonContactGetMaterial(contact);
	//		dFloat32 impulseImpact = NewtonMaterialGetContactMaxNormalImpact(material);
	//
	//		if (NewtonCollisionGetUserID(coll0) == 4) {
	//			// m_tirePart
	//			if (impulseImpact > breakImpact) {
	//				breakImpact = impulseImpact * 20.0f;
	//			}
	//
	//		}
	//		else if (NewtonCollisionGetUserID(coll1) == 8) {
	//			// m_linkPart
	//			if (impulseImpact > breakImpact) {
	//				breakImpact = impulseImpact * 20.0f;
	//			}
	//		}
	//		else if (impulseImpact > breakImpact) {
	//			// all othe types
	//			breakImpact = impulseImpact;
	//		}
	//	}
	//}
	//
	//dFloat32 invMass;
	//dFloat32 invIxx;
	//dFloat32 invIyy;
	//dFloat32 invIzz;
	//NewtonBodyGetInvMass(effect.m_body, &invMass, &invIxx, &invIyy, &invIzz);
	//
	//// if the force is bigger than N time Gravities, It is considered a collision force
	//breakImpact *= invMass;
	//
	//if (breakImpact > BREAK_IMPACT_IN_METERS_PER_SECONDS) {
	//	dMatrix bodyMatrix;
	//	dVector com(0.0f);
	//	dVector veloc(0.0f);
	//	dVector omega(0.0f);
	//	dFloat32 Ixx;
	//	dFloat32 Iyy;
	//	dFloat32 Izz;
	//	dFloat32 mass;
	//
	//	NewtonWorld* const world = GetWorld();
	//	// create the shape and visual mesh as a common data to be re used
	//	DemoEntityManager* const scene = (DemoEntityManager*)NewtonWorldGetUserData(world);
	//
	//	NewtonBodyGetVelocity(effect.m_body, &veloc[0]);
	//	NewtonBodyGetOmega(effect.m_body, &omega[0]);
	//	NewtonBodyGetCentreOfMass(effect.m_body, &com[0]);
	//	NewtonBodyGetMatrix(effect.m_body, &bodyMatrix[0][0]);
	//	NewtonBodyGetMass(effect.m_body, &mass, &Ixx, &Iyy, &Izz);
	//
	//	NewtonCollisionMaterial material;
	//	dInt32 defaultMaterialID = NewtonBodyGetMaterialGroupID(effect.m_body);
	//	NewtonCollisionGetMaterial(NewtonBodyGetCollision(effect.m_body), &material);
	//
	//	DemoEntity* const visualEntiry = (DemoEntity*)NewtonBodyGetUserData(effect.m_body);
	//
	//	com = bodyMatrix.TransformVector(com);
	//	dMatrix matrix(visualEntiry->GetCurrentMatrix());
	//	dQuaternion rotation(matrix);
	//
	//	effect.m_isDead = true;
	//
	//	// we need to lock the world before creation a bunch of bodies
	//	scene->Lock(m_lock);
	//
	//	for (ndVoronoidFractureEffect::dListNode* node = effect.GetFirst(); node; node = node->GetNext()) {
	//		WoodFractureAtom& atom = node->GetInfo();
	//
	//		DemoEntity* const entity = new DemoEntity(dMatrix(rotation, matrix.m_posit), nullptr);
	//		entity->SetMesh(atom.m_mesh, dGetIdentityMatrix());
	//		scene->Append(entity);
	//
	//		dFloat32 debriMass = mass * atom.m_massFraction;
	//
	//		//create the rigid body
	//		NewtonBody* const rigidBody = NewtonCreateDynamicBody(world, atom.m_collision, &matrix[0][0]);
	//
	//		// calculate debris initial velocity
	//		dVector center(matrix.TransformVector(atom.m_centerOfMass));
	//		dVector v(veloc + omega.CrossProduct(center - com));
	//
	//		// set initial velocity
	//		NewtonBodySetVelocity(rigidBody, &v[0]);
	//		NewtonBodySetOmega(rigidBody, &omega[0]);
	//
	//		// set the debris mass properties, mass, center of mass, and inertia 
	//		NewtonBodySetMassProperties(rigidBody, debriMass, atom.m_collision);
	//
	//		dFloat32 mass;
	//		dFloat32 Ixx;
	//		dFloat32 Iyy;
	//		dFloat32 Izz;
	//		NewtonBodyGetMass(rigidBody, &mass, &Ixx, &Iyy, &Izz);
	//		if (Iyy > 10.0f * Ixx) {
	//			Iyy *= 0.25f;
	//		}
	//		if (Izz > 5.0f * Ixx) {
	//			Izz *= 0.25f;
	//		}
	//		NewtonBodySetMassMatrix(rigidBody, mass, Ixx, Iyy, Izz);
	//
	//		// save the pointer to the graphic object with the body.
	//		NewtonBodySetUserData(rigidBody, entity);
	//
	//		// assign the wood id
	//		NewtonBodySetMaterialGroupID(rigidBody, defaultMaterialID);
	//
	//		// set high accuracy simulation
	//		NewtonBodySetGyroscopicTorque(rigidBody, 1);
	//
	//		//  set continuous collision mode
	//		//	NewtonBodySetContinuousCollisionMode (rigidBody, continueCollisionMode);
	//
	//		// set a destructor for this rigid body
	//		NewtonBodySetDestructorCallback(rigidBody, PhysicsBodyDestructor);
	//
	//		// set the transform call back function
	//		NewtonBodySetTransformCallback(rigidBody, DemoEntity::TransformCallback);
	//
	//		// set the force and torque call back function
	//		NewtonBodySetForceAndTorqueCallback(rigidBody, PhysicsApplyGravityForce);
	//
	//		NewtonCollision* const collision = NewtonBodyGetCollision(rigidBody);
	//		NewtonCollisionSetMaterial(collision, &material);
	//	}
	//
	//	// unlock the work after done with the effect 
	//	scene->Unlock(m_lock);
	//}
}
