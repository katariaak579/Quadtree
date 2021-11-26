#include "coordinates.h"
#include "Node.h"
#ifndef QUAD_TREES_TREE_H
#define QUAD_TREES_TREE_H
class Quad
{
    //Boundary Value of the node
    coordinates botLeft;//x coordinate of left edge of square, y coordinate of bottom edge of square
    coordinates topRight;//x coordinate of right edge of square, y coordinate of top edge of square
    
    //Contains details of this node
    Node*n;
    
    //The below four pointers are refferences to its four children
    Quad *topLeftTree;
    Quad *topRightTree;
    Quad *botLeftTree;
    Quad *botRightTree;
public:
    //We declare all functions of Quad class here and implement them in tree.cpp to beautify the code
    Quad();
    Quad(coordinates botL,coordinates topR);
    void insert(Node*);
    bool inboundary(coordinates);
    Node* search(coordinates);
};

#endif //QUAD_TREES_TREE_H
