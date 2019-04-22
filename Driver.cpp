#include "Structs.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//Basically repeated bernoulli trials
int expRand(int base_mod, int power){
	int total = 1;
	for(int i = 0; i < power; i++){
		total = total*(rand()%2);
	}
	return total;
}

void debug(string str){
	cout << str << endl;
}

//Generates adjacency matrix for directed graph
void genAdjMatDir(BoolMat *m, int numVerts){
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->cols; j++){
			m->mat[i][j] = rand()%2;
			//m->mat[i][j] = expRand(2, (int)sqrt(numVerts));
			if(i == j){
				m->mat[i][j] = 0;
			}
		}
	}
}

//Generates adjacency matrix for undirected graph
void genAdjMatUndir(BoolMat *m, int numVerts){
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < i; j++){
			m->mat[i][j] = rand()%2;
			//m->mat[i][j] = expRand(2, (int)sqrt(numVerts));
			m->mat[j][i] = m->mat[i][j];
		}
	}
}

void genGraphFromAdjMat(Graph *g, BoolMat *m){
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->cols; j++){
			if(m->mat[i][j]){
				//cout << i << j << endl;
				Vertex *v1 = g->findVertex(i);
				Vertex *v2 = g->findVertex(j);
				//cout << v1 << "|" << v2 << endl;
				g->addEdge(*v1, *v2);
			}
		}
	}
}

bool test(){
	debug("Testing~");
	return true;
}

//Requires single argument, a positive integer representing number of vertices in graph
int main(int argc, char const *argv[]){
	//Seeds random number generator & determines size of graph
	srand((unsigned)time(0));
	int numVerts = stoi(argv[1]);

	//Creates the adjacency matrix
	BoolMat *m;
	m = new BoolMat(numVerts, numVerts);
	genAdjMatDir(m, numVerts);
	m->printMat();

	//Initializes graph from adjacency matrix
	cout << endl << "Generating Graph..." << endl;
	Graph *g;
	g = new Graph(numVerts);
	genGraphFromAdjMat(g, m);
	g->printVertices();
	cout << "Graph generated succesfully" << endl << endl;

	//Checks connectivity of graph
	VertexLL *cons = new VertexLL;
	Vertex *t;
	std::cout << numVerts << std::endl;
	for(int i = 0; i < numVerts; i++){
		cout << "Size: " << g->getSize() << endl;
		t = g->findVertex(i);
		if(g->checkConnectivity(t)){
			cout << "Graph is connected from root node " << i << endl;
			cout << "ADDDING "<<  t->id << endl;
			cons->append(t);
			//cons.getHead()
			debug("A2");
		}
		else{
			cout << "Graph is not connected from root node " << i << endl;
			debug("A3");
		}
	}
	cout << endl << "Printing list of connected vertices..." << endl;
	cons->printLL();
}
