/*
 * main.h
 *
 *  Created on: 20/04/2016
 *      Author: Miguel Luis
 */

#ifndef READFILES_H_
#define READFILES_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "Client.h"
#include "Vehicle.h"
#include "Reserve.h"

using namespace std;

class ReadFiles {
private:
	vector<Client> clients;
	vector<Vehicle> vans;
	vector<Reserve> reserves;
public:
	ReadFiles();
	void readClients();
	void showClients();
	void readVehicles();
	void showVehicles();
	void readReserves();
	void showReserves();
};

#endif /* READFILES_H_ */
