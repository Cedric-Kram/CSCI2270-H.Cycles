#include "Structs.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

void debug(string str){
	cout << str << endl;
}

void genAdjMatDir(BoolMat *m){
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->cols; j++){
			m->mat[i][j] = rand()%2;
			if(i == j){
				m->mat[i][j] = 0;
			}
		}
	}
}

void genAdjMatUndir(BoolMat *m){
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < i; j++){
			m->mat[i][j] = rand()%2;
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
//*/
int main(){
	srand((unsigned)time(0));
	int numVerts = 5;
	
	BoolMat *m;
	m = new BoolMat(numVerts, numVerts);
	genAdjMatDir(m);
	m->printMat();
	
	cout << endl << "Generating Graph..." << endl;
	Graph *g;
	g = new Graph(numVerts);
	genGraphFromAdjMat(g, m);
	g->printVertices();
	cout << "Graph generated succesfully" << endl << endl;
	
	VertexStack s(numVerts);
	for(int i = 0; i < numVerts; i++){
		Vertex *t = g->findVertex(i);
		if(g->checkConnectivity(t)){
			cout << "Graph is connected from root node " << i << endl;
		}
		else{
			cout << "Graph is not connected from root node " << i << endl;
		}
	}
	
}
