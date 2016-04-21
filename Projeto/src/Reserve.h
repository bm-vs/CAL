#ifndef RESERVE_H_
#define RESERVE_H_

#include <iostream>

using namespace std;

class Reserve {
private:
	string name, dest;
	int NIF;
	int d, m, y;
	int h, min;
public:
	Reserve(string name, int NIF, string dest, int d, int m, int y, int h, int min);
	int getHour() const;
	int getMinutes() const;
	string getDest() const;
	void show();
};

#endif /* RESERVE_H_ */
