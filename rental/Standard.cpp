#include "Standard.h"

std::string Standard::getGearBox() const {
	return gear_box;
}

Standard* Standard::setGearBox(std::string gear_box) {
	this->gear_box = gear_box;
	return this;
}