#pragma once
#include "main.h"


using namespace std;

struct EF_TRIANGLE {

	GLfloat xyz[3];
	GLfloat rgba[4];

	vector<GLfloat>vertices;
	vector<GLuint>indices;

	GLuint vbo, vio;
};

struct EF_QUAD {
	GLfloat xyz[3];
	GLfloat rgba[4];
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

extern EF_TRIANGLE *triangle;
extern EF_QUAD *quad;
extern int tris;
extern int quads;
extern int objects;
class EFCreationSystem
{
public:
	EFCreationSystem();
	~EFCreationSystem();

	void CreateBuffers(int obj, int tri);
	void CreateQuad(int obj, int tri, GLfloat x[3], GLfloat y[3], GLfloat z[3], GLfloat x2[3], GLfloat y2[3], GLfloat z2[3]);
	void CreateTri(int obj, GLfloat x, GLfloat y, GLfloat z);
	void CreateCube(int obj);


};

