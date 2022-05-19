// Graph template class - allows for different vertex types

#ifndef _MY_GRAPH_CLASS_
#define _MY_GRAPH_CLASS_

#include <set>
#include <map>

#include "WeightedVertex.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// CLASS DEFINITION/PROTOTYPE   how do I implement this?!?
template <typename  T>
class Graph {
private:
//WeightedVertex look at the struct,
  set<WeightedVertex> sVertices;
  map<WeightedVertex,map<WeightedVertex,int>> mEdges;    //int == weight, 1st WeightedVertex = source 2nd WeightedVertex = destination

public:
//constructor
Graph(string name){}

//getNumVertices(): returns the number of vertices in the graph
  int getNumVertices() const {
    sVertices.size();
    return sVertices.size();
  }
//getNumEdges(): returns the number of edges in the graph
  int getNumEdges() const {
    return mEdges.size();
  };
~Graph (){};
/*
//add(WeightedVertex source, unsigned destination, int edgeWeight=1): adds an edge between vertices source and destination with weight edgeWeight (which defaults to 1)
  bool add(WeightedVertex source, WeightedVertex destination, int edgeWeight=1){

    auto foundSource = this.sVertices.find(source);   //have we added the source vertex already?
    auto foundDestination = this.sVertices.find(destination); //have we added the destination vertex already?

    if(foundSource == this.end())   //returns true if source isn't found, meaning we need to add the Vertex
    {
        this.sVertices.insert(source);     //insert the vertices that didn't exsist before
    }

    if(foundDestination == this.end()){   //returns true if source isn't found, meaning we need to add the Vertex
      this.sVertices.insert(destination);
    }

    this.mEdge.insert(make_pair(source,destination));    //adding the edge only if statements returns false, meaning we didn't find this edge to already exist
    added = true;

    return added;
  }
//remove(unsigned source, unsigned destination): removes the edge between vertices source and destination, if it exists
  bool remove(WeightedVertex source, WeightedVertex destination){
    bool removed = false,
         canRemove = false,
         soloVertex = false;

    auto foundSource = this.sVertices.find(source);
    auto foundDestination = this.sVertices.find(source);

//checking to see if an edge exsists between the source and destination vertex
    auto range = this.mEdges.equal_range(source)
    for(auto i = range.first; i != range.second; i++){
      if (destination == i->second){
        canRemove == true;             //condition is set to true because we found the edge exsits between source and destination, meaning we need to remove the edge
      }
    }
    if(foundSource != this.end()){   //returns true if source is found, meaning we might need to remove the Vertex
  //checks to see if there are any other edges to this vertex, if not soloVertex == true HOW DO I DO THIS?
      auto range = this.mEdges.equal_range(source);
      for(auto i = range.first; i != range.second; i++){
        if(i->second == destination){      //returns true if there is an edge between the source and destination vertex
//remove edges some how

        }
      }
      //map[1][2] example or destination.weight syntax could be used
      if(soloVertex){  //returns true if the vertex has no other edges, ok to remove vertex if so
          this.sVertices.erase(source);
        }    //insert the vertices that didn't exsist before
    }

    if(foundDestination != this.end()){   //returns true if source is found, meaning we need to remove the Vertex as well as the Edge
      this.sVertices.erase(destination);
    }

    if(canRemove){
      this.mEdges.erase(); //HOW DO I ACTUALLY ERASE?
    }
    return removed;
  }
//getEdgeWeight (unsigned source, unsigned destination): returns the weight of the edge between vertices source and destination, if it exists; otherwise, it just returns 0
  unsigned getEdgeWeight(WeightedVertex source, WeightedVertex destination){
    //checking to see if an edge exsists between the source and destination vertex
        auto range = this.mEdges.equal_range(source)
        for(auto i = range.first; i != range.second; i++){
          if (destination == i->second){  //returns true if the edge exsists...return the wieght if so

          return i->weight ;
        }

        return 0; //If we don't have an edge between source and destination we return 0
  }
//getVertices(): returns a set containing the vertices in the graph
  set <WeightedVertex> getVertices(){
    set<WeightedVertex> vertsInGraph;

    for(auto i = this.sVertices.begin(); i != this.sVertices.end(); i++){   //itterate through all vertices in the object that called this function "this"
      vertsInGraph.insert(*i);   //inserting the node into our locally declared set of vertices

    }

    return vertsInGraph;
  }
//getAdjacent(unsigned v): returns a set containing the vertices in the graph that are adjacent to a given vertex
  set <WeightedVertex> getAdjacent(WeightedVertex v) {
    set<WeightedVertex> adjVerts;

    auto range = this.mEdges.equal_range(v);
    for( auto i = range.first; i != range.second; i++){ //itterate through range of v vertices to find adjacent vertices
    auto adj = i->second.second;
    adjVerts.insert(adj);
    }
  return adjVerts;

  }
*/};


// CLASS IMPLEMENTATION



#endif
