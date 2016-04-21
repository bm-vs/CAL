/*
 * main.cpp
 *
 *  Created on: 20/04/2016
 *      Author: Miguel Luis
 */

#include "ReadFiles.h"

ReadFiles::ReadFiles() {}

void ReadFiles::readClients(){
	string line, name, nif, dest;
	int NIF;

	char delim = '/';
	char delim2 = '\n';
	size_t pos = 0;

	ifstream cli("Clients.txt");

	if(cli.is_open()){
		while ( getline (cli,line) )
		{
			pos = line.find(delim);
			name = line.substr(0, (pos-1));
			line.erase(0, pos + 1);

			pos = line.find(delim2);
			nif = line.substr(0, pos);
			NIF = atoi(nif.c_str());
			line.erase(0, pos + 1);

			Client u(name,NIF);
			clients.push_back(u);
		}
		cli.close();
	}
	else
		cout << "Falhou ao abrir ficheiro de clientes!" << endl;
}

void ReadFiles::readVehicles(){
	string line, mat, places;
	int nPlaces;

	char delim = '/';
	char delim2 = '\n';
	size_t pos = 0;

	ifstream cli("Vehicles.txt");

	if(cli.is_open()){
		while ( getline (cli,line) )
		{
			pos = line.find(delim);
			mat = line.substr(0, (pos-1));
			line.erase(0, pos + 1);

			pos = line.find(delim2);
			places = line.substr(0, pos);
			nPlaces = atoi(places.c_str());
			line.erase(0, pos + 1);

			Vehicle v(mat,nPlaces);
			vans.push_back(v);
		}
		cli.close();
	}
	else
		cout << "Falhou ao abrir ficheiro de veiculos!" << endl;
}

void ReadFiles::readReserves(){
	string line, name, nif, dest, day, month, year, hour, minutes;
	int NIF, d, m, y, h, min;

	char delim = '/';
	char delim2 = '-';
	char delim3 = ':';
	char delim4 = '\n';
	size_t pos = 0;

	ifstream cli("Reserves.txt");

	if(cli.is_open()){
		while ( getline (cli,line) )
		{
			pos = line.find(delim);
			name = line.substr(0,(pos-1));
			line.erase(0, pos + 1);

			pos = line.find(delim);
			nif = line.substr(0, (pos-1));
			NIF = atoi(nif.c_str());
			line.erase(0, pos + 2);

			pos = line.find(delim);
			dest = line.substr(0, (pos-1));
			line.erase(0, pos + 1);

			pos = line.find(delim2);
			day = line.substr(0, pos);
			d = atoi(day.c_str());
			line.erase(0, pos + 1);

			pos = line.find(delim2);
			month = line.substr(0, pos);
			m = atoi(month.c_str());
			line.erase(0, pos + 1);

			pos = line.find(delim);
			year = line.substr(0, (pos-1));
			y = atoi(year.c_str());
			line.erase(0, pos + 1);

			pos = line.find(delim3);
			hour = line.substr(0, pos);
			h = atoi(hour.c_str());
			line.erase(0, pos + 1);

			pos = line.find(delim4);
			minutes = line.substr(0, pos);
			min = atoi(minutes.c_str());
			line.erase(0, pos + 1);

			Reserve r(name,NIF,dest,d,m,y,h,min);
			reserves.push_back(r);
		}
		cli.close();
	}
	else
		cout << "Falhou ao abrir ficheiro de reservas!" << endl;
}

void ReadFiles::showClients(){
	for(unsigned int i=0; i<clients.size(); i++)
		clients[i].show();
}

void ReadFiles::showVehicles(){
	for(unsigned int i=0; i<vans.size(); i++)
		vans[i].show();
}

void ReadFiles::showReserves(){
	for(unsigned int i=0; i<reserves.size(); i++)
		reserves[i].show();
}
