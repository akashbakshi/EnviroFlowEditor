#pragma once
#include "Vertex.h"
class Triangle
{
public:
	Triangle();
	Triangle(GLfloat sx, GLfloat sy, GLfloat sz);
	~Triangle();
private:
	Vertex v[3];
	GLfloat pos[3];
	GLfloat rgba[4];
};

