#include "Util.h"


void readMap(Graph<Spot> &g) {
	map<long,Spot> spots;
	map<long,Road> roads;

	spots = readSpots(g);
	roads = readRoads();
	readConnections(g, spots, roads);
}

map<long, Spot> readSpots(Graph<Spot> &g) {
	// NODES
	map<long, Spot> spots;
	ifstream spots_file;
	spots_file.open("maps/spots.txt");

	string spot_id, lat_d, long_d, lat_r, long_r;

	while(true) {
		getline(spots_file, spot_id, ';');
		getline(spots_file, lat_d, ';');
		getline(spots_file, long_d, ';');
		getline(spots_file, lat_r, ';');
		getline(spots_file, long_r);

		if (spots_file.peek() == EOF) {
			break;
		}

		Spot s(atol(spot_id.c_str()), atof(lat_d.c_str()), atof(long_d.c_str()), atof(lat_r.c_str()), atof(long_r.c_str()));

		spots[atol(spot_id.c_str())] = s;
		g.addVertex(s);
	}

	spots_file.close();

	return spots;
}

map<long,Road> readRoads() {
	// EDGES
	map<long,Road> roads;

	ifstream edges_file;
	edges_file.open("maps/roads.txt");

	string road_id, road_name, is_two_way;

	while(true) {
		getline(edges_file, road_id, ';');
		getline(edges_file, road_name, ';');
		getline(edges_file, is_two_way);

		if (edges_file.peek() == EOF) {
			break;
		}

		if (is_two_way == "true") {
			roads[atol(road_id.c_str())] = Road(atol(road_id.c_str()), road_name, true);
		}
		else {
			roads[atol(road_id.c_str())] = Road(atol(road_id.c_str()), road_name, false);
		}
	}

	edges_file.close();

	return roads;
}

void readConnections(Graph<Spot> &g, map<long,Spot> &spots, map<long,Road> &roads) {
	// CONNECTIONS

	ifstream connections_file;
	connections_file.open("maps/connections.txt");

	string road_id, spot1_id, spot2_id;

	while(true) {
		getline(connections_file, road_id, ';');
		getline(connections_file, spot1_id, ';');
		getline(connections_file, spot2_id, ';');

		if (connections_file.peek() == EOF) {
			break;
		}

		if (connections_file.peek() == '\n') {
			char c;
			connections_file.get(c);
		}

		Road r = roads[atol(road_id.c_str())];
		Spot s1 = spots[atol(spot1_id.c_str())];
		Spot s2 = spots[atol(spot2_id.c_str())];

		if (r.getIsTwoWay() == true) {
			g.addEdge(s1, s2, getDistBetween(s1,s2));
			g.addEdge(s2, s1, getDistBetween(s1,s2));
		}
		else {
			g.addEdge(s1, s2, getDistBetween(s1,s2));
		}
	}

	connections_file.close();

}

double getDistBetween(Spot s1, Spot s2) {
	double r = 6371;

	double d_lat = s2.getLatR() - s1.getLatR();
	double d_long = s2.getLongR() - s1.getLongR();
	double lat1 = s1.getLatR();
	double lat2 = s2.getLatR();

	double a = sin(d_lat/2)*sin(d_lat/2) + sin(d_long/2)*sin(d_long/2)*cos(lat1)*cos(lat2);
	double c = 2*asin(sqrt(a));

	return r*c;
}
