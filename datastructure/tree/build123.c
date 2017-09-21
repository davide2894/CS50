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

*/



int main(void)
{
    //build a Binary Search Tree with a root(2), a left branch(1) and a right branch(3);
    tree* root = build123();
    printf("root->data = %i\n root->left->data %i\n root->right->data %i\n", root->data, root->left->data, root->right->data);
}