#pragma once
#include "Standard.h"

class Suv : public Standard {
private:
	double clearance;
public:
	double getClearance() const;
	Suv* setClearance(double);
	std::string toString() const override;
};