// Graph.h

/*
In an attempt to model graphs better, in this lab you will use a C++ set container to represent the set of vertices and a C++ multimap to represent the set of edges. To match our CLRS text notation more closely, you will define a typedef based on a struct called Graph that contains the set and multimap objects that represent the set of vertices and set of edges, respectively.

Using the array of vectors representation used by GeeksForGeeks as a reference, you are to implement

a typedef of a struct called Graph that contains a set object and a multimap object to represent a graph (assume all vertices are unsigned values);
an implementation of the addEdge() function that adds an edge between two vertices (note that if any vertex currently does not exist in the set of vertices for the graph, then this vertex must be added as well); and
an overload of operator<< to "display'" a graph as shown in the sample output below.
You will only need to complete a file named Graph.h below that implements the three items identified above.
*/

#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

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
    if (esize != 0){ //esize-1???
      cout << ",";
    }
  }
  cout << "}";
  return os;
}
