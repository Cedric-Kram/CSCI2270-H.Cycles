#include "Structs.hpp"
using namespace std;

//Matrix structors

BoolMat::BoolMat(int r, int c){
  rows = r;
  cols = c;
  mat = new bool*[rows];
  for(i = 0; i < rows; i++){
    mat[i] = new bool[cols];
    for(j = 0; j < cols; j++){
      mat[i][j] = false; 
    }
  }
}

BootMat::~BoolMat(){
  for(int i = 0; i < rows; i++){
    delete[] mat[i]; 
  }
  delete[] mat;
}

//Linked list

VertexLL::VertexLL(){
  head = NULL;
  tail = NULL:
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
  if(v == NULL){
    return; 
  }
  VertexLLNode *newVertex;
  newVertex->v = &n;
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
      head->prev = NULL:
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

void VertexStack::push(Vertex v){
  if(isFull()){
    return; 
  }
  stack[currSize] = v;
  currSize++;
}

void VertexStack::pop(){
  if(isEmpty()){
    return;
  }
  currSize--;
}

Vertex VertexStack::peek(){
  return stack[currSize - 1];
}

void VertexStack::printStack(){
  for(int i = 0; i < currSize; i++){
    cout << stack[i]->id << endl; 
  }
}

VertexQueue(int mSize){
  maxSize = mSize;
  headIndex = 0;
  tailIndex = 0;
  currSize = 0;
  q = new Vertex[maxSize];
}

~VertexQueue(){
  delete[] q;
}

bool isFull(){
  if(currSize == maxSize){
    return true; 
  }
  return false;
}

bool isEmpty(){
  if(currSize == 0){
    return true; 
  }
  return false;
}

void push(Vertex *v){
  
}

void pop(){
  
}

Vertex* peek(){
  
}

void printQueue(){
  
}

