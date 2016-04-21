/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>

using namespace std;

template <class T> class Edge;
template <class T> class Graph;


// ===================================================================================================
// VERTEX

template <class T>
class Vertex {
	T info;
	vector<Edge<T>  > adj;
	bool visited;
	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);
public:
	Vertex(T in);
	friend class Graph<T>;
	T getInfo();
	vector<Edge<T> > getAdj();
};


template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false){}


template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	typename vector<Edge<T> >::iterator it = adj.begin();

	while (it != adj.end()) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		}

		else it++;
	}

	return false;
}


template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edge(dest,w);
	adj.push_back(edge);
}

template<class T>
T Vertex<T>::getInfo() {
	return info;
}

template<class T>
vector<Edge<T> > Vertex<T>::getAdj() {
	return adj;
}


// ===================================================================================================
// EDGE


template <class T>
class Edge {
	Vertex<T> * dest;
	double weight;
public:
	Edge(Vertex<T> *d, double w);
	Vertex<T> * getDest();
	double getWeight();
	friend class Graph<T>;
	friend class Vertex<T>;
};


template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w){}

template <class T>
Vertex<T> * Edge<T>::getDest() {
	return dest;
}

template <class T>
double Edge<T>::getWeight() {
	return weight;
}




// ===================================================================================================
// GRAPH


template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, vector<T> &res) const;
public:
	bool addVertex(T &in);
	bool addEdge(T &sourc, T &dest, double w);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(Vertex<T> *v) const;
	int maxNewChildren(Vertex<T> *v, T &inf) const;
	vector<Vertex<T> * > getVertexSet() const;
	int getNumVertex() const;
};


template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}


template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
	return vertexSet;
}


template <class T>
bool Graph<T>::addVertex(T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();

	for (; it != vertexSet.end(); it++) {
		if ((*it)->info == in) {
			return false;
		}
	}

	Vertex<T> *v1 = new Vertex<T>(in);
	vertexSet.push_back(v1);
	return true;
}


template <class T>
bool Graph<T>::removeVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();

	for (; it != vertexSet.end(); it++) {
		if ((*it)->info == in) {
			Vertex<T> * v= *it;
			vertexSet.erase(it);

			typename vector<Vertex<T>*>::iterator it1 = vertexSet.begin();

			for (; it1 != vertexSet.end(); it1++) {
				(*it1)->removeEdgeTo(v);
			}

			delete v;
			return true;
		}
	}

	return false;
}


template <class T>
bool Graph<T>::addEdge(T &sourc, T &dest, double w) {
	typename vector<Vertex<T>*>::iterator it= vertexSet.begin();
	int found=0;
	Vertex<T> *vS, *vD;

	while (found != 2 && it != vertexSet.end() ) {
		if ((*it)->info == sourc) {
			vS=*it;
			found++;
		}

		if ((*it)->info == dest ) {
			vD=*it;
			found++;
		}

		it++;
	}

	if (found!=2) {
		return false;
	}

	vS->addEdge(vD,w);
	return true;
}


template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	int found=0;
	Vertex<T> *vS, *vD;

	while (found != 2 && it != vertexSet.end()) {
		if ((*it)->info == sourc) {
			vS=*it;
			found++;
		}

		if ((*it)->info == dest) {
			vD=*it;
			found++;
		}

		it++;
	}

	if (found!=2) {
		return false;
	}

	return vS->removeEdgeTo(vD);
}


template <class T>
vector<T> Graph<T>::dfs() const {
	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();

	for (; it != vertexSet.end(); it++) {
		(*it)->visited=false;
	}

	vector<T> res;
	it = vertexSet.begin();

	for (; it != vertexSet.end(); it++) {
		if ((*it)->visited == false) {
	    	dfs(*it,res);
	    }
	}

	return res;
}


template <class T>
void Graph<T>::dfs(Vertex<T> *v,vector<T> &res) const {
	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge<T> >::iterator it = (v->adj).begin();

	for (; it != (v->adj).end(); it++) {
	    if (it->dest->visited == false) {
	    	dfs(it->dest, res);
		}
	}
}


template <class T>
vector<T> Graph<T>::bfs(Vertex<T> *v) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	q.push(v);
	v->visited = true;

	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);

		typename vector<Edge<T> >::iterator it = v1->adj.begin();

		for (; it != v1->adj.end(); it++) {
			Vertex<T> *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
			}
		}
	}

	return res;
}


template <class T>
int Graph<T>::maxNewChildren(Vertex<T> *v, T &inf) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	queue<int> level;
	int maxChildren=0;
	inf = v->info;
	q.push(v);
	level.push(0);
	v->visited = true;

	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		int l = level.front();
		level.pop();
		l++;
		int nChildren=0;

		typename vector<Edge<T> >::iterator it=v1->adj.begin();

		for (; it != v1->adj.end(); it++) {
			Vertex<T> *d = it->dest;

			if (d->visited==false) {
				d->visited=true;
				q.push(d);
				level.push(l);
				nChildren++;
			}
		}

		if (nChildren>maxChildren) {
			maxChildren=nChildren;
			inf = v1->info;
		}
	}
	return maxChildren;
}



#endif /* GRAPH_H_ */
