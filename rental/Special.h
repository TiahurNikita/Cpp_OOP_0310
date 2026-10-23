#pragma once
#include "RentalCar.h"

class Special : public RentalCar {
private:
	double deposit;
public:
	double getDeposit() const;
	Special* setDeposit(double);
};