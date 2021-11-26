#include "image.hpp"

//Creates a Quad Tree Node
node* new_node(){
    node * tree_node = new node;
    tree_node->is_leaf=false;
    tree_node->pixel_gray_value=0;
    tree_node->top=0;
    tree_node->left=0;
    tree_node->bottom=0;
    tree_node->right=0;
    tree_node->north_west=NULL;
    tree_node->north_east=NULL;
    tree_node->south_east=NULL;
    tree_node->south_west=NULL;
   return tree_node;
 }
 
//Add pixel values and number of rows and cols in original image
 void add_values(node* q, int *p, int num_rows, int num_cols){
    q->p=p;
    q->prows=num_rows;
    q->pcols=num_cols;
    q->bottom=0;
    q->top=num_rows-1;
    q->left=0;
    q->right=num_cols-1;
}

//splits a quad tree node into 4 smaller nodes with corresponding pixel values
void split_node(node * q)
{
    int top=q->top;
    int left=q->left;
    int bottom=q->bottom;
    int right=q->right;
    bool noSouth=(top==bottom);
    bool noEast=(left==right);
    
    
    q->north_west=new_node();
    q->north_west->p=q->p;
    q->north_west->prows=q->prows;
    q->north_west->pcols=q->pcols;
    q->north_west->bottom=bottom;
    q->north_west->top=(top+bottom)/2;
    q->north_west->left=left;
    q->north_west->right=(left+right)/2;
    
    if(!noEast){
        q->north_east=new_node();
        q->north_east->p=q->p;
        q->north_east->prows=q->prows;
        q->north_east->pcols=q->pcols;
        q->north_east->bottom=bottom;
        q->north_east->top=(bottom+top)/2;
        q->north_east->left=(left+right)/2+1;
        q->north_east->right=right;
    }
    
    
    if(!noSouth){
        q->south_west=new_node();
        q->south_west->p=q->p;
        q->south_west->prows=q->prows;
        q->south_west->pcols=q->pcols;
        q->south_west->bottom=(top+bottom)/2+1;
        q->south_west->top=top;
        q->south_west->left=left;
        q->south_west->right=(left+right)/2;
    }
    
    if(!noEast && !noSouth){
        q->south_east=new_node();
        q->south_east->p=q->p;
        q->south_east->prows=q->prows;
        q->south_east->pcols=q->pcols;
        q->south_east->bottom=(bottom+top)/2+1;
        q->south_east->top=top;
        q->south_east->left=(left+right)/2+1;
        q->south_east->right=right;
    }
    
    
    
}


float avg_pxvalue(node* q){
    float total=0;
    int right=q->right;
    int left=q->left;
    int top=q->top;
    int bottom=q->bottom;
    int total_cells = (right-left+1)*(top-bottom+1);
    int pcols = q->pcols;
    for(int r =bottom; r <= top; r++){
        for(int c=left; c <= right; c++){
            total += q->p[r*pcols+c];
        }
    }
    float average = (total)/float(total_cells);
    return average;
}


float pixel_variance(node* q){
    float average = avg_pxvalue(q);
    
    float total_dev=0;
    int right=q->right;
    int left=q->left;
    int top=q->top;
    int bottom=q->bottom;
    int total_cells = (right-left+1)*(top-bottom+1);
    int pcols = q->pcols;
    for(int r = bottom; r <= top; r++){
        for(int c=left; c <= right; c++){
            total_dev += (average - q->p[r*pcols+c])*(average - q->p[r*pcols+c]);
        }
    }
    float dev = total_dev/total_cells;
    return dev;
}

//builds the quad-tree based on the specified maximum pixel value variance
//splits starting node and successive nodes into child nodes
void build_quad_tree(node * q, int limit)
{
    if(q==NULL)//base case or new quad tree
    {
        return;
    }
    float var = pixel_variance(q);
    
    if(var>limit)
    {
    split_node(q);
    build_quad_tree(q->north_west,limit);
    build_quad_tree(q->north_east,limit);
    build_quad_tree(q->south_east,limit);
    build_quad_tree(q->south_west,limit);
    }
    else{
        q->is_leaf=true;
        float avg=avg_pxvalue(q);
        q->pixel_gray_value=avg;
    }
}

void make_matrix(node* root, cv::Mat& modified, int total_rows, int total_cols)
{
    if(root==nullptr)
        return;
    
    if(root->is_leaf)
    {
        int right=root->right;
            int left=root->left;
        int top=root->top;
            int bottom=root->bottom;
            int pixel_value=root->pixel_gray_value;
            for(int r =bottom; r <= top; r++){
                for(int c=left; c <= right; c++){
                    modified.at<uint8_t>(r,c)=pixel_value;
                }
            }   
    }
    else{
    make_matrix(root->north_west, modified, total_rows, total_cols);
        make_matrix(root->north_east, modified, total_rows, total_cols);
        make_matrix(root->south_west, modified, total_rows, total_cols);
        make_matrix(root->south_east, modified, total_rows, total_cols);
    }       
}

int new_pixels_count(node* root){
    if (root == NULL){
        return 0;
    }
    if (root->is_leaf){
        return 1;
    }
    else{
        return new_pixels_count(root->north_west)+new_pixels_count(root->north_east)+new_pixels_count(root->south_west)+new_pixels_count(root->south_east);
    }
}
