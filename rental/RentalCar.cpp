#include "RentalCar.h"

std::string RentalCar::getName() const {
	return name;
}

RentalCar* RentalCar::setName(std::string name) {
	this->name = name;
	return this;
}

double RentalCar::getPrice() const {
	return price;
}

RentalCar* RentalCar::setPrice(double price) {
	this->price = price;
	return this;
}