#include "EFRender.h"
#include "EFCreationSystem.h"
#include "Camera.h"
#include "Input.h"

Cam Camera;
bool GetKey[256];
EFCreationSystem *Create = NULL;

bool init_quad = false;
bool v_wireframe = false;
bool v_solid = true;
bool v_textured = false;

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

		Camera.RAngleY(0.2f);
		//Display();
	}

	if (GetKey[VK_RIGHT])
	{
		Camera.RAngleY(-0.2f);
		//Display();

	}
	if (GetKey[SPACEBAR])
	{

	}
	if (GetKey[W])
	{
		Camera.MoveForwards(-0.2f);
		//Display();
	}
	if (GetKey[S])
	{
		Camera.MoveForwards(0.2f);
		//Display();	
	}
	if (GetKey[UP_ARROW])
	{
		Camera.RAngleX(0.2f);
		//Display();
	}
	if (GetKey[DOWN_ARROW])
	{
		Camera.RAngleX(-0.2f);
		//Display();
	}

	if (GetKey[A])
	{
		Camera.StrafeRight(-0.2f);
		//Display();
	}

	if (GetKey[D])
	{
		Camera.StrafeRight(0.2f);
		//Display();
	}
	
	if (GetKey[P]) {
		init_quad = true;
	}
	if (GetKey[L]) {
		init_quad = false;
	}
	//Basic OpenGL Viewport stuff

	glViewport(0, 0, (GLsizei)1440, (GLsizei)900);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(52.0f, float(1440) / float(900), 1.0f, 1000.0f);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
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

void EFRender::RenderMesh(int obj){

	for(int i =0;i<mesh[obj].quad_count;i++){
		glPushMatrix();
		glBindBuffer(GL_ARRAY_BUFFER, mesh[obj].m_quad[i].vbo);
		glVertexPointer(3, GL_FLOAT, 0, 0);
		glEnableClientState(GL_VERTEX_ARRAY);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh[obj].m_quad[i].vio);

		if(init_quad == true)
			glColor3ub(mesh[obj].m_quad[i].rgba[0], mesh[obj].m_quad[i].rgba[1], mesh[obj].m_quad[i].rgba[2]);
		if (v_solid == true || v_wireframe == true)
			glColor3ub(mesh[obj].rgba[0], mesh[obj].rgba[1], mesh[obj].rgba[2]);
		if (v_textured == true)
			glColor3ub(255, 255, 255);

		glBindBuffer(GL_ARRAY_BUFFER,mesh[obj].m_quad[i].tex[0].vto);
		glTexCoordPointer(2, GL_FLOAT, 0, 0);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glBindTexture(GL_TEXTURE_2D, mesh[obj].m_quad[i].tex[0].TexID);
		glDrawElements(GL_QUADS, mesh[obj].m_quad[i].q_indices.size(), GL_UNSIGNED_INT, 0);
		glDisableClientState(GL_VERTEX_ARRAY);
		glPopMatrix();
	}
}
