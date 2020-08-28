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

#ifndef _D_NEWTON_H_
#define _D_NEWTON_H_

class ntBody;
class ntBroadPhase;
class ntDynamicBody;

D_MSC_VECTOR_ALIGNMENT
class ntWorld
	:public dClassAlloc
	,public dSyncMutex
	,public dThread
	,public dThreadPool
{
	public:
	class dNewtonBaseJob: public dThreadPoolJob
	{
		public:
		std::atomic<int>* m_it;
		ntWorld* m_newton;
		dFloat32 m_timestep;
	};

	D_NEWTON_API ntWorld();
	D_NEWTON_API virtual ~ntWorld();

	D_NEWTON_API void Update(dFloat32 timestep);
	D_NEWTON_API void Sync();

	D_NEWTON_API dInt32 GetThreadCount() const;
	D_NEWTON_API void SetThreadCount(dInt32 count);

	D_NEWTON_API dInt32 GetSubSteps() const;
	D_NEWTON_API void SetSubSteps(dInt32 subSteps);

	D_NEWTON_API void DispatchJobs(dThreadPoolJob** const jobs);

	D_NEWTON_API void AddBody(ntBody* const body);
	D_NEWTON_API void RemoveBody(ntBody* const body);

	protected:
	D_NEWTON_API virtual void SubstepUpdate(dFloat32 timestep);
	D_NEWTON_API virtual void UpdateSkeletons(dFloat32 timestep);
	D_NEWTON_API virtual void UpdateSleepState(dFloat32 timestep);
	D_NEWTON_API virtual void ApplyExternalForces(dFloat32 timestep);
	D_NEWTON_API virtual void UpdatePrelisteners(dFloat32 timestep);
	D_NEWTON_API virtual void UpdatePostlisteners(dFloat32 timestep);
	D_NEWTON_API virtual void UpdateBroadPhase(dFloat32 timestep);
	D_NEWTON_API virtual void UpdateDynamics(dFloat32 timestep);
	
	D_NEWTON_API virtual void InternalUpdate(dFloat32 timestep);
	D_NEWTON_API virtual void TransformUpdate(dFloat32 timestep);
	D_NEWTON_API virtual void UpdateListenersPostTransform(dFloat32 timestep);

	protected:

	private:
	virtual void ThreadFunction();
	void BuildBodyArray();

	template <class T>
	void SubmitJobs(dFloat32 timestep);

	dList<ntBody*> m_bodyList;
	dArray<ntDynamicBody*> m_dynamicBodyArray;
	ntBroadPhase* m_broadPhase;
	dFloat32 m_timestep;
	dInt32 m_subSteps;

	friend class ntBroadPhase;
} D_GCC_VECTOR_ALIGNMENT;

template <class T>
void ntWorld::SubmitJobs(dFloat32 timestep)
{
	std::atomic<int> it(0);
	T extJob[D_MAX_THREADS_COUNT];
	dThreadPoolJob* extJobPtr[D_MAX_THREADS_COUNT];

	const dInt32 threadCount = GetThreadCount();
	for (int i = 0; i < threadCount; i++)
	{
		extJob[i].m_it = &it;
		extJob[i].m_newton = this;
		extJob[i].m_timestep = timestep;
		extJobPtr[i] = &extJob[i];
	}
	DispatchJobs(extJobPtr);
}


#endif