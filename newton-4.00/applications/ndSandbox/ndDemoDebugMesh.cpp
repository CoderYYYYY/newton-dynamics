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

#include "ndSandboxStdafx.h"
#include "ndDemoCamera.h"
#include "ndDemoEntity.h"
#include "ndDemoDebugMesh.h"
#include "ndTargaToOpenGl.h"
#include "ndDemoEntityManager.h"

ndFlatShadedDebugMesh::ndFlatShadedDebugMesh(const ndShaderPrograms& shaderCache, const ndShapeInstance* const collision)
	:ndDemoMeshInterface()
{
	class ndDrawShape : public ndShapeDebugCallback
	{
		public:
		ndDrawShape()
			:ndShapeDebugCallback()
			,m_triangles(1024)
		{
		}

		virtual void DrawPolygon(dInt32 vertexCount, const dVector* const faceVertex)
		{
			dVector p0(faceVertex[0]);
			dVector p1(faceVertex[1]);
			dVector p2(faceVertex[2]);
			
			dVector normal((p1 - p0).CrossProduct(p2 - p0));
			normal = normal.Normalize();
			for (dInt32 i = 2; i < vertexCount; i++)
			{
				ndPointNormal point;
				point.m_posit.m_x = faceVertex[0].m_x;
				point.m_posit.m_y = faceVertex[0].m_y;
				point.m_posit.m_z = faceVertex[0].m_z;
				point.m_normal.m_x = normal.m_x;
				point.m_normal.m_y = normal.m_y;
				point.m_normal.m_z = normal.m_z;
				m_triangles.PushBack(point);

				point.m_posit.m_x = faceVertex[i - 1].m_x;
				point.m_posit.m_y = faceVertex[i - 1].m_y;
				point.m_posit.m_z = faceVertex[i - 1].m_z;
				point.m_normal.m_x = normal.m_x;
				point.m_normal.m_y = normal.m_y;
				point.m_normal.m_z = normal.m_z;
				m_triangles.PushBack(point);

				point.m_posit.m_x = faceVertex[i].m_x;
				point.m_posit.m_y = faceVertex[i].m_y;
				point.m_posit.m_z = faceVertex[i].m_z;
				point.m_normal.m_x = normal.m_x;
				point.m_normal.m_y = normal.m_y;
				point.m_normal.m_z = normal.m_z;
				m_triangles.PushBack(point);
			}
		}
				
		dArray<ndPointNormal> m_triangles;
	};

	ndDrawShape drawShapes;
	collision->DebugShape(dGetIdentityMatrix(), drawShapes);

	dArray<dInt32> m_triangles(drawShapes.m_triangles.GetCount());
	m_triangles.SetCount(drawShapes.m_triangles.GetCount());
	dInt32 vertexCount = dVertexListToIndexList(&drawShapes.m_triangles[0].m_posit.m_x, sizeof(ndPointNormal), sizeof(ndPointNormal), 0, drawShapes.m_triangles.GetCount(), &m_triangles[0], dFloat32(1.0e-6f));
	
	m_shader = shaderCache.m_flatShaded;
	m_indexCount = m_triangles.GetCount();

	m_color.m_x = 1.0f;
	m_color.m_y = 1.0f;
	m_color.m_z = 1.0f;
	m_color.m_w = 1.0f;

	glGenVertexArrays(1, &m_vertextArrayBuffer);
	glBindVertexArray(m_vertextArrayBuffer);

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(ndPointNormal), &drawShapes.m_triangles[0].m_posit.m_x, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ndPointNormal), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ndPointNormal), (void*)sizeof(ndMeshVector));

	glGenBuffers(1, &m_triangleIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_triangleIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexCount * sizeof(GLuint), &m_triangles[0], GL_STATIC_DRAW);
	
	glBindVertexArray(0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glUseProgram(m_shader);
	m_shadeColorLocation = glGetUniformLocation(m_shader, "shadeColor");
	m_normalMatrixLocation = glGetUniformLocation(m_shader, "normalMatrix");
	m_projectMatrixLocation = glGetUniformLocation(m_shader, "projectionMatrix");
	m_viewModelMatrixLocation = glGetUniformLocation(m_shader, "viewModelMatrix");

	glUseProgram(0);
}

ndFlatShadedDebugMesh::~ndFlatShadedDebugMesh()
{
	if (m_vertextArrayBuffer)
	{
		glDeleteBuffers(1, &m_triangleIndexBuffer);
		glDeleteBuffers(1, &m_vertexBuffer);
		glDeleteVertexArrays(1, &m_vertextArrayBuffer);
	}
}

void ndFlatShadedDebugMesh::Render(ndDemoEntityManager* const scene, const dMatrix& modelMatrix)
{
	glUseProgram(m_shader);

	ndDemoCamera* const camera = scene->GetCamera();

	const dMatrix& viewMatrix = camera->GetViewMatrix();
	const dMatrix& projectionMatrix = camera->GetProjectionMatrix();
	dMatrix viewModelMatrix(modelMatrix * viewMatrix);

	glUniform4fv(m_shadeColorLocation, 1, &m_color.m_x);
	glUniformMatrix4fv(m_normalMatrixLocation, 1, false, &viewModelMatrix[0][0]);
	glUniformMatrix4fv(m_projectMatrixLocation, 1, false, &projectionMatrix[0][0]);
	glUniformMatrix4fv(m_viewModelMatrixLocation, 1, false, &viewModelMatrix[0][0]);

	glBindVertexArray(m_vertextArrayBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_triangleIndexBuffer);

	glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}

ndWireFrameDebugMesh::ndWireFrameDebugMesh(const ndShaderPrograms& shaderCache, const ndShapeInstance* const collision)
	:ndDemoMeshInterface()
{
	class ndDrawShape : public ndShapeDebugCallback
	{
		public:
		ndDrawShape()
			:ndShapeDebugCallback()
			,m_lines(1024)
		{
		}

		virtual void DrawPolygon(dInt32 vertexCount, const dVector* const faceVertex)
		{
			dInt32 i0 = vertexCount - 1;
			for (dInt32 i = 0; i < vertexCount; i++)
			{
				ndMeshVector point;
				point.m_x = faceVertex[i0].m_x;
				point.m_y = faceVertex[i0].m_y;
				point.m_z = faceVertex[i0].m_z;
				m_lines.PushBack(point);

				point.m_x = faceVertex[i].m_x;
				point.m_y = faceVertex[i].m_y;
				point.m_z = faceVertex[i].m_z;
				m_lines.PushBack(point);

				i0 = i;
			}
		}

		dArray<ndMeshVector> m_lines;
	};

	ndDrawShape drawShapes;
	collision->DebugShape(dGetIdentityMatrix(), drawShapes);

	dArray<dInt32> m_lines(drawShapes.m_lines.GetCount());
	m_lines.SetCount(drawShapes.m_lines.GetCount());
	dInt32 vertexCount = dVertexListToIndexList(&drawShapes.m_lines[0].m_x, sizeof(ndMeshVector), sizeof(ndMeshVector), 0, drawShapes.m_lines.GetCount(), &m_lines[0], dFloat32(1.0e-6f));

	m_indexCount = m_lines.GetCount();
	dTree<dUnsigned64, dUnsigned64> filter;
	for (dInt32 i = m_lines.GetCount() - 1; i >= 0; i -= 2)
	{
		union
		{
			dUnsigned64 m_key;
			struct
			{
				dUnsigned32 m_low;
				dUnsigned32 m_high;
			};
		} key;
		dInt32 i0 = m_lines[i - 1];
		dInt32 i1 = m_lines[i - 0];
		key.m_low = dMin(i0, i1);
		key.m_high = dMax(i0, i1);
		if (filter.Find(key.m_key))
		{
			m_lines[i - 1] = m_lines[m_indexCount - 2];
			m_lines[i - 0] = m_lines[m_indexCount - 1];
			m_indexCount -= 2;
		}
		else 
		{
			filter.Insert(key.m_key, key.m_key);
		}
	}

	m_shader = shaderCache.m_wireFrame;
	m_color.m_x = 1.0f;
	m_color.m_y = 1.0f;
	m_color.m_z = 1.0f;
	m_color.m_w = 1.0f;

	glGenVertexArrays(1, &m_vertextArrayBuffer);
	glBindVertexArray(m_vertextArrayBuffer);

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(ndMeshVector), &drawShapes.m_lines[0].m_x, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ndMeshVector), (void*)0);

	glGenBuffers(1, &m_lineIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_lineIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_lines.GetCount() * sizeof(GLuint), &m_lines[0], GL_STATIC_DRAW);

	glBindVertexArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glUseProgram(m_shader);
	m_shadeColorLocation = glGetUniformLocation(m_shader, "shadeColor");
	m_projectionViewModelMatrixLocation = glGetUniformLocation(m_shader, "projectionViewModelMatrix");
	glUseProgram(0);
}

ndWireFrameDebugMesh::~ndWireFrameDebugMesh()
{
	if (m_vertextArrayBuffer)
	{
		glDeleteBuffers(1, &m_lineIndexBuffer);
		glDeleteBuffers(1, &m_vertexBuffer);
		glDeleteVertexArrays(1, &m_vertextArrayBuffer);
	}
}

void ndWireFrameDebugMesh::Render(ndDemoEntityManager* const scene, const dMatrix& modelMatrix)
{
	ndDemoCamera* const camera = scene->GetCamera();
	dMatrix projectionViewModelMatrix(modelMatrix * camera->GetViewMatrix() * camera->GetProjectionMatrix());

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glDepthFunc(GL_LESS);

	glUseProgram(m_shader);
	glUniform4fv(m_shadeColorLocation, 1, &m_color.m_x);
	glUniformMatrix4fv(m_projectionViewModelMatrixLocation, 1, false, &projectionViewModelMatrix[0][0]);

	glBindVertexArray(m_vertextArrayBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_lineIndexBuffer);

	glDrawElements(GL_LINES, m_indexCount, GL_UNSIGNED_INT, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glUseProgram(0);

	//glDepthFunc(GL_EQUAL);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

