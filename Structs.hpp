#include <vector>
#include <iostream>
using namespace std;

//General Vertex struct to be used in other data structures

struct Vertex{
  int id;
  bool visited = false;
  Vertex(int num){id = num;}
  vector<Vertex*> edges;
};

//Bool Matrix struct

struct BoolMat{
  int rows;
  int cols;
  bool **mat;
  BoolMat(int r, int c);
  ~BoolMat();
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
    VertexLLNode* tail:
  public:
    VertexLL();
    ~VertexLL();
    void append(Vertex +
                n);
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
    Vertex peek();
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
    void push(Vertex *v);
    void pop();
    Vertex* peek();
    void printQueue();
};
