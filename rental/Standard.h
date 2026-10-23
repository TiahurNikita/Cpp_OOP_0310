#pragma once
#include "RentalCar.h"

class Standard : public RentalCar {
private:
	std::string gear_box;
public:
	std::string getGearBox() const;
	Standard* setGearBox(std::string);
};