#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//General Vertex struct to be used in other data structures

struct Vertex{
  int id;
  bool visited = false;
  bool valid = true;
  Vertex(int num){id = num;}
  Vertex(){};
  vector<Vertex*> edges;
  vector<Vertex*> invalids;
  bool isInvalid(Vertex *v);
  void clearInvalids();
};

//Bool Matrix struct

struct BoolMat{
  int rows;
  int cols;
  bool **mat;
  BoolMat(int r, int c);
  BoolMat(){};
  ~BoolMat();
  //bool checkNilpotence();
  void printMat();
  //void clearMat();
};

//Linked list stuff

struct VertexLLNode{
  Vertex *v;
  VertexLLNode *next = NULL;
  VertexLLNode *prev = NULL;
};

class VertexLL{
  private:
    VertexLLNode* head;
    VertexLLNode* tail;
  public:
    VertexLL();
    ~VertexLL();
    void append(Vertex *n);
    void remove(int id);
    VertexLLNode* findVertexNode(int id);
    void printLL();
    VertexLLNode* getHead();
    VertexLLNode* getTail();
};

//Stack stuff

class VertexStack{
  private:
    int maxSize;
    int currSize;
    Vertex **stack;
  public:
    VertexStack(int mSize);
    ~VertexStack();
    bool isFull();
    bool isEmpty();
    void push(Vertex *v);
    void pop();
    Vertex* peek();
    Vertex* front();
    void printStack();
    bool inStack(Vertex *v);
	int getSize();
};

//Queue stuff

class VertexQueue{
  private:
    int maxSize;
    int currSize;
    int headIndex;
    int tailIndex;
    Vertex **q;
  public:
    VertexQueue(int mSize);
    ~VertexQueue();
    bool isFull();
    bool isEmpty();
    void push(Vertex *v);
    void pop();
    Vertex* peek();
    Vertex* front();
    void printQueue();
};

class Graph{
  private:
    int graphSize;
    int currentSize; // Just for loading purposes
    //With this array of Vertex we will have a fixed sized
    Vertex *vertices;
  public:
    //Constructor will take pointer to adjacency matrix as pointer, will construct graph from this
    Graph(int);
    ~Graph();
	void addVertex(Vertex v);
    void addEdge(Vertex &v1, Vertex &v2);
    //Finds index of vertex in vertices array
    Vertex* findVertex(int id);
    void setVertsUnvisited();
    void setVertsValid();
    bool checkConnectivity(Vertex *v);
    void findHamiltonian(Vertex *v, VertexStack *s);
	void findHamiltonians(VertexStack *s, vector<VertexStack> cycles);
	void printVertices();
	int getSize();
};
