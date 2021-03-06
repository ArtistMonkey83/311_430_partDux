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
#include <algorithm>

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
      esize = gPrint.mEdges.size();
      //setSize = 0;

  os << "Graph has " << vsize <<" vertices and " << esize <<" edges." <<endl;
  os << "  V={";
  for(auto it=gPrint.sVertices.begin(); it!=gPrint.sVertices.end();it++){
    os << *it;
    vsize--;
    if (vsize!= 0){
      os <<",";
    }
  }
  os << "}"<<endl;

  os <<"  E={";
  for (auto it=gPrint.mEdges.begin(); it!=gPrint.mEdges.end(); it++){
    unsigned ascending = gPrint.mEdges.count(it->first);  // use gprint.mEdges.count(it->first) here
    //pair <unsigned,unsigned> ascendingPair;
    set <unsigned> sSorted;
      if(ascending >1){   // if that count is > 1

        auto ascendingPair = gPrint.mEdges.equal_range(it->first);    //  use equal_range(it->first) here for all pairs with same it->first values
        for(auto it2 = ascendingPair.first; it2!= ascendingPair.second;it2++){
          sSorted.insert(it2->second);      //    push 2nd items of all those pairs into a set by iterating over the equal range so that the different 'it->second's get sorted
          //setSize++;
        //  os<< "setSize: " <<setSize;
          //os<< "esize: " <<esize;
        }

        for(auto iter = sSorted.begin(); iter!=sSorted.end();iter++){   //    iterate over newly created set and os << it->first << curr_set_item << endl;
          os << "(" << it->first << "," << *iter << ")";
          it++;
          esize--;

           if (esize > 1){os << ",";}
        }
        //esize=- ascending;
        //setSize=0;
      }
      else{
        esize--;
        os << "(" << it->first << "," << it->second << ")";
         if (esize > 2){os << ",";}
      }

  }
//os << "esize is: "<< esize;
  os << "}";
  return os;
}

// Overloaded operator+ to implement union of two graphs
Graph operator+(Graph const &lhs, Graph const &rhs) {
  Graph catenatedGraph;

  for(auto it=lhs.sVertices.begin(); it!=lhs.sVertices.end();it++){
    catenatedGraph.sVertices.insert(*it);
  }

  for(auto it=rhs.sVertices.begin(); it!=rhs.sVertices.end();it++){
    catenatedGraph.sVertices.insert(*it);
  }

  for (auto it=lhs.mEdges.begin(); it!=lhs.mEdges.end(); it++){

      catenatedGraph.mEdges.insert(make_pair(it->first,it->second));
  }

  for (auto its=rhs.mEdges.begin(); its!=rhs.mEdges.end(); its++){
    pair <unsigned,unsigned> uPair = make_pair(its->first,its->second);
    auto errorChk = catenatedGraph.mEdges.equal_range(its->first);
    bool canInsert = true;
    for (auto it=errorChk.first; it!=errorChk.second; ++it)
      {
      if (its->second == it->second){
        canInsert=false;
      }


    }
    //if(errorChk.first != errorChk.second){
    if(canInsert){
        catenatedGraph.mEdges.insert(uPair);
    }

    //
    //

  }
  return catenatedGraph;
}
