#ifndef VEHICLE_H_
#define VEHICLE_H_

using namespace std;

class Vehicle {
private:
	string mat; //Matricula
	int nPlaces; //Numero de lugares
public:
	Vehicle(string mat, int nPlaces);
	string getMat() const;
	int getNPlaces() const;
};

#endif /* VEHICLE_H_ */
