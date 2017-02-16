#pragma once
#include<iostream>
#include <fstream>
#include <time.h>

class AppLog
{
public:
	AppLog();
	AppLog(std::string path,bool append);
	~AppLog();
	void setDateAndTimestamp(std::string s_time, std::string d_stamp);
	void writeLog(std::string content);
private:
	std::string filepath;
	std::string timestamp;
	std::string datestamp;
};

