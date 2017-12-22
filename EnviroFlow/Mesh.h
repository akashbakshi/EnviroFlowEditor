#pragma once
#include "Quad.h"

typedef struct Mesh {
	int num_quads;
	Quad *q;
	GLuint vbo, vio;
	std::vector<GLfloat> vertices;
	std::vector<GLuint>indices;
	bool quad_mode, mesh_mode;

	int mesh_type;
	GLubyte rgba[4];
};


	
	void setScale(GLfloat x, GLfloat y, GLfloat z);
	GLubyte getColor(char section);

	bool QuadColorCheck(GLubyte r, GLubyte g, GLubyte b);
	void GenerateQuadColors(int quad);

	void GenerateMeshColors(int mesh);
	


