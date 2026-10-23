#include <iostream>
#include "autos_basic.h"

void autos_basic() {

	RentalCar* stock[4];

	stock[0] = (new Sedan())
		->setTrunkVol(493)
		->setGearBox("Automatic")
		->setName("Toyota Camry")
		->setPrice(15.2);

	stock[1] = (new Suv())
		->setClearance(21.5)
		->setGearBox("Automatic")
		->setName("Toyota RAV4")
		->setPrice(20.6);
	

	stock[2] = (new Hypercar())
		->setAcceleration(2.4)
		->setDeposit(10000)
		->setName("Bugatti Chiron")
		->setPrice(100.5);
	
	stock[3] = (new Minivan())
		->setSeats(8)
		->setDeposit(2560.5)
		->setName("Kia Carnival")
		->setPrice(73.0);

	std::cout << "----------------------------" << std::endl;
	for (auto product : stock) {
		std::cout << product->toString() << std::endl;
		std::cout << "----------------------------" << std::endl;
	}
}

/*
							ќренда автомоб≥л≥в
Sedan				SUV					Hypercar		 Minivan
- назва				- назва				- назва			 - назва
- ц≥на				- ц≥на				- ц≥на			 - ц≥на
- коробка передач	- коробка передач	- депозит		 - депозит
- об'Їм багажника	- кл≥ренс			- розг≥н		 - к≥льк≥сть м≥сць


							   RentalCar
							   - name (назва)
							   - price (ц≥на)
						   /				\
			       Standard(стандартн≥)	    Special (спец≥альн≥)
				   - gear_box				- deposit (депозит)
				   (коробка передач)			/    	   \
				   /		   \			   /		    \
			Sedan		       SUV		     Hypercar		Minivan
		    -trunk_vol		   -clearance	 -acceleration	-seats
			(об'Їм багажника)  (кл≥ренс)	 (розг≥н)		(м≥сц€)
*/