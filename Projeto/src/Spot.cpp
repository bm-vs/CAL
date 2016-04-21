#include "Spot.h"

Spot::Spot() {
}

Spot::Spot(long id, double lat_d, double long_d, double lat_r, double long_r) {
	this->id = id;
	this->lat_d = lat_d;
	this->long_d = long_d;
	this->lat_r = lat_r;
	this->long_r = long_r;
}


long Spot::getID() {
	return id;
}

double Spot::getLatD() {
	return lat_d;
}

double Spot::getLongD() {
	return long_d;
}

double Spot::getLatR() {
	return lat_r;
}

double Spot::getLongR() {
	return long_r;
}

bool Spot::operator==(Spot &s) {
	return id == s.getID();
}
