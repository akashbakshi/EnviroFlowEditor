#include "Mesh.h"

AppLog mLog;
MAP_HEADER header;


bool Mesh::QuadColorCheck(GLubyte r, GLubyte g, GLubyte b)
{
	bool exists = false;
	for (int i = 0; i <num_quads; i++)
	{
		if (q[i].getColor('r') == r &&q[i].getColor('g') == g && q[i].getColor('b') == b)
			exists = true;
		else
			exists = false;
	}
	return exists;
}


void Mesh::GenerateQuadColors(int quad)
{
	GLubyte r, g, b;

	//mLog.writeLog("Generating Quad #"+std::to_string(quad+1)+" Color");
	r = rand() * 256 / RAND_MAX;
	g = rand() * 256 / RAND_MAX;
	b = rand() * 256 / RAND_MAX;
	while (QuadColorCheck(r, g, b))
	{
		r = rand() * 256 / RAND_MAX;
		g = rand() * 256 / RAND_MAX;
		b = rand() * 256 / RAND_MAX;
	}
	//mLog.writeLog("[" + std::to_string(r)+", "+std::to_string(g)+", "+std::to_string(b)+"]");
	q[quad].setColor(r, g, b, 0);
}



void Mesh::GenerateMeshColors(int mesh)
{
	GLubyte r, g, b;

	r = rand() * 256 / RAND_MAX;
	g = rand() * 256 / RAND_MAX;
	b = rand() * 256 / RAND_MAX;
	while (MeshColorCheck(r, g, b))
	{
		r = rand() * 256 / RAND_MAX;
		g = rand() * 256 / RAND_MAX;
		b = rand() * 256 / RAND_MAX;
	}

	rgba[0] = r;
	rgba[1] = g;
	rgba[2] = b;

	//mLog.writeLog("Generating Mesh " + std::to_string(mesh) + " Color");
	//mLog.writeLog("[" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + "]");
}


Mesh::Mesh()
{
}

Mesh::Mesh(GLfloat sx, GLfloat sy, GLfloat sz,int type)
{
	switch (type) {
	case CUBE: {
		num_quads = 6;
		q = new Quad[num_quads];

		//mLog = AppLog("log.txt", true);
		//mLog.writeLog("\nQuad 1");
		q[0] = Quad(Vertex(sx,-sy,sz),Vertex(sx, sy, sz),  Vertex(sx, sy, -sz),  Vertex(sx, -sy, -sz));
		q[0].setPos(0.0f, 0.0f,0.0f );
		//mLog.writeLog("\nQuad 2");
		q[1] = Quad(Vertex(sx, -sy, -sz), Vertex(-sx,-sy, -sz), Vertex(-sx, -sy,sz), Vertex(sx, -sy, sz));
		q[1].setPos(0.0f, 0.0f, 0.0f);
		//mLog.writeLog("\nQuad 3");
		q[2] = Quad(Vertex(sx, -sy, sz), Vertex(sx, sy, sz), Vertex(-sx, sy, sz), Vertex(-sx, -sy, sz));
		q[2].setPos(0.0f, 0.0f, 0.0f);
		//mLog.writeLog("\nQuad 4");
		q[3] = Quad(Vertex(-sx, -sy, sz), Vertex(-sx, -sy, -sz), Vertex(-sx, sy, -sz), Vertex(-sx, sy, sz));
		q[3].setPos(0.0f, 0.0f, 0.0f);
		//mLog.writeLog("\nQuad 5");
		q[4] = Quad(Vertex(-sx, sy, sz), Vertex(sx, sy, sz), Vertex(sx, sy, -sz), Vertex(-sx, sy, -sz));
		q[4].setPos(0.0f, 0.0f, 0.0f);
		//mLog.writeLog("\nQuad 6");
		q[5] = Quad(Vertex(-sx, sy, -sz), Vertex(-sx, -sy, -sz), Vertex(sx, -sy, -sz), Vertex(sx, sy, -sz));
		q[5].setPos(0.0f, 0.0f, 0.0f);

		for (int i = 0; i < num_quads; i++) {
			GenerateQuadColors(i);
			//mLog.writeLog("Creating Quad " + std::to_string(i + 1) + " Buffer");
			q[i].CreateBuffers();
		}

		header.numMesh += 1;
		header.numQuads += num_quads;
		quad_mode = true;
		mesh_mode = false;
		GenerateMeshColors(header.numMesh);
		//mLog.writeLog("Mesh Type: CUBE");
	}break;

	}

}


Mesh::~Mesh()
{
}

void Mesh::CreateBuffers() {
	glGenBuffers(1, &vbo); 
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertices.size(), &vertices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indices.size(), &indices[0], GL_STATIC_DRAW); 

}

void Mesh::setScale(GLfloat x, GLfloat y, GLfloat z)
{

}

GLubyte Mesh::getColor(char section)
{
	GLubyte val;
	if (section == 'r' || section == 'R')
		val = rgba[0];
	else if (section == 'g' || section == 'G')
		val = rgba[1];
	else if (section == 'b' || section == 'B')
		val = rgba[2];
	else if (section == 'a' || section == 'A')
		val = rgba[3];

	return val;
}

