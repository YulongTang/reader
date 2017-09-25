#include "gyreader.h"
#include<fstream>
GYReader::GYReader()
{

}

bool GYReader::read(string filepath)
{
	ZBs.clear();

	ifstream infile;
	infile.open(filepath.data());
	if (!infile.is_open())
	{
		return false;
	}

	string s;
	while (getline(infile, s))
	{
		//¶ÁÈ¡ZB
		if (s.find("*ZB") != string::npos)
		{
			while (getline(infile, s))
			{
				if (s.find("*ZB") != string::npos)
				{
					break;
				}
				s = trimComments(s);
				if (trimHeadTailBlank(s).size() > 0)
				{
					ZBs.push_back(s);
				}
				
			}
		}

		//¶ÁÈ¡INFO
		if (s.find("*INFO") != string::npos)
		{
			while (getline(infile, s))
			{
				string strL, strR;
				if (s.find("*INFO") != string::npos)
				{
					break;
				}
				s = trimComments(s);
				strR = splitByString(s, "=", strL);
				strL = trimHeadTailBlank(strL);
				strR = trimHeadTailBlank(strR);
				if (strL.compare(GY_KEY_PID) == 0)
				{
					PID = strR;
				}
				if (strL.compare(GY_KEY_DESINGER) == 0)
				{
					designer = strR;
				}
				if (strL.compare(GY_KEY_ANALYZER) == 0)
				{
					analyzer = strR;
				}
				if (strL.compare(GY_KEY_TIME) == 0)
				{
					time = strR;
				}
				
			}
		}
		//¶ÁÈ¡DESCRIPTION
		if (s.find("*DESCRIPTION") != string::npos)
		{
			while (getline(infile, s))
			{
				if (s.find("*DESCRIPTION") != string::npos)
				{
					if (description.size()>0)
					{
						description = description.substr(0, description.size()-2);
					}
					break;
				}
				description += s;         
				description += '\n';    //²¹ÉÏ»»ÐÐ·û
			}
		}


	}

	infile.close();
	return true;
}

bool GYReader::write(string filepath)
{
	ofstream outfile;
	outfile.open(filepath);
	if (!outfile.is_open())
	{
		return false;
	}

	//Ð´ZB
	outfile << "*ZB" << endl;
	for (int i = 0; i < ZBs.size(); i++)
	{
		outfile << ZBs[i].data() << endl;
	}
	outfile << "*ZB" << endl << endl;

	//Ð´INFO
	outfile << "*INFO" << endl;
	outfile << GY_KEY_PID << " = " << PID.data() << endl;
	outfile << GY_KEY_DESINGER << " = " << designer.data() << endl;
	outfile << GY_KEY_ANALYZER << " = " << analyzer.data() << endl;
	outfile << GY_KEY_TIME << " = " << time.data() << endl;
	outfile << "*INFO" << endl << endl;

	//Ð´DESCRIPTION
	outfile << "*DESCRIPTION" << endl;
	outfile << description.data() << endl;
	outfile << "*DESCRIPTION" << endl;

	outfile.close();
	return true;
}