/*
 * Reserve.cpp
 *
 *  Created on: 19/04/2016
 *      Author: Miguel Luis
 */

#include "Reserve.h"

Reserve::Reserve(string name, int NIF, string dest, int d, int m, int y, int h, int min) {
	this->name = name;
	this->NIF = NIF;
	this->dest = dest;
	this->d = d;
	this->m = m;
	this->y = y;
	this->h = h;
	this->min = min;
}

int Reserve::getHour() const{
	return h;
}

int Reserve::getMinutes() const{
	return m;
}

string Reserve::getDest() const{
	return dest;
}

void Reserve::show(){
	cout << name << "  |  " << NIF << "  |  " << dest << "  |  " << d << "-" << m << "-" << y << "  |  " << h << ":" << min << endl;
}
