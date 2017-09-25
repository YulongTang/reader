#ifndef TEST_READERS_H
#define TEST_READERS_H
#include "../readers/gcreader.h"
#include "../readers/gyreader.h"

namespace TEST
{
	void test_gcReader()
	{
		GCReader gc;
		string filepath = "tests\\Demo\\Demo.gc";
		bool b = gc.read(filepath);
		b = gc.write(filepath);
		if (b)
		{
			cout<<"Passed: gcReader.write()";
		}
	}

	void test_gyReader()
	{
		GYReader gy;
		string filepath = "tests\\Demo\\工艺1\\工艺1.gy";
		bool b = gy.read(filepath);
		if (b)
		{
			cout << "Passed: GYReader.read()";
		}

		bool c = gy.write(".\\工艺0.gy");
		if (c)
		{
			cout << "Passed: GYReader.write()";
		}

	}
}

#endif