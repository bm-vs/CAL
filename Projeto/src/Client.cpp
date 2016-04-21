#include "Client.h"

Client::Client(string name, int NIF) {
	this->name = name;
	this->NIF = NIF;
}

string Client::getName() const{
	return name;
}

int Client::getNIF() const{
	return NIF;
}

void Client::show(){
	cout << name << "  |  " << NIF << endl;
}
