#pragma once
#include <string>

class RentalCar {
private:
	std::string name;
	double price;
public:
	std::string getName() const;
	RentalCar* setName(std::string);
	double getPrice() const;
	RentalCar* setPrice(double);

	virtual std::string toString() const = 0;
};