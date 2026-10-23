#pragma once
#include "Special.h"

class Minivan : public Special {
private:
	int seats;
public:
	int getSeats() const;
	Minivan* setSeats(int);
	std::string toString() const override;
};