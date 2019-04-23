#include "Structs.hpp"
#include <cstdlib>
#include <vector>
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
			//m->mat[i][j] = rand()%2;
			m->mat[i][j] = expRand(2, (int)sqrt(numVerts));
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

void methodOne(Vertex *Start, Vertex *v, vector<Vertex> path, int Size){
	if(path.size() ==  Size){
		bool flag;
		for(int i = 0; i < path[Size-1].edges.size(); i++){
			if(path[Size-1].edges[i]->id == Start->id) flag = true;
		}
		if(flag){
			for(int i =0; i < path.size(); i++){
				std::cout << path[i].id << " ";
			}
			std::cout << Start->id;
			std::cout<<std::endl;
		}
		return;
	}
	for(int i = 0; i < v->edges.size();i++){
		//std::cout << "Check Point 1: (Vertex Source)" << v->id  << " Checking (Termial) " << v->edges[i]->id << std::endl;
		if(!v->edges[i]->visited){

			v->edges[i]->visited = true;
			path.push_back(*v->edges[i]);

			//cout << "Path Size:" << path.size() << endl;
			methodOne(Start ,v->edges[i], path, Size);

			v->edges[i]->visited = false;
			path.pop_back();
		}
	}
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
	//cout << numVerts << endl;
	for(int i = 0; i < numVerts; i++){
		//cout << "Size: " << g->getSize() << endl;
		t = g->findVertex(i);
		if(g->checkConnectivity(t)){
			//cout << "Graph is connected from root node " << i << endl;
			//cout << "ADDDING "<<  t->id << endl;
			cons->append(t);
			//cons.getHead()
			//debug("A2");
		}
		else{
			//cout << "Graph is not connected from root node " << i << endl;
			//debug("A3");
		}
	}
	cout << endl << "Graph is connected from nodes: " << endl;
	cons->printLL();

	cout << endl;
	std::cout << "Print Ham Paths from Method One: " << std::endl;
	Vertex *temp;
	g->setVertsUnvisited();
	temp = g->findVertex(0);
	temp->visited = true;
	vector<Vertex> path;
	path.push_back(*temp);
	methodOne(temp,temp, path, std::stoi(argv[1]));

}
