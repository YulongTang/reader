#pragma once
#include <vector>
#include <string>
#include "./fileoperate.h"
using namespace YF;
using namespace std;

class YFTable
{
public:
	string m_name;
	std::vector<string> m_head;
	std::vector<std::vector<string>> m_data;
	int m_col;
	int m_row;
public:
	YFTable();
	~YFTable();
	
	/**Read a table from a file
	 *[in] filePath, the full path of a file to be read
	 *[in] tableName, the name (or keyword) of a table to be read in the file, such as "**INLETS" in run.cfg.
	 *[return] true or false.
	**/
	bool readTable(string filePath, string tableName);

	/**Write a table to a file, this method will always write in "append" mod.
	*[in] filePath, the full path of a file to be written
	*[in] tableName, the name (or keyword) of a table to be written, such as "**INLETS" in run.cfg.
	*[return] true or false.
	**/
	bool writeTable(string filePath, string tableName);
};