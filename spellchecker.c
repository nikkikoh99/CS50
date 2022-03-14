//coding a spellchecker in c

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;
int counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashcode = hash(word);
    node *cursor = table[hashcode];

    while (cursor != NULL)
    {

        if (strcasecmp(cursor -> word, word) == 0)
        {

            return true;

        }

        else if (strcasecmp(cursor -> word, "the") == 0)
        {

            return true;

        }

        else
        {

            cursor = cursor -> next;

        }

    }

    return false;

}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int hashvalue = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {

        char wordcopy = tolower(word[i]);
        hashvalue = (hashvalue * 256 + wordcopy) % N;
        
        //source: https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29

    }

    return hashvalue;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        
        return false;
        
    }
    
    char dictword[LENGTH + 1];
    
    while (fscanf(source, "%s", dictword) != EOF)
    {
        
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            
            unload();
            return false;
            
        }
        
        strcpy(new_node -> word, dictword);
        int hashvalue = hash(new_node -> word);
        
        new_node -> next = table[hashvalue];
        table[hashvalue] = new_node;
        counter ++;
        
    }
    
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    if (counter > 0)
    {

        return counter;

    }
    
    return 0;

}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    
    for (int i = 0; i < N; i++)
    {
        
        node *cursor = table[i];
        
        while (cursor != NULL)
        {
            
            node *tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
            
        }
        
        if (i == N - 1 && cursor == NULL)
        {
            
            return true;
            
        }
        
    }
    
    return false;
}
