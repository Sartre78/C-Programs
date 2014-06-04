#include "hash1.h"

int main (void)
{
    // offer the user four options. 
    while (true)
    {
        printf("Please choose an option:\n\n");
        printf("0 - Quit\n");
        printf("1 - Load the Dictionary\n");
        printf("2 - Print an individual Letter of the Dictionary\n");
        printf("3 - Print the entire Dictionary\n");
        printf("4 - Check to see if a specific word is in the Dictionary\n");
        printf("\n"); 
        int option = GetInt();

        switch (option)
        {
            // quit
            case 0: free_table(); printf("\n\nGoodbye!\n\n"); return 0;

            // load dictionary
            case 1: load(); printf("\nThe dictionary has now been uploaded.\n\n"); break;

            // print an individual section ("Letter") of the dictionary.
            case 2: printf("\nWhich letter of the dictionary would you like to print?\n\n");
                    char* c = GetString();
                    int h = hash(c);
                    print_i(h); free(c); break;
                    
            case 3: print_all(); break;
            
            case 4: printf("\nWhich word would you like to check?\n\n");
                    char* w = GetString(); 
                    check(w); free(w); break;                    
                    
            default: printf("\nNot a valid option.\n\n"); break;
        }                
    }
}    
