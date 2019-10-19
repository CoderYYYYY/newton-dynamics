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


#ifndef __D_VEHICLE_TIRE_CONTACT_H__
#define __D_VEHICLE_TIRE_CONTACT_H__

#include "dStdafxVehicle.h"
#include "dVehicleLoopJoint.h"

#define D_TIRE_MAX_LATERAL_SLIP				(0.175f)
#define D_TIRE_MAX_ELASTIC_DEFORMATION		(0.05f)
#define D_TIRE_MAX_ELASTIC_NORMAL_STIFFNESS (10.0f / D_TIRE_MAX_ELASTIC_DEFORMATION)

class dVehicleTireContact: public dVehicleLoopJoint
{
	public:
	class dTireModel
	{
		public:
		dTireModel()
			:m_lateralSlip(0.0f)
			,m_longitodinalSlip(0.0f)
			,m_alingMoment(0.0f)
			,m_lateralForce(0.0f)
			,m_longitunalForce(0.0f)
		{
		}

		dFloat m_lateralSlip;
		dFloat m_longitodinalSlip;
		dFloat m_alingMoment;
		dFloat m_lateralForce;
		dFloat m_longitunalForce;
	};

	dVehicleTireContact();
	void ResetContact();
	void Debug(dCustomJoint::dDebugDisplay* const debugContext, dFloat scale) const;
	void SetContact(const dVector& posit, const dVector& normal, const dVector& lateralDir, dFloat penetration, dFloat staticFriction, dFloat kineticFriction);

	private:
	int GetMaxDof() const { return 3; }
	void TireForces(dFloat longitudinalSlip, dFloat lateralSlip, dFloat frictionCoef);
	void JacobianDerivative(dComplementaritySolver::dParamInfo* const constraintParams);
	void UpdateSolverForces(const dComplementaritySolver::dJacobianPair* const jacobians) const { dAssert(0); }

	dVector m_point;
	dVector m_normal;
	dVector m_lateralDir;
	dVector m_longitudinalDir;
	dFloat m_penetration;
	dFloat m_staticFriction;
//	dFloat m_kineticFriction;
	dFloat m_load____;
	dFloat m_lateralSlip;
	dFloat m_longitudinalSlip;

	dTireModel m_tireModel;
//	dFloat m_normalFilter[4];
//	bool m_isActiveFilter[4];

	friend class dVehicleTire;
};

#endif 
