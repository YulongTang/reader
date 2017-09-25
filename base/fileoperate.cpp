#include "fileoperate.h"

//ȥ���ַ��������пհף���ո�' '���Ʊ�'\t'��
//�����µ��ַ���
string YF::trimAllBlank(const string str)
{
	string newstr = "";
	for(unsigned i=0; i<str.length(); i++)
	{
		if(' ' == str[i] || '\t' == str[i]) continue;
		newstr += str[i];
	}
	return newstr;
}

//ȥ��β���Ŀհף���ո�' '���Ʊ�'\t'��
//�����µ��ַ���
string YF::trimTailBlank(const string str)
{
	int tailindex = str.size()-1;
	while(tailindex >= 0)
	{
		if (str[tailindex] == ' ' || str[tailindex] == '\t')
		{
			tailindex--;
		}
		else break;
	}
	return str.substr(0,tailindex+1);
}

//ȥ���ײ��հף���ո�' '���Ʊ�'\t'��
//�����µ��ַ���
string YF::trimHeadBlank(const string str)
{
	unsigned index = 0;
	while (index < str.size())
	{
		if (str[index] == ' ' || str[index] == '\t')
		{
			index++;
		}
		else
		{
			break;
		}
	}
	return str.substr(index,str.size()-index);
}

string YF::trimHeadTailBlank(const string str)
{
	string newstr = trimHeadBlank(str);
	return trimTailBlank(newstr);
}

//ȥ�����ۣ���һ����"//"֮������֣��Լ��ַ���ĩβ�Ŀհ�
//�����µ��ַ���
string YF::trimComments(const string str)
{
	string comstr = "//";
	string newstr;
	int comindex = str.find(comstr);
	if (comindex >=0)
	{
		newstr = str.substr(0,comindex);
	}
	else
	{
		newstr = str;
	}
	return trimTailBlank(newstr);
}

string YF::splitByString(const string source, const string split, string & left)
{
	if (split.size() == 0)
	{
		return source;
	}
	int index = source.find(split);
	if (index == string::npos)
	{
		return source;
	}
	left = source.substr(0,index);
	return source.substr(index+split.size(),source.size()-split.size()-index);
}

//��ȡ����׺���ļ���
//[in] ȫ·�����硰D:\\test\\test.txt����D:/test/test.txt��
//[return] ����׺���ļ������硰test.txt��
string YF::getFileName(string filepath)
{
	int index_slash = -1;
	for (int i=filepath.size()-1; i>=0; i--)
	{
		if (filepath[i] == '\\' || filepath[i] == '/')
		{
			index_slash = i;
			break;
		}
	}
	if (index_slash<0)
	{
		return filepath;
	}
	else if (index_slash>=filepath.size()-1)
	{
		return "";
	}
	else
	{
		return filepath.substr(index_slash+1,filepath.size()-index_slash-1);
	}
}

//��ȡ������׺���ļ���
//[in] ȫ·�����硰D:\\test\\test.txt����D:/test/test.txt��
//[return] ������׺���ļ������硰test��
string YF::getFileNameWithoutExt(string filepath)
{
	int index_ext = 0;
	int index_slash = -1;
	string newstr;
	for (int i=filepath.size()-1; i>=0; i--)
	{
		if (filepath[i] == '\\' || filepath[i] == '/')
		{
			index_slash = i;
			break;
		}
	}
	if (index_slash<0)
	{
		newstr = filepath;
	}
	else if (index_slash >= filepath.size()-1)
	{
		return "";
	}
	else
	{
		newstr = filepath.substr(index_slash+1,filepath.size()-index_slash-1);
	}

	index_ext = newstr.rfind(".");
	if (index_ext == string::npos)
	{
		return newstr;
	}
	else
	{
		return newstr.substr(0,index_ext);
	}
}

//��ȡ�ļ���
//[in] ȫ·�����硰D:\\test\\test.txt����D:/test/test.txt��
//[return] ��б�ܵ��ļ��С��硰D:/test/��
string YF::getFileFolder(string filepath)
{
	int index_slash = -1;
	for (int i=filepath.size()-1; i>=0; i--)
	{
		if (filepath[i] == '\\' || filepath[i] == '/')
		{
			index_slash = i;
			break;
		}
	}
	if (index_slash<=0)
	{
		return "";
	}
	else
	{
		return filepath.substr(0,index_slash+1);
	}
}