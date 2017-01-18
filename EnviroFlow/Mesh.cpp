#include "Mesh.h"

MAP_HEADER header;


bool Mesh::QuadColorCheck(GLubyte r, GLubyte g, GLubyte b)
{
	bool exists = false;
	for (int i = 0; i <num_quads; i++)
	{
		if (q[i].getColor('r') == r &&q[i].getColor('g') == g && q[i].getColor('b') == b)
			exists = true;
		else
			exists = false;
	}
	return exists;
}


void Mesh::GenerateQuadColors(int quad)
{
	GLubyte r, g, b;

	r = rand() * 256 / RAND_MAX;
	g = rand() * 256 / RAND_MAX;
	b = rand() * 256 / RAND_MAX;
	while (QuadColorCheck(r, g, b))
	{
		r = rand() * 256 / RAND_MAX;
		g = rand() * 256 / RAND_MAX;
		b = rand() * 256 / RAND_MAX;
	}

	q[quad].setColor(r, g, b, 0);
}



void Mesh::GenerateMeshColors(int mesh)
{
	GLubyte r, g, b;

	r = rand() * 256 / RAND_MAX;
	g = rand() * 256 / RAND_MAX;
	b = rand() * 256 / RAND_MAX;
	while (MeshColorCheck(r, g, b))
	{
		r = rand() * 256 / RAND_MAX;
		g = rand() * 256 / RAND_MAX;
		b = rand() * 256 / RAND_MAX;
	}

	rgba[0] = r;
	rgba[1] = g;
	rgba[2] = b;
}


Mesh::Mesh()
{
}

Mesh::Mesh(GLfloat sx, GLfloat sy, GLfloat sz,int type)
{
	switch (type) {
	case CUBE: {
		q = new Quad[6];
		for (int i = 0; i < 6; i++) {
			q[i] = Quad(sx, sy, 0.0f);
			GenerateQuadColors(i);
		}
		//0 back face
		q[1].setPos(q[1].getPos('x'), q[1].getPos('y'), sz);//1 front face
		q[2].setRotation(90.0f, 90.0f, 0.0f, 0.0f); // 2 bottom face

		q[3].setPos(q[3].getPos('x'), sy, q[3].getPos('z')); // 3 top face
		q[3].setRotation(90.0f, 90.0f, 0.0f, 0.0f);

		q[4].setPos(sx, q[4].getPos('y'), sz); //4 right face
		q[4].setRotation(90.0f, 0.0f, 90.0f, 0.0f);


		q[5].setPos(q[1].getPos('x'), q[4].getPos('y'), sz); //4 left face
		q[5].setRotation(90.0f, 0.0f, 90.0f, 0.0f);

		num_quads = 6;
		for (int i = 0; i < 6; i++)
			q[i].CreateBuffers();

		header.numMesh += 1;
		header.numQuads += 6;
		quad_mode = true;
		mesh_mode = false;
		GenerateMeshColors(header.numMesh);
	}break;

	}

}


Mesh::~Mesh()
{
}

void Mesh::CreateBuffers() {
	glGenBuffers(1, &vbo); 
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indices.size(), &indices[0], GL_STATIC_DRAW);
}

GLubyte Mesh::getColor(char section)
{
	GLubyte val;
	if (section == 'r' || section == 'R')
		val = rgba[0];
	else if (section == 'g' || section == 'G')
		val = rgba[1];
	else if (section == 'b' || section == 'B')
		val = rgba[2];
	else if (section == 'a' || section == 'A')
		val = rgba[3];

	return val;
}

