/*****************************************************************
//
//  NAME:        Cory Parker
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 20, 2021
//
//  FILE:        user_interface.c
//
//  DESCRIPTION: Validates info and calls the 
//               correct functions of the Database.
//   
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"

int debugMode = 0;

void getaddress (char [], int);
void menu();
int getAccNum();
int clean_stdin();

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Shows user the UI and gives a selection of
//                 possible choices. Validates the input.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed.
//
//  Return values:  0 : program exited succesfully.
//
****************************************************************/

int main(int argc, char* argv[])
{

    struct record * start = NULL;
    int working = 0;
    char usrInp[10], accName[50], accAddr[150];
    int usrInpSize, accNameSize;
    int accNum = 0;
 
    int functReturnVal;    
    int argLen = 1;

    if (argc > 2)
    {
        printf("\n---Too many arguments given---\n");
        working = 1;
    }
    else if (argc > 1) 
    {
        if (strcmp(argv[argLen], "debug") == 0)
        {
            printf("\n<<<NOTE: Debug Mode Active>>>\n");
            debugMode = 1;
        }
        else 
        {
            printf("\n---Incorrect argument given---\n");
            working = 1;
        }
    }    
    else
    {
        debugMode = 0;
    }
    
    readfile(&start, "records.txt"); 
  
    while (working != 1)
    {        
        menu();
        fgets(usrInp, 10, stdin);
        usrInp[strcspn(usrInp, "\n")] = 0;
        usrInpSize = strlen(usrInp);

        if (strncmp(usrInp, "add",usrInpSize) == 0)
        {  
 
            accNum = getAccNum();
            clean_stdin();
            printf("\nEnter name: ");
            fgets(accName, sizeof accName, stdin);

            for (accNameSize = 0; accName[accNameSize] != '\0';accNameSize++)
            {
                if(accName[accNameSize]=='\n')
                {
                    accName[accNameSize]='\0';
                }
            }       
    
            getaddress(accAddr, sizeof accAddr);
            clean_stdin();
            addRecord(&start, accNum, accName, accAddr);
        }
        
        else if (strncmp(usrInp, "printall",usrInpSize) == 0)
        {
            printAllRecords(start);
        }

        else if (strncmp(usrInp, "find",usrInpSize) == 0)
        {
            accNum = getAccNum();
            clean_stdin();
            findRecord(start, accNum);  
        }

        else if (strncmp(usrInp, "delete",usrInpSize) == 0)
        {
            accNum = getAccNum();
            clean_stdin();
            functReturnVal = deleteRecord(&start, accNum);
            if (functReturnVal == 0)
            {
                printf("\n-- delete of '%d' sucessful --\n",accNum);
            }
            else if (functReturnVal == -1)
            {
                printf("\n-- delete of '%d' failed --\n",accNum);
            } 
        }

        else if (strncmp(usrInp, "quit",usrInpSize) == 0)
        {
            writefile(start,"accWrite.txt");
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
//  Function name: clean_stdin
//
//  DESCRIPTION:   Catches possible inputs leftover.
//                 Cleans stdin in event of.
//
//  Return values: 1 : there is a character caught.
//
****************************************************************/

int clean_stdin()
{
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- clean_stdin called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }

    while (getchar()!='\n');
    return 1;
}

/*****************************************************************
//
//  Function name: getAccNum
//
//  DESCRIPTION:   Prompts the user for a valid account number,
//                 validates input.
//
//  Return values: Valid address given by the user.
//
****************************************************************/

int getAccNum()
{     
    int input, valid;
 
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- getAccNum called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }    
   
    while(valid !=1)
    {
        printf("\nEnter account number: \n");
        valid = scanf("%d", &input);

        if (valid<1 || input <= 0)
        {
            clean_stdin();
            printf("-- Error, please enter valid account number --");
            valid=0;
        }
    }
    return input;
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   Gets the mail address of the user, checks
//                 if entry is done with "#"
//
//  Parameters:    address (char[]): The address given by user
//                 size (int): The max size of the address
//
****************************************************************/

void getaddress(char address[], int size)
{
    char buffInput;
    int end = 0, i = 0;
   
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- getAddress called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }
    
    printf("\nEnter address followed by # when done:\n");
    while (end != 1)
    {
        if ((buffInput = getchar()) != '#' && i < size)
        {
            address[i] = buffInput;
            i++;     
        }
        else
        {
            address[i] = '\0';
            end = 1;
        }
    } 
}

/*****************************************************************
//
//  Function name: menu
//
//  DESCRIPTION:   Prints the formatted menu to the command line
//
****************************************************************/

void menu()
{
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- menu called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }

    printf("\n-  Parker Banking -\n");
    printf("\nPlease type the name of the option you\nwould like to access:\n\n");
    printf("add: Add a new record in the database\n");
    printf("printall: Print all records in the database\n");
    printf("find: Find record(s) with a specified account #\n");
    printf("delete: Delete existing record(s) from the database");
    printf(" using the account # as a key\nquit: Quit the program\n\n");

}
