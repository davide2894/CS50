#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

/*
Utility functions defined in tree.h

tree* build123()
{
    tree* root = buildNewNode(2);
    root->left = buildNewNode(1);
    root->right = buildNewNode(3);
    return root;
}

int size(tree* node)
{
    //1. node is empty
    if(node == NULL)
        return 0;
    else
    {
        //2. recur down the tree and count the size
        //size of left sub-branch + size of right sub-branch +1(brach head)
        return ( size(node->left) + size(node->right) + 1);
    }
}


*/



int main(void)
{
    //Given a binary tree, count the number of nodes in the tree

    //build tree
    tree* root = build123();

    //calucalte size by using a recursive method
    int n = size(root);

    //display size
    printf("%i\n", n);
}