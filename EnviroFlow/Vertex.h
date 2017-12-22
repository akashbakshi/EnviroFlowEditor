#pragma once
#include "main.h"
#include "AppLog.h"

typedef struct Vertex {
	GLfloat xyz[3];
	GLfloat pos[3];
	GLfloat rgba[4];
};

Vertex CreateVertex(GLfloat x, GLfloat y, GLfloat z);


