#include "Mesh.h"



Mesh::Mesh()
{
}

Mesh::Mesh(GLfloat sx, GLfloat sy, GLfloat sz,int sides)
{
	q = new Quad[sides];
	for (int i = 0; i < sides; i++){
		q[i] = Quad(sx, sy, 0.0f);
		q[i].setPos(0.0f, 0.0f, 1.0f+5.0f);
	}

	

	num_quads = sides;
	for (int i = 0; i < sides; i++)
		q[i].CreateBuffers();
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