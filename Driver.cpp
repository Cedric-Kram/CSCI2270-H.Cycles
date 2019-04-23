#include "Structs.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//Generates adjacency matrix for directed graph
void genAdjMatDir(BoolMat *m, int numVerts){
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->cols; j++){
			m->mat[i][j] = rand()%2;
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
			m->mat[j][i] = m->mat[i][j];
		}
	}
}

//Generates adjacency matrix for directed graph
void genGraphFromAdjMat(Graph *g, BoolMat *m){
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->cols; j++){
			if(m->mat[i][j]){
				Vertex *v1 = g->findVertex(i);
				Vertex *v2 = g->findVertex(j);
				g->addEdge(*v1, *v2);
			}
		}
	}
}

//Function to store stack in a linked list
void convertStackToList(VertexStack *s, VertexLL *l){
	while(!s->isEmpty()){
		Vertex* temp = s->peek();
		l->append(temp);
		s->pop();
	}
}

//Method to find all cycles that does not use graphs class
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

//Arguments:
//1) Positive integer corresponding to the desired number of vertices in the graph
	
int main(int argc, char const *argv[]){
	
	//Seeds random number generator & determines size of graph
	srand((unsigned)time(0));
	int numVerts = stoi(argv[1]);

	//Creates the adjacency matrix
	BoolMat *m;
	m = new BoolMat(numVerts, numVerts);
	//genAdjMatUndir(m, numVerts);
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
	for(int i = 0; i < numVerts; i++){
		t = g->findVertex(i);
		//cout << t << endl;
		if(g->checkConnectivity(t)){
			cons->append(t);
		}
	}
	//cout << cons->getHead() << endl;
	VertexStack *s = new VertexStack(numVerts);
	vector<VertexLL*> cycles;
	//vector<VertexStack> cycles;
	
	if(cons->getHead() == NULL){
		cout << "No connected nodes found, Graph has no Hamiltonian cycles" << endl;
	}
	else{
		t = cons->getHead()->v;
		//Prints list of nodes on which graph is connected
		cout << endl << "Graph is connected from nodes: " << endl;
		cons->printLL();
		cout << endl;
		
		/*
		g->setVertsUnvisited();
		t->visited = true;
		s->push(t);
		g->findHamiltonians(s, cycles);
		*/
		VertexLLNode *temp = cons->getHead();
		while(temp != NULL){	
			t = temp->v;
			//Finds Hamiltonian cycle, if there are any connected nodes
			g->setVertsUnvisited();
			cout << "Starting at vertex " << t->id << ": ";
			VertexStack *s = new VertexStack(numVerts);
			g->findHamiltonian(t, s);
			if(s->isEmpty()){
				cout << "No Hamiltonian cycle found" << endl;
			}
			else{
				cout << "Hamiltonian cycle found: ";
				s->printStack();
				cout << endl;
				VertexLL* l = new VertexLL;
				convertStackToList(s, l);
				cycles.push_back(l);
			}
			temp = temp->next;
			cout << endl;
		}
		cout << "Using method one to print all Ham cycles:" << endl;
		Vertex *tempa;
		g->setVertsUnvisited();
		tempa = g->findVertex(0);
		tempa->visited = true;
		vector<Vertex> path;
		path.push_back(*tempa);
		methodOne(tempa,tempa, path, stoi(argv[1]));
	}
}
