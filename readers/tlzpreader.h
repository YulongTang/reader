#ifndef TLZPREADER_H
#define TLZPREADER_H

#include <iostream>
#include <vector>
#include <string>
#include "../base/fileoperate.h"
using namespace std;
using namespace YF;


class TLZPReader
{
public:
	vector<string> geometry1;
	vector<string> geometry2;
	vector<string> coating;
	vector<float> thick;

public:
	TLZPReader();
	bool read(string filepath);
	bool write(string filepath);
};

#endif // TLZPREADER_H


