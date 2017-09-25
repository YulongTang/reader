#include "../base/fileoperate.h"
using namespace YF;

namespace TEST
{
	void printFailInfo(string str, int itest)
	{
		cout<<"Failed: "<<str.c_str()<<" at test "<<itest<<endl;
	}
	void printPassInfo(string str)
	{
		cout<<"Passed: "<<str.c_str()<<endl;
	}

	void test_trimAllBlank()
	{
		string str1 = "My test   .";
		string str2 = "";
		string str3 = " ";
		string newstr = YF::trimAllBlank(str1);
		string test_name = "test trimAllBlank()";
		if (newstr.compare("Mytest.") != 0)
		{
			printFailInfo(test_name, 1);
			return;
		}
		newstr = YF::trimAllBlank(str2);
		if (newstr.compare("") != 0)
		{
			printFailInfo(test_name,2);
			return;
		}
		newstr = YF::trimAllBlank(str3);
		if (newstr.compare("") != 0)
		{
			printFailInfo(test_name, 3);
			return;
		}

		printPassInfo(test_name);
	}

	void test_trimTailBlank()
	{
		string test_name = "test trimTailBlank";
		string str = "test tail blank.   ";
		string trimed = YF::trimTailBlank(str);
		string cmpstr = "test tail blank.";
		if (trimed.compare(cmpstr) != 0)
		{
			printFailInfo(test_name,1);
			return;
		}
		str = "test tail blank \t.		";
		trimed = YF::trimTailBlank(str);
		cmpstr = "test tail blank \t.";
		if (trimed.compare(cmpstr) != 0)
		{
			printFailInfo(test_name, 2);
			return;
		}
		str = "    ";
		trimed = YF::trimTailBlank(str);
		cmpstr = "";
		if (trimed.compare(cmpstr))
		{
			printFailInfo(test_name, 3);
			return;
		}
		printPassInfo(test_name);
	}

	void test_trimHeadBlank()
	{
		string name = "test trimeHeadBlank()";
		string str = "  Head";
		string cmpstr = "Head";
		string trimed = trimHeadBlank(str);
		if (trimed.compare(cmpstr) != 0)
		{
			printFailInfo(name,1);
			return;
		}
		str = "		";
		cmpstr = "";
		trimed = trimHeadBlank(str);
		if (trimed.compare(cmpstr) != 0)
		{
			printFailInfo(name, 2);
			return;
		}

		printPassInfo(name);
	}

	void test_trimComment()
	{
		string name = "test trimComment()";
		string str = "We think in generalities, but we live in details. //Alfred N. Whitehead";
		string trimed = trimComments(str);
		string cmpstr = "We think in generalities, but we live in details.";
		if (trimed.compare(cmpstr) != 0)
		{
			printFailInfo(name, 1);
			return;
		}
		str = "//ddd";
		trimed = trimComments(str);
		cmpstr = "";
		if (trimed.compare(cmpstr)!=0)
		{
			printFailInfo(name, 2);
			return;
		}
		printPassInfo(name);
	}

	void test_getFileNameWithoutExt()
	{
		string name = "test getFileNameWithoutExt()";
		string str = "D:\\test\\test.txt";
		string cmp = "test";
		string resultstr = getFileNameWithoutExt(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,1);
			return;
		}
		str = "D:/test/test.txt";
		cmp = "test";
		resultstr = getFileNameWithoutExt(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,2);
			return;
		}
		str = "D:\\test/test.txt";
		cmp = "test";
		resultstr = getFileNameWithoutExt(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,3);
			return;
		}
		str = "D:\\test\\../test.txt";
		cmp = "test";
		resultstr = getFileNameWithoutExt(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,4);
			return;
		}
		str = "D:\\test\\../";
		cmp = "";
		resultstr = getFileNameWithoutExt(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,5);
			return;
		}
		str = "/test";
		cmp = "test";
		resultstr = getFileNameWithoutExt(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,6);
			return;
		}

		printPassInfo(name);
	}

	void test_getFileName()
	{
		string name = "test getFileName()";
		string str = "D:\\test\\test.txt";
		string cmp = "test.txt";
		string resultstr = getFileName(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,1);
			return;
		}
		str = "D:/test/test.txt";
		cmp = "test.txt";
		resultstr = getFileName(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,2);
			return;
		}
		str = "D:\\test\\../test.txt";
		cmp = "test.txt";
		resultstr = getFileName(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,3);
			return;
		}
		str = "D:\\test\\../";
		cmp = "";
		resultstr = getFileName(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,4);
			return;
		}
		printPassInfo(name);
	}

	void test_getFileFolder()
	{
		string name = "test getFileFolder()";
		string str = "D:\\test\\test.txt";
		string cmp = "D:\\test\\";
		string resultstr = getFileFolder(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,1);
			return;
		}
		str = "D:/test/test.txt";
		cmp = "D:/test/";
		resultstr = getFileFolder(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,2);
			return;
		}
		str = "D:\\test/test.txt";
		cmp = "D:\\test/";
		resultstr = getFileFolder(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,3);
			return;
		}
		str = "D:\\test\\../test.txt";
		cmp = "D:\\test\\../";
		resultstr = getFileFolder(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,4);
			return;
		}
		str = "D:\\test\\../";
		cmp = "D:\\test\\../";
		resultstr = getFileFolder(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,5);
			return;
		}
		str = "test";
		cmp = "";
		resultstr = getFileFolder(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,6);
			return;
		}
		str = "/test";
		cmp = "";
		resultstr = getFileFolder(str);
		if (resultstr.compare(cmp) != 0)
		{
			printFailInfo(name,7);
			return;
		}

		printPassInfo(name);
	}

	void test_splitByString()
	{
		string name = "test splitByString()";
		string str = "456=123";
		string cmp1 = "456";
		string cmp2 = "123";
		string rslt1;
		string rslt2 = splitByString(str,"=",rslt1);
		if (rslt1.compare(cmp1)!=0 || rslt2.compare(cmp2)!=0)
		{
			printFailInfo(name,1);
			return;
		}
		str = "=123";
		cmp1 = "";
		cmp2 = "123";
		rslt2 = splitByString(str,"=",rslt1);
		if (rslt1.compare(cmp1)!=0 || rslt2.compare(cmp2)!=0)
		{
			printFailInfo(name,1);
			return;
		}
		str = "123";
		cmp1 = "";
		cmp2 = "123";
		rslt2 = splitByString(str,"=",rslt1);
		if (rslt1.compare(cmp1)!=0 || rslt2.compare(cmp2)!=0)
		{
			printFailInfo(name,1);
			return;
		}

		printPassInfo(name);
	}
}