#include "Suv.h"
#include <format>

double Suv::getClearance() const {
	return clearance;
}

Suv* Suv::setClearance(double clearance) {
	this->clearance = clearance;
	return this;
}

std::string Suv::toString() const {
	return std::format("Class: SUV\nName: {}\nPrice: {} thousand hrn per day\nGearbox: {}\nClearance: {} cm",
		getName(),
		getPrice(),
		getGearBox(),
		clearance);
}