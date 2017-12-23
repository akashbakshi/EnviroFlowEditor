#pragma once
#include "main.h"

class EFRender
{
public:
	EFRender();
	~EFRender();

	void Init();
	void SetUpViewport(int winWidth, int winHeight);
	void Render(int renderWidth, int renderHeight);

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
	GLfloat scale[3];
	GLuint vbo, vio;
};

extern bool init_quad;
extern Arrow arrow[3];
extern bool sel_trans, sel_scale, sel_rot;

extern void TranslateArrowsXYZ(int arr_obj);
extern void ScaleArrowsXYZ(int arr_obj);