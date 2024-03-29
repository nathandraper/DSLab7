#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <fstream>
#include <string>
#include "OutOfListRange.h"
#include "EmptyList.h"

using namespace std;

string HEADER_FILENAME = "part_list_art.txt";

template <typename T>
struct Node {
	T* data = nullptr;
	Node<T>* next = nullptr;
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

	T* getItem(int num) {
		Node<T>* curr = this->list;
		Node<T>* prev = this->list;

		// in case the very first node contains desired data, we need to reset the class list head
		if (this->list && this->list->data->getNumber() == num) {
			this->length--;

			this->list = curr->next;
			T* result = curr->data;
			delete curr;
			return result;
		}

		while (curr) {
			if (curr->data->getNumber() == num) {
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

	bool isInList(int num) {
		Node<T>* prev = this->list;
		Node<T>* curr = this->list;
		while (curr) {
			if (curr->data->getNumber() == num) {
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
			this->next = curr->next;
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

	void display() {
		string line;
		Node<T>* curr = this->list;
		ifstream header(HEADER_FILENAME);

		getline(header, line);
		while (!header.eof()) {
			cout << line << endl; 
			getline(header, line);
		}

		while (curr){
			curr->data->display();
			curr = curr->next;
		}
	}
};

#endif
