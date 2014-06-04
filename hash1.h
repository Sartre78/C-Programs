/**
 * 06/04/2014  
 *
 * hash1.h
 *
 * header file for hash1.c
 *
 * practice for pset6 - CS50x
 *
 * This program loads a text file identical to the large dictionary
 * used in pset6, and then accesses the dictionary to print out the 
 * dictionary.  The dictionary is stored utilizing a hash table with
 * separate chaining (linked lists).
 *
 */
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


// define node.  Arbitrarily setting max word length to 56 char.
typedef struct node {char word[56]; struct node* next;} node;

// initialize table array
node* table[26];
// declare functions
int hash (char* string);
void load (void);
void print_i (int i);
void print_all (void);
void free_table (void);
void check (char* w);

// frees table
void free_table (void)
{
    for (int i = 0; i <= 25; i++) {free(table[i]);}
}    
// loads dictionary
void load (void)
{
    // Open dictionary    
    FILE* file = fopen("largedictionary.txt", "r");

    /* begin loop to read words from file.  "143091" is being hard coded in as 
       the known value of total words in the file. */
    for (int i = 0; i < 143091; i++)
    {
        // allocate new node and check for NULL
        node* new_node = malloc(sizeof(node));
    
        // scan word from file into the "word" portion of the new node struct
        fscanf(file, "%s", new_node->word);
        
        // create a string (char*) to be hashed 
        char* v = new_node->word;

        // retrieve hash key by hashing the current word
        int k = hash (v);

        // initial insertion scenario (i.e., the spot in the table array is empty)
        if (table[k] == NULL)  {table[k] = new_node;}
    
        /* otherwise, put the new string in the first position and link the
           previous node to the new head of the list */
        else 
        {
            // create a node equal to the current value of the table
            node* curr = table[k];  
            /* point "new_node" (the struct holding the value of the desired
               word to be inserted) to the newly created node that equals what
               to this point was the start of the list */ 
            new_node->next = curr;
            /* set the head pointer of the "k"th spot in the array (i.e., the 
               "head") to be the node containing the desired string to be 
               inserted.  */ 
            table[k] = new_node;
        }
    free(new_node);                     
    }
    fclose(file);
}

void print_i (int i)
{
    if (table[i] == NULL) {printf("Dictionary has not been loaded yet!\n\n");}
    
    int word_counter = 0;
    int x = i;
    node* current = table[i]; 
    int letter = x + 65;
    printf("\nDictionary - Letter: %c\n\n", (char) letter);
    while (current->word != NULL) 
    {
        printf("%s.\n", current->word); 
        current = current->next;
        word_counter++;
    }
    printf("\n");
    printf("Total Letter %c word count: %i.\n\n", (char) letter, word_counter);
    free(current);        
}

void print_all (void) 
{
    int word_counter = 0;
    printf("\nDictionary - Complete:\n\n");
    
    for (int i = 0; i <= 25; i++) 
    {
        int letter = i + 65;
        int letter_counter = 0;
        printf("Dictionary - Letter: %c\n\n", (char) letter); 
        node* current = table[i];
        while (current->word != NULL) 
        {
            printf("%s.\n", current->word); 
            current = current->next;
            word_counter++;
            letter_counter++;
        }
        printf("\n");
        printf("Total Letter %c word count: %i.\n\n", (char) letter, letter_counter);
        free(current);  
    }
    printf("Total Dictionary Word Count: %i.\n\n", word_counter);
}


void check(char* w)
{
    char* original = malloc((strlen(w) + 1) * sizeof(char));
    if (original == NULL) {free(w);}
    
    
    for (int i = 0, n = strlen(w); i < n; i++) {original[i] = w[i]; w[i] = tolower(w[i]);}
    
    int h = hash(w);
    
    node* current = table[h];
    
    while (current->word != NULL && w != NULL)
    { 
        if (strcmp(w,current->word) == 0) {printf("\n%s is in the Dictionary!\n\n", original); break;}
        
        else {current = current->next;}
    }            
    if (current->word == NULL) {printf("\n%s was not in the Dictionary.\n\n", original);}
    free(current);
    free(original);    
}
  
/* basic hash function - takes the first letter of each string and returns a 
   numerical value (a = 0, b = 1, c = 2, etc.) */      
    
int hash (char* string) {int h = toupper(string[0]) - 'A'; return h % 26;}
