/*
Having successfully implemented a struct approach in representing graphs using a set of vertices and a multimap of edges, you are now ready to implement some additional operations on graphs.

Recall that for sets, say A = {1, 2, 3} and B = {2, 4, 6}, the following set operation is defined:

the union (denoted by ∪) of two sets A and B is the set of all elements in both A or B. Hence, for the sets A and B given above, A ∪ B = {1, 2, 3, 4, 6}.
Note that we can extend the definition of union on sets to graphs. Basically, given two graphs, A = (Va,Ea) and B = (Vb,Eb)

the union of two graphs A and B, denoted A + B, is the graph G = (Va ∪ Vb , Ea ∪ Eb ).
You will overload the operator+ to represent the union operation on graphs.
*/
// Graph.h

#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

// Insert any code you need from your prior lab(s) here ...
// Define your typedef for the struct here ...
typedef struct Graph{
  set<unsigned> sVertices;    //set object to hold our vertices in the graph
  multimap<unsigned,unsigned> mEdges;  //multimap object to represent a graph
};

// A utility function to add an edge in an
// undirected graph.
void addEdge(Graph& gAdd, unsigned u, unsigned v){
  //think make pair (1,4) this represents an edge between 1-4
  gAdd.sVertices.insert(u);//just a list of all the vertices I have in graph
  gAdd.sVertices.insert(v);//just a list of all the vertices I have in graph
  gAdd.mEdges.insert(make_pair(u,v));// makepair u,v
  gAdd.mEdges.insert(make_pair(v,u));// makepair v,u

}

// Overloaded operator<< to "display" a graph.
 ostream& operator<< (ostream &os, const Graph& gPrint) {
  //if(gPrint.sVertices.size()==0){ return os;}
  int vsize = gPrint.sVertices.size(),
      esize = gPrint.mEdges.size() ;

  cout << "Graph has " << vsize <<" vertices and " << esize <<" edges." <<endl;
  cout << "  V={";
  for(auto it=gPrint.sVertices.begin(); it!=gPrint.sVertices.end();it++){
    cout << *it;
    vsize--;
    if (vsize!= 0){
      cout <<",";
    }
  }
  cout << "}"<<endl;

  cout <<"  E={";
  for (auto it=gPrint.mEdges.begin(); it!=gPrint.mEdges.end(); it++){
    cout << "(" << it->first << "," << it->second << ")";
    esize--;
    if (esize != 0){
      cout << ",";
    }
  }
  cout << "}";
  return os;
}

// Overloaded operator+ to implement union of two graphs
Graph operator+(Graph const &lhs, Graph const &rhs){
  Graph catenatedGraph;

  for(auto it=lhs.sVertices.begin(); it!=lhs.sVertices.end();it++){
    catenatedGraph.sVertices.insert(*it);
  }

  for(auto it=rhs.sVertices.begin(); it!=rhs.sVertices.end();it++){
    catenatedGraph.sVertices.insert(*it);
  }

  for (auto it=lhs.mEdges.begin(); it!=lhs.mEdges.end(); it++){

      catenatedGraph.mEdges.insert(make_pair(it->first,it->second))


  }

  for (auto it=rhs.mEdges.begin(); it!=rhs.mEdges.end(); it++){
    //make_pair(it->first,it->second)
    if (catenatedGraph.mEdges.equal_range(it)==){
      catenatedGraph.mEdges.insert(make_pair(it->first,it->second))
    }
  }

  return catenatedGraph;
}


/* Overloaded operator- to implement difference of two graphs
Graph operator-(Graph const &lhs, Graph const &rhs){
  Graph differGraph;

  for(auto it=lhs.sVertices.begin(); it!=lhs.sVertices.end();it++){

  }

  for (auto it=lhs.mEdges.begin(); it!=lhs.mEdges.end(); it++){

  }
  return differGraph;

}
*/
