/* Copyright (c) <2003-2019> <Julio Jerez, Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef _DG_COLLISION_SPHERE_H__
#define _DG_COLLISION_SPHERE_H__


#include "dgCollisionConvex.h"

#define DG_SPHERE_VERTEX_COUNT 18

class dgCollisionSphere: public dgCollisionConvex
{
	public:
	dgCollisionSphere(dgMemoryAllocator* allocator, dgUnsigned32 signature, dgFloat32 radius);
	dgCollisionSphere(dgWorld* const world, dgDeserialize deserialization, void* const userData, dgInt32 revisionNumber);
	virtual ~dgCollisionSphere();


	protected:
	void Init (dgFloat32 radius, dgMemoryAllocator* allocator);
	virtual dgVector SupportVertex (const dgVector& dir, dgInt32* const vertexIndex) const;

	virtual void CalcAABB (const dgMatrix& matrix, dgVector& p0, dgVector& p1) const;
	virtual void DebugCollision  (const dgMatrix& matrix, dgCollision::OnDebugCollisionMeshCallback callback, void* const userData) const;
	virtual dgFloat32 RayCast (const dgVector& localP0, const dgVector& localP1, dgFloat32 maxT, dgContactPoint& contactOut, const dgBody* const body, void* const userData, OnRayPrecastAction preFilter) const;

	void TesselateTriangle (dgInt32 level, const dgVector& p0, const dgVector& p1, const dgVector& p2, dgInt32& count, dgVector* const ouput) const;
	
//	private:
	static dgInt32 CalculateSignature (dgFloat32 radius);

	virtual dgInt32 CalculateSignature () const;
	virtual void SetCollisionBBox (const dgVector& p0, const dgVector& p1);

	virtual void MassProperties ();

	virtual dgInt32 CalculatePlaneIntersection (const dgVector& normal, const dgVector& point, dgVector* const contactsOut) const;

	virtual void GetCollisionInfo(dgCollisionInfo* const info) const;
	virtual void Serialize(dgSerialize callback, void* const userData) const;

	virtual dgVector SupportVertexSpecial (const dgVector& dir, dgFloat32 skinThickness, dgInt32* const vertexIndex) const;
	virtual dgVector SupportVertexSpecialProjectPoint (const dgVector& point, const dgVector& dir) const;

	dgFloat32 m_radius;
	dgVector m_vertex[DG_SPHERE_VERTEX_COUNT];
	
	static dgInt32 m_shapeRefCount;
	static dgVector m_unitSphere[];
	static dgConvexSimplexEdge m_edgeArray[];

	friend class dgWorld;
};


class dgCollisionPoint: public dgCollisionSphere
{
	public:
	dgCollisionPoint (dgMemoryAllocator* const allocator) 
		:dgCollisionSphere(allocator, 0x12344321, dgFloat32 (0.25f))
	{
	}

	virtual dgFloat32 GetVolume () const;
	virtual dgVector SupportVertex (const dgVector& dir, dgInt32* const vertexIndex) const;
	virtual dgVector SupportVertexSpecial (const dgVector& dir, dgFloat32 skinThickness, dgInt32* const vertexIndex) const;
};

#endif 

