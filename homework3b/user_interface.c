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
//  DESCRIPTION: Calls the  correct functions of the DB part
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

    struct record * start = NULL;
    int working = 0;
    char usrInp[10], accName[50], accAddr[150];
    int usrInpSize, accNameSize;
    int accNum = 0;
     
    int argLen = 1;

    if (argc > 2)
    {
        printf("\n---Too many arguments given---\n");
        working = 1;
    }
    else if (argc > 1) 
    {
        if (strcmp(argv[argLen], "debugmode") == 0)
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

            deleteRecord(&start, accNum);
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
//  Function name: clean_stdin
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

      /*  printf("address:%s",address);*/
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

void menu()
{
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- menu called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }

    printf("\n---  Welcome to the Parker Banking System ---\n");
    printf("\nPlease type the name of the option you\nwould like to access:\n\n");
    printf("add: Add a new record in the database\n");
    printf("printall: Print all records in the database\n");
    printf("find: Find record(s) with a specified account #\n");
    printf("delete: Delete existing record(s) from the database");
    printf(" using the account # as a key\nquit: Quit the program\n\n");

}
