#ifndef _NUM_MAZE_H_
#define _NUM_MAZE_H_

#include <utility>
#include <map>
#include <queue>
#include <climits>
#include "WeightedVertex.h"

using namespace std;

// readMaze() - Reads in the number of rows N, the number of columns M, and
//              the NxM vertex weights. This function also connects the
//              vertices appropriately to build the represented number maze.
// Parameters:  a graph of WeightedVertex objects
/*
void readMaze(Graph &inputMaze){ //nXm vertices that are not connectted?
  //connections occur horizontally and vertically
  //Graph tempGraph;
  unsigned n, //number of rows
           m,  //number of columns
           c = 0, //index counter
           weights; //weight variable for a vertex
  vector<vector<WeightedVertex>> matrix;

  cin >> n; //number rows
  cin >> m; //number columns

  for (auto i = 0; i < n; i++){   //for loop itterates through the rows
    for(auto j = 0; j < m; j++){  //for loop iterates through the columns
      cin >> wieghts;             //cin n*m vertex wieghts
      matrix[i].push_back(weights);// push puack the weights for a specific row
       }
     }

  for (auto i = 0; i < n; i++){
    for(auto j = 0; j < m; j++){
      if(i+1 < n){   // if we are out of bounds on the row, don't add
        if(j-1 < m){  //if we are out of bounds on the column, don't add
          WeightedVertex  input(c,weight),    //source
                          input2,   //right destination
                          input3;   //below destination

          input.setNodeNumber(c);  //index of the source vertex
          input.setNodeWeight(matrix[i][j]); //weight of source vertex

          input2.setNodeNumber(c+1);   //index of the next vertice to the right
          input2.setNodeWeight(matrix[i][j+1]);  //weight of the vertex to the right of source

          input3.setNodeNumber(c+m);  //index of vertice below source
          input3.setNodeWeight(matrix[i+1][j]); //weight of the vertex below the source

          add(input,input2); //adds horizontal edge to the right of source
          add(input,input3); //adds vertical edge below source
          c++;               //increments our source vertex

       }
      }
    }
   }
  return;
}

// getSSSP()  - Applies a modification to Dijkstra's SSSP algorithm to
//              work with weighted vertices instead of weighted edges.
// Parameters:  a graph of WeightedVertex objects and
//              the source WeightedVertex object
// Returns: a pair consisting of
//    - a map containing shortest distances by (weighted) vertex
//    - a map containing pi/parent information to store the path

//<first,second> first is our parent, and second is our edge from parent to child. v.d and then v.pi
 pair<map<WeightedVertex,int>,map<WeightedVertex,WeightedVertex>> getSSSP(Graph <WeightedVertex> const &weightedGraph, WeightedVertex const &source){

  map<WeightedVertex,unsigned> vD;  //shortest distance from source
  map<WeightedVertex,WeightedVertex> vPi;  //map from weighted vertex to weighted vertex  MAX_UNT FOR INFITITY information
  vD[0].setNodeWeight(0);   //The source has a distance of zero from itself
  vPi[0].setNodeWeight(UINT_MAX); //for the source maximum value represents null value, it has no parent
  for(int i = 1; i != weightedGraph.sVertices.size(); i++){   //initialize values to infinity, we haven't updated them
    vD[i].setNodeWeight(UINT_MAX);
    vPi[i].setNodeWeight(UINT_MAX);
  }
//D's algorithm, adjust to the weights on the vertices relax needs to be modified
  //insert vertices into priority que v.d the priority que needs to be ordered overload comparison operator for order of weighted vertex class?
  priority_queue<WeightedVertex> theQueue; //ordered by d values! pair (v.d, WeightedVertex) than push priority_queue orders things in descending order, we need it reversed! review how to declare on a min heap
  for (int i = 0; i != weightedGraph.sVertices.size(); i++){  //push all (PAIRS) the vertices present into theQueue so we can pop them eventually

  }

  while(!theQueue.empty()){   //while priorty que is not empty, pop and then extract adjacent vertex
 unsigned front = theQueue.front(); // the front of the priority_queue is the one with the smallest vD value pair
    theQueue.pop();             //pop the (PAIR) smallest path vertex from the queue to assess other options

    for (int i = 0; i < theQueue.size(); i++){  //itterate through the vertices adjacent to the vertex we just popped
      if( vD[i].getNodeWeight()> vD[i+1].getNodeWeight() + vPi[i].getNodeWeight()){ //If v.d > weight from u to v + u.d relax the edge u is source an v is destination
        //vD[i].getNodeWeight() < (vPi.getNodeWeight() + vd.getNodeWeight())??
       unsigned newDistance = vPi[i].getNodeWeight() + vd[i].getNodeWeight();
      vD[i].setNodeWeight(newDistance); //update v.d to the previous calculated "cheaper" edge
      vPi[i].setNodeNumber(front);     //update v.Pi to u so we know where we came from
      }
    getAdjacent(vd[i]);
  } //call adjacentVertex() here
  }



 pair<map<WeightedVertex,int>,map<WeightedVertex,WeightedVertex>> aPair = make_pair(vD,vPi)
  return aPair;
}


// showPath() - Shows the path information from a source vertex to a destination vertex.
//              Assumes vertices are WeightedVertex objects.
// Parameters:  a map from a WeightedVertex object to another WeightedVertex object
//                  representing the pi/parent information;
//              the source WeightedVertex object; and
//              the destination WeightedVertex object
void showPath(map<WeightedVertex,WeightedVertex> const &wvMap,WeightedVertex const &source,WeightedVertex const &destination){

  //cout << "Path of the maze: " << endl;
  for(auto i : wvMap){
    cout << i << ","
  }
  cout << endl;

}*///pi map path from source to destination


#endif
