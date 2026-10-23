#include "Hypercar.h"
#include <format>

double Hypercar::getAcceleration() const {
	return acceleration;
}

Hypercar* Hypercar::setAcceleration(double acceleration) {
	this->acceleration = acceleration;
	return this;
}

std::string Hypercar::toString() const {
	return std::format("Class: Hypercar\nName: {}\nPrice: {} thousand hrn per day\nDeposit: {} hrn\nAcceleration: {} s",
		getName(),
		getPrice(),
		getDeposit(),
		acceleration);
}