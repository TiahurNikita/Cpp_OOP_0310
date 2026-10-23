#include "Minivan.h"
#include <format>

int Minivan::getSeats() const {
	return seats;
}

Minivan* Minivan::setSeats(int seats) {
	this->seats = seats;
	return this;
}

std::string Minivan::toString() const {
	return std::format("Class: Minivan\nName: {}\nPrice: {} thousand hrn per day\nDeposit: {} hrn\nSeats: {}",
		getName(),
		getPrice(),
		getDeposit(),
		seats);
}