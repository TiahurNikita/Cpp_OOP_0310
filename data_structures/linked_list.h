#pragma once
#include <iostream>
#include "list_node.h"

template<typename T>
class LinkedList {
private:
	ListNode<T>* first = NULL;
	ListNode<T>* last = NULL;
	size_t size = 0;
public:
	void add(T data);
	void insertBefore(T data, size_t index);
	T remove(size_t index);
	size_t getSize() const { return size; }
	ListNode<T>* getFirst() const { return first; }
	bool is_in(T data) const;

	ListNode<T>* copy() const;
	ListNode<T>* operator +(const LinkedList<T>& other) const;
	ListNode<T>* operator *(const LinkedList<T>& other) const;

	void print() const;
};



//#include "linked_list.cpp"

template<typename T>
void LinkedList<T>::add(T data) {
	if(last){
		last->next = new ListNode<T> { data, last, NULL };
		last = last->next;
	}
	else {
		first = last = new ListNode<T> { data, NULL, NULL };
	}
	size += 1;
}

template<typename T>
void LinkedList<T>::insertBefore(T data, size_t index) {
	if (index == 0) {
		if (first) {
			first = first->prev = new ListNode<T>{ data, NULL, first };
			size += 1;
		}
		else {
			add(data);
		}
	}
	else {
		if (index < size) {
			ListNode<T>* node = first;
			for (size_t i = 0; i < index-1; ++i) {
				node = node->next;
			}
			node->next = new ListNode<T>{ data, node, node->next };
			node->next->next->prev = node->next;
			size += 1;
		}
		else {
			//помилка - index out of range
		}
	}
}

template<typename T>
void LinkedList<T>::print() const {
	ListNode<T>* node = first;
	if (node == NULL) {
		std::cout << "Empty list, size = " << size << std::endl;
	}
	std::cout << size << " element(s) ";
	while (node) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;
}

template<typename T>
T LinkedList<T>::remove(size_t index) {
	if (index < size) {
		if (index == 0) {
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
		if (index == size - 1) {
			ListNode<T>* node = last;
			T data = node->data;
			last = last->prev;
			last->next = NULL;
			delete node;
			size -= 1;
			return data;
		}
		else {
			ListNode<T>* node = first;
			for (size_t i = 0; i < index; ++i) {
				node = node->next;
			}
			node->prev->next = node->next;
			node->next->prev = node->prev;
			T data = node->data;
			delete node;
			size--;
			return data;
		}
	}
	else {
		//error
		return T(0);
	}
}

template<typename T>
ListNode<T>* LinkedList<T>::copy() const {
	LinkedList<T>* newList = new LinkedList<T>();
	ListNode<T>* node = first;
	while (node) {
		newList->add(node->data);
		node = node->next;
	}
	return newList->getFirst();
}

template<typename T>
ListNode<T>* LinkedList<T>::operator +(const LinkedList<T>& other) const {
	LinkedList<T>* newList = new LinkedList<T>();
	ListNode<T>* node = this->first;
	while (node) {
		newList->add(node->data);
		node = node->next;
	}
	node = other.first;
	while (node) {
		newList->add(node->data);
		node = node->next;
	}
	return newList->getFirst();
}

template<typename T>
bool LinkedList<T>::is_in(T data) const {
	ListNode<T>* node = first;
	while (node) {
		if (node->data == data) return true;
		node = node->next;
	}
	return false;
}

template<typename T>
ListNode<T>* LinkedList<T>::operator *(const LinkedList<T>& other) const {
	LinkedList<T>* newList = new LinkedList<T>();
	ListNode<T>* node = this->first;
	while (node) {
		if(other.is_in(node->data) && !newList->is_in(node->data)) newList->add(node->data);
		node = node->next;
	}
	return newList->getFirst();
}
/*
    node
0<-[p|d|n]<->[p|d|n]->0

[p|d|n] - struct (ListNode) - комплексний об'єкт, що складається з трьох полів:
дані (d) та два покажчики (адреси) n (next) на наступний та p (prev) на попередній
new ListNode - створює новий об'єкт, розміщує його у випадковому
місці пам'яті та повертає адресу цього місця
node - змінна, що зберігає адресу об'єкта
first - окрема змінна (поле), що зберігає адресу першого об'єкта списку

first(100)        node(200)
[NULL|1|200]  [100|2|300]  [200|3|400]  [400|4|NULL]
				   /            /
				  1            2
1: node->next — поле next об'єкта за адресою node (200)
   семантика: покажчик на наступний елемент (з адресою 300)
2: node->next->prev — поле prev об'єкта за адресою node->next (300)
   семантика: покажчик на поточний елемент (node)
? чи еквівалентні тоді операції:
  node = ...
  node->next->prev = ...
  Ні:
  node = ... змінить вміст змінної node
  node->next->prev = ... змінить зміст поле prev об'єкта за адресою node->next

? чи еквівалентні тоді операції:
  node->data = 10;
  node->next->prev->data = 10;
  Так
*/