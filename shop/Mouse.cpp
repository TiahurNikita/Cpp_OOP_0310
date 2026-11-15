#include "Mouse.h"
#include <format>
#include <iostream>

unsigned int Mouse::getDPI() const {
	return dpi;
}

Mouse* Mouse::setDPI(unsigned int dpi) {
	if (dpi == 0) {
		throw std::invalid_argument("DPI cannot be equal 0");
	}
	this->dpi = dpi;
	return this;
}

std::string Mouse::toString() const {
	return std::format("Mouse: {} {} hrn, {} dpi (Connection: {})",
		getName(),
		getPrice(),
		dpi,
		getConnection()
	);
}

std::ostream& operator <<(std::ostream& out, const Mouse& obj) {
	out << obj.toString();
	return out;
}

std::ostream& operator <<(std::ostream& out, const Mouse* obj) {
	out << *obj;
	return out;
}