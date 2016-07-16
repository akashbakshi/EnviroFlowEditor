#include "EFCreationSystem.h"

using namespace std;

EF_TRIANGLE *triangle;
EF_QUAD *quad;
EF_VERTEX *vertex;
EF_MESH *mesh;
int quads = 0;
int objects = 0;
int tris = 0;
GLfloat tempx[4], tempy[4], tempz[4];

EFCreationSystem::EFCreationSystem()
{
}


EFCreationSystem::~EFCreationSystem()
{
}

void EFCreationSystem::CreateBuffers(int obj, int tri)
{

	glGenBuffers(1, &mesh[obj].m_quad[tri].vbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh[obj].m_quad[tri].vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*mesh[obj].m_quad[tri].q_vertices.size(), &mesh[obj].m_quad[tri].q_vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &mesh[obj].m_quad[tri].vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh[obj].m_quad[tri].vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*mesh[obj].m_quad[tri].q_indices.size(), &mesh[obj].m_quad[tri].q_indices[0], GL_STATIC_DRAW);
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

void EFCreationSystem::CreateQuad(int obj, int quad_num, GLfloat x[4], GLfloat y[4], GLfloat z[4])
{
		// Initialize quad
		quad = new EF_QUAD[1];

		// Create 4 vertices for the plane
		CreateVertex(obj, x[0], y[0], z[0]);
		CreateVertex(obj, x[1], y[1], z[1]);
		CreateVertex(obj, x[2], y[2], z[2]);
		CreateVertex(obj, x[3], y[3], z[3]);

		// Take  coordinates for vertices and add it to the vertices list
		quad[obj].q_vertices.push_back(x[0]);
		quad[obj].q_vertices.push_back(y[0]);
		quad[obj].q_vertices.push_back(z[0]);

		quad[obj].q_vertices.push_back(x[1]);
		quad[obj].q_vertices.push_back(y[1]);
		quad[obj].q_vertices.push_back(z[1]);

		quad[obj].q_vertices.push_back(x[2]);
		quad[obj].q_vertices.push_back(y[2]);
		quad[obj].q_vertices.push_back(z[2]);

		quad[obj].q_vertices.push_back(x[3]);
		quad[obj].q_vertices.push_back(y[3]);
		quad[obj].q_vertices.push_back(z[3]);

		// Set color for quad
		quad[obj].rgba[0] = 1.0f;
		quad[obj].rgba[1] = 0.0f;
		quad[obj].rgba[2] = 0.0f;
		quad[obj].rgba[3] = 0.0f;

		// add indices for quad to tell program which vertices to draw in what order
		quad[obj].q_indices.push_back(0);
		quad[obj].q_indices.push_back(1);
		quad[obj].q_indices.push_back(2);
		quad[obj].q_indices.push_back(3);

}

void EFCreationSystem::CreateCube(int obj) {


	mesh = new EF_MESH[1];

	mesh[obj].m_quad = new EF_QUAD[6];

	//Making Front Face
	
	//Set The XYZ Coordinates For the face
	SetQuadCoordinates(-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	// Take those coordinates and put them in the structure to be drawn
	CreateQuad(obj, quads, tempx, tempy, tempz);
	mesh[obj].m_quad[quads] = quad[0];
	CreateBuffers(obj, quads);
	quads += 1;

	
	SetQuadCoordinates(-1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 0.0f);
	CreateQuad(obj, quads, tempx, tempy, tempz);
	mesh[obj].m_quad[quads] = quad[0];
	CreateBuffers(obj, quads);
	quads += 1;
	
	SetQuadCoordinates(-1.0f, -1.0f, 2.0f, 1.0f, -1.0f, 2.0f, 1.0f, 1.0f, 2.0f, -1.0f, 1.0f, 2.0f);
	CreateQuad(obj, quads, tempx, tempy, tempz);
	mesh[obj].m_quad[quads] = quad[0];
	CreateBuffers(obj, quads);
	quads += 1;

	SetQuadCoordinates(-1.0f, -1.0f, 0.0f, -1.0f, -1.0f, 2.0f, 1.0f, -1.0f, 2.0f, 1.0f, -1.0f, 0.0f);
	CreateQuad(obj, quads, tempx, tempy, tempz);
	mesh[obj].m_quad[quads] = quad[0];
	CreateBuffers(obj, quads);
	quads += 1;

	SetQuadCoordinates(-1.0f, -1.0f, 0.0f, -1.0f, -1.0f, 2.0f, -1.0f, 1.0f, 2.0f, -1.0f, 1.0f, 0.0f);
	CreateQuad(obj, quads, tempx, tempy, tempz);
	mesh[obj].m_quad[quads] = quad[0];
	CreateBuffers(obj, quads);
	quads += 1;

	SetQuadCoordinates(1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 0.0f);
	CreateQuad(obj, quads, tempx, tempy, tempz);
	mesh[obj].m_quad[quads] = quad[0];
	CreateBuffers(obj, quads);
	quads += 1;

	objects += 1;
}

void EFCreationSystem::SetQuadCoordinates(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3, GLfloat x4, GLfloat y4, GLfloat z4)
{

	tempx[0] = x1;
	tempy[0] = y1;
	tempz[0] = z1;

	tempx[1] = x2;
	tempy[1] = y2;
	tempz[1] = z2;

	tempx[2] = x3;
	tempy[2] = y3;
	tempz[2] = z3;

	tempx[3] = x4;
	tempy[3] = y4;
	tempz[3] = z4;
}
