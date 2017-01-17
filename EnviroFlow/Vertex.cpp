#include "Vertex.h"


Vertex::Vertex()
{
	//Initialize values to a default values
	for (int i = 0; i < 3; i++)
	{
		xyz[i] = 0.0f;
		pos[i] = 0.0f;
	}
	for (GLfloat i = 0; i < 4; i++)
		rgba[4] = 0.0f;
}

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z) {
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;

	for (int i = 0; i < 3; i++)
		pos[i] = 0.0f;
	for (int i = 0; i < 4; i++)
		rgba[4] = 0.0f;
}

Vertex::~Vertex()
{

}

void Vertex::setXYZ(GLfloat x, GLfloat y, GLfloat z)
{
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;
}

void Vertex::setPos(GLfloat x, GLfloat y, GLfloat z)
{
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
}

void Vertex::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	rgba[0] = r;
	rgba[1] = g;
	rgba[2] = b;
	rgba[3] = a;
}

GLfloat Vertex::getCoordinates(int num)
{
	return xyz[num];
}
