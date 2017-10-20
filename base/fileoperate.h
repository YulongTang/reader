#ifndef FILEOPERATE_H
#define FILEOPERATE_H

#include <iostream>
#include <vector>
using namespace std;


bool readText(string filepath,std::vector<string>&a,std::vector<string>&b,std::vector<string>&c);
bool readText(string filepath,std::vector<string>&a,std::vector<string>&b,std::vector<string>&c,std::vector<float>&d);

namespace YF {

	//去掉字符串中所有空白，如空格' '，制表'\t'。
	//返回新的字符串
	string trimAllBlank(const string str);
	
	//去掉尾部的空白，如空格' '，制表'\t'。
	//返回新的字符串
	string trimTailBlank(const string str);
	
	//去掉首部空白，如空格' '，制表'\t'。
	//返回新的字符串
	string trimHeadBlank(const string str);

	//去掉首尾空白，返回新的字符串
	string trimHeadTailBlank(const string str);
	
	//去掉评论，即一行中"//"之后的文字，以及字符串末尾的空白
	//返回新的字符串
	string trimComments(const string str);

	//用一个标识字符串剪切源字符串，如果存在多个标识字符串，则从第一个标识处剪切（从左至右）
	//[in] source 源字符串
	//[in] split  标识字符串
	//[in] left   剪切后字符串左半部分
	//[return]    剪切后字符串右半部分
	string splitByString(const string source, const string split, string & left);

	//获取带后缀的文件名
	//[in] 全路径。如“D:\\test\\test.txt”或“D:/test/test.txt”
	//[return] 带后缀的文件名。如“test.txt”
	string getFileName(string filepath);

	//获取不带后缀的文件名
	//[in] 全路径。如“D:\\test\\test.txt”或“D:/test/test.txt”
	//[return] 不带后缀的文件名。如“test”
	string getFileNameWithoutExt(string filepath);

	//获取文件夹
	//[in] 全路径。如“D:\\test\\test.txt”或“D:/test/test.txt”
	//[return] 带斜杠的文件夹。如“D:/test/”
	string getFileFolder(string filepath);
}

#endif // FILEOPERATE_H
