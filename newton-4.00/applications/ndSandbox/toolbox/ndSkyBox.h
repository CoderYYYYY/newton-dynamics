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

#ifndef __SKY_BOX_H__
#define __SKY_BOX_H__

#include "ndSandboxStdafx.h"
#include "ndDemoEntity.h"

class ndDemoCameraManager;

class ndSkyBox: public ndDemoEntity
{
	public:
	ndSkyBox(GLuint shader);
	virtual ~ndSkyBox();

	virtual void Render(dFloat32 timestep, ndDemoEntityManager* const scene, const dMatrix& matrix) const;

	private:
	void DrawMesh () const;

	GLuint m_displayList;
	GLuint m_shader;
	GLuint m_textures[6];
};

#endif 
