/*
 * Reserve.cpp
 *
 *  Created on: 19/04/2016
 *      Author: Miguel Luis
 */

#include "Reserve.h"

Reserve::Reserve(int h, int m, string dest) {
	this->h = h;
	this->m = m;
	this->dest = dest;
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
