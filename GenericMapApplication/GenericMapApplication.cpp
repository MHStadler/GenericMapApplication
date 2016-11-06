// GenericMapApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GenericMap.h"
#include "IntComparator.h"

int main() {
	GenericMap<int, int> *intIntMap = new GenericMap<int, int>(IntComparator());

	intIntMap->put(4, 5);
	intIntMap->put(6, 7);

	intIntMap->print(0);
	intIntMap->remove(4);
	intIntMap->print(0);
	intIntMap->get(4);

	intIntMap->put(8, 9);
	intIntMap->print(2);
	intIntMap->remove(5);
	intIntMap->print(2);
	intIntMap->put(8, 8);
	intIntMap->print(2);


	intIntMap->print(0);
	intIntMap->print(1);
	intIntMap->print(2);

	intIntMap->remove(5);
	intIntMap->print(0);
	intIntMap->print(1);
	intIntMap->print(2);

	system("pause");
    return 0;
}

