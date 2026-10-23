#pragma once
#include "Standard.h"

class Sedan : public Standard {
private:
	int trunk_vol;
public:
	int getTrunkVol() const;
	Sedan* setTrunkVol(int);
	std::string toString() const override;
};