#include "hash1.h"

int main (void)
{
    // offer the user five options. 
    while (true)
    {
        printf("Please choose an option:\n\n");
        printf("0 - Quit\n");
        printf("1 - Load the Dictionary (recommended to be done first)\n");
        printf("2 - Print an individual Letter of the Dictionary\n");
        printf("3 - Print the entire Dictionary\n");
        printf("4 - Check to see if a specific word is in the Dictionary\n");
        printf("\n"); 
        int option = GetInt(); // get user's decision

        switch (option)
        {
            // quit: free table and say "Goodbye!"
            case 0: free_table(); printf("\n\nGoodbye!\n\n"); return 0;

            // load dictionary and inform user that it has been done.
            case 1: load(); printf("\nThe dictionary has now been uploaded.\n\n"); break;

            // print an individual section ("Letter") of the dictionary.
            case 2: printf("\nWhich letter of the dictionary would you like to print?\n\n"); // prompt user
                    char* c = GetString(); // get string from user
                    int h = hash(c); // determine hash key
                    print_i(h); free(c); break; // print table for letter & free memory
                    
            case 3: print_all(); break; // print the entire F%@#$!ing Dictionary
            
            case 4: printf("\nWhich word would you like to check?\n\n"); // prompt user
                    char* w = GetString(); // get string from user
                    check(w); free(w); break; // check word and free memory                    
                    
            default: printf("\nNot a valid option.\n\n"); break; // invalid option
        }                
    }
}    
