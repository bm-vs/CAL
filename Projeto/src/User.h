#ifndef USER_H_
#define USER_H_

using namespace std;

class User {
private:
	string name;
	int NIF;
	string dest;
public:
	User(string name,int NIF,string dest);
	string getName() const;
	int getNIF() const;
	string getDest() const;
};

#endif /* USER_H_ */
