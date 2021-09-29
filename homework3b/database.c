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
//  DESCRIPTION: The database for user_interface. adds, finds,
//               prints, and deletes records.
//
****************************************************************/

#include <stdio.h>
#include "database.h"
extern int debugMode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a new record.
//
//   PARAMETERS:   start (struct record**): double pointer to the start of the record
//                 accNum (int): account number given by the user
//                 name (char[]): account name given by the user
//                 address (char[]): account address given by the user
//
//  Return values:  0 : completed
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
//  DESCRIPTION:   Prints all records held.
//
//  Parameters:    start (struct record*): the start of records.
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
//  DESCRIPTION:   Finds a record from the given account number.
//
//  Parameters:    accNum (int) : account number.
//                 start (record*) : the start of records.
//
//  Return values:  0 : Completed properly
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
//  DESCRIPTION:   Deletes a record given an account number.
//
//  Parameters:    accNum (int) : given account number.
//                 start (struct record**): double pointer to the start of the record.
//
//  Return values:  0 : Completed properly
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

