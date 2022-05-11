#ifndef _NUM_MAZE_H_
#define _NUM_MAZE_H_

#include <utility>
#include <map>
#include <queue>

#include "WeightedVertex.h"

// readMaze() - Reads in the number of rows N, the number of columns M, and
//              the NxM vertex weights. This function also connects the
//              vertices appropriately to build the represented number maze.
// Parameters:  a graph of WeightedVertex objects
void readMaze(Graph &inputMaze){ //nXm vertices that are not connectted?
  //connections occur horizontally and vertically
  //Graph tempGraph;
  unsigned n, //number of rows
           m,  //number of columns
           i = 0, //index counter
           weights, //weight variable for a vertex
           horizEdge = n - 1, //number of horizontal edges
           vertEdge = m - 1;  //number of vertical edges
           var;
  vector<unsigned> vUWieghts; //local container to hold wieghts of the vertex
  cin >> n; //number rows
  cin >> m; //number columns
  while(cin >> wieghts){    //wieghted vertex from standard in
      WeightedVertex input;      //weightedvertex object?[i,weight] using a constructor
      input.setNodeNumber(i); //node number starts at 0 ends at nXm
      input.setNodeWeight(wieghts); //set the node(vertex) wieght to that value passed from calling function

      vUWieghts[i].push_back (input.getNodeWeight(i));    //populating the vector with all of the maze's wieghts, index of vector represents the nodeNumber

      //inputMaze.sVertices.insert(input);   //created the vertices now add them to graph
      i++;
  }


//create the edges for the above graph horizontally and vertically m-1 horizontal edges two loops for both edges
map<WeightedVertex> temp; //temp map with -> second in WHAT?!?!


    for(auto i = 0; i != n-1;i++){  //for loop that will itterate through the rows graph
      for(auto j = 0; j!= m-1;j++){ //for loop that will itterate through the columns of a graph
          var =
          if( (n*m >= var) && (var%n == 0))
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
 //D's algorithm, adjust to the weights on the vertices relax needs to be modified
  map<WeightedVertex,int> vD;  //shortest distance from source
  map<WeightedVertex,WeightedVertex> vPi;  //map that will hold parent info map from weighted vertex to weighted vertex  MAX_UNT FOR INFITITY information
  //insert vertices into priority que v.d the priority que needs to be ordered overload comparison operator for order of weighted vertex class?

  //while priorty que is not empty, pop and then extract adjacent vertexLabel
  //



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
}//pi map path from source to destination


#endif
