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
	m_name = tableName;
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
				lineToCells(s, m_head);
				m_col = m_head.size();
				//读表体
				vector<string> tmp;
				m_data.clear();
				getline(infile, s);
				while (s.find(">") == string::npos && s.size()>0)
				{
					lineToCells(s, tmp);
					m_data.push_back(tmp);
					getline(infile, s);
				}
				m_row = m_data.size();
				//读到">"结束
				if (s.find(">") != string::npos)
				{
					status = 2;
					infile.close();
					return true;
				}
			}
		}
	}

	//一直没读到表名
	infile.close();
	return false;
}

bool YFTable::writeTable(string filePath, string tableName)
{
	ofstream outfile;
	outfile.open(filePath, std::ofstream::out | std::ofstream::app);
	if (!outfile.is_open())
	{
		return false;
	}
	//写表名
	outfile << tableName << endl;
	outfile << "<" << endl;
	//写表头
	for (int i = 0; i < m_col - 1; i++)
		outfile << m_head[i] << "\t";
	outfile << m_head[m_col-1] << endl;
	//写数据
	for (int i = 0; i < m_row; i++)
	{
		int icol = m_data[i].size();
		for (int j = 0; j < icol - 1; j++)
			outfile << m_data[i][j] << "\t";
		outfile << m_data[i][icol-1] << endl;
	}
	//写结束符
	outfile << ">" << endl;
	outfile << tableName << endl;

	return true;
}

void YFTable::lineToCells(string line, vector<string> &cells)
{
	cells.clear();
	string leftstr = "";
	line = trimHeadTailBlank(line);
	line = splitByString(line, "\t", leftstr);
	leftstr = trimAllBlank(leftstr);
	while (leftstr.length()>0)
	{
		cells.push_back(leftstr);
		line = trimHeadTailBlank(line);
		line = splitByString(line, "\t", leftstr);
		leftstr = trimAllBlank(leftstr);
	}
	line = trimAllBlank(line);
	if (line.length() > 0)
	{
		cells.push_back(line);
	}
}