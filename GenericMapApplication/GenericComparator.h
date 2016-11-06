#pragma once
template <typename T>
class GenericComparator
{
public:
	GenericComparator() {

	}
	virtual ~GenericComparator() {

	}

	bool operator() (const T& val1, const T& val2) { 
		return areEqual(val1, val2);
	}
private:
	virtual bool areEqual(const T& val1, const T& val2) {
		return val1 == val2;
	};
};

