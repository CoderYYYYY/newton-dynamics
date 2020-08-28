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

#include "ntStdafx.h"
#include "ntBody.h"
#include "ntShapeNull.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


dUnsigned32 ntBody::m_uniqueIDCount = 0;

class ntDummyCollision: public ntShapeNull
{
	public: 
	ntDummyCollision()
		:ntShapeNull()
	{
		m_refCount.fetch_add(1);
	}

	~ntDummyCollision()
	{
		m_refCount.fetch_add(-1);
	}

	static ntShapeNull* GetNullShape()
	{
		static ntDummyCollision nullShape;
		return &nullShape;
	}
};

ntBody::ntBody()
	:m_matrix(dGetIdentityMatrix())
	,m_invWorldInertiaMatrix(dGetZeroMatrix())
	,m_veloc(dVector::m_zero)
	,m_omega(dVector::m_zero)
	,m_localCentreOfMass(dVector::m_zero)
	,m_globalCentreOfMass(dVector::m_zero)
	,m_minAABB(dVector::m_zero)
	,m_maxAABB(dVector::m_zero)
	,m_rotation()
	,m_notifyCallback(nullptr)
	,m_shapeInstance(ntDummyCollision::GetNullShape())
	,m_newton(nullptr)
	,m_broadPhaseNode(nullptr)
	,m_newtonNode(nullptr)
	,m_broadPhaseAggregateNode(nullptr)
	,m_flags(0)
	,m_uniqueID(m_uniqueIDCount)
{
	m_equilibrium = 0;
	m_uniqueIDCount++;
}

ntBody::~ntBody()
{
	if (m_notifyCallback)
	{
		delete m_notifyCallback;
	}
}

void ntBody::SetCentreOfMass(const dVector& com)
{
	m_localCentreOfMass.m_x = com.m_x;
	m_localCentreOfMass.m_y = com.m_y;
	m_localCentreOfMass.m_z = com.m_z;
	m_localCentreOfMass.m_w = dFloat32(1.0f);
	m_globalCentreOfMass = m_matrix.TransformVector(m_localCentreOfMass);
}

const ntShapeInstance& ntBody::GetCollisionShape() const
{
	return m_shapeInstance;
}

void ntBody::SetCollisionShape(const ntShapeInstance& shapeInstance)
{
	m_shapeInstance = shapeInstance;
}

void ntBody::SetNotifyCallback(ntBodyNotify* const notify)
{
	//dAssert(notify->m_body == nullptr);
	if (m_notifyCallback)
	{
		delete m_notifyCallback;
	}
	m_notifyCallback = notify;
	m_notifyCallback->m_body = this;
}

ntBodyNotify* ntBody::GetNotifyCallback(ntBodyNotify* const notify) const
{
	return m_notifyCallback;
}

dInt32 ntBody::GetId() const
{
	return m_uniqueID;
}

ntWorld* ntBody::GetNewton() const
{
	return m_newton;
}

void ntBody::SetNewtonNode(ntWorld* const newton, dList<ntBody*>::dListNode* const node)
{
	m_newton = newton;
	m_newtonNode = node;
}

dList<ntBody*>::dListNode* ntBody::GetNewtonNode() const
{
	return m_newtonNode;
}

ntBroadPhaseBodyNode* ntBody::GetBroadPhaseNode() const
{
	return m_broadPhaseNode;
}

void ntBody::SetBroadPhaseNode(ntBroadPhaseBodyNode* const node)
{
	m_broadPhaseNode = node;
}

ntBroadPhaseAggregate* ntBody::GetBroadPhaseAggregate() const
{
	return m_broadPhaseAggregateNode;
}

void ntBody::SetBroadPhaseAggregate(ntBroadPhaseAggregate* const node)
{
	m_broadPhaseAggregateNode = node;
}

dVector ntBody::GetOmega() const
{
	return m_omega;
}

void ntBody::SetOmega(const dVector& veloc)
{
	m_equilibrium = 0;
	m_omega = veloc;
}

dVector ntBody::GetVelocity() const
{
	return m_veloc;
}

void ntBody::SetVelocity(const dVector& veloc)
{
	m_equilibrium = 0;
	m_veloc = veloc;
}

dMatrix ntBody::GetMatrix() const
{
	return m_matrix;
}

void ntBody::UpdateCollisionMatrix()
{
	m_shapeInstance.SetGlobalMatrix(m_shapeInstance.GetLocalMatrix() * m_matrix);
	m_shapeInstance.CalculateFastAABB(m_shapeInstance.GetGlobalMatrix(), m_minAABB, m_maxAABB);
}

void ntBody::SetMatrix(const dMatrix& matrix)
{
	m_equilibrium = 0;
	m_matrix = matrix;
	dAssert(m_matrix.TestOrthogonal(dFloat32(1.0e-4f)));

	m_rotation = dQuaternion(m_matrix);
	m_globalCentreOfMass = m_matrix.TransformVector(m_localCentreOfMass);
}