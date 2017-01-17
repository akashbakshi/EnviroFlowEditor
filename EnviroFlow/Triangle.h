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

	GLuint getVBO();
	GLuint getVIO();
	GLfloat getPos(char axis);
	void setPos(GLfloat x, GLfloat y, GLfloat z);
	//vectors to hold data
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

private:
	Vertex v[3];
	GLfloat pos[3];
	GLfloat scale[3];
	GLfloat rgba[4];
	int num_indices;

	//Buffer holders
	GLuint vbo, vio;
};

