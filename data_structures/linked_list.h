#pragma once
#include <iostream>
#include <stdexcept>
#include <format>
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
	ListNode<T>* getLast() const { return last; }
	bool is_in(T data) const;

	ListNode<T>* copy() const;
	ListNode<T>* operator +(const LinkedList<T>& other) const;
	ListNode<T>* operator *(const LinkedList<T>& other) const;

	void print() const;

	void clear() {
		ListNode<T>* node = this->first;
		while (node) {
			first = first->next;
			delete node;
			node = first;
		}
		first = last = NULL;
		size = 0;
	}

	LinkedList<T>* clone() const;
	
	LinkedList() : first{ NULL }, last{ NULL }, size{ 0 } {
		//Default constructor
	}

	LinkedList(const LinkedList& other) { // Copy
		ListNode<T>* node = other.first;
		while (node) {
			this->add(node->data);
			node = node->next;
		}
	}

	LinkedList(LinkedList&& other) noexcept: 
		first{ other.first }, last{ other.last }, size{ other.size } { // Move
		other.first = other.last = NULL;
		other.size = 0;
	}

	LinkedList<T>& operator =(const LinkedList<T>& other) {
		if (this == &other) return *this;
		this->clear();
		ListNode<T>* node = other.first;
		while (node) {
			this->add(node->data);
			node = node->next;
		}
		return *this;
	}

	LinkedList<T>& operator =(LinkedList<T>&& other) noexcept {
		if (this == &other) return *this;
		this->clear();
		this->first = other.first;
		this->last = other.last;
		this->size = other.size;

		other.first = other.last =  NULL;
		other.size = 0;
		return *this;
	}

	~LinkedList() { // Destructor
		while (first) {
			last = first;
			first = first->next;
			delete last;
		}
	}
	//Реалізувати структуру даних Стек з дотриманням "правила шести"
};



//#include "linked_list.cpp"

template<typename T>
LinkedList<T>* LinkedList<T>::clone() const {
	/*
	Q1
	 *list1
		*first1 --> [p|d|n]<-->[p|d|n]...[ ] <-- last1
	clone			   |		  |		  |
		*first2 --> [p|d|n]<-->[p|d|n]...[ ] <-- last2
	*/
	LinkedList<T>* res = new LinkedList<T>;
	ListNode<T>* node = this->first;
	while (node) {
		res->add(node->data);
		node = node->next;
	}
	return res;
}

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
			throw std::range_error(
				std::format("LinkedList<T>::insertBefore: Max list index {} but got {}", size - 1, index)
			);
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
		throw std::range_error(
			std::format("LinkedList<T>::remove: Unable to remove element. Max list index {} but got {}", size - 1, index)
		);
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