#ifndef TEST_READERS_H
#define TEST_READERS_H
#include "../readers/gcreader.h"
#include "../readers/gyreader.h"
#include "../readers/zpreader.h"
#include "../readers/tlzpreader.h"

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
			cout<<"Passed: gcReader.write()\n";
		}
	}

	void test_gyReader()
	{
		GYReader gy;
		string filepath = "tests\\Demo\\工艺1\\工艺1.gy";
		bool b = gy.read(filepath);
		if (b)
		{
			cout << "Passed: gyReader.read()\n";
		}

		bool c = gy.write(".\\工艺-test.gy");
		if (c)
		{
			cout << "Passed: gyReader.write()\n";
		}

	}

	void test_zpReader()
	{
		ZPReader zp;
		string path = "tests\\Demo\\工艺1\\充型01\\assembly.zp";
		bool v = zp.read(path);
		if(v)
		{
			cout << "Passed: zpReader.read()\n";
		}

		bool c = zp.write(".\\assembly-test.zp");
		if (c)
		{
			cout << "Passed: zpReader.write()\n";
		}

	}

	void test_tlzpReader()
	{
		TLZPReader tlzp;
		string path = "tests\\Demo\\工艺1\\充型01\\coating.tlzp";
		bool v = tlzp.read(path);
		if (v)
		{
			cout << "Passed: tlzpReader.read()\n";
		}

		bool c = tlzp.write(".\\coating-test.tlzp");
		if (c)
		{
			cout << "Passed: tlzpReader.write()\n";
		}

	}


}

#endif