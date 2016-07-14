#pragma once
#include "main.h"

class EFRender
{
public:
	EFRender();
	~EFRender();

	void Init();
	void Render();

	void RenderMesh(int obj);
};

