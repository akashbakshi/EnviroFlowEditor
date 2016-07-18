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

int arr = 0;


EFRender::EFRender()
{
}


EFRender::~EFRender()
{
}

struct Arrow
{
	vector<GLfloat>vertices;
	vector<GLuint>faces;
	GLubyte rgb[3];
	GLfloat pos[3];
	GLfloat rot[4];
	GLuint vbo, vio;
};


Arrow arrow[3];


void ArrowXYZ(int arr_obj)
{
	arrow[arr_obj].vertices.push_back(0.022402f);
	arrow[arr_obj].vertices.push_back(-0.000660f);
	arrow[arr_obj].vertices.push_back(-0.023251f);

	arrow[arr_obj].vertices.push_back(0.022402f);
	arrow[arr_obj].vertices.push_back(-0.000660f);
	arrow[arr_obj].vertices.push_back(0.023251f);

	arrow[arr_obj].vertices.push_back(-0.022402f);
	arrow[arr_obj].vertices.push_back(-0.000660f);
	arrow[arr_obj].vertices.push_back(0.023251f);

	arrow[arr_obj].vertices.push_back(-0.022402f);
	arrow[arr_obj].vertices.push_back(-0.000660f);
	arrow[arr_obj].vertices.push_back(-0.023251f);

	//
	arrow[arr_obj].vertices.push_back(0.022402f);
	arrow[arr_obj].vertices.push_back(0.999497f);
	arrow[arr_obj].vertices.push_back(-0.023251f);

	arrow[arr_obj].vertices.push_back(0.022402f);
	arrow[arr_obj].vertices.push_back(0.999497f);
	arrow[arr_obj].vertices.push_back(0.023251f);

	arrow[arr_obj].vertices.push_back(-0.022402f);
	arrow[arr_obj].vertices.push_back(0.999497f);
	arrow[arr_obj].vertices.push_back(0.023251f);

	arrow[arr_obj].vertices.push_back(-0.022402f);
	arrow[arr_obj].vertices.push_back(0.999497f);
	arrow[arr_obj].vertices.push_back(-0.023251f);

	//
	arrow[arr_obj].vertices.push_back(0.095719f);
	arrow[arr_obj].vertices.push_back(1.000003f);
	arrow[arr_obj].vertices.push_back(-0.095718f);

	arrow[arr_obj].vertices.push_back(0.095718f);
	arrow[arr_obj].vertices.push_back(1.000003f);
	arrow[arr_obj].vertices.push_back(0.095719f);

	arrow[arr_obj].vertices.push_back(-0.095719f);
	arrow[arr_obj].vertices.push_back(1.000003f);
	arrow[arr_obj].vertices.push_back(0.095719f);

	arrow[arr_obj].vertices.push_back(-0.095719f);
	arrow[arr_obj].vertices.push_back(1.000003f);
	arrow[arr_obj].vertices.push_back(-0.095718f);

	//
	arrow[arr_obj].vertices.push_back(0.001761f);
	arrow[arr_obj].vertices.push_back(1.268505f);
	arrow[arr_obj].vertices.push_back(-0.001761f);

	arrow[arr_obj].vertices.push_back(0.001761f);
	arrow[arr_obj].vertices.push_back(1.268505f);
	arrow[arr_obj].vertices.push_back(0.001761f);

	arrow[arr_obj].vertices.push_back(-0.001761f);
	arrow[arr_obj].vertices.push_back(1.268505f);
	arrow[arr_obj].vertices.push_back(0.001761f);

	arrow[arr_obj].vertices.push_back(-0.001761f);
	arrow[arr_obj].vertices.push_back(1.268505f);
	arrow[arr_obj].vertices.push_back(-0.001761f);

	//faces
	arrow[arr_obj].faces.push_back(0);
	arrow[arr_obj].faces.push_back(1);
	arrow[arr_obj].faces.push_back(2);


	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(10);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(1);
	arrow[arr_obj].faces.push_back(0);

	arrow[arr_obj].faces.push_back(5);
	arrow[arr_obj].faces.push_back(2);
	arrow[arr_obj].faces.push_back(1);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(2);

	arrow[arr_obj].faces.push_back(0);
	arrow[arr_obj].faces.push_back(7);
	arrow[arr_obj].faces.push_back(4);

	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(14);
	arrow[arr_obj].faces.push_back(10);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(5);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(11);
	arrow[arr_obj].faces.push_back(7);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(11);
	arrow[arr_obj].faces.push_back(8);

	arrow[arr_obj].faces.push_back(15);
	arrow[arr_obj].faces.push_back(13);
	arrow[arr_obj].faces.push_back(12);

	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(12);
	arrow[arr_obj].faces.push_back(13);

	arrow[arr_obj].faces.push_back(10);
	arrow[arr_obj].faces.push_back(15);
	arrow[arr_obj].faces.push_back(11);

	arrow[arr_obj].faces.push_back(11);
	arrow[arr_obj].faces.push_back(12);
	arrow[arr_obj].faces.push_back(8);

	arrow[arr_obj].faces.push_back(0);
	arrow[arr_obj].faces.push_back(1);
	arrow[arr_obj].faces.push_back(2);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(5);
	arrow[arr_obj].faces.push_back(9);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(5);
	arrow[arr_obj].faces.push_back(1);

	arrow[arr_obj].faces.push_back(5);
	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(2);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(7);
	arrow[arr_obj].faces.push_back(3);

	arrow[arr_obj].faces.push_back(0);
	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(7);

	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(13);
	arrow[arr_obj].faces.push_back(14);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(8);
	arrow[arr_obj].faces.push_back(9);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(10);
	arrow[arr_obj].faces.push_back(11);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(7);
	arrow[arr_obj].faces.push_back(11);

	arrow[arr_obj].faces.push_back(15);
	arrow[arr_obj].faces.push_back(14);
	arrow[arr_obj].faces.push_back(13);

	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(8);
	arrow[arr_obj].faces.push_back(12);

	arrow[arr_obj].faces.push_back(10);
	arrow[arr_obj].faces.push_back(14);
	arrow[arr_obj].faces.push_back(15);

	arrow[arr_obj].faces.push_back(11);
	arrow[arr_obj].faces.push_back(15);
	arrow[arr_obj].faces.push_back(12);


	glGenBuffers(1, &arrow[arr_obj].vbo);
	glBindBuffer(GL_ARRAY_BUFFER, arrow[arr_obj].vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*arrow[arr_obj].vertices.size(), &arrow[arr_obj].vertices[0], GL_STATIC_DRAW);



	glGenBuffers(1, &arrow[arr_obj].vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, arrow[arr_obj].vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*arrow[arr_obj].faces.size(), &arrow[arr_obj].faces[0], GL_STATIC_DRAW);
	arr += 1;

}


void RenderArrows(int obj)
{
	glPushMatrix();

	glBindBuffer(GL_ARRAY_BUFFER, arrow[obj].vbo);

	glVertexPointer(3, GL_FLOAT, 0, 0);
	glEnableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, arrow[obj].vio);

	glTranslated(3, 1, 1);
	glRotatef(arrow[obj].rot[0], arrow[obj].rot[1], arrow[obj].rot[2], arrow[obj].rot[3]);

	glColor3ub(arrow[obj].rgb[0], arrow[obj].rgb[1], arrow[obj].rgb[2]);
	glDrawElements(GL_TRIANGLES , arrow[obj].faces.size(), GL_UNSIGNED_INT, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void EFRender::Init() {

	glEnable(GL_DEPTH_TEST);
	//Create Cube
	Create->CreateCube(0);
	//Create->CreateCube(1);


	ArrowXYZ(0);
	arrow[0].rgb[0] = 0.0;
	arrow[0].rgb[1] = 255.0;
	arrow[0].rgb[2] = 0.0;


	arrow[0].pos[0] = -2.05f;
	/*arrow[0].pos[1] = 1.0f;
	arrow[0].pos[2] = -1.85f;
	*/


	ArrowXYZ(1);
	arrow[1].rgb[0] = 255.0;
	arrow[1].rgb[1] = 0.0;
	arrow[1].rgb[2] = 0.0;

	arrow[1].rot[0] = 90.0f;
	arrow[1].rot[1] = 0.0f;
	arrow[1].rot[2] = 0.0f;
	arrow[1].rot[3] = -90.0f;
	/*
	arrow[1].pos[0] = -5.0f;
	arrow[1].pos[1] = 0.0f;
	arrow[1].pos[2] = 0.0f;
	*/

	ArrowXYZ(2);
	arrow[2].rgb[0] = 0.0;
	arrow[2].rgb[1] = 0.0;
	arrow[2].rgb[2] = 255.0;

	arrow[2].rot[0] = 90.0f;
	arrow[2].rot[1] = 90.0f;
	arrow[2].rot[2] = 0.0f;
	arrow[2].rot[3] = 0.0f;
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
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	glLoadIdentity();

	gluLookAt(-0.5, 1.0, 7.0, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);
	//Initialize Camera Render
	Camera.Render();
	//Draw XYZ and Grid to the scene

	DisplayGrid();
	DrawXYZ();


	for (int a=0;a<arr;a++)
		RenderArrows(a);

	for (int i = 0; i < objects; i++)
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
		if (v_solid == true || v_wireframe == true && v_textured == false)
			glColor3ub(mesh[obj].rgba[0], mesh[obj].rgba[1], mesh[obj].rgba[2]);
		if (v_textured == true)
			glColor3ub(255, 255, 255);
		glTranslated(3.0, 0.0, 0.0);
		glBindBuffer(GL_ARRAY_BUFFER,mesh[obj].m_quad[i].tex[0].vto);
		glTexCoordPointer(2, GL_FLOAT, 0, 0);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glBindTexture(GL_TEXTURE_2D, mesh[obj].m_quad[i].tex[0].TexID);
		glDrawElements(GL_QUADS, mesh[obj].m_quad[i].q_indices.size(), GL_UNSIGNED_INT, 0);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glPopMatrix();
	}
}
