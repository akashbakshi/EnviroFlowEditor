#pragma once
#include "main.h"
#include "EFTGALoader.h"


using namespace std;

struct EF_TEXTURE {

	string filename;

	GLfloat st[2];
	GLuint TexID;
	GLuint vto;
	vector<GLfloat>uv;
};

struct EF_VERTEX {
	GLfloat xyz[3];
	GLfloat rgba[4];
};

struct EF_TRIANGLE {

	EF_VERTEX vert[3];
	GLfloat rgba[4];

	vector<GLfloat>vertices;
	vector<GLuint>indices;

	GLuint vbo, vio;
};

struct EF_QUAD {
	GLfloat xyz[3];
	GLubyte rgba[4];
	GLfloat rot[3];
	GLfloat scale[3];

	int tri_count;

	EF_TRIANGLE tri[2];
	EF_TEXTURE tex[1];

	vector<GLfloat> q_vertices;
	vector<GLuint> q_indices;

	GLuint vbo, vio;
};

struct EF_MESH {
	GLfloat xyz[3];
	GLubyte rgba[4];
	GLfloat rot[4];
	GLdouble pos[3];
	GLfloat scale[3];

	EF_QUAD *m_quad;
	int quad_count;
	vector<GLfloat>m_vert;
	vector<GLfloat>m_ind;
};

extern EF_TRIANGLE *triangle;
extern EF_QUAD *quad;
extern EF_MESH *mesh;
extern int tris;
extern int objects;

class EFCreationSystem
{
public:
	EFCreationSystem();
	~EFCreationSystem();

	void CreateBuffers(int obj, int tri);
	void CreateVertex(int obj,GLfloat x,GLfloat y, GLfloat z);
	void CreateQuad(int obj, int tri, GLfloat x[4], GLfloat y[4], GLfloat z[4]);
	void CreateTri(int obj,int tri, GLfloat x, GLfloat y, GLfloat z);
	void CreateCube(int obj);
	void SetQuadCoordinates(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3, GLfloat x4, GLfloat y4, GLfloat z4);

};

