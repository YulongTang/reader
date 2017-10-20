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
		//��ȡ���
		if (s.find(tableName) != string::npos)
		{
			getline(infile, s);
			if (s.find("<") != string::npos)
			{
				//������<����ʼ
				status = 1;
				//����ͷ
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
					//����">"����
					status = 2;
					break;
				}
				s = trimComments(s);

			}
			//��ȡ��ɣ�����
			return true;
		}
	}

	//һֱû��������
	return false;
}

bool YFTable::writeTable(string filePath, string tableName)
{

}