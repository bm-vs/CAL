#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>

using namespace std;

class Client {
private:
	string name;
	int NIF;
public:
	Client(string name,int NIF);
	string getName() const;
	int getNIF() const;
	void show();
};

#endif /* CLIENT_H_ */
