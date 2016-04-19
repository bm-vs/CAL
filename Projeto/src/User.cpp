#include "User.h"

User::User(string name,unsigned int NIF,string dest) {
	this->name = name;
	this->NIF = NIF;
	this->dest = dest;
}

string User::getName() const{
	return name;
}

unsigned int User::getNIF() const{
	return NIF;
}

string User::getDest() const{
	return dest;
}
