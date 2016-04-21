#include "Road.h"

Road::Road() {
}

Road::Road(long id, string name, bool is_two_way) {
	this->id = id;
	this->name = name;
	this->is_two_way = is_two_way;
}

long Road::getID() {
	return id;
}

string Road::getName() {
	return name;
}

bool Road::getIsTwoWay() {
	return is_two_way;
}
