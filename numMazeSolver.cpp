// Solution to UVA Problem 929: Number Maze

#include <iostream>

using namespace std;

#include "Graph.h"
#include "WeightedVertex.h"
#include "numMaze.h"

int main()
{
   Graph< WeightedVertex > G("Number Maze");
   readMaze(G);
   // cout << G << endl;

   set<WeightedVertex> V=G.getVertices();
   pair<map<WeightedVertex,int>,map<WeightedVertex,WeightedVertex>> //first=distance from source to vertice, second= pi values
      result=getSSSP( G , *(V.begin()) );

    //Show the distances from the source
    cout << "Distances from " << *(V.begin()) << ": ";
    for( auto v : V )
        cout << result.first[v] << " ";
    cout << endl;

    // Show the path
     cout << "Solution: ";
     showPath( result.second , *(V.begin()) , *(V.rbegin()));
     cout << endl;

    cout << result.first[*(V.rbegin())] << endl;

   return 0;
}
