#ifndef SPOT_H_
#define SPOT_H_

class Spot {
private:
	long id;
	double lat_d;
	double long_d;
	double lat_r;
	double long_r;
public:
	Spot();
	Spot(long id, double lat_d, double long_d, double lat_r, double long_r);
	long getID();
	double getLatD();
	double getLongD();
	double getLatR();
	double getLongR();
	bool operator==(Spot &s);
};


#endif
