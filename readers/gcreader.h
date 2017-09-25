#ifndef GCREADER_H
#define GCREADER_H

#include <iostream>
#include <vector>
#include <string>
#include "../base/fileoperate.h"
using namespace std;
using namespace YF;

#define GC_KEY_COMPANY  "COMPANY"
#define GC_KEY_PRODUCT  "PRODUCT"
#define GC_KEY_PROCODE  "PROCODE"
#define GC_KEY_MATERIAL "MATERIAL"
#define GC_KEY_METHOD   "METHOD"

class GCReader
{
public:
    string company;
    string product;
    string procode;
    string mat_cast;
    string method_cast;
    vector<string> gys;
public:
    GCReader();
	bool read(string filepath);
	bool write(string filepath);
};

#endif // GCREADER_H
