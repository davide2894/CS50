/*
    Given a binary tree and a sum, return true
    if the tree has a root-to-leaf path such
    that adding up all the values along the
    path equals the given sum
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

/*

tree* build123()
{
    tree* root = buildNewNode(2);
    root->left = buildNewNode(1);
    root->right = buildNewNode(3);
    return root;
}


int hasPathSum(tree* node, int sum)
{
    //1. base case: node is empty and sum == 0
    if(node == NULL)
    {
        return(sum == 0);
    }
    else
    {
        //2. recurse case: check subtrees
        int subSum = sum - node->data;
        return( hasPathSum(node->left, subSum) ||
                  hasPathSum(node->right, subSum) );
    }
}

*/


int main(void)
{
    //build tree
    tree* root = build123();
    int sumPath = 5;


    if(hasPathSum(root, sumPath))
        printf("there is a path\n");
    else
        printf("no path in this tree\n");
}