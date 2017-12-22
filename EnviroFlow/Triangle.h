#pragma once
#include "Vertex.h"
#include <vector>

typedef struct Triangle {
	Vertex v[3];
	GLfloat pos[3];
	GLfloat scale[3];
	GLfloat rgba[4];
	int num_indices;

	//Buffer holders
	GLuint vbo, vio;

	std::vector<GLfloat>vertices;
	std::vector<GLuint>indices;
};


GLfloat getPos(char axis, Triangle tri);

GLfloat getScale(char axis, Triangle tri);

void setPos(Triangle tri, GLfloat x, GLfloat y, GLfloat z);