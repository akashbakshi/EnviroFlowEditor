#include "EFRender.h"
#include "EFCreationSystem.h"
#include "Camera.h"
#include "Input.h"

Cam Camera;
bool GetKey[256];
EFCreationSystem *Create = NULL;

//Booleans for each view mode
bool init_quad = false;
bool v_wireframe = false;
bool v_solid = true;
bool v_textured = false;

GLfloat camY = 0.0f;
// arrow index
int arr = 0;

bool selection = false;

Arrow arrow[3];
EFRender::EFRender()
{
}


EFRender::~EFRender()
{
}

void ScaleArrowsXYZ(int arr_obj)
{

	arrow[arr_obj].vertices.push_back(0.022402f);
	arrow[arr_obj].vertices.push_back(-0.000660f);
	arrow[arr_obj].vertices.push_back(-0.023251f);

	arrow[arr_obj].vertices.push_back(-0.022402f);
	arrow[arr_obj].vertices.push_back(-0.000660f);
	arrow[arr_obj].vertices.push_back(0.023251f);

	arrow[arr_obj].vertices.push_back(-0.022402f);
	arrow[arr_obj].vertices.push_back(-0.000660f);
	arrow[arr_obj].vertices.push_back(-0.023251f);

	arrow[arr_obj].vertices.push_back(-0.022402f);
	arrow[arr_obj].vertices.push_back(0.999497f);
	arrow[arr_obj].vertices.push_back(0.023251f);

	//
	arrow[arr_obj].vertices.push_back(0.095718f);
	arrow[arr_obj].vertices.push_back(1.000003f);
	arrow[arr_obj].vertices.push_back(0.095719f);

	arrow[arr_obj].vertices.push_back(-0.095719f);
	arrow[arr_obj].vertices.push_back(1.000003f);
	arrow[arr_obj].vertices.push_back(0.095719f);

	arrow[arr_obj].vertices.push_back(0.022402f);
	arrow[arr_obj].vertices.push_back(0.999497f);
	arrow[arr_obj].vertices.push_back(-0.023251f);


	arrow[arr_obj].vertices.push_back(0.022402f);
	arrow[arr_obj].vertices.push_back(-0.000660f);
	arrow[arr_obj].vertices.push_back(0.023251f);

	//
	arrow[arr_obj].vertices.push_back(0.022402f);
	arrow[arr_obj].vertices.push_back(0.999497f);
	arrow[arr_obj].vertices.push_back(0.023251f);

	arrow[arr_obj].vertices.push_back(-0.022402f);
	arrow[arr_obj].vertices.push_back(0.999497f);
	arrow[arr_obj].vertices.push_back(-0.023251f);

	arrow[arr_obj].vertices.push_back(-0.095688f);
	arrow[arr_obj].vertices.push_back(1.201575f);
	arrow[arr_obj].vertices.push_back(0.095132f);

	arrow[arr_obj].vertices.push_back(-0.095719f);
	arrow[arr_obj].vertices.push_back(1.000003f);
	arrow[arr_obj].vertices.push_back(-0.095718f);

	//
	arrow[arr_obj].vertices.push_back(0.095719f);
	arrow[arr_obj].vertices.push_back(1.000003f);
	arrow[arr_obj].vertices.push_back(-0.095718f);

	arrow[arr_obj].vertices.push_back(-0.095688f);
	arrow[arr_obj].vertices.push_back(1.201575f);
	arrow[arr_obj].vertices.push_back(-0.095822f);

	arrow[arr_obj].vertices.push_back(0.095688f);
	arrow[arr_obj].vertices.push_back(1.201575f);
	arrow[arr_obj].vertices.push_back(0.095132f);

	arrow[arr_obj].vertices.push_back(0.095688f);
	arrow[arr_obj].vertices.push_back(1.201575f);
	arrow[arr_obj].vertices.push_back(-0.095822f);

	//faces
	arrow[arr_obj].faces.push_back(0);
	arrow[arr_obj].faces.push_back(1);
	arrow[arr_obj].faces.push_back(2);


	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(5);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(7);
	arrow[arr_obj].faces.push_back(0);
	//
	arrow[arr_obj].faces.push_back(8);
	arrow[arr_obj].faces.push_back(1);
	arrow[arr_obj].faces.push_back(7);

	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(2);
	arrow[arr_obj].faces.push_back(1);

	//
	arrow[arr_obj].faces.push_back(0);
	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(6);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(10);
	arrow[arr_obj].faces.push_back(5);
	//

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(8);

	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(11);
	arrow[arr_obj].faces.push_back(9);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(11);
	arrow[arr_obj].faces.push_back(12);

	arrow[arr_obj].faces.push_back(13);
	arrow[arr_obj].faces.push_back(14);
	arrow[arr_obj].faces.push_back(15);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(15);
	arrow[arr_obj].faces.push_back(14);
	//

	arrow[arr_obj].faces.push_back(5);
	arrow[arr_obj].faces.push_back(13);
	arrow[arr_obj].faces.push_back(11);

	arrow[arr_obj].faces.push_back(11);
	arrow[arr_obj].faces.push_back(15);
	arrow[arr_obj].faces.push_back(12);

	arrow[arr_obj].faces.push_back(0);
	arrow[arr_obj].faces.push_back(7);
	arrow[arr_obj].faces.push_back(1);

	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(8);
	arrow[arr_obj].faces.push_back(4);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(8);
	arrow[arr_obj].faces.push_back(7);
	//

	arrow[arr_obj].faces.push_back(8);
	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(1);

	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(2);

	arrow[arr_obj].faces.push_back(0);
	arrow[arr_obj].faces.push_back(2);
	arrow[arr_obj].faces.push_back(9);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(14);
	arrow[arr_obj].faces.push_back(10);

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(12);
	arrow[arr_obj].faces.push_back(4);

	arrow[arr_obj].faces.push_back(3);
	arrow[arr_obj].faces.push_back(5);
	arrow[arr_obj].faces.push_back(11);
	//

	arrow[arr_obj].faces.push_back(6);
	arrow[arr_obj].faces.push_back(9);
	arrow[arr_obj].faces.push_back(11);

	arrow[arr_obj].faces.push_back(13);
	arrow[arr_obj].faces.push_back(10);
	arrow[arr_obj].faces.push_back(14);

	arrow[arr_obj].faces.push_back(4);
	arrow[arr_obj].faces.push_back(12);
	arrow[arr_obj].faces.push_back(15);

	arrow[arr_obj].faces.push_back(5);
	arrow[arr_obj].faces.push_back(10);
	arrow[arr_obj].faces.push_back(13);

	arrow[arr_obj].faces.push_back(11);
	arrow[arr_obj].faces.push_back(13);
	arrow[arr_obj].faces.push_back(15);


	glGenBuffers(1, &arrow[arr_obj].vbo);
	glBindBuffer(GL_ARRAY_BUFFER, arrow[arr_obj].vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*arrow[arr_obj].vertices.size(), &arrow[arr_obj].vertices[0], GL_STATIC_DRAW);



	glGenBuffers(1, &arrow[arr_obj].vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, arrow[arr_obj].vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*arrow[arr_obj].faces.size(), &arrow[arr_obj].faces[0], GL_STATIC_DRAW);
	arr += 1;

}

void TranslateArrowsXYZ(int arr_obj)
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
	//Bind vertex buffer for arrow.
	glBindBuffer(GL_ARRAY_BUFFER, arrow[obj].vbo);

	glVertexPointer(3, GL_FLOAT, 0, 0);
	glEnableClientState(GL_VERTEX_ARRAY);
	//bind indices buffer for arrow
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, arrow[obj].vio);

	//translate arrow.
	glTranslated(arrow[obj].pos[0], arrow[obj].pos[1], arrow[obj].pos[2]);
	//rotate arrow
	glRotatef(arrow[obj].rot[0], arrow[obj].rot[1], arrow[obj].rot[2], arrow[obj].rot[3]);
	//color arrow
	glColor3ub(arrow[obj].rgb[0], arrow[obj].rgb[1], arrow[obj].rgb[2]);
	//draw call for arrow
	glDrawElements(GL_TRIANGLES , arrow[obj].faces.size(), GL_UNSIGNED_INT, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void EFRender::Init() {

	glEnable(GL_DEPTH_TEST);

	/* create 5 objects test
	for (int i = 0; i < 5; i++) {
		Create->CreateCube(i, 2.0f, 2.0f, 2.0f);
		mesh[i].pos[0] = 3.0f * i;


	}*/

	/* create 500 objects test*/
	for (int i = 0; i < 500; i++) {
		Create->CreateCube(i, 2.0f, 2.0f, 2.0f);
		mesh[i].pos[0] = 3.0f * i;


	}

	/* create 5000 objects test
	for (int i = 0; i < 2500; i++) {
		Create->CreateCube(i, 2.0f, 2.0f, 2.0f);
		mesh[i].pos[0] = 3.0f * i;


	}
	*/

	
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

void viewportDirChange() {
	if (GetKey[T]) {
		Camera.RotatedX = -90.0f;
		Camera.RotatedY = 0.0f;
		Camera.RotatedZ = 0.0f;
		Camera.SetPos(0.0f, 5.0f, 0.0f);
	}
	if (GetKey[L]) {

		Camera.RotatedX = 0.0f;
		Camera.RotatedY = -90.0f;
		Camera.RotatedZ = 0.0f;
		Camera.SetPos(-5.0f, 0.0f, 0.0f);
	}
	if (GetKey[R]) {
		Camera.RotatedX = 0.0f;
		Camera.RotatedY = 90.0f;
		Camera.RotatedZ = 0.0f;
		Camera.SetPos(5.0f, 0.0f, 0.0f);
	}
	if (GetKey[B]) {
		Camera.RotatedX = 90.0f;
		Camera.RotatedY = 0.0f;
		Camera.RotatedZ = 0.0f;
		Camera.SetPos(0.0f, -5.0f, 0.0f);
	}
	if (GetKey[F]) {
		Camera.RotatedX = 0.0f;
		Camera.RotatedY = 0.0f;
		Camera.RotatedZ = 0.0f;
		Camera.SetPos(0.0f, 0.0f, 5.0f);
	}
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

void EFRender::SetUpViewport(int winWidth, int winHeight) {
	//Basic OpenGL Viewport stuff

	glViewport(0, 0, (GLsizei)winWidth, (GLsizei)winHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(52.0f, float(winWidth) / float(winHeight), 1.0f, 1000.0f);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	glLoadIdentity();

	gluLookAt(-0.5, 1.0, 7.0, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);
}

void EFRender::Render(int renderWidth,int renderHeight) {
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
	viewportDirChange();
	if (GetKey[P]) {
		init_quad = true;
	}
	if (GetKey[L]) {
		init_quad = false;
	}

	
	this->SetUpViewport(renderWidth, renderHeight);
	//Initialize Camera Render
	Camera.Render();
	camY = Camera.RotatedY;

	//Draw XYZ and Grid to the scene

	DisplayGrid();
	DrawXYZ();
	if(selection == true){
		//Render The XYZ Arrows 
		for (int a=0;a<arr;a++)
			RenderArrows(a);
	}

	//Render Every other mesh
	for (int i = 0; i < objects; i++)
		RenderMesh(i);

}

void EFRender::RenderMesh(int obj){

	for(int i =0;i<mesh[obj].quad_count;i++){
		glPushMatrix();

		//Bind buffer to vertices object
		glBindBuffer(GL_ARRAY_BUFFER, mesh[obj].m_quad[i].vbo);
		glVertexPointer(3, GL_FLOAT, 0, 0);
		glEnableClientState(GL_VERTEX_ARRAY);
		//Bind buffer to indices object
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh[obj].m_quad[i].vio);

		//If statement for making face only color.
		if(init_quad == true )
			glColor3ub(mesh[obj].m_quad[i].rgba[0], mesh[obj].m_quad[i].rgba[1], mesh[obj].m_quad[i].rgba[2]);
		//If statement for mesh only color.
		if (init_quad == false) {
			if (v_solid == true || v_wireframe == true || v_textured == false) {
					glColor3ub(mesh[obj].rgba[0], mesh[obj].rgba[1], mesh[obj].rgba[2]);
			
			}
			//set color to white if textures enabled so they look right.
			if (v_textured == true)
				glColor3ub(255, 255, 255);
		}
	
		if(mesh[obj].selected == true)
				glColor3ub(220, 20, 60);

		if (quad_uni_sel == true)
		{
			if (uni_sel == i)					
				glColor3ub(220, 20, 60);
		}
		//Scale mesh
		glScalef(mesh[obj].scale[0], mesh[obj].scale[1], mesh[obj].scale[2]);
		//Translate mesh
		glTranslated(mesh[obj].pos[0], mesh[obj].pos[1], mesh[obj].pos[2]);
		//Bind Texture object.
		glBindBuffer(GL_ARRAY_BUFFER,mesh[obj].m_quad[i].tex[0].vto);
		glTexCoordPointer(2, GL_FLOAT, 0, 0);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		//Bind texture to ID
		glBindTexture(GL_TEXTURE_2D, mesh[obj].m_quad[i].tex[0].TexID);
		//Draw call for drawing mesh.
		glDrawElements(GL_QUADS, mesh[obj].m_quad[i].q_indices.size(), GL_UNSIGNED_INT, 0);
		//Disable CLient states after meshes have been drawn.
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		glPopMatrix();
	}
}
