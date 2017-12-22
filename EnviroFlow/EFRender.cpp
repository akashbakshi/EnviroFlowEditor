#include "EFRender.h"
#include "Camera.h"
#include "Input.h"
#include "Mesh.h"

Mesh mesh[500];
Cam Camera;
bool GetKey[256];

bool MeshColorCheck(Mesh m, GLubyte r, GLubyte g, GLubyte b)
{
	//std::cout << "this one";
	bool exists = false;
	for (int i = 0; i <header.numMesh; i++)
	{
		if (getColor('r', mesh[i]) == r && mesh[i].getColor('g', mesh[i]) == g && mesh[i].getColor('b', mesh[i]) == b)
			exists = true;
		else
			exists = false;
	}
	return exists;
}

EFRender::EFRender()
{
	
}


EFRender::~EFRender()
{
}

void EFRender::Init() {
	glewInit();
	glEnable(GL_DEPTH_TEST);
	float x_amnt = 8.0f;

	for (int i = 0; i < 500; i++) {
		mesh[i] = Mesh(2.0f, 2.0f, 2.0f, CUBE);
		for (int c = 0; c < mesh[i].num_quads; c++)
			mesh[i].q[c].setPos(i*x_amnt, 0.0f, 0.0f);
	}
}

void RenderTri(int num) {
	for (int a = 0; a < num; a++) {

		for(int i =0;i<mesh[a].num_quads;i++){
			glPushMatrix(); 
	
			glBindBuffer(GL_ARRAY_BUFFER, mesh[a].q[i].getVBO());
			glVertexPointer(3, GL_FLOAT, 0, 0);
			glEnableClientState(GL_VERTEX_ARRAY);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh[a].q[i].getVIO());
		
			if(mesh[a].quad_mode == true)
				glColor3ub(mesh[a].q[i].getColor('r'), mesh[a].q[i].getColor('g'), mesh[a].q[i].getColor('b'));
			else if(mesh[a].mesh_mode == true)
				glColor3ub(mesh[a].getColor('r'), mesh[a].getColor('g'), mesh[a].getColor('b'));

			glScalef(mesh[a].q[i].getScale('x'), mesh[a].q[i].getScale('y'), mesh[a].q[i].getScale('z'));
			glTranslatef(mesh[a].q[i].getPos('x'), mesh[a].q[i].getPos('y'), mesh[a].q[i].getPos('z'));
			glRotatef(mesh[a].q[i].getRot('a'), mesh[a].q[i].getRot('x'), mesh[a].q[i].getRot('y'), mesh[a].q[i].getRot('z'));
	
			glDrawElements(GL_QUADS, mesh[a].q[i].indices.size(), GL_UNSIGNED_INT, 0);

			glDisableClientState(GL_VERTEX_ARRAY);
			glPopMatrix();
		}
	}
}
// D raw the XYZ lines in scene
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
		for(int i =0;i<header.numMesh;i++){
			mesh[i].mesh_mode = true;
			mesh[i].quad_mode = false;
		}
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

	RenderTri(500);
}