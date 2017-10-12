#ifndef ZPREADER_H
#define ZPREADER_H

#include <iostream>
#include <vector>
#include <string>
#include "../base/fileoperate.h"
using namespace std;
using namespace YF;


class ZPReader
{
public:
	vector<string> geometry;
	vector<string> type;
	vector<string> material;

public:
	ZPReader();
	bool read(string filepath);
	bool write(string filepath);
};

#endif // ZPREADER_H


