#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

/*
Utility functions defined in tree.h

int maxDepth(tree* tree)
{
    //1. base case: tree is empty
    if(tree == NULL)
    {
        return 0;
    }
    else
    {
        //2. get max right and left depth
        int lMaxDepth = maxDepth(tree->left);
        int rMaxDepth = maxDepth(tree->right);

        //3. compare the two depths and choose the bigger one
        if(lMaxDepth > rMaxDepth)
        {
            int maxDepth = lMaxDepth + 1; //1 for the head
            return maxDepth;
        }
        else
        {
            int maxDepth = rMaxDepth + 1;
            return maxDepth;
        }
    }
}


tree* build123()
{
    tree* root = buildNewNode(2);
    root->left = buildNewNode(1);
    root->right = buildNewNode(3);
    return root;
}

*/

int main(void)
{
    //create tree
    tree* root = build123();

    //calculate tree's depth
    int depth = maxDepth(root);

    //display it
    printf("depth = %i\n", depth);
}