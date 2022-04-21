// Graph.h

#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

// Insert any code you need from your prior lab(s) here ...
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

void edgesToSort( multimap<unsigned,unsigned>& gToSort ){
  vector <pair <unsigned,unsigned>> pSorted; //vector?
  for(auto it3 = gToSort.begin(); it3!=gToSort.end();it3++){
    pSorted.push_back(make_pair(it3->first,it3->second)); //copy from mEdges
  }
  sort(pSorted.begin(),pSorted.end());    //run sort,
  gToSort.clear();   //clear mEdges,

  for(auto i = 0;i<pSorted.size();i++)
  {  gToSort.insert(pSorted[i]);    //then insert into mEdges

  }

}
// A utility function to add an edge in an
// undirected graph.
void addEdge(Graph& gAdd, unsigned u, unsigned v){
  //think make pair (1,4) this represents an edge between 1-4
  gAdd.sVertices.insert(u);//just a list of all the vertices I have in graph
  gAdd.sVertices.insert(v);//just a list of all the vertices I have in graph
  gAdd.mEdges.insert(make_pair(u,v));// makepair u,v
  gAdd.mEdges.insert(make_pair(v,u));// makepair v,u
  edgesToSort(gAdd.mEdges);

}

// Overloaded operator<< to "display" a graph.
 ostream& operator<< (ostream &os, const Graph& gPrint) {
  //if(gPrint.sVertices.size()==0){ return os;}
  int vsize = gPrint.sVertices.size(),
      esize = gPrint.mEdges.size() ;

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
    os << "(" << it->first << "," << it->second << ")";
    esize--;
    if (esize != 0){
      os << ",";
    }
  }
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
      if (its->second == it->second) {canInsert=false;}
      }

    if(canInsert) {catenatedGraph.mEdges.insert(uPair);}

  }
  edgesToSort(catenatedGraph.mEdges);
  return catenatedGraph;
}

// Overloaded operator- to implement difference of two graphs if element is also in rhs remove it return lhs

Graph operator-(Graph const &lhs, Graph const &rhs){
  Graph differGraph;

  for(auto itl=lhs.sVertices.begin(); itl!=lhs.sVertices.end();itl++){       //itterate through the lhs
      bool canInsert = true;
    for (auto itr=rhs.sVertices.begin(); itr!=rhs.sVertices.end(); itr++){   //itterate through the rhs

        if (*itr == *itl) {
          canInsert=false;
          break;
        }                   //if the rhs graph's (u,v) v member is equal to the lhs v member don't insert


      if(canInsert) {differGraph.sVertices.insert(*itr);}

    }
  }

  for (auto itl=lhs.mEdges.begin(); itl!=lhs.mEdges.end(); itl++){
    for (auto itr=rhs.mEdges.begin(); itr!=rhs.mEdges.end(); itr++){
      pair <unsigned,unsigned> uPair = make_pair(itr->first,itr->second);
      auto mdiffChk = differGraph.mEdges.equal_range(itr->first);
      bool canInsert = true;
      for (auto itd=mdiffChk.first; itd!=mdiffChk.second; ++itd)
        {
        if (itr->second == itl->second) {
          canInsert=false;
          break;
          }
        }

      if(canInsert) {differGraph.mEdges.insert(uPair);}

    }
  }
  return differGraph;

}
