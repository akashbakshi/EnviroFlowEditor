#include "WinMain.h"


using namespace std;

WinMain::WinMain()
{
}


WinMain::~WinMain()
{
}

void WinMain::CreateClass()
{
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	wc.hInstance = hInst;
	wc.lpszClassName = "EF";
	wc.lpfnWndProc = WndProc;
	wc.hCursor = SetCursor(IDC_ARROW);
	wc.hIcon = 

}

void WinMain::CreateWindows(string name, int width, int height)
{
}

void WinMain::WinLoop()
{
}

