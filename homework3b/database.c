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
//  FILE:        database.c
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#include <stdio.h>
#include "database.h"
extern int debugMode;

/*****************************************************************
//
//  Function name: addRecord
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

int addRecord (struct record **start, int accNum, char name[], char address[])
{
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- addRecord called");
        printf("\n---- Account Number: %d", accNum);
        printf("\n---- Account Name: %s", name);
        printf("\n---- Account Address: %s", address);
        printf("\n<<<< ----------------  >>>>\n\n");
    }
    return 0;
}

/*****************************************************************
//
//  Function name: printAllRecords
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


void printAllRecords(struct record *start)
{
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- printAllRecords called");
        printf("\n---- Records: ");
        printf("\n<<<< ----------------  >>>>\n\n");
    }
}

/*****************************************************************
//
//  Function name: findRecord
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

int findRecord (struct record *start, int accNum)
{ 
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- findRecord called");
        printf("\n---- Account Number: %d", accNum);
        printf("\n<<<< ----------------  >>>>\n\n");
    }
    return 0;
}

/*****************************************************************
//
//  Function name: deleteRecord
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
// 
****************************************************************/


int deleteRecord(struct record **start, int accNum)
{
    if (debugMode == 1)
    { 
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- deleteRecord called");
        printf("\n---- Account Number: %d", accNum);
        printf("\n<<<< ----------------  >>>>\n\n");
    }
    return 0;
}

