#include "Triangle.h"



Triangle::Triangle()
{
	v[0] = Vertex(0.0f, 0.0f, 0.0f);
	v[1] = Vertex(0.0f, 1.0f, 0.0f);
	v[2] = Vertex(1.0f, 1.0f, 0.0f);

	for (int i = 0; i < 3; i++)
		pos[i] = 0.0f;
	for (int i = 0; i < 4; i++)
		rgba[i] = 0.0f;
}

Triangle::Triangle(GLfloat sx, GLfloat sy, GLfloat sz)
{
	v[0] = Vertex(0.0f, 0.0f, 0.0f);
	v[1] = Vertex(0.0f, sy, 0.0f);
	v[2] = Vertex(sx, sy, 0.0f);

	for (int i = 0; i < 3; i++)
		pos[i] = 0.0f;
	for (int i = 0; i < 4; i++)
		rgba[i] = 0.0f;
}


Triangle::~Triangle()
{
}
