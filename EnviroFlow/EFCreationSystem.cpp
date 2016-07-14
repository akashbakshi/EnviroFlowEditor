#include "EFCreationSystem.h"

using namespace std;

EF_TRIANGLE *triangle;

int tri = 0;
EFCreationSystem::EFCreationSystem()
{
}


EFCreationSystem::~EFCreationSystem()
{
}

void EFCreationSystem::CreateBuffers(int obj, int tri)
{
}

void EFCreationSystem::CreateQuad(int obj, int tri, GLfloat x, GLfloat y, GLfloat z, GLfloat x2, GLfloat y2, GLfloat z2)
{
	//First half of triangle
	//CreateTri(tri, -1.0f, 1.0f, 0.0f);
	//CreateTri(tri, -1.0f, -1.0f, 0.0f);
	//CreateTri(tri, 1.0f, -1.0f, 0.0f);
	
	//Second half of triangle
	//CreateTri(tri, 1.0f, 1.0f, 0.0f);
	//CreateTri(tri, -1.0f, -1.0f, 0.0f);
	//CreateTri(tri, 1.0f, -1.0f, 0.0f);
}

void EFCreationSystem::CreateTri(int obj, GLfloat x, GLfloat y, GLfloat z)
{
	if (tri == 0) {

		triangle = new EF_TRIANGLE[1];
		triangle[obj].xyz[0] = x;
		triangle[obj].xyz[1] = y;
		triangle[obj].xyz[2] = z;
	}
}

void EFCreationSystem::CreateCube(int obj) {

	

	
}
