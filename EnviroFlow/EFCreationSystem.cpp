#include "EFCreationSystem.h"

using namespace std;

EF_TRIANGLE *triangle;
EF_QUAD *quad;
EF_VERTEX *vertex;

int quads = 0;
int objects = 0;
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

void EFCreationSystem::CreateVertex(int obj, GLfloat x, GLfloat y, GLfloat z)
{
	vertex = new EF_VERTEX[1]; 
	
	//set xyz of vertex based on x,y,z parameter
	vertex[obj].xyz[0] = x;
	vertex[obj].xyz[1] = y;
	vertex[obj].xyz[2] = z;
}

void EFCreationSystem::CreateTri(int obj,int tri, GLfloat x, GLfloat y, GLfloat z)
{
	if (obj == 0) {

		triangle = new EF_TRIANGLE[1];

		CreateVertex(obj, x, y, z);
		
	}
	
}

void EFCreationSystem::CreateQuad(int obj, int tri, GLfloat x[3], GLfloat y[3], GLfloat z[3], GLfloat x2[3], GLfloat y2[3], GLfloat z2[3])
{
	//First half of triangle
	if(quads == 0){
		quad = new EF_QUAD[1];
		CreateVertex(obj, x[0], y[0], z[0]);
		CreateVertex(obj, x[1], y[1], z[1]);
		CreateVertex(obj, x[2], y[2], z[2]);
		CreateVertex(obj, x2[0], y2[0], z2[0]);

		quad[obj].tri[tri].vertices.push_back(x[0]);
		quad[obj].tri[tri].vertices.push_back(y[0]);
		quad[obj].tri[tri].vertices.push_back(z[0]);

		quad[obj].tri[tri].vertices.push_back(x[1]);
		quad[obj].tri[tri].vertices.push_back(y[1]);
		quad[obj].tri[tri].vertices.push_back(z[1]);

		quad[obj].tri[tri].vertices.push_back(x[2]);
		quad[obj].tri[tri].vertices.push_back(y[2]);
		quad[obj].tri[tri].vertices.push_back(z[2]);

		quad[obj].tri[tri ].vertices.push_back(x2[0]);
		quad[obj].tri[tri ].vertices.push_back(y2[0]);
		quad[obj].tri[tri ].vertices.push_back(z2[0]);

		quad[obj].tri[tri].rgba[0] = 1.0f;
		quad[obj].tri[tri].rgba[1] = 0.0f;
		quad[obj].tri[tri].rgba[2] = 0.0f;
		quad[obj].tri[tri].rgba[3] = 0.0f;

		quad[obj].tri[tri].indices.push_back(0);
		quad[obj].tri[tri].indices.push_back(1);
		quad[obj].tri[tri].indices.push_back(2);
		quad[obj].tri[tri].indices.push_back(3);

		CreateBuffers(obj, tri);
		//Second half of triangle;
	}
	if (quads > 0) {

		EF_QUAD *temp = new EF_QUAD[quads];
		for (int i = 0; i < quads; i++)
			temp[i] = quad[i];
		quad = new EF_QUAD[quads+1];
		for (int i = 0; i < quads; i++)
			quad[i] = temp[i];
		CreateTri(obj, tri, x[0], y[0], z[0]);
		CreateTri(obj, tri, x[1], y[1], z[1]);
		CreateTri(obj, tri, x[2], y[2], z[2]);


		quad[obj].tri[tri].vertices.push_back(x[0]);
		quad[obj].tri[tri].vertices.push_back(y[0]);
		quad[obj].tri[tri].vertices.push_back(z[0]);

		quad[obj].tri[tri].vertices.push_back(x[1]);
		quad[obj].tri[tri].vertices.push_back(y[1]);
		quad[obj].tri[tri].vertices.push_back(z[1]);

		quad[obj].tri[tri].vertices.push_back(x[2]);
		quad[obj].tri[tri].vertices.push_back(y[2]);
		quad[obj].tri[tri].vertices.push_back(z[2]);


		quad[obj].tri[tri].rgba[0] = 0.0f;
		quad[obj].tri[tri].rgba[1] = 1.0f;
		quad[obj].tri[tri].rgba[2] = 0.0f;
		quad[obj].tri[tri].rgba[3] = 0.0f;

		quad[obj].tri[tri].indices.push_back(0);
		quad[obj].tri[tri].indices.push_back(1);
		quad[obj].tri[tri].indices.push_back(2);

		CreateBuffers(obj, tri);
		//Second half of triangle
		CreateTri(obj, tri, x[0], y[0], z[0]);
		CreateTri(obj, tri, x[1], y[1], z[1]);
		CreateTri(obj, tri, x[2], y[2], z[2]);


		quad[obj].tri[tri + 1].vertices.push_back(x2[0]);
		quad[obj].tri[tri + 1].vertices.push_back(y2[0]);
		quad[obj].tri[tri + 1].vertices.push_back(z2[0]);

		quad[obj].tri[tri + 1].vertices.push_back(x2[1]);
		quad[obj].tri[tri + 1].vertices.push_back(y2[1]);
		quad[obj].tri[tri + 1].vertices.push_back(z2[1]);

		quad[obj].tri[tri + 1].vertices.push_back(x2[2]);
		quad[obj].tri[tri + 1].vertices.push_back(y2[2]);
		quad[obj].tri[tri + 1].vertices.push_back(z2[2]);


		quad[obj].tri[tri + 1].rgba[0] = 0.0f;
		quad[obj].tri[tri + 1].rgba[1] = 0.0f;
		quad[obj].tri[tri + 1].rgba[2] = 1.0f;
		quad[obj].tri[tri + 1].rgba[3] = 0.0f;

		quad[obj].tri[tri + 1].indices.push_back(0);
		quad[obj].tri[tri + 1].indices.push_back(1);
		quad[obj].tri[tri + 1].indices.push_back(2);

		CreateBuffers(obj, tri + 1);
	}
}

void EFCreationSystem::CreateCube(int obj) {

	x = new GLfloat[3];
	y = new GLfloat[3];
	z = new GLfloat[3];

	x2 = new GLfloat[3];
	y2 = new GLfloat[3];
	z2 = new GLfloat[3];

	//front face
	x[0] = -1.0f;
	y[0] = -1.0f;
	z[0] = 0.0f;

	x[1] = -1.0f;
	y[1] = 1.0f;
	z[1] = 0.0f;

	x[2] = 1.0f;
	y[2] = 1.0f;
	z[2] = 0.0f;


	x2[0] = 1.0f;
	y2[0] = -1.0f;
	z2[0] = 0.0f;

	x2[1] = 1.0f;
	y2[1] = 1.0f;
	z2[1] = 0.0f;

	x2[2] = -1.0f;
	y2[2] = 1.0f;
	z2[2] = 0.0f;

	CreateQuad(objects, 0, x, y, z, x2, y2, z2);
	tris += 2;
	objects += 1;
	quads += 1;
	/*
	//top face
	x[0] = -1.0f;
	y[0] = 1.0f;
	z[0] = 0.0f;

	x[1] = -1.0f;
	y[1] = 1.0f;
	z[1] = 2.0f;

	x[2] = 1.0f;
	y[2] = 1.0f;
	z[2] = 0.0f;


	x2[0] = 1.0f;
	y2[0] = 1.0f;
	z2[0] = 0.0f;

	x2[1] = 1.0f;
	y2[1] = 1.0f;
	z2[1] = 2.0f;

	x2[2] = -1.0f;
	y2[2] = 1.0f;
	z2[2] = 2.0f;

	CreateQuad(objects, 0, x, y, z, x2, y2, z2);
	objects += 1;
	quads += 1;

	//Back Face
	x[0] = -1.0f;
	y[0] = -1.0f;
	z[0] = 2.0f;

	x[1] = -1.0f;
	y[1] = 1.0f;
	z[1] = 2.0f;

	x[2] = 1.0f;
	y[2] = -1.0f;
	z[2] = 2.0f;


	x2[0] = 1.0f;
	y2[0] = -1.0f;
	z2[0] = 2.0f;

	x2[1] = 1.0f;
	y2[1] = 1.0f;
	z2[1] = 2.0f;

	x2[2] = -1.0f;
	y2[2] = 1.0f;
	z2[2] = 2.0f;

	CreateQuad(objects, 0, x, y, z, x2, y2, z2);
	quads += 1;
	objects += 1;

	//Bottom Face
	x[0] = -1.0f;
	y[0] = -1.0f;
	z[0] = 0.0f;

	x[1] = -1.0f;
	y[1] = -1.0f;
	z[1] = 2.0f;

	x[2] = 1.0f;
	y[2] = -1.0f;
	z[2] = 0.0f;


	x2[0] = 1.0f;
	y2[0] = -1.0f;
	z2[0] = 0.0f;

	x2[1] = 1.0f;
	y2[1] = -1.0f;
	z2[1] = 2.0f;

	x2[2] = -1.0f;
	y2[2] = -1.0f;
	z2[2] = 2.0f;

	CreateQuad(objects, 0, x, y, z, x2, y2, z2);
	objects += 1;
	quads += 1;

	//Left Face
	x[0] = -1.0f;
	y[0] = 1.0f;
	z[0] = 0.0f;

	x[1] = -1.0f;
	y[1] = 1.0f;
	z[1] = 2.0f;

	x[2] = -1.0f;
	y[2] = -1.0f;
	z[2] = 0.0f;


	x2[0] = -1.0f;
	y2[0] = -1.0f;
	z2[0] = 0.0f;

	x2[1] = -1.0f;
	y2[1] = -1.0f;
	z2[1] = 2.0f;

	x2[2] = -1.0f;
	y2[2] = 1.0f;
	z2[2] = 2.0f;

	CreateQuad(objects, 0, x, y, z, x2, y2, z2);
	objects += 1;
	quads += 1;

	// Right Face

	x[0] = 1.0f;
	y[0] = 1.0f;
	z[0] = 0.0f;

	x[1] = 1.0f;
	y[1] = 1.0f;
	z[1] = 2.0f;

	x[2] = 1.0f;
	y[2] = -1.0f;
	z[2] = 2.0f;


	x2[0] = 1.0f;
	y2[0] = -1.0f;
	z2[0] = 2.0f;

	x2[1] = 1.0f;
	y2[1] = -1.0f;
	z2[1] = 0.0f;

	x2[2] = 1.0f;
	y2[2] = 1.0f;
	z2[2] = 0.0f;

	CreateQuad(objects, 0, x, y, z, x2, y2, z2);
	objects += 1;
	quads += 1;
	*/
}