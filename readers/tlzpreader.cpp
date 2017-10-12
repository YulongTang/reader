#include "tlzpreader.h"
#include <fstream>

TLZPReader::TLZPReader()
{
}

bool TLZPReader::read(string filepath)
{
	geometry1.clear();
	geometry2.clear();
	coating.clear();
	thick.clear();
	bool v = readText(filepath, geometry1,geometry2,coating,thick);
	if (!v)
	{
		return false;
	}
	return true;
}

bool TLZPReader::write(string filepath)
{
	ofstream outfile;
	outfile.open(filepath);
	if (!outfile.is_open())
	{
		return false;
	}
	//写表头
	outfile << "GEOMETRY1\tGEOMETRY2\tCOATING\tTHICK-MM"<<endl;
	//写数据
	for (int i = 0; i < geometry1.size(); i++)
	{
		outfile <<geometry1[i].data()<<'\t'<< geometry2[i].data() 
			<<'\t'<< coating[i].data()<<'\t'<<thick[i]<< endl;
	}
	outfile.close();
	return true;
}
