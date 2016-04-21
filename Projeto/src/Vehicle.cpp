#include "Vehicle.h"

Vehicle::Vehicle(string mat, int nPlaces) {
	this->mat = mat;
	this->nPlaces = nPlaces;
	this->occupated = false;
	this->placesOccupied = 0;
}

string Vehicle::getMat() const{
	return mat;
}

int Vehicle::getNPlaces() const{
	return nPlaces;
}

bool Vehicle::getOccupated() const{
	return occupated;
}

int Vehicle::getPlacesOccupied() const{
	return placesOccupied;
}

void Vehicle::show(){
	cout << mat << "  |  " << nPlaces << endl;
}
