#include "AppWindow.h"
#include <time.h>
#include "AppLog.h"
AppWindow *Win = NULL;
AppLog logs;
MSG msg;
int main() {
	logs = AppLog("log.txt", false);
	srand(time(NULL));
	Win->CreateClass();
	Win->CreateWindows("EnviroFlow Build UNO", 1920, 1080);
	Win->WinLoop(msg);
}