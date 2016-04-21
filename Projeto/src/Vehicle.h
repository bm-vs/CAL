#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>

using namespace std;

class Vehicle {
private:
	string mat;
	int nPlaces;
	bool occupated;
	int placesOccupied;
public:
	Vehicle(string mat, int nPlaces);
	string getMat() const;
	int getNPlaces() const;
	bool getOccupated() const;
	int getPlacesOccupied() const;
	void show();
};

#endif /* VEHICLE_H_ */
