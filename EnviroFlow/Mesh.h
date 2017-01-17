#pragma once
#include "Quad.h"

class Mesh
{
public:
	Mesh();
	Mesh(GLfloat sx,GLfloat sy, GLfloat sz, int sides);
	~Mesh();
private:
	Quad *q;
};

