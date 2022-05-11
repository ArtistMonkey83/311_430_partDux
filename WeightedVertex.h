// A weighted vertex class

#ifndef _MY_WEIGHTED_VERTEX_CLASS_
#define _MY_WEIGHTED_VERTEX_CLASS_

//what we need to define a weighted graph
class WeightedVertex{
private:
  unsigned nodeNumber,
           weight;    //weight
public:
  unsigned getNodeNumber();
  unsigned getNodeWeight();
  unsigned setNodeNumber(unsigned vertexLabel);
  unsigned setNodeWeight(unsigned vertexWeight);
//map for holding the following?
//node number something.number
//distance (wieght) something.distance ?
};


#endif
