#ifndef MYHASH_H
#define MYHASH_H

#include "LinkList.h"
#include "LinkList.cpp"
#include "DuplicateError.h"


template <class T, size_t N>
class Myhash {
private:
	size_t hashTableSize = N;
	LinkList<T>* hashArray;
	int numberOfElements;

public:

	Myhash();
	double averageNonEmptyBucketSize();
	int largestBucketSize();
	int size();
	double percentOfBucketsUsed();
	void insert(T);
	bool find(T);

	unsigned hash(unsigned key);
};

#endif
