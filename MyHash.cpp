#include "MyHash.h"


//The constructor inititalizes an empty hash table
template<class T, size_t N>
Myhash<T, N>::Myhash() {

	this->numberOfElements = 0;
	this->hashArray = new LinkList<T>[this->hashTableSize];

}


//This method finds and returns average of all buckets
template<class T, size_t N>
double Myhash<T, N>::averageNonEmptyBucketSize() {

	int totalNonEmptyBuckets = 0;
	
	for (int i = 0; i < this->hashTableSize; i++) {
		if (this->hashArray[i].getSize() != 0) {
			totalNonEmptyBuckets++;
		}
	}

	if (totalNonEmptyBuckets == 0) {
		return 0;
	}
	return (double)this->numberOfElements / (double)totalNonEmptyBuckets;

}


//This method returns the max size of bucket currently in table
template<class T, size_t N>
int Myhash<T, N>::largestBucketSize() {

	int max = 0;

	for (int i = 0; i < this->hashTableSize; i++) {
		if (this->hashArray[i].getSize() > max) {
			max = this->hashArray[i].getSize();
		}
	}

	return max;
}

//This method returns the current number of elements in the table
template<class T, size_t N>
int Myhash<T, N>::size() {


	return this->numberOfElements;
}

//This method returns the percentage of used buckets
template<class T, size_t N>
double Myhash<T, N>::percentOfBucketsUsed() {

	int bucketsUsed = 0;
	for (int i = 0; i < this->hashTableSize; i++) {
		if (this->hashArray[i].getSize() != 0) {
			bucketsUsed++;
		}
	}

	
	return ((double)bucketsUsed / (double)this->hashTableSize);

}


// hash function adapted from: Thomas Wang https://gist.github.com/badboy/6267743
template<class T, size_t N>
unsigned Myhash<T, N>::hash(unsigned key) {

	int c2 = 0x27d4eb2d; // a prime or an odd constant
	key = (key ^ 61) ^ (key >> 16);
	key = key + (key << 3);
	key = key ^ (key >> 4);
	key = key * c2;
	key = key ^ (key >> 15);
	return key % this->hashTableSize;
}

//This method inserts the value into the hash table using hash function
template<typename T, size_t N>
void Myhash<T, N>::insert(T val) {

	unsigned key = (unsigned)val;

	unsigned hashedIndex = this->hash(key);



	if (this->find(val)) {
		throw DuplicateError<T>(val);
	}

	this->hashArray[hashedIndex].push_back(val);

	this->numberOfElements++;

}


//This method returns true if the value passed as parameter is found
template<class T, size_t N>
bool Myhash<T, N>::find(T val) {

	unsigned key = (unsigned)val;

	unsigned hashedIndex = this->hash(key);

	return this->hashArray[hashedIndex].find(val);

}