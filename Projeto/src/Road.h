#ifndef ROAD_H_
#define ROAD_H_

#include <iostream>

using namespace std;

class Road {
private:
	long id;
	string name;
	bool is_two_way;
public:
	Road();
	Road(long id, string name, bool is_two_way);
	long getID();
	string getName();
	bool getIsTwoWay();
};


#endif
