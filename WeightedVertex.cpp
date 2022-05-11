#include "WeightedVertex.h"

// CLASS IMPLEMENTATION

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

//constructor?
