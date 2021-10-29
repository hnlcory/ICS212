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
//  DATE:        October 24, 2021
//
//  FILE:        database.c
//
//  DESCRIPTION: The database for user_interface. adds, finds,
//               prints, deletes, reads, writes, and cleans up records.
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
    struct record *start, *temp, *current;   
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

    if (start == NULL)
    {
        start = (struct record*)malloc(sizeof(struct record));
        start->accountno = uaccountno;
        strcpy(start->name, uname);
        strcpy(start->address, uaddress);
        start->next = NULL;
        status = 0;
    }
    
    else if (status == 1)
    {
        current = start;
        
        while (status != -1 && current != NULL)
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
            temp = (struct record*)malloc(sizeof(struct record));
            temp->accountno = uaccountno;
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
            while (current != NULL && uaccountno < current->accountno)
            {
                current = current->next;
                i = i+1;
            }

            temp->next = current;
            current = start;

            while (j != i)
            {
                if (j+1 == i)
                {
                    current->next = temp;
                }
                j = j+1;
                current = current->next;
            }
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
    {
        printf("\nAccount #: %i\nAccount Name: %s\nAccount Address: %s\n",itr->accountno,itr->name,itr->address);  
        itr = itr->next;
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
//
****************************************************************/

int findRecord (struct record *start, int accNum)
{ 
    struct record * itr = start;
    int status = 1;
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- findRecord called");
        printf("\n---- Account Number: %d", accNum);
        printf("\n<<<< ----------------  >>>>\n\n");
    }

    if(itr == NULL)
    {
        printf("\n-- No records are contained to search --\n");
        status = 0;
    }
    
    while (status == 1)
    {
        if(itr == NULL)
        {
            printf("\n-- Account # of '%d' in database does not exist --\n",accNum);
            status = -1;
        }

        else if(itr->accountno == accNum)
        {
            printf("\n-- Record Found--\nAccount #: %d",itr->accountno);
            printf("\nAccount Name: %s\nAccount Address: %s\n",itr->name,itr->address);
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
                status = -1;
            }
            else if (temp->accountno == uaccountno)
            {                
                holder = temp->next;
                free(temp);
                temp = start;
                
                if (itr == 0)
                {
                    start = holder;
                    status = 0;                
                }
                
                while (status != 0 && itr - 1 != 0)
                {
                    temp = temp->next;
                    itr = itr - 1;
                }

                if (status != 0)
                {
                    temp->next = holder;
                    status = 0;
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
//  Function name: readfile
//
//  DESCRIPTION:   Reads in fromatted data from a file and uses
//                 addRecord to add it into a linked list of              
//                 records.
//
//  Parameters:    fileName (char []) : name of file being read
//                 startPtr (struct record **) : pointer to pointer
//                 of the start of a list.
//
//  Return values:  0 : completed properly
//                 -1 : no file
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
    fileIn = fopen(fileName,"a+");    

    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- readfile called");
        printf("\n---- reading from '%s'",fileName);
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
                
             
                fgets(nameTemp,25,fileIn);
                
                for (accNameSize = 0; nameTemp[accNameSize] != '\0';accNameSize++)
                {
                    if(nameTemp[accNameSize]=='\n')
                    {
                        nameTemp[accNameSize]='\0';
                    }
                }

                                   
                endAddress = 0, i = 0;
                while (endAddress != 1)
                {
                   
                    if ((buffInput = fgetc(fileIn)) != '#' && i < 50)
                    {
                   
                   
                        addressTemp[i] = buffInput;
                        i++;     
                    }
                    else
                    {
                   
                        addressTemp[i] = '\0';
                        endAddress = 1;
                    }   
                                
                }
                 
                addRecord(startPtr, accountnoTemp, nameTemp, addressTemp);
            }   
        }

    }
    fclose(fileIn);
    return status;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   writes the data of the given record list to 
//                 a text file.
//                 
//  Parameters:    fileName (char []) : name of file being read
//                 startPtr (struct record **) : pointer to pointer
//                 of the start of a list.
//
//  Return values:  0 : completed properly
//                 -1 : no file
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
        printf("\n---- writing to '%s'",fileName);
        printf("\n<<<< ----------------  >>>>\n\n");
    }
 
    if (itr == NULL) 
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
//  Function name: cleanup
//
//  DESCRIPTION:   Releases heap space of a struct record
//                 linked list
//
//  Parameters:    startPtr (struct record **) pointer to pointer
//                 to the start of a record list
//
//  ****************************************************************/

void cleanup(struct record ** startPtr) 
{
    struct record *temp, *start;
    start = *startPtr;
    if (debugMode == 1)
    {
        printf("\n\n<<<< ----------------  >>>>");
        printf("\n<<<< Debug Mode Active >>>>");
        printf("\n---- cleanup called");
        printf("\n<<<< ----------------  >>>>\n\n");
    }

    while (start != NULL)
    {
        temp = start->next;
        free(start);
        start = temp;       
    }   
}
