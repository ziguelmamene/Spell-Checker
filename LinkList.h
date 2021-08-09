#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

/*
Node is template based class used to store a node in the link list
*/
template <typename T>
class Node {

public:

	T value;
	Node<T>* next;

};


/*
The LinkList class implements the link list data structure.
*/
template<typename T>
class LinkList {
private:

	Node<T>* head;
	Node<T>* tail;
	int numberOfElements;
public:


	//Constructor initializes an empty list
	LinkList();


	int getSize();

	//This method adds a new node to the end of the list
	void push_back(T d);


	bool find(T d);


};




#endif