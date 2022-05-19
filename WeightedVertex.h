// A weighted vertex class

#ifndef _MY_WEIGHTED_VERTEX_CLASS_
#define _MY_WEIGHTED_VERTEX_CLASS_

//what we need to define a weighted graph
class WeightedVertex{
private:
  unsigned nodeNumber;
  unsigned weight;    //weight
public:
  WeightedVertex(unsigned nodeNumber, unsigned weight);
  ~WeightedVertex();

  unsigned getNodeNumber();
  unsigned getNodeWeight();
  void setNodeNumber(unsigned vertexLabel);
  void setNodeWeight(unsigned vertexWeight);
//map for holding the following?
//node number something.number
//distance (wieght) something.distance ?
};


#endif
