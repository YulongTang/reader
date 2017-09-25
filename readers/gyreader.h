#ifndef GYREADER_H
#define GYREADER_H

#include <iostream>
#include <vector>
#include <string>
#include "../base/fileoperate.h"
using namespace std;
using namespace YF;

#define GY_KEY_PID                "PID"
#define GY_KEY_DESINGER   "DESINGER"
#define GY_KEY_ANALYZER  "ANALYZER"
#define GY_KEY_TIME            "TIME"

class GYReader
{
public:
	vector<string> ZBs;
	string PID;
	string designer;
	string analyzer;
	string time;
	string description;
public:
	GYReader();
	bool read(string filepath);
	bool write(string filepath);
};

#endif