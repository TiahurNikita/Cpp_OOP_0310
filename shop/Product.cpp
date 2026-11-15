#include <string>
#include "Product.h"
#include <iostream>

std::string Product::getName() const {
	return name;
}

Product* Product::setName(std::string name) {
	this->name = name;
	return this;
}

double Product::getPrice() const {
	return price;
}

Product* Product::setPrice(double price) {
	this->price = price;
	return this;
}

std::ostream& operator << (std::ostream& out, const Product *p) {
	out << p->toString();
	return out;
}