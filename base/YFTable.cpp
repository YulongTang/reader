#include "YFTable.h"
#include <fstream>

YFTable::YFTable()
{
	m_col = 0;
	m_row = 0;
}

YFTable::~YFTable()
{
}

bool YFTable::readTable(string filePath, string tableName)
{
	m_data.clear();
	m_head.clear();
	m_name.clear();
	m_col = 0;
	m_row = 0;

	ifstream infile;
	infile.open(filePath.data());
	if (!infile.is_open())
	{
		return false;
	}

	string s;
	int status = 0;
	while (getline(infile, s))
	{
		//读取表格
		if (s.find(tableName) != string::npos)
		{
			getline(infile, s);
			if (s.find("<") != string::npos)
			{
				//读到“<”开始
				status = 1;
				//读表头
				getline(infile, s);
				string leftstr = "";
				trimHeadTailBlank(s);
				s = splitByString(s, "\t", leftstr);
				trimAllBlank(leftstr);
				while (leftstr.length()>0)
				{
					m_row++;
					m_head.push_back(leftstr);
					trimHeadTailBlank(s);
					s = splitByString(s, "\t", leftstr);
					trimAllBlank(leftstr);
				}
				trimAllBlank(s);
				if (s.length() > 0)
				{
					m_row++;
					m_head.push_back(s);
				}
			}
			while (getline(infile, s))
			{
				
				if (s.find(">") != string::npos)
				{
					//读到">"结束
					status = 2;
					break;
				}
				s = trimComments(s);

			}
			//读取完成，结束
			return true;
		}
	}

	//一直没读到表名
	return false;
}

bool YFTable::writeTable(string filePath, string tableName)
{

}