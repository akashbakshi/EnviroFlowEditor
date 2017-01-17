#pragma once
#include "Vertex.h"
#include <vector>

class Triangle
{
public:
	Triangle();
	Triangle(GLfloat sx, GLfloat sy, GLfloat sz);
	~Triangle();

	void CreateBuffers();

	//vectors to hold data
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	GLuint getVBO();
	GLuint getVIO();
private:
	Vertex v[3];
	GLfloat pos[3];
	GLfloat rgba[4];
	int num_indices;

	//Buffer holders
	GLuint vbo, vio;
};

