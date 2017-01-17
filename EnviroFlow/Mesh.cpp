#include "Mesh.h"



Mesh::Mesh()
{
}

Mesh::Mesh(GLfloat sx, GLfloat sy, GLfloat sz,int sides)
{
	q = new Quad[sides];
	for (int i = 0; i < sides; i++)
		q[i] = Quad(sx, sy,sz);
}


Mesh::~Mesh()
{
}
