#include "EFCreationSystem.h"

using namespace std;

EF_TRIANGLE *triangle;
EF_QUAD *quad;
EF_VERTEX *vertex;
EF_MESH *mesh;
int objects = 0;
int tris = 0;
GLfloat tempx[4], tempy[4], tempz[4];
GLuint LoadTGATexture(char *TexName);

bool ColorCheck(int obj, GLubyte r, GLubyte g, GLubyte b)
{
	if (objects > 0)
	{
		for (int i = 0; i < objects; i++)
		{
			if (mesh[obj].rgba[0] == r && mesh[obj].rgba[1] == g && mesh[obj].rgba[2] == b)return (true);
		}
	}

	return (false);
}

void GenerateColors(int obj, GLubyte &r, GLubyte &g, GLubyte &b)
{
	unsigned int one, two, three;

	r = rand() * 256 / RAND_MAX;
	g = rand() * 256 / RAND_MAX;
	b = rand() * 256 / RAND_MAX;
	while (ColorCheck(obj,r, g, b))
	{
		r = rand() * 256 / RAND_MAX;
		g = rand() * 256 / RAND_MAX;
		b = rand() * 256 / RAND_MAX;
	}
	one = r;
	two = g;
	three = b;
	cout << "R:" << one << endl;
	cout << "G:" << two << endl;
	cout << "B:" << three << endl;
}


bool QuadColorCheck(int obj,int n_quad,GLubyte r, GLubyte g, GLubyte b)
{
	if (objects > 0)
	{
		for (int i = 0; i < objects; i++)
		{
			if (mesh[obj].m_quad[n_quad].rgba[0] == r && mesh[obj].m_quad[n_quad].rgba[1] == g && mesh[obj].m_quad[n_quad].rgba[2] == b)return (true);
		}
	}

	return (false);
}

void GenerateQuadColors(int obj,int n_quad,GLubyte &r, GLubyte &g, GLubyte &b)
{
	unsigned int one, two, three;

	r = rand() * 256 / RAND_MAX;
	g = rand() * 256 / RAND_MAX;
	b = rand() * 256 / RAND_MAX;
	while (QuadColorCheck(obj,n_quad,r, g, b))
	{
		r = rand() * 256 / RAND_MAX;
		g = rand() * 256 / RAND_MAX;
		b = rand() * 256 / RAND_MAX;
	}
	one = r;
	two = g;
	three = b;
	cout << "R:" << one << endl;
	cout << "G:" << two << endl;
	cout << "B:" << three << endl;
}

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
	vertex[0].xyz[0] = x;
	vertex[0].xyz[1] = y;
	vertex[0].xyz[2] = z;

}

void EFCreationSystem::CreateTri(int obj,int tri, GLfloat x, GLfloat y, GLfloat z)
{
	
		triangle = new EF_TRIANGLE[1];

		CreateVertex(obj, x, y, z);
		
	
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
		quad[0].q_vertices.push_back(x[0]);
		quad[0].q_vertices.push_back(y[0]);
		quad[0].q_vertices.push_back(z[0]);

		quad[0].q_vertices.push_back(x[1]);
		quad[0].q_vertices.push_back(y[1]);
		quad[0].q_vertices.push_back(z[1]);

		quad[0].q_vertices.push_back(x[2]);
		quad[0].q_vertices.push_back(y[2]);
		quad[0].q_vertices.push_back(z[2]);

		quad[0].q_vertices.push_back(x[3]);
		quad[0].q_vertices.push_back(y[3]);
		quad[0].q_vertices.push_back(z[3]);

		// Set color for quad
		GenerateQuadColors(0,quad_num,quad[0].rgba[0], quad[0].rgba[1], quad[0].rgba[2]);

		// add indices for quad to tell program which vertices to draw in what order
		quad[0].q_indices.push_back(0);
		quad[0].q_indices.push_back(1);
		quad[0].q_indices.push_back(2);
		quad[0].q_indices.push_back(3);

}

void SetTexCoord(int obj,int nq,GLfloat s, GLfloat t) {
	
	mesh[obj].m_quad[nq].tex[0].st[0] = s;
	mesh[obj].m_quad[nq].tex[0].st[1] = t;

	mesh[obj].m_quad[nq].tex[0].uv.push_back(mesh[obj].m_quad[nq].tex[0].st[0]);
	mesh[obj].m_quad[nq].tex[0].uv.push_back(mesh[obj].m_quad[nq].tex[0].st[0]);
	mesh[obj].m_quad[nq].tex[0].uv.push_back(mesh[obj].m_quad[nq].tex[0].st[1]);
	mesh[obj].m_quad[nq].tex[0].uv.push_back(mesh[obj].m_quad[nq].tex[0].st[0]);
	mesh[obj].m_quad[nq].tex[0].uv.push_back(mesh[obj].m_quad[nq].tex[0].st[1]);
	mesh[obj].m_quad[nq].tex[0].uv.push_back(mesh[obj].m_quad[nq].tex[0].st[1]);
	mesh[obj].m_quad[nq].tex[0].uv.push_back(mesh[obj].m_quad[nq].tex[0].st[0]);
	mesh[obj].m_quad[nq].tex[0].uv.push_back(mesh[obj].m_quad[nq].tex[0].st[1]);

	glGenBuffers(1, &mesh[obj].m_quad[nq].tex[0].vto);
	glBindBuffer(GL_ARRAY_BUFFER, mesh[obj].m_quad[nq].tex[0].vto);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*mesh[obj].m_quad[nq].tex[0].uv.size(), &mesh[obj].m_quad[nq].tex[0].uv[0], GL_STATIC_DRAW);

}
void EFCreationSystem::CreateCube(int obj) {

	if(obj  == 0)
		mesh = new EF_MESH[1];
	if (obj > 0)
	{
		EF_MESH *temp = new EF_MESH[obj];
		for (int i = 0; i < obj; i++)
			temp[i] = mesh[i];

		mesh = new EF_MESH[obj + 1];
		for (int i = 0; i < obj; i++)
			mesh[i] = temp[i];

	}

	mesh[obj].m_quad = new EF_QUAD[6];
	mesh[obj].quad_count = 0;
	//Making Front Face
	
	//Set The XYZ Coordinates For the face
	SetQuadCoordinates(-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	// Take those coordinates and put them in the structure to be drawn
	CreateQuad(obj, mesh[obj].quad_count, tempx, tempy, tempz);
	mesh[obj].m_quad[mesh[obj].quad_count] = quad[0];
	
	CreateBuffers(obj, mesh[obj].quad_count);
	mesh[obj].m_quad[mesh[obj].quad_count].tex[0].TexID = LoadTGATexture("front.tga");
	SetTexCoord(obj, mesh[obj].quad_count, 0.0001, 0.9999);
	mesh[obj].quad_count += 1;
	
	SetQuadCoordinates(-1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 0.0f);
	CreateQuad(obj, mesh[obj].quad_count, tempx, tempy, tempz);
	mesh[obj].m_quad[mesh[obj].quad_count] = quad[0];
	delete[]quad;
	CreateBuffers(obj, mesh[obj].quad_count);

	mesh[obj].m_quad[mesh[obj].quad_count].tex[0].TexID = LoadTGATexture("top.tga");
	SetTexCoord(obj, mesh[obj].quad_count, 0.0001, 0.9999);
	mesh[obj].quad_count += 1;
	
	SetQuadCoordinates(-1.0f, -1.0f, 2.0f, 1.0f, -1.0f, 2.0f, 1.0f, 1.0f, 2.0f, -1.0f, 1.0f, 2.0f);
	CreateQuad(obj, mesh[obj].quad_count, tempx, tempy, tempz);
	mesh[obj].m_quad[mesh[obj].quad_count] = quad[0];
	delete[]quad;
	CreateBuffers(obj, mesh[obj].quad_count);

	mesh[obj].m_quad[mesh[obj].quad_count].tex[0].TexID = LoadTGATexture("back.tga");
	SetTexCoord(obj, mesh[obj].quad_count, 0.0001, 0.9999);
	mesh[obj].quad_count += 1;

	SetQuadCoordinates(-1.0f, -1.0f, 0.0f, -1.0f, -1.0f, 2.0f, 1.0f, -1.0f, 2.0f, 1.0f, -1.0f, 0.0f);
	CreateQuad(obj, mesh[obj].quad_count, tempx, tempy, tempz);
	mesh[obj].m_quad[mesh[obj].quad_count] = quad[0];
	delete[]quad;
	CreateBuffers(obj, mesh[obj].quad_count);
	mesh[obj].m_quad[mesh[obj].quad_count].tex[0].TexID = LoadTGATexture("bottom.tga");
	SetTexCoord(obj, mesh[obj].quad_count, 0.0001, 0.9999);
	mesh[obj].quad_count += 1;

	SetQuadCoordinates(-1.0f, -1.0f, 0.0f, -1.0f, -1.0f, 2.0f, -1.0f, 1.0f, 2.0f, -1.0f, 1.0f, 0.0f);
	CreateQuad(obj, mesh[obj].quad_count, tempx, tempy, tempz);
	mesh[obj].m_quad[mesh[obj].quad_count] = quad[0];
	delete[]quad;
	CreateBuffers(obj, mesh[obj].quad_count);
	mesh[obj].m_quad[mesh[obj].quad_count].tex[0].TexID = LoadTGATexture("left.tga");
	SetTexCoord(obj, mesh[obj].quad_count, 0.0001, 0.9999);
	mesh[obj].quad_count += 1;

	SetQuadCoordinates(1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 2.0f, 1.0f, 1.0f, 2.0f, 1.0f, 1.0f, 0.0f);
	CreateQuad(obj, mesh[obj].quad_count, tempx, tempy, tempz);
	mesh[obj].m_quad[mesh[obj].quad_count] = quad[0];
	delete[]quad;
	CreateBuffers(obj, mesh[obj].quad_count);
	mesh[obj].m_quad[mesh[obj].quad_count].tex[0].TexID = LoadTGATexture("Right.tga");
	SetTexCoord(obj, mesh[obj].quad_count, 0.0001, 0.9999);
	mesh[obj].quad_count += 1;

	GenerateColors(obj, mesh[obj].rgba[0], mesh[obj].rgba[1], mesh[obj].rgba[2]);
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
