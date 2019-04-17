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
    void append(Vertex n);
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
    Vertex *stack;
  public:
    VertexStack(int mSize);
    ~VertexStack();
    bool isFull();
    bool isEmpty();
    void push(Vertex v);
    void pop();
    Vertex* peek();
    void printStack();
};

//Queue stuff

class VertexQueue{
  private:
    int maxSize;
    int currSize;
    int headIndex;
    int tailIndex;
    Vertex *q;
  public:
    VertexQueue(int mSize);
    ~VertexQueue();
    bool isFull();
    bool isEmpty();
    void push(Vertex v);
    void pop();
    Vertex* peek();
    void printQueue();
};

class Graph{
  private:
    int graphSize;
    Vertex *vertices;
  public:
    //Constructor will take pointer to adjacency matrix as pointer, will construct graph from this
    Graph();
    ~Graph();
    void addVertex(Vertex v);
    void addEdge(Vertex v1, Vertex v2);
    //Finds index of vertex in vertices array
    int findVertex(Vertex v);
    void setVertsUnvisited();
    void setVertsValid();
    bool checkConnectivity(Vertex v);
    VertexStack findHamiltonian(Vertex v);
};

class Driver{
  private:
    BoolMat adjacencyMatrix;
    //int getSize(std::string); // Finds Size of giving matrix file
  public:
    Driver(std::string); //Loading a graph from file
    Driver(int); //Generating a random graph of n vertexes;
};
