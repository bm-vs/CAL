#include "Util.h"
#include <iostream>

using namespace std;

int main() {
	Graph<Spot> *g = new Graph<Spot>();

	readMap(*g);


	vector<Vertex<Spot> *> v = g->getVertexSet();

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i)->getInfo().getID();

		vector<Edge<Spot> > va = v.at(i)->getAdj();

		for (int j = 0; j < va.size(); j++) {
			cout << " -> " << va.at(j).getDest()->getInfo().getID() << " (" << va.at(j).getWeight() << "); ";
		}

		cout << endl;
	}
}
