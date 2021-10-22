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
#include <stdlib.h>
#include <string.h>
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

int addRecord (struct record **startptr, int uaccountno, char uname[], char uaddress[])
{
    int i, j, status;
    struct record * start, *temp, *current;
       
    start = *startptr;
    status = 1;
    i = 0;
    j = 0;    

    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- addRecord called");
        printf("\n---- Account Number: %d", uaccountno);
        printf("\n---- Account Name: %s", uname);
        printf("\n---- Account Address: %s", uaddress);
        printf("\n<<<< ----------------  >>>>\n\n");
    }

    if (start == NULL)ess, uaddress);
        start->next = NULL;
     /*   *startptr = start;*/
        status = 0;
    }
    
    else if ( status == 1)
    {
        current = start;
        
        while ( status != -1 && current != NULL)
        {
            if (current->accountno == uaccountno)
            {
                status = -1;
            }
            else 
            {
                current = current->next;
            }
        }

        if (status == 1)
        {
            current = start;
            strcpy(temp->name, uname);
            strcpy(temp->address, uaddress);

            if (temp->accountno > start->accountno)
            {
                temp->next = start;
                start = temp;
                current = temp;
                status = 0;
            }
        }

        if (status == 1)
        {
   
            status = 0;
        }
    }
    *startptr = start;   
    return status;
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
    struct record *itr = start;
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- printAllRecords called");
        printf("\n---- Records: ");
        printf("\n<<<< ----------------  >>>>\n\n");
    }
 
    if(itr == NULL)
    {
        printf("\n-- No valid records are contained to print --\n");
    }    

    while(itr != NULL)
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
//
****************************************************************/

int findRecord (struct record *start, int accNum)
{ 
    struct record * itr = start;
    int status = 1;
    if (debugMode == 1)
    {
      
    while (status == 1)
    {
        if(itr == NULL)
        {
            printf("\n-- Account # of '%d' in database does not exist --\n",accNum);
            status = -1;
        }tr->address);
            status = 0;
        }

        else
        {
            itr = itr->next;
        }
    } 
    return status;
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
//                  -1: Nothing to delete
// 
****************************************************************/

int deleteRecord(struct record **startptr, int uaccountno)
{
    int status, itr;
    struct record *start, *temp, *holder;  
    start = *startptr;    
    status = 1;
    itr = 0;

    if (debugMode == 1)
    { 
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- deleteRecord called");
        printf("\n---- Account Number: %d", uaccountno);
        printf("\n<<<< ----------------  >>>>\n\n");
    }
   
    if (start == NULL)
    {
        status = -1;
    }
    
    else 
    {
        temp = start;

        while (status == 1)
        {
            if (temp == NULL)
            {                
                holder = temp->next;
                free(temp);
                temp = start;
                
                if (itr == 0)
                {
                    /* the first record is the one to be deleted*/
                    start = holder;
                    status = 0;
                 
                }
                
                while (status != 0 && itr - 1 != 0)
                {
                    temp = temp->next;
                    itr = itr - 1;
                }

            }

            else
            {       
                temp = temp->next;
                itr = itr + 1;
            } 
        }
    }
    *startptr = start;
    return status;
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

int readfile(struct record ** startPtr, char fileName[])
{
    int status = 0;
    int end = 0;

    int endAddress;
    int i;
    int accNameSize;   
    
    int accountnoTemp;
    char nameTemp[25];
    char addressTemp[50];
    char buffInput;

    FILE * fileIn;
    fileIn = fopen(fileName,"r");    

    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- readfile called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }
 
    if (fileIn == NULL)
    {      
        status = -1;
    }

    else
    {
        while (end == 0 && feof(fileIn) == 0)
        {
            if (fscanf(fileIn, "%i\n", &accountnoTemp) != 1)
            {
                end = 1;
            }

            else
            {
                printf("\naccnumstored:%i\n",accountnoTemp);
             
                fgets(nameTemp,25,fileIn);
                
               

                printf("namestored:%s",nameTemp);
                   
                endAddress = 0, i = 0;
                while (endAddress != 1)
                {
                    printf("in while loop");
                    if ((buffInput = fgetc(fileIn)) != '#' && i < 50)
                    {
                        printf("in the if");
                        printf("char is:%c",buffInput);
                        addressTemp[i] = buffInput;
                        i++;     
                    }
                                
                }
                printf("toward end"); 
                addRecord(startPtr, accountnoTemp, nameTemp, addressTemp);
            }   
        }

    }
    fclose(fileIn);
    return status;
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

int writefile(struct record * start, char fileName[])
{
    int status = 0;
    FILE * fileOut;
    struct record * itr;
    itr = start;
    fileOut = fopen(fileName,"w");

    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- writefile called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }
 
    if (itr == NULL) /* or fileout -- null?*/
    {
        status = -1;
    }

    else 
    {
        while (status == 0 && itr != NULL)
        {
            fprintf(fileOut,"%i\n%s\n%s#\n",itr->accountno,itr->name,itr->address);
            itr = itr->next;           

        }
    }
    fclose(fileOut);
    return status;
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
//
****************************************************************/

void cleanup(struct record ** startPtr) 
{
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- cleanup called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }  
}
