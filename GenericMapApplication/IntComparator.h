#pragma once
#include "GenericComparator.h"
class IntComparator :
	public GenericComparator<int>
{
public:
	IntComparator();
	~IntComparator();
};

