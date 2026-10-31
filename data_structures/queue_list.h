#pragma once
#include <iostream>
#include "list_node.h"

template<typename T>
class QueueList {
private:
	ListNode<T>* first = NULL;
	ListNode<T>* last = NULL;
	size_t size = 0;
public:
	void add(T data);
	T pop();
	size_t getSize() const { return size; }
	void clear();
	T peek();

	void print() const;
};

template<typename T>
void QueueList<T>::add(T data) {
	if (last) {
		last->next = new ListNode<T>{ data, last, NULL };
		last = last->next;
	}
	else {
		first = last = new ListNode<T>{ data, NULL, NULL };
	}
	size += 1;
}

template<typename T>
T QueueList<T>::pop() {
	if (size == 0) {
		//error
		return T(0);
	}
	else {
		ListNode<T>* node = first;
		T data = node->data;
		first = first->next;
		if (first) {
			first->prev = NULL;
		}
		delete node;
		size -= 1;
		if (size == 0) last = NULL;
		return data;
	}
}

template<typename T>
void QueueList<T>::clear() {
	while (first) {
		ListNode<T>* t = first->next;
		delete first;
		first = t;
	}
	last = NULL;
	size = 0;
}

template<typename T>
T QueueList<T>::peek() {
	if (size == 0) {
		//error
		return T(0);
	}
	return first->data;
}

template<typename T>
void QueueList<T>::print() const {
	ListNode<T>* node = first;
	if (node == NULL) {
		std::cout << "Empty queue";
	}
	while (node) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;
}