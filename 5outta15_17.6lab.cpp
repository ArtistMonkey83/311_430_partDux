// Graph.h

#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Insert any code you need from your prior lab(s) here ...

// Define your typedef for the struct here (from our 23.1 LAB)
typedef struct Graph{
  set<unsigned> sVertices;    //set object to hold our vertices in the graph
  multimap<unsigned,unsigned> mEdges;  //multimap object to represent a graph
};
//A utility function to sort edges in a graphs
void edgesToSort( multimap<unsigned,unsigned>& gToSort ){
  vector <pair <unsigned,unsigned>> pSorted; //vector?
  set<pair<unsigned,unsigned>> temp;
  for(auto it3 = gToSort.begin(); it3!=gToSort.end();it3++){
    temp.insert(make_pair(it3->first,it3->second)); //copy from mEdges
  }
  for(auto it2 = temp.begin(); it2!= temp.end(); it2++){
    pSorted.push_back(*it2);
  }
  sort(pSorted.begin(),pSorted.end());    //run sort,
  gToSort.clear();   //clear mEdges,

  for(auto i = 0;i<pSorted.size();i++)
  {  gToSort.insert(pSorted[i]);    //then insert into mEdges

  }
}
//  void verticesToSort( vector<unsigned> &vToSort ){

//    sort(vToSort.cbegin(),vToSort.cend());    //run sort,

//}

bool hasEdge(Graph g, unsigned u, unsigned v){
  auto range = g.mEdges.equal_range(u);
  for( auto i =range.first; i != range.second; i++){
    if(v==i->second){
      return true;
    }
  }
  return false;
}
// A utility function to add an edge in an
// DIRECTED GRAPH graph (from our 23.1 LAB)
void addEdge(Graph& gAdd, unsigned u, unsigned v){
  //think make pair (1,4) this represents an edge between 1-4
  gAdd.sVertices.insert(u);//just a list of all the vertices I have in graph
  gAdd.sVertices.insert(v);//just a list of all the vertices I have in graph
  if(!hasEdge(gAdd,u,v)){
    gAdd.mEdges.insert(make_pair(u,v));// makepair u,v
  }
  //if(!hasEdge(gAdd,v,u)){
    //gAdd.mEdges.insert(make_pair(v,u));// makepair v,u
  //}
  edgesToSort(gAdd.mEdges);


}
// Overloaded operator<< to "display" a graph (from our 23.1 LAB)
ostream& operator<< (ostream &os, const Graph& gPrint) {

 int vsize = gPrint.sVertices.size(),
     esize = gPrint.mEdges.size() ;

 os << "Digraph G has " << vsize <<" vertices and " << esize <<" edges:" <<endl;
 os << "  V={";
 for(auto it=gPrint.sVertices.begin(); it!=gPrint.sVertices.end();it++){
   os << *it;
   vsize--;
   if (vsize!= 0){
     os <<",";
   }
 }
 os << "}"<<endl;
 int counter=0;

 os <<"  E={";
 for (auto it=gPrint.mEdges.begin(); it!=gPrint.mEdges.end(); it++){
   os << "(" << it->first << "," << it->second << ")";
   esize--;
   counter++;
   if (esize != 0){
     os << ",";
   }
 }
 os << "}";
 //cout <<"counter has: " << counter <<endl;
 return os;
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(unsigned node,map<int,bool> &mvVisted, Graph const &gToSort,vector<unsigned> &topoList){
  mvVisted[node] = true;
  auto range=gToSort.mEdges.equal_range(node);
  for( auto u = range.first; u != range.second; u++){  //iterate through the vertices initialized to false because they havent been visted
    //condition to check that you are in range first
    if( mvVisted[u->second] == false){
      DFSUtil(u->second,mvVisted,gToSort,topoList);
    }
  }
  return;
}
// Function that does DFS() for all
// unvisited vertices.
void DFS(map<int,bool> mvVisted,Graph const &gToSort,vector<unsigned> &topoList){
  for (auto i=mvVisted.begin(); i != mvVisted.end(); i++){
    if( i->second == false){
      DFSUtil(i->second,mvVisted,gToSort,topoList);
    }
    topoList.insert(topoList.begin(),i->first);
  //  verticesToSort(topoList);
  }
}
// Code for topologicalSort() function goes here ...
vector<unsigned> topologicalSort(Graph const &gToSort){
  vector<unsigned> gSorted;   //This will hold the stack representing our tree starting at the root
  map<int, bool> mvistedVertex;  //make container to hold node and visited status
  for(auto i = gToSort.sVertices.begin(); i!= gToSort.sVertices.end();i++ ){
    mvistedVertex[*i] = false;
  }
  DFS(mvistedVertex,gToSort,gSorted);
//cout << "gsorted contains : " << gSorted.size() << " ";
  return gSorted;
}

