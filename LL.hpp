#include <vector>
using namespace std;

struct Vertex{
  int id;
  bool visited = false;
  Vertex(int num){id = num;}
  vector<Vertex*> edges;
}

//Linked list stuff

struct VertexLLNode{
  Vertex *v;
  VertexLLNode *next = NULL;
  VertexLLNode *prev = NULL;
}

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
}
