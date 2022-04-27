// Graph.h

#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Define your typedef for the struct here (from our 23.1 LAB)
typedef struct Graph{
  set<unsigned> sVertices;    //set object to hold our vertices in the graph
  multimap<unsigned,unsigned> mEdges;  //multimap object to represent a graph
};

//A utility function to sort edges in a graphs
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
// undirected graph (from our 23.1 LAB)
void addEdge(Graph& gAdd, unsigned u, unsigned v){
  //think make pair (1,4) this represents an edge between 1-4
  gAdd.sVertices.insert(u);//just a list of all the vertices I have in graph
  gAdd.sVertices.insert(v);//just a list of all the vertices I have in graph
  gAdd.mEdges.insert(make_pair(u,v));// makepair u,v
  gAdd.mEdges.insert(make_pair(v,u));// makepair v,u
  edgesToSort(gAdd.mEdges);

}

// Overloaded operator<< to "display" a graph (from our 23.1 LAB)
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




// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFS(multimap<int,bool> mvVisted){
  for( auto u = mvVisted.begin(); u != mvVisted.end(); u++){  //iterate through the vertices initialized to fals because they havent been visted
    //cout <<"we made it inside the DFS"<<endl;
    if( u->second == false){
      //cout <<"u second1 =="<< u->second << endl;
      u->second = true;
      //cout <<"u second2 =="<< u->second << endl;
      DFS(mvVisted);    //we are seg faulting here

      //cout << "we made it out of the recursive DFSUtil call" << endl;
    }
  }
}
// Function that does DFS() for all
// unvisited vertices.
void DFSUtil(multimap<int,bool> mvVisted){

  for (auto i=mvVisted.begin(); i != mvVisted.end(); i++){
    if( i->second == false){
      DFS(mvVisted);
    }

  }

}
// Function that determines whether a given graph
// is connected or not. map each node to visited status multimap
bool connected(Graph const &gConnect){
  multimap<int, bool> mvistedVertex;  //make container to hold node and visited status
  bool connectedResult;
  for(auto i = gConnect.sVertices.begin(); i!= gConnect.sVertices.end();i++ ){
    mvistedVertex.insert(make_pair(*i,false));
  }
  //cout << "we made it into the connected function" << endl;
  DFSUtil(mvistedVertex);//dfs is called once passing the container by reference
  //cout << "we made it out of DFS in connected function" << endl;
  for(auto i = mvistedVertex.begin(); i != mvistedVertex.end(); i++){

    if ( i->second == false)
    {
      connectedResult = false;
    }
    else
      connectedResult = true;
  }
  if(mvistedVertex.size() == 0){
    connectedResult = true;
  }
  return connectedResult;
// check the updated values
//one false we return false

}
