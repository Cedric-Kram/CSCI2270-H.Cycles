#include <vector>
using namespace std;

//General Vertex struct to be used in other data structures

struct Vertex{
  int id;
  bool visited = false;
  Vertex(int num){id = num;}
  vector<Vertex*> edges;
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
    void printStack();
};
