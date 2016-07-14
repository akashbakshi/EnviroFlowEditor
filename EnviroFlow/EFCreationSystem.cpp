#include "EFCreationSystem.h"

using namespace std;

EF_TRIANGLE *triangle;
EF_QUAD *quad;

int tris = 0;

GLfloat *x, *y, *z;
GLfloat *x2, *y2, *z2;
EFCreationSystem::EFCreationSystem()
{
}


EFCreationSystem::~EFCreationSystem()
{
}

void EFCreationSystem::CreateBuffers(int obj, int tri)
{

	glGenBuffers(1, &quad[obj].tri[tri].vbo);
	glBindBuffer(GL_ARRAY_BUFFER, quad[obj].tri[tri].vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*quad[obj].tri[tri].vertices.size(), &quad[obj].tri[tri].vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &quad[obj].tri[tri].vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad[obj].tri[tri].vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*quad[obj].tri[tri].indices.size(), &quad[obj].tri[tri].indices[0], GL_STATIC_DRAW);
}

void EFCreationSystem::CreateQuad(int obj, int tri, GLfloat x[3], GLfloat y[3], GLfloat z[3], GLfloat x2[3], GLfloat y2[3], GLfloat z2[3])
{
	//First half of triangle

	quad = new EF_QUAD[1];
	CreateTri(tri, x[0], y[0], z[0]);
	CreateTri(tri, x[1], y[1], z[1]);
	CreateTri(tri, x[2], y[2], z[2]);

	quad[obj].tri[tri].vertices.push_back(x[0]);
	quad[obj].tri[tri].vertices.push_back(y[0]);
	quad[obj].tri[tri].vertices.push_back(z[0]);

	quad[obj].tri[tri].vertices.push_back(x[1]);
	quad[obj].tri[tri].vertices.push_back(y[1]);
	quad[obj].tri[tri].vertices.push_back(z[1]);

	quad[obj].tri[tri].vertices.push_back(x[2]);
	quad[obj].tri[tri].vertices.push_back(y[2]);
	quad[obj].tri[tri].vertices.push_back(z[2]);

	quad[obj].tri[tri].rgba[0] = 1.0f;
	quad[obj].tri[tri].rgba[1] = 0.0f;
	quad[obj].tri[tri].rgba[2] = 0.0f;
	quad[obj].tri[tri].rgba[3] = 0.0f;

	quad[obj].tri[tri].indices.push_back(0);
	quad[obj].tri[tri].indices.push_back(1);
	quad[obj].tri[tri].indices.push_back(2);

	CreateBuffers(obj, tri);
	//Second half of triangle
	CreateTri(tri, x2[0], y2[0], z2[0]);
	CreateTri(tri, x2[1], y2[1], z2[1]);
	CreateTri(tri, x2[2], y2[2], z2[2]);


	quad[obj].tri[tri+1].vertices.push_back(x2[0]);
	quad[obj].tri[tri+1].vertices.push_back(y2[0]);
	quad[obj].tri[tri+1].vertices.push_back(z2[0]);

	quad[obj].tri[tri+1].vertices.push_back(x2[1]);
	quad[obj].tri[tri+1].vertices.push_back(y2[1]);
	quad[obj].tri[tri+1].vertices.push_back(z2[1]);

	quad[obj].tri[tri+1].vertices.push_back(x2[2]);
	quad[obj].tri[tri+1].vertices.push_back(y2[2]);
	quad[obj].tri[tri+1].vertices.push_back(z2[2]);


	quad[obj].tri[tri + 1].rgba[0] = 0.0f;
	quad[obj].tri[tri + 1].rgba[1] = 0.0f;
	quad[obj].tri[tri + 1].rgba[2] = 1.0f;
	quad[obj].tri[tri + 1].rgba[3] = 0.0f;

	quad[obj].tri[tri+1].indices.push_back(0);
	quad[obj].tri[tri+1].indices.push_back(1);
	quad[obj].tri[tri+1].indices.push_back(2);

	CreateBuffers(obj, tri+1);
}

void EFCreationSystem::CreateTri(int obj, GLfloat x, GLfloat y, GLfloat z)
{
	if (obj == 0) {

		triangle = new EF_TRIANGLE[1];
		triangle[obj].xyz[0] = x;
		triangle[obj].xyz[1] = y;
		triangle[obj].xyz[2] = z;

		triangle[obj].vertices.push_back(triangle[obj].xyz[0]);
		triangle[obj].vertices.push_back(triangle[obj].xyz[1]);
		triangle[obj].vertices.push_back(triangle[obj].xyz[2]);

		triangle[obj].indices.push_back(0);
		triangle[obj].indices.push_back(1);
		triangle[obj].indices.push_back(2);
	}
}

void EFCreationSystem::CreateCube(int obj) {

	x = new GLfloat[3];
	y = new GLfloat[3];
	z = new GLfloat[3];

	x2 = new GLfloat[3];
	y2 = new GLfloat[3];
	z2 = new GLfloat[3];

	x[0] = -1.0f;
	x[1] = 1.0f;
	x[2] = 1.0f;

	y[0] = -1.0f;
	y[1] = -1.0f;
	y[2] = 1.0f;

	z[0] = 0.0f;
	z[1] = 0.0f;
	z[2] = 0.0f;

	x2[0] = 1.0f;
	x2[1] = -1.0f;
	x2[2] = -1.0f;

	y2[0] = 1.0f;
	y2[1] = 1.0f;
	y2[2] = -1.0f;

	z2[0] = 0.0f;
	z2[1] = 0.0f;
	z2[2] = 0.0f;

	CreateQuad(obj, tris, x, y, z, x2, y2, z2);
	
	CreateBuffers(obj, tris);
}
