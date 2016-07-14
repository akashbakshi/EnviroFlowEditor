#pragma once
#include "main.h"

struct EF_TRIANGLE {

	GLfloat xyz[3];
	GLfloat rgba[4];

	vector<GLfloat>vertices;
	vector<GLuint>indices;
};

struct EF_QUAD {
	GLfloat xyz[3];
	GLfloat rgba[4];
	GLfloat rot[3];
	GLfloat rot[3];
	GLfloat scale[3];

	EF_TRIANGLE tri[2];

};

struct EF_MESH {
	GLfloat xyz[3];
	GLfloat rgba[4];
	GLfloat rot[4];
	GLfloat pos[3];
	GLfloat scale[3];

	EF_QUAD quad[2];

	vector<GLfloat>m_vert;
	vector<GLfloat>m_ind;
};


class EFCreationSystem
{
public:
	EFCreationSystem();
	~EFCreationSystem();

	void CreateBuffers(int obj, int tri);
	void CreateQuad(int obj, int tri, GLfloat x, GLfloat y, GLfloat z, GLfloat x2, GLfloat y2, GLfloat z2);
	void CreateTri(int obj, GLfloat x, GLfloat y, GLfloat z);
	void CreateCube(int obj);
};

