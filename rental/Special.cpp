#include "Special.h"

double Special::getDeposit() const {
	return deposit;
}

Special* Special::setDeposit(double deposit) {
	this->deposit = deposit;
	return this;
}