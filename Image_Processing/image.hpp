#ifndef qtree_hpp
#define qtree_hpp
#include<iostream>
#include <stdio.h>
#include <opencv2/highgui.hpp>

using namespace std;

typedef struct node{
	bool is_leaf;
	int pixel_gray_value;
	int * p;
	
	//x coordinate of left edge and right edge. y coordinate of top edge and bottom edge.
	int top;
	int left;
	int bottom;
	int right;
	
	//Constant parameters in every node i.e.  rows and cols in original image
       int prows;
       int pcols;
       
	//four children
	node* north_west;
    	node* north_east;
    	node* south_east;
    	node* south_west;
}node;

//Creates a new quad tree node 
node* new_node();

//add pixel values prows and and pcols
void add_values(node* q, int* p, int num_rows, int num_cols);

//splits a qt_node into 4 smaller nodes with corresponding pixel values
void split_node(node* q);

//calculates the average pixel value in the assigned range.
float avg_pxvalue(node* q);

//gets the variance in the range of q
float pixel_variance(node* q);

//builds the quad-tree based on the specified maximum pixel value variance
//splits starting node and successive nodes into child nodes
void build_quad_tree(node* root, int var);


//Unpacks the tree data into an OpenCV Matrix structure
void make_matrix(node*start, cv::Mat& modified, int total_rows, int total_cols);

//counts leaf nodes of an already built tree. An approximate of new pixels
int new_pixels_count(node* root);

#endif
