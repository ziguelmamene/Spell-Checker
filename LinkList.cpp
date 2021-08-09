#include "LinkList.h"


//Constructor initializes an empty list
template <typename T>
LinkList<T>::LinkList() {
	head = NULL;
	tail = NULL;
	numberOfElements = 0;
}

//This method returns current size of the list
template <typename T>
int LinkList<T>::getSize() {
	return this->numberOfElements;
}

//This method adds a new node to the end of the list
template<typename T>
void LinkList<T>::push_back(T d) {

	Node<T>* newNode = new Node<T>();
	newNode->value = d;
	newNode->next = NULL;


	if (this->head == NULL) {
		this->head = newNode;
		this->tail = head;
	}
	else {

		this->tail->next = newNode;
		this->tail = this->tail->next;
	}

	numberOfElements++;
}


template<class T>
bool LinkList<T>::find(T d) {

	Node<T>* temp = this->head;

	while (temp != NULL) {

		if (d == temp->value) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}
