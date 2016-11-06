#pragma once
#include "GenericKvPair.h"
#include "GenericComparator.h"
#include <iostream>
#include <exception>

template <typename K, typename V>
class GenericMap {

private:
	static const int sizeInterval = 10;

	int index;
	int currMaxSize;

	GenericKvPair<K, V> *map;
	GenericComparator<K> comparator;

public:
	GenericMap() {
		//Init with a default GenericComparator if none is supplied
		init(sizeInterval, GenericComparator<K>());
	}

	GenericMap(const GenericComparator<K>& comp) {
		init(sizeInterval, comp);
	}

	~GenericMap() {
		delete[] map;
	}

	void put(const K& key, const V& value) {
		bool found = false;

		for (int i = 0; i < index; i++) {
			GenericKvPair<K, V> kvPair = map[i];

			if (comparator(key, kvPair.key)) {
				kvPair.value = value;
				found = true;
				break;
			}
		}

		if (!found) {
			//If a new entry is necessary and the array is full -> extend array with sizeInterval
			if (index == currMaxSize) {
				resizeArray(currMaxSize + sizeInterval);
			}

			GenericKvPair<K, V> kvPair = GenericKvPair<K, V>();

			kvPair.key = key;
			kvPair.value = value;

			map[index] = kvPair;
			index++;
		}
	}

	V get(const K& key) {
		for (int i = 0; i < index; i++)
		{
			GenericKvPair<K, V> kvPair = map[i];

			if (comparator(key, kvPair.key))
			{
				return kvPair.value;
			}
		}

		throw new std::exception("Error");
	}

	void remove(const K& key) {
		int targetIndex = -1;

		for (int i = 0; i < index; i++) {
			GenericKvPair<K, V> kvPair = map[i];
			if (comparator(key, kvPair.key)) {
				targetIndex = i;
				break;
			}
		}

		if (targetIndex >= 0) {
			map[targetIndex] = map[index-1];
			index--;
		}

		//If array space is no longer needed shrink it for sizeInterval -> only shrink it if there's 1.5 * sizeInterval free spaces to keep resizing to a minimum
		if (index < (currMaxSize - 1.5 * sizeInterval)) {
			resizeArray(currMaxSize - sizeInterval);
		}
	}

	void print(int index) {
		GenericKvPair<K, V> kvPair = map[index];

		std::cout << kvPair.key << kvPair.value << "\n";
	}

private:
	/* Replace current map with a new array of given size targetSize and copy over the elements from map */
	void resizeArray(int targetSize) {
		GenericKvPair<K, V>* tmp = new GenericKvPair<K, V>[targetSize];
		for (int i = 0; i < index; i++) {
			tmp[i] = map[i];
		}
		delete[] map;
		map = tmp;

		currMaxSize = targetSize;
	}

	void init(const int& size, const GenericComparator<K>& comp) {
		map = new GenericKvPair<K, V>[size];
		comparator = comp;

		index = 0;
		currMaxSize = size;
	}
};