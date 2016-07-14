#include "EFCreationSystem.h"

using namespace std;

EF_TRIANGLE *triangle;

int tris = 0;
EFCreationSystem::EFCreationSystem()
{
}


EFCreationSystem::~EFCreationSystem()
{
}

void EFCreationSystem::CreateBuffers(int obj, int tri)
{

	glGenBuffers(1, &triangle[tri].vbo);
	glBindBuffer(GL_ARRAY_BUFFER, triangle[tri].vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*triangle[tri].vertices.size(), &triangle[tri].vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &triangle[tri].vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle[tri].vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*triangle[tri].indices.size(), &triangle[tri].indices[0], GL_STATIC_DRAW);
}

void EFCreationSystem::CreateQuad(int obj, int tri, GLfloat x[3], GLfloat y[3], GLfloat z[3], GLfloat x2[3], GLfloat y2[3], GLfloat z2[3])
{
	//First half of triangle
	//CreateTri(tri, -1.0f, 1.0f, 0.0f);
	//CreateTri(tri, -1.0f, -1.0f, 0.0f);
	//CreateTri(tri, 1.0f, -1.0f, 0.0f);
	
	//Second half of triangle
	//CreateTri(tri, 1.0f, 1.0f, 0.0f);
	//CreateTri(tri, -1.0f, -1.0f, 0.0f);
	//CreateTri(tri, 1.0f, -1.0f, 0.0f);

	

	//First half of triangle
	CreateTri(tri, x[0], y[0], z[0]);
	CreateTri(tri, x[1], y[1], z[1]);
	CreateTri(tri, x[2], y[2], z[2]);

	//Second half of triangle
	CreateTri(tri, x2[0], y2[0], z2[0]);
	CreateTri(tri, x2[1], y2[1], z2[1]);
	CreateTri(tri, x2[2], y2[2], z2[2]);
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

	CreateTri(obj, -1.0f, 1.0f, 0.0f);
	CreateTri(obj, -1.0f, -1.0f, 0.0f);
	CreateTri(obj, 1.0f, -1.0f, 0.0f);
	
	CreateBuffers(obj, tris);
}
