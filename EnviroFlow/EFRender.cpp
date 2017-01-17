#include "EFRender.h"
#include "Camera.h"
#include "Input.h"
#include "Quad.h"

Triangle tri[1];
Quad quad[2];
Cam Camera;
bool GetKey[256];

EFRender::EFRender()
{
}


EFRender::~EFRender()
{
}

void EFRender::Init() {
	glewInit();
	glEnable(GL_DEPTH_TEST);

	quad[0] = Quad(1.0f, 1.0f,1.0f);
	quad[0].CreateBuffers();

	quad[1] = Quad(1.0f, 1.0f, 0.0f);
	quad[1].CreateBuffers();
	quad[1].setPos(0.0f, 0.0f, -1.0f);
	quad[1].setColor((GLubyte)0, (GLubyte)155, (GLubyte)0, (GLubyte)0);

}

void RenderTri(int num) {

	for(int i =0;i<num;i++){
		glPushMatrix(); 
	
		glBindBuffer(GL_ARRAY_BUFFER, quad[i].getVBO());
		glVertexPointer(3, GL_FLOAT, 0, 0);
		glEnableClientState(GL_VERTEX_ARRAY);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quad[i].getVIO());
		
		
		glColor3ub(quad[i].getColor('r'), quad[i].getColor('g'), quad[i].getColor('b'));
		glTranslatef(quad[i].getPos('x'), quad[i].getPos('y'), quad[i].getPos('z'));
		glScalef(quad[i].getScale('x'), quad[i].getScale('y'), quad[i].getScale('z'));
	
		glDrawElements(GL_QUADS, quad[i].indices.size(), GL_UNSIGNED_INT, 0);

		glDisableClientState(GL_VERTEX_ARRAY);
		glPopMatrix();
	}
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
	glClearColor(0.329412f, 0.329412f, 0.329412f, 0.0f);
	glLoadIdentity();

	gluLookAt(-0.5, 1.0, 7.0, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);
	//Initialize Camera Render
	Camera.Render();

	//Draw XYZ and Grid to the scene
	DisplayGrid();
	DrawXYZ();

	RenderTri(2);
}