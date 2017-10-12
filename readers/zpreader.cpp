#include "zpreader.h"
#include <fstream>

ZPReader::ZPReader()
{
}

bool ZPReader::read(string filepath)
{
	geometry.clear();
	type.clear();
	material.clear();
	bool v = readText(filepath, geometry,type,material);
	if (!v)
	{
		return false;
	}
	return true;
}

bool ZPReader::write(string filepath)
{
	ofstream outfile;
	outfile.open(filepath);
	if (!outfile.is_open())
	{
		return false;
	}	
	//写表头
	outfile << "GEOMETRY\tTYPE\tMATERIAL" << endl;
	//写数据
	for (int i = 0; i < geometry.size(); i++)
	{
		outfile<<geometry[i].data()<<'\t'<<type[i].data()<<'\t'<<material[i].data()<<endl;
	}
	outfile.close();
	return true;
}
