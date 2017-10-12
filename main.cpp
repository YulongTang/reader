#include <iostream>
#include "tests/test_fileoperate.h"
#include "tests/test_readers.h"

using namespace std;
using namespace TEST;

int main()
{
    cout << "Test fileoperate:" << endl;
    test_trimAllBlank();
	test_trimTailBlank();
	test_trimHeadBlank();
	test_trimComment();
	test_getFileNameWithoutExt();
	test_getFileName();
	test_getFileFolder();
	test_splitByString();

	test_gcReader();
	test_gyReader();
	test_zpReader();
	test_tlzpReader();

    return 0;
}
