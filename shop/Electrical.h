#pragma once
#include "Product.h"

class Electrical : public Product { // ":" - спадкування
private:
	double power;
public:
	double getPower() const;
	void setPower(double);
};