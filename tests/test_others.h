#pragma once
#include "../base/YFTable.h"

namespace TEST
{
	void test_table()
	{
		YFTable table;
		string filepath = "tests\\Demo\\π§“’1\\≥‰–Õ01\\run.cfg";
		string outfile = "table.txt";
		table.readTable(filepath, "**VALUE");
		table.writeTable(outfile, "*TABLE");
	}
}