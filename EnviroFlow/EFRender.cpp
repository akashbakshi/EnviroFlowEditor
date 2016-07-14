#include "EFRender.h"
#include "EFCreationSystem.h"
#include "Camera.h"
#include "Input.h"

Cam Camera;
bool GetKey[256];
EFCreationSystem *Create = NULL;

EFRender::EFRender()
{
}


EFRender::~EFRender()
{
}

void EFRender::Init() {

	glEnable(GL_DEPTH_TEST);

	//Create Cube
	Create->CreateCube(0);
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
	glClearColor(0.4747f, 0.4747f, 0.4747f, 0.0f);
	glLoadIdentity();

	gluLookAt(-0.5, 1.0, 7.0, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);
	//Initialize Camera Render
	Camera.Render();
	//Draw XYZ and Grid to the scene

	DisplayGrid();
	DrawXYZ();
	for (int i =0; i < objects; i++)
		RenderMesh(i);
}

void EFRender::RenderMesh(int obj)
{
		for(int i=0;i<tris;i++){
		glPushMatrix();
		glBindBuffer(GL_ARRAY_BUFFER, quad[obj].tri[i].vbo);
		glVertexPointer(3, GL_FLOAT, 0, 0);
		glEnableClientState(GL_VERTEX_ARRAY);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad[obj].tri[i].vio);

		glColor3f(quad[obj].tri[i].rgba[0], quad[obj].tri[i].rgba[1], quad[obj].tri[i].rgba[2]);

		glDrawElements(GL_TRIANGLES, quad[obj].tri[i].indices.size(), GL_UNSIGNED_INT, 0);

		glDisableClientState(GL_VERTEX_ARRAY);
		glPopMatrix();
	}
}
