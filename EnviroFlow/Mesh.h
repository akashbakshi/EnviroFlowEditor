#pragma once
#include "Quad.h"

class Mesh
{
public:
	Mesh();
	Mesh(GLfloat sx,GLfloat sy, GLfloat sz, int sides);
	~Mesh();
	
	void CreateBuffers();
	int num_quads;
	GLuint vbo,vio;
	std::vector<GLfloat> vertices;
	std::vector<GLuint>indices;
	Quad *q;
private:
};

