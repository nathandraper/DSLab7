#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "OutOfListRange.h"
#include "EmptyList.h"

template <typename T>
struct Node {
	T* data;
	Node<T>* next;
};

// holds the floor layout in a singly-linked linked list structure
// each node contains a pointer to a room object and a pointer to the next node
template <typename T>
class LinkedList {
private:
	Node<T>* list;
	Node<T>* next;
	int length;

public:
	LinkedList() {
		this->list = nullptr;
		this->next = nullptr;
		this->length = 0;
	}

	LinkedList(T* data) {
		this->list = new Node{data, nullptr};
		this->next = this->list;
		this->length = 0;
	}

	~LinkedList() {
		Node<T>* curr = this->list;
		Node<T>* temp = nullptr;

		while (curr){
			temp = curr->next;
			delete curr->data;
			delete curr;
			curr = temp;
		}
	}

	T* getItem(T* find) {
		Node<T>* curr = this->list;
		Node<T>* prev = this->list;

		// in case the very first node contains desired data, we need to reset the class list head
		if (this->list && *this->list->data == *find) {
			this->length--;

			this->list = curr->next;
			T* result = curr->data;
			delete curr;
			return result;
		}

		while (curr) {
			if (*curr->data == *find) {
				this->length--;

				prev->next = curr->next;
				T* result = curr->data;
				delete curr;
				return result;
			}
			prev = curr;
			curr = curr->next;
			
		}
		return nullptr;
	}

	bool isInList(T* find) {
		Node<T>* prev = this->list;
		Node<T>* curr = this->list;
		while (curr) {
			if (*curr->data == *find) {
				return true;
			}
			prev = curr;
			curr = curr->next;
		}
		return false;
	}

	bool isEmpty() {
		return !this->list;
	}

	int size() {
		return this->length;
	}

	void addItem(T* data) {
		this->length++;
		Node<T>* curr = this->list;
		Node<T>* newNode = new Node<T>{data, nullptr};

		if (!curr) {
			this->list = newNode;
			this->next = list;
			return;
		}

		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newNode;
	}

	T* seeNext() {
		if (this->isEmpty()) {
			throw EmptyList();
		}

		if (!this->next) {
			return nullptr;
		}

		T* result = this->next->data;
		this->next = this->next->next;
		
		return result;
	}

	// assuming the list is zero-based
	T* seeAt(int i){
		Node<T>* curr = this->list;

		if (i >= this->length) {
			throw OutOfListRange();
		}

		while (i > 0) {
			curr = curr->next;
			this->next = curr;
			i--;
		}
		return curr->data;
	}

	void reset() {
		this->next = this->list;
	}

	// operator overloads
	bool operator > (int num) {
		return this->length > num;
	}

	bool operator >= (int num) {
		return this->length >= num;
	}

	bool operator < (int num) {
		return this->length < num;
	}

	bool operator <= (int num) {
		return this->length <= num;
	}

	bool operator == (int num) {
		return this->length == num;
	}

};

#endif
