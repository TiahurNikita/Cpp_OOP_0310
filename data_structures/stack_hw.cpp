#include "stack_hw.h"
#include "stack.h"
#include <string>
#include <format>
#include <iostream>

void stack_hw() {
	Stack<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.pop();
	std::cout << "s1: " << std::endl;
	s1.print();

	Stack<int> s2 = s1;
	std::cout << "s2: " << std::endl; 
	s2.print();

	Stack<int> s3;
	s3.push(0);
	s1.push(40);
	s3 = s1;
	s1.push(50);
	std::cout << "s3: " << std::endl;
	s3.print();

	Stack<int> s4 = std::move(s2);
	std::cout << "s4: " << std::endl;
	s4.print();

	Stack<int> s5;
	s5 = std::move(s3);
	std::cout << "s5: " << std::endl;
	s5.print();
}

void stack_hw_ð() {
	//({x-y-z} * [x + 2y] - (z + 4x)) - No errors
	//([x-y-z} * [x + 2y) - {z + 4x)] - Open-Close
	//x * y - z} - No open
	//(x * {y - z} - No close

	std::string task;
	std::cout << "Enter string (ending with \";\"): " << std::endl;
	std::getline(std::cin, task);
	std::cout << std::endl;
	Stack<char> brackets;
	Stack<size_t> op_i;
	size_t error_pos=0;
	std::string error = "";
	for (size_t i = 0; i < task.length(); i++) {
		char c = task[i];
		if (c == ';') break;
		if (c == '(' || c == '[' || c == '{') {
			brackets.push(c);
			op_i.push(i);
		}
		if (c == ')' || c == ']' || c == '}') {
			if (brackets.isEmpty()) {
				error = std::format("No open-bracket:\n\tclose-bracket \'{}\' at pos = {}", c, i + 1);
				error_pos = i;
				break;
			}
			char last = brackets.pop();
			size_t pos = op_i.pop();
			if (!((last == '(' && c == ')') || (last == '[' && c == ']') || (last == '{' && c == '}'))) {
				error = std::format(
					"Bracket conflict:\n\topen-bracket \'{}\'in pos = {}\n\tclose-bracket \'{}\' at pos = {}",
					last, pos + 1, c, i + 1);
				error_pos = i;
				break;
			}
			
			
		}
	}
	if (error == "" && !brackets.isEmpty()) {
		char c = brackets.pop();
		size_t pos = op_i.pop();
		error_pos = pos;
		error = std::format("No close-bracket:\n\topen-bracket \'{}\' at pos = {}", 
			c, pos+1);
	}
	if (error != "") {
		std::cout << "Error: " << error << std::endl;
		std::cout << "String till error: ";
		for (size_t i = 0; i <= error_pos; i++) {
			std::cout << task[i];
		}
		std::cout << std::endl;
	}
	else std::cout << "No errors" << std::endl;
}

void stack_hw_e() {
	Stack<int> s;
	std::cout << "--- pop() empty stack error ---" << std::endl;
	try {
		s.pop();
	}
	catch (const std::length_error& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Generic exception" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "--- pop() error ---" << std::endl;
	try {
		s.push(1);
		s.push(2);
		s.push(3);
		std::cout << s.pop() << std::endl;
		std::cout << s.pop() << std::endl;
		std::cout << s.pop() << std::endl;
		std::cout << s.pop() << std::endl;
	}
	catch (const std::length_error& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Generic exception" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "--- top() error ---" << std::endl;
	try {
		s.top();
	}
	catch (const std::length_error& ex) {
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Generic exception" << std::endl;
	}
}