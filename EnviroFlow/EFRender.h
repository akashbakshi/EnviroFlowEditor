#pragma once
#include "main.h"

class EFRender
{
public:
	EFRender();
	~EFRender();

	void Init();
	void Render();

	void RenderMesh(int obj);
};

using namespace std;
// Structure for arrows
struct Arrow
{
	vector<GLfloat>vertices;
	vector<GLuint>faces;
	GLubyte rgb[3];
	GLfloat pos[3];
	GLfloat rot[4];
	GLuint vbo, vio;
};

extern bool init_quad;
extern Arrow arrow[3];