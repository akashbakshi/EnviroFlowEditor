#include "Camera.h"
#include <iostream>

using namespace std;
SF3dVector F3dVector(GLdouble x, GLdouble y, GLdouble z)
{
	SF3dVector tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return tmp;
}
SF3dVector AddF3dVectors (SF3dVector* u, SF3dVector* v)
{
	SF3dVector result;
	result.x = u->x + v->x;
	result.y = u->y + v->y;
	result.z = u->z + v->z;
	return result;
}
void AddF3dVectorToVector ( SF3dVector * Dst, SF3dVector * V2)
{
	Dst->x += V2->x;
	Dst->y += V2->y;
	Dst->z += V2->z;
}


/***************************************************************************************/

Cam::Cam()
{
	//Init with standard OGL values:
	Position = F3dVector (	0.0, 
							0.0,
							0.0);
	ViewDir = F3dVector(	0.0,
							0.0,
							-1.0);
	ViewDirChanged = false;
	//Only to be sure:
	RotatedX = RotatedY = RotatedZ = 0.0;
}

void Cam::GetViewDir( void )
{
	SF3dVector Step1, Step2;
	//Rotate around Y-axis:
	Step1.x = cos( (RotatedY + 90.0f) * PIdiv180);
	Step1.z = -sin( (RotatedY + 90.0f) * PIdiv180);
	//Rotate around X-axis:
	double cosX = cos (RotatedX * PIdiv180);
	Step2.x = Step1.x * cosX;
	Step2.z = Step1.z * cosX;
	Step2.y = sin(RotatedX * PIdiv180);
	//Rotation around Z-axis not yet implemented, so:
	ViewDir = Step2;
}
void Cam::Move (SF3dVector Direction)
{
	AddF3dVectorToVector(&Position, &Direction );
}

void Cam::RAngleY (GLfloat Angle)
{
	RotatedY += Angle;
	ViewDirChanged = true;
}

void Cam::RAngleX (GLfloat Angle)
{
	RotatedX += Angle;

	ViewDirChanged = true;

}

void Cam::Render( void )
{
	glRotatef(-RotatedX, 1.0, 0.0, 0.0);
	glRotatef(-RotatedY, 0.0, 1.0, 0.0);
	glRotatef(-RotatedZ, 0.0, 0.0, 1.0);

	//cout <<-RotatedX << " " <<-RotatedY <<" " << RotatedZ << endl;
	glTranslated(-Position.x, -Position.y, -Position.z);



}

void Cam::MoveForwards( GLfloat Distance )
{
	if (ViewDirChanged) GetViewDir();

	SF3dVector MoveVector;
	MoveVector.x = ViewDir.x * -Distance;
	MoveVector.y = ViewDir.y * -Distance;
	MoveVector.z = ViewDir.z * -Distance;
	AddF3dVectorToVector(&Position, &MoveVector );
	
}

void Cam::StrafeRight ( GLfloat Distance )
{
	if (ViewDirChanged) GetViewDir();
	SF3dVector MoveVector;
	MoveVector.z = -ViewDir.x * -Distance;
	MoveVector.y = 0.0;
	MoveVector.x = ViewDir.z * -Distance;
	AddF3dVectorToVector(&Position, &MoveVector );
}

void Cam::SetPos(GLfloat x, GLfloat y, GLfloat z)
{
	Position.x = x;
	Position.y = y;
	Position.z = z;
}
