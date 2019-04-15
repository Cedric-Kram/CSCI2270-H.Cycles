#include "LL.hpp"
#include <iostream>
using namespace std;

//Linked list

VertexLL::VertexLL(){
  head = NULL;
  tail = NULL:
}

VertexLL::~VertexLL(){
  
}

void VertexLL::append(Vertex *n){
  if(v == NULL){
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