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

#ifndef _D_DYNAMIC_BODY_H_
#define _D_DYNAMIC_BODY_H_

#include "ntNewtonStdafx.h"
#include "ntContact.h"
#include "ntBodyKinematic.h"

//#define DG_MAX_SPEED_ATT	dgFloat32(0.02f)
////#define DG_FREEZE_ACCEL	dgFloat32(0.1f)
//#define DG_FREEZE_ACCEL		dgFloat32(1.0f)
//#define DG_FREEZE_SPEED		dgFloat32(0.032f)
//
//#define DG_FREEZE_ACCEL2	(DG_FREEZE_ACCEL * DG_FREEZE_ACCEL)
//#define DG_FREEZE_SPEED2	(DG_FREEZE_SPEED * DG_FREEZE_SPEED)
//
//#define DG_FREEZE_MAG		DG_FREEZE_ACCEL
//#define DG_FREEZE_MAG2		(DG_FREEZE_MAG * DG_FREEZE_MAG)
//
//#define DG_ERR_TOLERANCE	dgFloat32(1.0e-2f)
//#define DG_ERR_TOLERANCE2	(DG_ERR_TOLERANCE * DG_ERR_TOLERANCE)
//
//class dgSkeletonContainer;

D_MSV_NEWTON_ALIGN_32
class ntBodyDynamic: public ntBodyKinematic
{
	public:
	D_NEWTON_API ntBodyDynamic();
	D_NEWTON_API virtual ~ntBodyDynamic ();
	D_NEWTON_API virtual ntBodyDynamic* GetAsBodyDynamic() { return this; }
	D_NEWTON_API virtual void ApplyExternalForces(dInt32 threadIndex, dFloat32 timestep);


	dVector GetForce() const;
	void SetForce(const dVector& force);
	
	dVector GetToque() const;
	void SetTorque(const dVector& torque);

	


	protected:
	dVector m_externalForce;
	dVector m_externalTorque;
	dArray<ntBilateralJoint*> m_jointArray;
} D_GCC_NEWTON_ALIGN_32 ;

inline dVector ntBodyDynamic::GetForce() const
{
	return m_externalForce;
}

inline void ntBodyDynamic::SetForce(const dVector& force)
{
	m_externalForce = force;
}

inline dVector ntBodyDynamic::GetToque() const
{
	return m_externalTorque;
}

inline void ntBodyDynamic::SetTorque(const dVector& torque)
{
	m_externalTorque = torque;
}


#endif 

