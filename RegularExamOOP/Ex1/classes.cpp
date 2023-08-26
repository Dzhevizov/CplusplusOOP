#include "classes.h"


void Vehicle::printInfo(ostream& output)
{
	output << numberPlate << ", " << color << " ";

	if (getSize() == "S")
		output << "with 2 wheels.";
	else if (getSize() == "M")
		output << "medium car.";
	else if (getSize() == "L")
		output << "bigger car.";
	else if (getSize() == "XL")
		output << "truck.";
	else if (getSize() == "XXL")
		output << "big truck.";
}