#include "gcreader.h"
#include <fstream>

GCReader::GCReader(){

}

bool GCReader::read(string filepath)
{
	gys.clear();

	ifstream infile;
	infile.open(filepath.data());
	if (!infile.is_open())
	{
		return false;
	}

	string s;
	while(getline(infile,s))
	{
		//¶ÁÈ¡INFO
		if (s.find("*INFO") != string::npos)
		{
			while(getline(infile,s))
			{
				string strL, strR;
				if (s.find("*INFO") != string::npos)
				{
					break;
				}
				s = trimComments(s);
				strR = splitByString(s,"=",strL);
				strL = trimHeadTailBlank(strL);
				strR = trimHeadTailBlank(strR);
				if (strL.compare(GC_KEY_COMPANY) == 0)
				{
					company = strR;
				}
				if (strL.compare(GC_KEY_PRODUCT) == 0)
				{
					product = strR;
				}
				if (strL.compare(GC_KEY_PROCODE) == 0)
				{
					procode = strR;
				}
				if (strL.compare(GC_KEY_MATERIAL) == 0)
				{
					mat_cast = strR;
				}
				if (strL.compare(GC_KEY_METHOD) == 0)
				{
					method_cast = strR;
				}
			} 
		}

		//¶ÁÈ¡GY
		if (s.find("*GY") != string::npos)
		{
			while(getline(infile,s)) 
			{
				if (s.find("*GY") != string::npos)
				{
					break;
				}
				if (trimHeadTailBlank(s).size()>0)
				{
					gys.push_back(s);
				}
			} 
		}
	}

	infile.close();
	return true;
}

bool GCReader::write(string filepath)
{
	ofstream outfile;
	outfile.open(filepath);
	if (!outfile.is_open())
	{
		return false;
	}
	
	//Ð´INFO
	outfile<<"*INFO"<<endl;
	outfile<<GC_KEY_COMPANY<<" = "<<company.data()<<endl;
	outfile<<GC_KEY_PRODUCT<<" = "<<product.data()<<endl;
	outfile<<GC_KEY_PROCODE<<" = "<<procode.data()<<endl;
	outfile<<GC_KEY_MATERIAL<<" = "<<mat_cast.data()<<endl;
	outfile<<GC_KEY_METHOD<<" = "<<method_cast.data()<<endl;
	outfile<<"*INFO"<<endl<<endl;
	//Ð´GY
	outfile<<"*GY"<<endl;
	for (int i=0; i<gys.size(); i++)
	{
		outfile<<gys[i].data()<<endl;
	}
	outfile<<"*GY"<<endl;

	outfile.close();
	return true;
}
