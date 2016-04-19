#ifndef RESERVE_H_
#define RESERVE_H_

using namespace std;

class Reserve {
private:
	int h;
	int m;
	string dest;
public:
	Reserve(int h, int m,string dest);
	int getHour() const;
	int getMinutes() const;
	string getDest() const;
};

#endif /* RESERVE_H_ */
