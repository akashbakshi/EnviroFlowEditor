#include "EFBMPLoader.h"



EFBMPLoader::EFBMPLoader()
{
}


EFBMPLoader::~EFBMPLoader()
{
}

bool EFBMPLoader::loadBMP(std::string filename)
{
	FILE **file = nullptr;
	fopen_s(file, filename.c_str(), "rb");

	if (!file)
		return false;

	if (fread(header, 1, 54, *file) != 54)
		return false;


	return true;
}
