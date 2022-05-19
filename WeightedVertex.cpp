#include "WeightedVertex.h"

using namespace std;
// CLASS IMPLEMENTATION
WeightedVertex::WeightedVertex(unsigned nodeNumber, unsigned weight){
  setNodeNumber(nodeNumber);
  setNodeWeight(weight);
}
//getter
unsigned WeightedVertex::getNodeNumber(){
  return nodeNumber;
}

unsigned WeightedVertex::getNodeWeight(){
  return weight;
}

//setters
void WeightedVertex::setNodeNumber( unsigned vertexLabel){
  nodeNumber = vertexLabel;
}

void WeightedVertex::setNodeWeight( unsigned vertexWeight){
  weight =  vertexWeight;
}
//comparison operator overloaded
bool operator< (const WeightedVertex &lhs,const WeightedVertex &rhs){
  if(lhs.getNodeWeight() < rhs.getNodeWeight()){ //do this by id not weight
    return true;
  }
  return false;
}

bool operator> (const WeightedVertex &lhs,const WeightedVertex &rhs){
  if(lhs.getNodeWeight() > rhs.getNodeWeight()){ //do this by id not weight
    return true;
  }
  return false;
}


WeightedVertex::~WeightedVetex();
//constructor?
