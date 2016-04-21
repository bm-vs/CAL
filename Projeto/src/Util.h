#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cmath>
#include "Graph.h"
#include "Road.h"
#include "Spot.h"

void readMap(Graph<Spot> &g);
map<long,Spot> readSpots(Graph<Spot> &g);
map<long,Road> readRoads();
void readConnections(Graph<Spot> &g, map<long,Spot> &spots, map<long,Road> &roads);
double getDistBetween(Spot s1, Spot s2);
double haversine(double angRad);
