#ifndef VEHICLE_H_
#define VEHICLE_H_

using namespace std;

class Vehicle {
private:
	string mat;
	int nPlaces;
	int placesOccupied;
public:
	Vehicle(string mat, int nPlaces);
	string getMat() const;
	int getNPlaces() const;
	int getPlacesOccupied() const;
};

#endif /* VEHICLE_H_ */
