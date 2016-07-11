#include <glew.h>
#include <math.h>


#define PI 3.1415265359
#define PIdiv180 3.1415265359/180.0


/////////////////////////////////
//Note: All angles in degrees  //
/////////////////////////////////

struct SF3dVector  //Float 3d-vect, normally used
{
	GLdouble x, y, z;
};
struct SF2dVector
{
	GLdouble x, y;
};

class Cam
{
private:
	SF3dVector Position;
	SF3dVector ViewDir;		/*Not used for rendering the camera, but for "moveforwards"
							So it is not necessary to "actualize" it always. It is only
							actualized when ViewDirChanged is true and moveforwards is called*/
	bool ViewDirChanged;
	GLfloat RotatedX, RotatedY, RotatedZ;	
	void GetViewDir ( void );
public:
	Cam();				//inits the values (Position: (0|0|0) Target: (0|0|-1) )
	void Render ( void );	//executes some glRotates and a glTranslate command
							//Note: You should call glLoadIdentity before using Render
	void Move ( SF3dVector Direction );
	void RAngleX ( GLfloat Angle );
	void RAngleY ( GLfloat Angle );
	void RAngleZ ( GLfloat Angle );
	void RAngleXYZ ( SF3dVector Angles );
	void MoveForwards ( GLfloat Distance );
	void StrafeRight ( GLfloat Distance );
};


SF3dVector F3dVector(GLdouble x, GLdouble y, GLdouble z);
SF3dVector AddF3dVectors ( SF3dVector * u, SF3dVector * v);
void AddF3dVectorToVector ( SF3dVector * Dst, SF3dVector * V2);
