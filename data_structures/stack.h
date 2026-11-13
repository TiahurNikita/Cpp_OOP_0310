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
			throw std::length_error("Stack<T>::top(): Top element requested for empty stack");
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
		this->stack = other.stack->clone();
		std::cout << "Stack copied" << std::endl;
	}

	Stack(Stack<T>&& other) noexcept {
		this->stack = other.stack;
		other.stack = NULL;
		std::cout << "Stack moved" << std::endl;
	}

	Stack<T>& operator =(const Stack<T>& other) {
		if (this == &other) return *this;
		delete this->stack;
		this->stack = other.stack->clone();
		std::cout << "Stack copied = " << std::endl;
		return *this;
	}

	Stack<T>& operator =(Stack<T>&& other) noexcept {
		if (this == &other) return *this;
		delete this->stack;
		this->stack = other.stack;
		other.stack = NULL;
		std::cout << "Stack moved = " << std::endl;
		return *this;
	}

	~Stack() {
		if (stack) delete stack;
	}
};