/*****************************************************************
//
//  NAME:        Ravi Narayan
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 3, 2112
//
//  FILE:        template.c
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"
/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Don't forget to describe what your main
//                 functions does.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/

int main(int argc, char* argv[])
{
    int working = 0;
    struct record * start = NULL;
    char usrInp[10];
    int usrInpSize;
    printf("test");
    
    printf("\nWelcome to the Parker Banking System\n");
   
    while (working != 1)
    {
        printf("\nPlease type the name of the option you\nwould like to access\n\n");
        printf("add: Add a new record in the database\nprintall: Print all records in the database\nfind: Find record(s) with a specified account #\ndelete: Delete existing record(s) from the database using the account # as a key\nquit: Quit the program\n\n");
        fscanf(stdin,"%s",usrInp);
        usrInpSize = strlen(usrInp);

        if (strncmp(usrInp, "add",usrInpSize) == 0)
        {
            printf("\nPlease enter account number: ");   
        }
        
        else if (strncmp(usrInp, "printall",usrInpSize) == 0)
        {
           printf("printall!");   
        }
        else if (strncmp(usrInp, "find",usrInpSize) == 0)
        {
            printf("find!");
        }
        else if (strncmp(usrInp, "delete",usrInpSize) == 0)
        {
          printf("delete!");
        }
        else if (strncmp(usrInp, "quit",usrInpSize) == 0)
        {
            working = 1;
        }
        else
        {
            printf("\n--- Invalid Input, Try Again ---\n");   
        }

    }








    return 0;
}

/*****************************************************************
//
//  Function name: foo
//
//  DESCRIPTION:   A template function
//                 This function does not do anything.
//                 Please describe your function correctly.
//
//  Parameters:    bar (int) : Describe the meaning
//
//  Return values:  0 : some meaning
//                 -1 : some meaning
//
****************************************************************/


