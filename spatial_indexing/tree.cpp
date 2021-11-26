//File Guards to prevent multiple times include
#ifndef test
#define test
//#include "iostream"


#include "tree.h"

//A simple function to return |x|
int absolute_value_fun(int x) {
    if (x < 0)
        x = -x;
    return x;
}

//Constructor for empty Quad Tree
Quad::Quad() {
    botLeft = coordinates(0, 0);
    topRight = coordinates(0, 0);
    n = nullptr;
    topLeftTree = nullptr;
    topRightTree = nullptr;
    botLeftTree = nullptr;
    botRightTree = nullptr;
}

//Constructor for boundary defined Quad Tree
Quad::Quad(coordinates botL, coordinates topR) {
    n = nullptr;
    topLeftTree = nullptr;
    topRightTree = nullptr;
    botLeftTree = nullptr;
    botRightTree = nullptr;
    botLeft = botL;
    topRight = topR;
}

//Insert a node into quad tree
void Quad::insert(Node *_node) {
    if (_node == nullptr)
        return;
    //If quad tree cannot contain the node (due to boundary conditions) then return
    if (!inboundary(_node->loc))
        return;
    
    // We are at a quad of unit area. We cannot subdivide this quad further and insert into this
    if (absolute_value_fun(botLeft.x - topRight.x) <= 1 && (absolute_value_fun(botLeft.y - topRight.y) <= 1)) {
        if (n == nullptr)
            n = _node;
        return;
    }
   // std::cout<<std::endl<<"Debug "<<((botLeft.x + topRight.x) / 2>(_node->loc.x))<<"\n";//some debugging
    
    //We check if x coordinate of node is less than equal to x coordinate of centre square, if so it will lie on left side of square else on right side
    if ((botLeft.x + topRight.x) / 2 >= _node->loc.x) {
        //We check if y coordinate of given node is greater than equal to y coordinate of centre of square, if so it will lie on upper side of square else in bottom.
        if ((botLeft.y + topRight.y) / 2 <= _node->loc.y) {
            //If the  corresponding child is null we declare a new child for it
            if (topLeftTree == nullptr) {
                topLeftTree = new Quad(coordinates(botLeft.x, (botLeft.y + topRight.y) / 2),
                                       coordinates((botLeft.x + topRight.x) / 2, topRight.y));
            }
            //We recursively call insert on the child that should contain the node
            topLeftTree->insert(_node);

        } else {
            if (botLeftTree == nullptr)
                botLeftTree = new Quad(coordinates(botLeft.x, (botLeft.y)),
                                       coordinates((botLeft.x + topRight.x) / 2, (botLeft.y + topRight.y) / 2));
            botLeftTree->insert(_node);

        }
    } else {
        if ((botLeft.y + topRight.y) / 2 <= _node->loc.y) {
            if (topRightTree == nullptr)
                topRightTree = new Quad(coordinates((botLeft.x + topRight.x) / 2, (botLeft.y + topRight.y) / 2),
                                        coordinates(topRight.x, topRight.y));
            topRightTree->insert(_node);

        } else {
            if (botRightTree == nullptr)
                botRightTree = new Quad(
                        coordinates((botLeft.x + topRight.x) / 2, botLeft.y),
                        coordinates(topRight.x, (botLeft.y + topRight.y) / 2));
            botRightTree->insert(_node);

        }
    }
}

Node *Quad::search(coordinates point) {
    //If point is outside boundary directly return null
    if (!inboundary(point))
        return nullptr;
    //base case. when we reach a node of unit area i.e. leaf node we return its pointer.
    if (n != nullptr)
        return n;
    //Now simmilar to insert function we recurisvely call search on one of the four children based on the x and y coordinates of nodes to be searched.
    
    if ((botLeft.x + topRight.x) / 2 >= point.x) {
        if ((botLeft.y + topRight.y) / 2 > point.y) {
            if (botLeftTree == nullptr)
                return nullptr;
            return botLeftTree->search(point);
        } else {
            if (topLeftTree == nullptr)
                return nullptr;
            return topLeftTree->search(point);
        }
    } else {
        if ((botLeft.y + topRight.y) / 2 > point.y) {
            if (botRightTree == nullptr)
                return nullptr;
            return botRightTree->search(point);
        } else {
            if (topRightTree == nullptr)
                return nullptr;
            return topRightTree->search(point);
        }
    }
}

//Checks if a point lies in the boundary of square by comparing x and y coordinate
bool Quad::inboundary(coordinates point) {
    return (point.x >= botLeft.x && point.x <= topRight.x && point.y >= botLeft.y && point.y <= topRight.y);
}

#endif
