//This was a prototype for the algorithm to find cycles

#include <iostream>

bool safe(int vert, bool graph[][5], int path[], int pos, int size){
  //Checking if the graph path's last vertex doesnt have an edge to the new vertex
  if(!graph[ path[pos - 1] ][ vert ]) return false;
  //Check if the vert is already in the path
  for(int i = 0; i < size; i++){
    if(path[i] == vert) return false;
  }
  //We know its a safe path now.
  return true;
}

bool hamilCycleTil(bool graph[5][5], int path[], int pos, int size){
  //Base Case
  if(pos == size){
    //Checks if there is an edges from the last postion in the path to orginal 0
    if(graph[ path[pos-1] ][ path[0] ]){return true;}
    else return false;
  }
  //Induction,(Start at 1 because we already have first vertex in the path)
  for(int i = 1; i < size; i++){
    if(safe(i,graph,path,pos,size)){
      std::cout << "Checking " << i << "  " << pos << std::endl;
      path[pos] = i;
      if(hamilCycleTil(graph,path,pos+1,size)){
        //std::cout << "Progress Check " << pos << std::endl;
        //path[pos] = i;
        return true;
      }
      //If we need to back track the stack, Aka a dead end
      path[pos] = -1;
      return false;
    }
  }
}

void hamilCycle(bool graph[5][5], int size){
  int *path  = new int[size];
  for(int i = 0; i < size; i++){
    path[i] = -1;
  }
  //Starting Pos
  path[0] = 0; //This could be anything but for now it is this
  if(hamilCycleTil(graph,path,1,size)){
    for(int i  = 0; i < size; i++){
      std::cout << path[i] << " ";
    }
    std::cout<< std::endl;
  } else {
    std::cout << "No H.Cycles" << std::endl;
  }
}

int main(){
  int v = 5; // Size of graph (#of vertices)
  bool graph[5][5] = { {0,1,1,1,1},
                       {1,0,1,1,1},
                       {1,1,0,1,1},
                       {1,1,1,0,1},
                       {1,1,1,1,0}};

  bool graph1[5][5] = { {0,1,0,0,0},
                       {1,0,1,0,0},
                       {1,1,0,0,1},
                       {1,0,0,0,0},
                       {0,0,0,1,0}};

  hamilCycle(graph,v);
  hamilCycle(graph1,v);
}
