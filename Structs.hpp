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
  Vertex *next = NULL;
  Vertex *prev = NULL;
  VertexLLNode(Vertex *t){v = t;}
}

class VertexLL{
  private:
    VertexLLNode head(NULL);
    VertexLLNode tail(NULL):
  public:
    VertexLL();
    ~VertexLL();
    void append(Vertex *v);
    void remove(int id);
    VertexLLNode findVertexNode(int id);
}
