#pragma once
#include <iostream>
#include "list_node.h"

template<typename T>
class Array {
private:
	ListNode<T>* first = NULL;
	ListNode<T>* last = NULL;
	int usedSize = 0;
	int size = 0;
	int grow = 1;

	void popNode() {
		if (!last) return;
		ListNode<T>* node = last;
		last = last->prev;
		if (last) last->next = NULL;
		else first = NULL;
		delete node;
		usedSize--;
		if (size > usedSize) size = usedSize;
	}

	ListNode<T>* getNode(int index) const{
		if (index<0 || index>=usedSize) return NULL;
		ListNode<T>* node = first;
		for (int i = 0; i < index; i++) node = node->next;
		return node;
	}

public:
	int GetSize() const { return usedSize; }
	void SetSize(int size, int grow = 1);
	int GetUpperBound() const { return size-1;}
	bool IsEmpty() const { return size == 0; }

	void FreeExtra(){
		if (usedSize > size) SetSize(size, grow);
	}
	void RemoveAll();

	T GetAt(int index) const;
	void SetAt(int index, T data);

	void Add(T data);
	void Append(const Array<T>& other);
	Array<T>& operator=(const Array<T>& other);

	ListNode<T>* GetData() const { return first; }

	void print();
	//TODO
	// InsertAt, RemoveAt, operator []
};

template<typename T>
void Array<T>::SetSize(int size, int grow) {
	if (size < 0) return;
	if (grow <= 0) this->grow = 1;
	else this->grow = grow;
	if (size > usedSize) {
		int cnt = size - usedSize;
		for (int i = 0; i < cnt; i++) {
			if (last) {
				last->next = new ListNode<T>{ T(), last, NULL };
				last = last->next;
			}
			else {
				first = last = new ListNode<T>{ T(), NULL, NULL };
			}
			usedSize++;
		} 
	}
	else {
		int cnt = usedSize - size;
		for (int i = 0; i < cnt; i++) popNode();
	}
}

template<typename T>
void Array<T>::RemoveAll() {
	while (first) {
		popNode();
	}
	usedSize = 0;
	size = 0;
}

template<typename T>
T Array<T>::GetAt(int index) const {
	if (index >= 0 && index < usedSize) {
		return getNode(index)->data;
	}
	return T();
}

template<typename T>
void Array<T>::SetAt(int index, T data) {
	if (index >= 0 && index < usedSize) {
		getNode(index)->data = data;
		if (index >= size) size = index + 1;
	}
}

template<typename T>
void Array<T>::Add(T data) {
	if (size >= usedSize) SetSize(usedSize + grow, grow);
	SetAt(size, data);
}

template<typename T>
void Array<T>::Append(const Array<T>& other) {
	int cnt = other.GetUpperBound() + 1;
	for (int i = 0; i < cnt; i++) {
		this->Add(other.GetAt(i));
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this == &other) return *this;
	this->RemoveAll();
	this->grow = other.grow;
	this->Append(other);
	return *this;
}

template<typename T>
void Array<T>::print() {
	if (usedSize == 0) {
		std::cout << "Array is empty" << std::endl;
		return;
	}
	ListNode<T>* node = first;
	for (int i = 0; i < usedSize; ++i) {
		if(node->data!=T()) std::cout << node->data << " ";
		else std::cout << "_ ";
		node = node->next;
	}
	std::cout << std::endl;
}