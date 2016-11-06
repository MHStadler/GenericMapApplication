#pragma once
template <typename K, typename V>
class GenericKvPair
{
public:
	K key;
	V value;

	GenericKvPair() { }

	~GenericKvPair() { }
};
