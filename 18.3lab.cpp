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

 return os;
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(unsigned node,map<unsigned,bool> &mvVisted, Graph const &gToSort,vector<unsigned> &topoList){
  mvVisted[node] = true;
  auto range=gToSort.mEdges.equal_range(node);
  for( auto u = range.first; u != range.second; u++){  //iterate through the vertices initialized to false because they havent been visted
    //condition to check that you are in range first
  if((u->first == node) && (mvVisted[u->second] == false)){
    DFSUtil(u->second,mvVisted,gToSort,topoList);
      topoList.insert(topoList.begin(),u->second);
      }
  }
  return;
}

// Function that does DFS() for all
// unvisited vertices.
void DFS(map<unsigned,bool> &mvVisted,Graph const &gToSort,vector<unsigned> &topoList){
  for (auto i=mvVisted.begin(); i != mvVisted.end(); i++){    //checking to see if the adjacent vertices have been visted
    if( i->second == false){  // the false value means we have not visted this vertex
      DFSUtil(i->first,mvVisted,gToSort,topoList);  //recursively call DFS on adjacent vertices
      topoList.insert(topoList.begin(),i->first); //we come back from the recursive call and that vertex is now "black"/finsihed insert it
    }
  }
}

// Code for topologicalSort() function goes here ... in the lab it was referred to as fillOrder()... effciently reusing code instead of redesigning the wheel!
vector<unsigned> topologicalSort(Graph const &gToSort){
  vector<unsigned> gSorted;   //This will hold the stack representing our tree starting at the root
  map<unsigned, bool> mvistedVertex;  //make container to hold node and visited status
  for(auto i = gToSort.sVertices.begin(); i!= gToSort.sVertices.end();i++ ){
    mvistedVertex[*i] = false;
  }
  DFS(mvistedVertex,gToSort,gSorted);
  return gSorted;
}

// transpose() function: takes a Graph and returns another Graph
// representing the first graph's transpose. flips edges
Graph transpose(Graph const &gToReverse){
  Graph transGraph;
  for(auto it = gToReverse.mEdges.begin(); it != gToReverse.mEdges.end(); it++){              //iterate through the edges of the graph passed from driving function "G"
    addEdge(transGraph,it->second,it->first);   //the transpose graph has edges (v,u) graph G from driver function has (u,v)!
  }
  return transGraph;  //we populated our local graph with vertices and reversed edges based off the graph passed from the driving function
}


// printSCCs() function: implements Kosaraju's SCC algorithm and displays
// vertices that belong to each SCC of a given digraph.
ostream& printSCCs(ostream &os, Graph const &gToPrint){
  unsigned counter = 1;
  vector<unsigned> stack = topologicalSort(gToPrint);    //holds the order in which we will visit the vertices for the transpose version.
  Graph trasnposeGraph = transpose(gToPrint);   //graph that is populated with reverse edges
  vector<unsigned> transStack = topologicalSort(trasnposeGraph); //stack for the transpose graph, this holds the list of vertices that have turned "black"/ no more adjacent unvisited "white" vertices
  for(auto i : transStack){
    os << "  SCC " << counter << " = " << i << " " <<endl;
    counter++;
  }
  return os;
}
