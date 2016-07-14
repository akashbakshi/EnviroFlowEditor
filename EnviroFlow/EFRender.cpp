#include "EFRender.h"
#include "Camera.h"
#include "Input.h"

Cam Camera;
bool GetKey[256];

EFRender::EFRender()
{
}


EFRender::~EFRender()
{
}

void EFRender::Init() {

	glEnable(GL_DEPTH_TEST);
}

// Draw the XYZ lines in scene
void DrawXYZ()
{
	glTranslatef(0.0f, 0.1f, 0.0f);
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(10, 0, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3d(0, 1, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 10, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3d(0, 0, 1);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 10);
	glEnd();
}

// Draw the grid
void DisplayGrid()
{
	glBegin(GL_LINES);
	for (GLfloat i = -250.0f; i <= 250.0f; i++) {
		glColor3ub(52, 211, 255);
		glVertex3f(i, 0.0f, -250.0f);
		glVertex3f(i, 0.0f, 250.0f);

		glVertex3f(-250.0f, 0.0f, i);
		glVertex3f(250.0f, 0.0f, i);

	}
	glEnd();

}

void EFRender::Render() {
	//Camera Key Binding
	if (GetKey[LEFT_ARROW])
	{

		Camera.RAngleY(0.4f);
		//Display();
	}

	if (GetKey[VK_RIGHT])
	{
		Camera.RAngleY(-0.4f);
		//Display();

	}
	if (GetKey[SPACEBAR])
	{

	}
	if (GetKey[W])
	{
		Camera.MoveForwards(-0.4f);
		//Display();
	}
	if (GetKey[S])
	{
		Camera.MoveForwards(0.4f);
		//Display();	
	}
	if (GetKey[UP_ARROW])
	{
		Camera.RAngleX(0.4f);
		//Display();
	}
	if (GetKey[DOWN_ARROW])
	{
		Camera.RAngleX(-0.4f);
		//Display();
	}

	if (GetKey[A])
	{
		Camera.StrafeRight(-0.4f);
		//Display();
	}

	if (GetKey[D])
	{
		Camera.StrafeRight(0.4f);
		//Display();
	}

	
	//Basic OpenGL Viewport stuff

	glViewport(0, 0, (GLsizei)1440, (GLsizei)900);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(52.0f, float(1440) / float(900), 1.0f, 1000.0f);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.4747, 0.4747, 0.4747, 0.0f);
	glLoadIdentity();

	gluLookAt(-0.5, 1.0, 7.0, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);
	//Initialize Camera Render
	Camera.Render();

	//Draw XYZ and Grid to the scene
	DisplayGrid();
	DrawXYZ();
}