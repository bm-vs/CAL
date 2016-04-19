#ifndef USER_H_
#define USER_H_

#include <iostream>

using namespace std;

class User {
private:
	string name;
	unsigned int NIF;
	string dest;
public:
	User(string name,unsigned int NIF,string dest);
	string getName() const;
	unsigned int getNIF() const;
	string getDest() const;
};

#endif /* USER_H_ */
