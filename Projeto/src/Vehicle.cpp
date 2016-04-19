#include "Vehicle.h"

Vehicle::Vehicle(string mat, int nPlaces) {
	this->mat = mat;
	this->nPlaces = nPlaces;
}

string Vehicle::getMat() const{
	return mat;
}

int Vehicle::getNPlaces() const{
	return nPlaces;
}
