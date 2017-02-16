#include "AppLog.h"

using namespace std;

AppLog::AppLog()
{
}

AppLog::AppLog(std::string path,bool append) {
	filepath = path;
	ofstream file;
	char date[10]; 
	char time[10];

	_strdate_s(date);
	_strtime_s(time);

	if(append == false){
		file.open(filepath);
		file <<"Log Session Started "<< date <<" "<<time<< endl;
		file.close();
	}
	else {
		file.open(filepath,ios::app);
		file << "Log Opened: " << date << " " << time << endl;
		file.close();
	}
}

AppLog::~AppLog()
{
}

void AppLog::writeLog(std::string content) {
	
	ofstream file;
	file.open(filepath, ios::app);
	file << content.c_str() << endl;
	file.close();
}

void AppLog::setDateAndTimestamp(std::string s_time, std::string d_stamp)
{
}

