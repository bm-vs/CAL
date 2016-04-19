#include "Vehicle.h"

Vehicle::Vehicle(string mat, int nPlaces) {
	this->mat = mat;
	this->nPlaces = nPlaces;
	this->placesOccupied = 0;
}

string Vehicle::getMat() const{
	return mat;
}

int Vehicle::getNPlaces() const{
	return nPlaces;
}

int Vehicle::getPlacesOccupied() const{
	return placesOccupied;
}
