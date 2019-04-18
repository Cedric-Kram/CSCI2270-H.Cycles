#include "Structs.hpp"
using namespace std;

//Core functions of program
//Or we can skip this
bool BoolMat::checkNilpotence(){

}

//Checks if graph is connected
bool Graph::checkConnectivity(Vertex v){
  int index = findVertex(v);

}

//Finds hamiltonian starting at v
VertexStack Graph::findHamiltonian(Vertex v){

}

//Matrix structors

BoolMat::BoolMat(int r, int c){
  rows = r;
  cols = c;
  mat = new bool*[rows];
  for(int i = 0; i < rows; i++){
    mat[i] = new bool[cols];
    for(int j = 0; j < cols; j++){
      mat[i][j] = false;
    }
  }
}

BoolMat::~BoolMat(){
  for(int i = 0; i < rows; i++){
    delete[] mat[i];
  }
  delete[] mat;
}

//Linked list

VertexLL::VertexLL(){
  head = NULL;
  tail = NULL;
}

VertexLL::~VertexLL(){
  VertexLLNode* temp1 = head;
  VertexLLNode* temp2;
  while(temp1 != NULL){
    temp2 = temp1;
    temp1 = temp1->next;
    delete temp2;
  }
}

void VertexLL::append(Vertex *n){
  if(n == NULL){
    return;
  }
  VertexLLNode *newVertex;
  newVertex->v = n;
  if(head == NULL){
    head = newVertex;
    tail = newVertex;
  }
  else{
    newVertex->prev = tail;
    tail->next = newVertex;
    tail = newVertex;
  }
}

void VertexLL::remove(int id){
  VertexLLNode *node = findVertexNode(id);
  if(node == NULL){
    return;
  }
  else if(node == head){
    if(node == tail){
      head == NULL;
      tail == NULL;
    }
    else{
      head = node->next;
      head->prev = NULL;
    }
  }
  else if(node == tail){
    tail = node->prev;
    tail->next = NULL;
  }
  else{
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  delete node;
  node = NULL;
}

VertexLLNode* VertexLL::findVertexNode(int id){
  VertexLLNode* temp = head;
  while(temp != NULL){
    if(temp->v->id == id){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

VertexLLNode* VertexLL::getHead(){
  return head;
}

VertexLLNode* VertexLL::getTail(){
  return tail;
}

void VertexLL::printLL(){
  VertexLLNode* t = head;
  while(t != NULL){
    cout << t->v->id << endl;
    t = t->next;
  }
}

//Stack

VertexStack::VertexStack(int mSize){
  maxSize = mSize;
  currSize = 0;
  stack = new Vertex[maxSize];
  for(int i = 0; i < maxSize; i++){
    stack[i].id = i;
  }
}

VertexStack::~VertexStack(){
  delete[] stack;
}

bool VertexStack::isFull(){
  if(currSize == maxSize){
    return true;
  }
  return false;
}

bool VertexStack::isEmpty(){
  if(currSize == 0){
    return true;
  }
  return false;
}
// I think the scope could be a tad funky here,
// Since we are in the heap with the storage of the vertex
// We need to make sure the v is poiting to vertex that is also in the heap
// Otherwise this will be gross.
void VertexStack::push(Vertex *v){
  if(isFull()){
    return;
  }
  stack[currSize] = *v; // I deferenced it here because we are only poitning to a vertex value.
  //Im not sure what this means if it edits the heap stuff to match the deferenced stuff or something else
  currSize++;
}

void VertexStack::pop(){
  if(isEmpty()){
    return;
  }
  currSize--;
}
/*
By adding the [] this is derferencing the vertex so it will be returning the last value.

*/
Vertex* VertexStack::peek(){
  return stack[currSize - 1];
}

void VertexStack::printStack(){
  for(int i = 0; i < currSize; i++){
    cout << stack[i].id << endl;
  }
}

Graph::Graph(int graphSize){
  this->graphSize = graphSize;
  vertices = new Vertex[graphSize];
  currentSize = 0;
}

Graph::~Graph(){delete vertices[]}

void Graph::addVertex(Vertex v){
  if(currentSize >= graphSize){
    vertices[currentSize] = v;
    currentSize++;
  }
}

void Graph::addEdge(Vertex v1, Vertex v2){
  v1.edges.push_back(v2);
}

void Graph::setVertsUnvisited(){
  for(int i = 0, i < graphSize, i++){
    vertices[i].visited = false;
  }
}

void Graph::setVertsValid(){
  for(int i = 0, i < graphSize, i++){
    vertices[i].valid = false;
  }
}


//For Constructor
int split (std::string str, char c, std::string storage[])
{
    if (str.length() == 0) {
        return 0;
    }
    std::string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
        	if (word.length() == 0) continue;
            storage[j] = word;
            j++;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return j ;
}
/*
Data will be presented just like an adjency matrix. Values are csv
ROW will be the Source of the edge, and the Column will be the target for the edge
Since we are NOT considering multiple edges a non-present edge will be a 0, 1 will be present
*/
Driver::Driver(std::string file){
  fstream reader(file);
  if(reader.fail()){
    std::cerr << "Bad File Name" << std::endl;
  }
  std::string line;
  int pos = 1;
  std::getline(reader,line);
  for(int i = 0; i < line.length(); i++){
    if(line[i] == ',') pos++;
  }
  //Im pretty sure there has to better way to do this.
  //But Right now this is how it is going to be done
  BoolMat matrix(pos,pos);
  adjacencyMatrix = matrix;
  reader.clear();
  reader.seekg(0, ios::beg);
  while(std::getline(reader,line)){
    std::istringstream ss(line);
    while(std::getline(ss,status,',')){
      if(std::stoi(status)){
        adjacencyMatrix.mat[row][col] = true;
      } else {
        adjacencyMatrix.mat[row][col] = false;
      }
    }
  }
}
