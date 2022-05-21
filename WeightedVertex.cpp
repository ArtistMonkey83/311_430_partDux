#include "WeightedVertex.h"

using namespace std;
// CLASS IMPLEMENTATION
WeightedVertex::WeightedVertex(unsigned nodeNumber, unsigned weight){
  nodeNumber = nodeNumber;
  weight = weight;
}

//comparison operator overloaded
bool operator< ( WeightedVertex lhs, WeightedVertex rhs){
  if(lhs.getNodeNumber() < rhs.getNodeNumber()){ //do this by id not weight
    return true;
  }
  return false;
}

bool operator> ( WeightedVertex lhs, WeightedVertex rhs){
  if(lhs.getNodeNumber() > rhs.getNodeNumber()){ //do this by id not weight
    return true;
  }
  return false;
}


WeightedVertex::~WeightedVertex(){}
