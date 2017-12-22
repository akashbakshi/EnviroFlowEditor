#include "Vertex.h"

using namespace std;

Vertex CreateVertex(GLfloat x, GLfloat y, GLfloat z) {
	Vertex tmpVert;

	tmpVert.xyz[0] = x;
	tmpVert.xyz[1] = y;
	tmpVert.xyz[2] = z;

	return tmpVert;
}

GLfloat * setXYZ(Vertex *v,GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat xyz[3];
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;

	return xyz;
}

GLfloat * setPos(GLfloat x, GLfloat y, GLfloat z)
{
	GLfloat pos[3];
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
	return pos;
}

GLfloat *setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	GLfloat rgba[4];
	rgba[0] = r;
	rgba[1] = g;
	rgba[2] = b;
	rgba[3] = a;
	return rgba;
}

