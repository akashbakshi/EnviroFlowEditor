#include "main.h"

class EFBMPLoader
{
public:
	EFBMPLoader();
	~EFBMPLoader();

	bool loadBMP(std::string filename);
private:
	unsigned char header[54];
	unsigned int dataOffeset;
	unsigned int width, height;
	unsigned int bmpImgSize;

	unsigned char *data;

};

