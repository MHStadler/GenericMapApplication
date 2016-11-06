#include "stdafx.h"
#include "IntComparator.h"

IntComparator::IntComparator() {

}

IntComparator::~IntComparator() {

}

bool GenericComparator<int>::areEqual(const int& val1, const int& val2) {
	return val1 == val2;
}

