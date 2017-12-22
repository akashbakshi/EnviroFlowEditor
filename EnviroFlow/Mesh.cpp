#include "Mesh.h"

AppLog mLog;
MAP_HEADER header;


bool QuadColorCheck(Mesh m,GLubyte r, GLubyte g, GLubyte b)
{
	bool exists = false;
	for (int i = 0; i <m.num_quads; i++)
	{
		if (m.q[i].getColor('r') == r && m.q[i].getColor('g') == g && m.q[i].getColor('b') == b)
			exists = true;
		else
			exists = false;
	}
	return exists;
}


void GenerateQuadColors(Mesh m,int quad)
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
	m.q[quad].setColor(r, g, b, 0);
}



void GenerateMeshColors(Mesh m,int mesh)
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

	m.rgba[0] = r;
	m.rgba[1] = g;
	m.rgba[2] = b;

	//mLog.writeLog("Generating Mesh " + std::to_string(mesh) + " Color");
	//mLog.writeLog("[" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + "]");
}



Mesh CreateMesh(GLfloat sx, GLfloat sy, GLfloat sz,int type)
{
	Mesh tmpMesh;
	switch (type) {
	case CUBE: {
		tmpMesh.num_quads = 6;
		tmpMesh.q = new Quad[tmpMesh.num_quads];

		//mLog = AppLog("log.txt", true);
		//mLog.writeLog("\nQuad 1");
		tmpMesh.q[0] = Quad(CreateVertex(sx,-sy,sz), CreateVertex(sx, sy, sz), CreateVertex(sx, sy, -sz), CreateVertex(sx, -sy, -sz));
		tmpMesh.q[0].setPos(0.0f, 0.0f,0.0f );
		//mLog.writeLog("\nQuad 2");
		tmpMesh.q[1] = Quad(CreateVertex(sx, -sy, -sz), CreateVertex(-sx,-sy, -sz), CreateVertex(-sx, -sy,sz), CreateVertex(sx, -sy, sz));
		tmpMesh.q[1].setPos(0.0f, 0.0f, 0.0f);
		//mLog.writeLog("\nQuad 3");
		tmpMesh.q[2] = Quad(CreateVertex(sx, -sy, sz), CreateVertex(sx, sy, sz), CreateVertex(-sx, sy, sz), CreateVertex(-sx, -sy, sz));
		tmpMesh.q[2].setPos(0.0f, 0.0f, 0.0f);
		//mLog.writeLog("\nQuad 4");
		tmpMesh.q[3] = Quad(CreateVertex(-sx, -sy, sz), CreateVertex(-sx, -sy, -sz), CreateVertex(-sx, sy, -sz), CreateVertex(-sx, sy, sz));
		tmpMesh.q[3].setPos(0.0f, 0.0f, 0.0f);
		//mLog.writeLog("\nQuad 5");
		tmpMesh.q[4] = Quad(CreateVertex(-sx, sy, sz), CreateVertex(sx, sy, sz), CreateVertex(sx, sy, -sz), CreateVertex(-sx, sy, -sz));
		tmpMesh.q[4].setPos(0.0f, 0.0f, 0.0f);
		//mLog.writeLog("\nQuad 6");
		tmpMesh.q[5] = Quad(CreateVertex(-sx, sy, -sz), CreateVertex(-sx, -sy, -sz), CreateVertex(sx, -sy, -sz), CreateVertex(sx, sy, -sz));
		tmpMesh.q[5].setPos(0.0f, 0.0f, 0.0f);

		for (int i = 0; i < tmpMesh.num_quads; i++) {
			GenerateQuadColors(i);
			//mLog.writeLog("Creating Quad " + std::to_string(i + 1) + " Buffer");
			tmpMesh.q[i] = CreateBuffers();
		}
		tmpMesh.vbo = CreateVertexBuffers(tmpMesh);
		tmpMesh.vio = CreateIndexBuffers(tmpMesh);
		header.numMesh += 1;
		header.numQuads += tmpMesh.num_quads;
		tmpMesh.quad_mode = true;
		tmpMesh.mesh_mode = false;
		GenerateMeshColors(header.numMesh);
		//mLog.writeLog("Mesh Type: CUBE");
	}break;

	}

}



GLuint CreateVertexBuffers(Mesh m) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.vertices.size(), &m.vertices[0], GL_STATIC_DRAW);
	return vbo;
}

GLuint CreateIndexBuffers(Mesh m) {
	GLuint vio;
	glGenBuffers(1, &vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*m.indices.size(), &m.indices[0], GL_STATIC_DRAW); 
	return vio;
}


GLubyte getColor(char section,Mesh m)
{
	GLubyte val;
	if (section == 'r' || section == 'R')
		val = m.rgba[0];
	else if (section == 'g' || section == 'G')
		val = m.rgba[1];
	else if (section == 'b' || section == 'B')
		val = m.rgba[2];
	else if (section == 'a' || section == 'A')
		val = m.rgba[3];

	return val;
}

