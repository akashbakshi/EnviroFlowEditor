#include "AppWindow.h"


AppWindow *Win = NULL;
MSG msg;
int main() {
	Win->CreateClass();
	Win->CreateWindows("EnviroFlow Build UNO", 1920, 1080);
	Win->WinLoop(msg);
}