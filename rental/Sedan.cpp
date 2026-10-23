#include "Sedan.h"
#include <format>

int Sedan::getTrunkVol() const {
	return trunk_vol;
}

Sedan* Sedan::setTrunkVol(int trunk_vol) {
	this->trunk_vol = trunk_vol;
	return this;
}

std::string Sedan::toString() const {
	return std::format("Class: Sedan\nName: {}\nPrice: {} thousand hrn per day\nGearbox: {}\nTrunk Volume: {} L",
		getName(),
		getPrice(),
		getGearBox(),
		trunk_vol);
}