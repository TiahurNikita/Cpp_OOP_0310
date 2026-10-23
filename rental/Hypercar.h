#pragma once
#include "Special.h"

class Hypercar : public Special {
private:
	double acceleration;
public:
	double getAcceleration() const;
	Hypercar* setAcceleration(double);
	std::string toString() const override;
};