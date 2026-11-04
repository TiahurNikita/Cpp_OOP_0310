#pragma once
#include "linked_list.h"

template <typename T>
class Stack {
private:
	LinkedList<T>* stack = NULL;
public:
	void push(T data) {
		stack->add(data);
	}

	T pop() {
		if (!isEmpty()) {
			return stack->remove(getLength()-1);
		}
		else {
			throw std::length_error("Stack<T>::pop(): Pop requested for empty stack");
		}
	}

	T top() {
		if (!isEmpty()) {
			return stack->getLast()->data;
		}
		else {
			throw std::length_error("Stack<T>::top(): Top requested for empty stack");
		}
	}

	size_t getLength() {
		return stack->getSize();
	}

	bool isEmpty() {
		return getLength() == 0;
	}

	Stack() {
		stack = new LinkedList<T>();
	}

	Stack(const Stack<T>& other) {
		this->stack = new LinkedList<T>();
		if (other.stack) {
			ListNode<T>* node = other.stack->getFirst();
			while (node) {
				this->stack->add(node->data);
				node = node->next;
			}
		}
	}

	Stack(Stack<T>&& other) {
		this->stack = other.stack;
		other.stack = NULL;
	}

	~Stack() {
		if (stack) delete stack;
	}
};