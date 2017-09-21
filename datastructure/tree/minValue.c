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


tree* insert(tree* node, int data)
{

    //1. base case = if the root is empty
    //   return a new single node
    if(node == NULL)
        return buildNewNode(data);
    else
    {
        //2. recur down the correct tree
        if(data < node->data)
             node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
    }

    return node; //return the unchanged root pointer
}


int minValue(tree* node)
{
    //1. base case: min value is found when tree->left is empty
    //   i.e. there is no lesser value
    if(node->left == NULL)
        return node->data;
    else
    {
        //2. otherwise search on left side recursively
        return (minValue(node->left));
    }
}

*/



int main(void)
{
    //build tree
    tree* node = build123();
    insert(node, 0);
    insert(node, 4);
    insert(node, 2);
    insert(node, 5);

    //find min value
    int minVal = minValue(node);

    printf("min value in tree is %i\n", minVal);


}