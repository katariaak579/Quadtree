#ifndef QUAD_TREES_coordinates_H
#define QUAD_TREES_coordinates_H

struct coordinates {
    int x;
    int y;

    //Method to access data members of the struct coordinates.
    //The first method initializes with two given x,y values while the second intialises with 0,0 if no arguments are provided
    coordinates(int _x, int _y) {
        x = _x;
        y = _y;
    }

    coordinates() {
        x = 0;
        y = 0;
    }
};

#endif
