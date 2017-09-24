/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

//define node
typedef struct node
{
    bool is_word;
    struct node* children[27]; //26 letter + "\'" (apostrophe). impo: 27 node pointers
}
node;

node* root;

int wordCount = 0;


int getIndex(const char c)
{

    if(c == '\'')
    {
        return 26;
    }
    else
    {
        return ( tolower(c) - 97 ) ;
    }
}



/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{

    FILE* fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
        printf("Could not open %s\n", dictionary);

        unload();

        return false;

    }

    root = calloc(1, sizeof(node));

    node* current = root;

    for(int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {

        //if the character is not alphabetic
        if(c == '\n')
        {
            //end of word
            current->is_word = true;

            //set current back to root
            current = root;

            //increment word counter
            wordCount++;

        }
        //allow only alphabetic characters
        else
        {
            int c_index = getIndex(c);

            if(current->children[c_index] == NULL) //i.e. points to nothnig
            {
                //malloc a new node for the character
                node* newNode =(node*) calloc(1, sizeof(node));
                current->children[c_index] = newNode;
            }

            //move to next node
            current = current->children[c_index];
        }
    }


    //close dictionary file
    fclose(fp);
    return true;
}



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node* current = root;

    //for each letter in word
    for(int i = 0; word[i] != '\0';  i++)
    {
        char c = tolower(word[i]);

        //get correspondant index of dictionary's node
        int loc = getIndex(c);

        //go to correspondant children node
        if(current->children[loc] == NULL)
        {
            //if it is NULL the word is not in dictionary
            return false;
        }

        //move to following node on the same word path
        current = current->children[loc];
    }
    //when at the end of input word, check is_word value (true or false)
    return current->is_word;
}






/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    int s = wordCount;

    return s;
}






bool unloadHelper(node* current)
{
    //for each children in the node
    for(int i = 0; i < 27; i++)
    {
        //if sub-node is not null, i.e. points to another sub-node
        if(current->children[i] != NULL)
        {
            //check all of its sub-nodes as well
            unloadHelper(current->children[i]);
        }
    }
    //free parent node if all children are NULL as well
    free(current);

    return true;
}




/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    unloadHelper(root);
    return true;
}
