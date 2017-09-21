/*

    Given a binary search tree (aka an "ordered binary tree"),
    iterate over the nodes to print them out in increasing
    order. So the tree...
      2
     / \
     1 3
     /  \
     0   5
    Produces the output "0 1 2 3".

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"


/*
Utility functions in tree.h

void printTree(tree* node)
{
    //1. base case: node is empty
    if(node == NULL)
    {
        return;
    }
    else
    {
        //2. recur left, print node, recur right
        printTree(node->left);
        printf("%i ", node->data);
        printTree(node->right);
    }
}


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


*/


int main(void)
{
    //build tree
    tree* root = build123();
    insert(root, 0);
    insert(root, 4);
    insert(root, 5);

    printTree(root);
    printf("\n");
}