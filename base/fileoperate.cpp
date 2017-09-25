#include "fileoperate.h"

//去掉字符串中所有空白，如空格' '，制表'\t'。
//返回新的字符串
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

//去掉尾部的空白，如空格' '，制表'\t'。
//返回新的字符串
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

//去掉首部空白，如空格' '，制表'\t'。
//返回新的字符串
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

//去掉评论，即一行中"//"之后的文字，以及字符串末尾的空白
//返回新的字符串
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

//获取带后缀的文件名
//[in] 全路径。如“D:\\test\\test.txt”或“D:/test/test.txt”
//[return] 带后缀的文件名。如“test.txt”
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

//获取不带后缀的文件名
//[in] 全路径。如“D:\\test\\test.txt”或“D:/test/test.txt”
//[return] 不带后缀的文件名。如“test”
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

//获取文件夹
//[in] 全路径。如“D:\\test\\test.txt”或“D:/test/test.txt”
//[return] 带斜杠的文件夹。如“D:/test/”
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