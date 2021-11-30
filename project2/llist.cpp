/*****************************************************************
//
//  NAME:        Cory Parker
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 18, 2021
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   The database for user_interface in C++. adds, finds,
//   prints, deletes, reads, writes, and cleans up records.
//
//
****************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include "llist.h"
#include <string.h>
#include <stdlib.h>

/*****************************************************************
//
//  Function name: readfile()
//
//  DESCRIPTION:   Reads in fromatted data from a file and uses
//                 addRecord to add it into a linked list of              
//                 records.
//
//  Return values:  1 : success
//                  0 : working
//
****************************************************************/

int llist::readfile()
{
    #ifdef DEBUGMODE
        std::cout << "\n-readfile Called-" << std::endl;
    #endif
   
    int status = 0, end = 0;
    int accnoTemp;  
    std::string nameTmp, accnoTmp, addressTmp, buffer;
    std::ifstream fileIn;       
    fileIn.open (filename); 

    if (fileIn == NULL)
    {      
        status = -1;
    }

    else
    {
        while (end == 0 && fileIn.peek() != EOF)
        {
            if (fileIn.peek() == EOF)
            {
               end = 1;
            }

            else
            {       
                nameTmp.clear();
                accnoTmp.clear();
                addressTmp.clear();

                std::getline(fileIn, accnoTmp, '\n');
                accnoTemp = atoi(accnoTmp.c_str());
                std::getline(fileIn, nameTmp, '\n');
                getline(fileIn, addressTmp, '#');
                if (!fileIn.eof())
                {
                    getline(fileIn, buffer, '\n');
                }                    
                               
                addRecord(accnoTemp, (char*)(nameTmp.c_str()), (char*)(addressTmp.c_str()));
            }   
        }
    }
    fileIn.close();
    return status;
}

/*****************************************************************
//
//  Function name: writefile();
//
//  DESCRIPTION:   writes the data of the given record list to 
//                 a text file.
//
//  Return values:  0 : completed properly
//                 -1 : no file
//
****************************************************************/

int llist::writefile()
{
    #ifdef DEBUGMODE
        std::cout << "\n-writefile Called-" << std::endl;
    #endif
 
    int status = 0;
    struct record * itr;
    itr = this->start;
    std::ofstream fileOut;
    fileOut.open (filename);

    if (itr == NULL) 
    {
        status = -1;
    }

    else 
    {
        while (status == 0 && itr != NULL)
        {
            fileOut << itr->accountno << "\n" << itr->name << "\n" << itr->address << "#\n";
            itr = itr->next;           
        }
    }
    fileOut.close();
    return status;

}

/*****************************************************************
//
//  Function name: cleanup();
//
//  DESCRIPTION:   Releases heap space of a struct record
//                 linked list
//
//  Return values:  void
//
****************************************************************/

void llist::cleanup() 
{
    #ifdef DEBUGMODE
        std::cout << "\n-Cleanup Called-" << std::endl;
    #endif

    record * itr;
    while(this->start != NULL) 
    {
        itr = this->start;
        this->start = ((this->start)->next);
        delete(itr);
        itr = NULL;
    }
    this->start = NULL;    
    
}

/*****************************************************************
//
//  Function name: llist();
//
//  DESCRIPTION:   Default Constructor for llist. Reads and writes to 
//                 a file named database.txt.
//
****************************************************************/

llist::llist()
{
    #ifdef DEBUGMODE
        std::cout << "\n-Default Constructor Called-" << std::endl;
    #endif
  
    this->start = NULL;
    strcpy(this->filename, "database.txt"); 
    this->readfile();
}

/*****************************************************************
//
//  Function name: llist(char[]);
//
//  DESCRIPTION:   A Constructor for llist to allow for a custom file
//                 name to read and write data to.
//
****************************************************************/

llist::llist(char name[])
{
    #ifdef DEBUGMODE
        std::cout << "\n-Constructor Called-" << std::endl;
        std::cout << "-file name given: " << name << " -" << std::endl;
    #endif

    this->start = NULL;
    strcpy(this->filename, name);
    this->readfile();     
}

/*****************************************************************
//
//  Function name: ~llist();
//
//  DESCRIPTION:   Deconstructor for llist. Writes data to file 
//                 then cleans up linked list.
//
****************************************************************/

llist::~llist()
{
    #ifdef DEBUGMODE
        std::cout << "\n-deconstructor Called-" << std::endl;
    #endif

    this->writefile();
    this->cleanup();
}

/*****************************************************************
//
//  Function name: addRecord()
//
//  DESCRIPTION:   Adds a new record to linked list.
//
//  Parameters:    accNum (int): account number given by the user
//                 name (char[]): account name given by the user
//                 address (char[]): account address given by the user
//
//  Return values:  0 : completed
//
****************************************************************/

int llist::addRecord(int accNum, char name[],char address[])
{
    #ifdef DEBUGMODE
        std::cout << "\n-addRecord Called-" << std::endl;
        std::cout << "-account# to add: " << accNum << " -" << std::endl;
        std::cout << "-name to add: " << name << " -" << std::endl;
        std::cout << "-address to add: " << address << " -" << std::endl;
    #endif       
 
    int i, j, status;   
    record *temp, *current;
    //startt = this->start;
    status = 1;
    i = 0;
    j = 0;

    if (start == NULL)
    {
        this->start = new record;
        this->start->accountno = accNum;
        strcpy(start->name, name);
        strcpy(start->address, address);
        start->next = NULL;
        status = 0;
    }
    
    else
    {
        current = this->start;
        
        while (status != -1 && current != NULL)
        {
            if (current->accountno == accNum)
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
            current = this->start;
            temp = new record;
            temp->accountno = accNum;
            strcpy(temp->name, name);
            strcpy(temp->address, address);

            if (temp->accountno > this->start->accountno)
            {
                temp->next = this->start;
                this->start = temp;
                current = temp;
                status = 0;
            }
        }
        
        if (status == 1)
        {
            while (current != NULL && accNum < current->accountno)
            {
                current = current->next;
                i = i+1;
            }

            temp->next = current;
            current = this->start;

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
    return status;
}

/*****************************************************************
//
//  Function name: findRecord()
//
//  DESCRIPTION:   Finds a record from the given account number.
//
//  Parameters:    accNum (int) : account number.
//
//  Return values:  0 : success
//                  1 : working
//
****************************************************************/

int llist::findRecord(int accNum)
{
    #ifdef DEBUGMODE
        std::cout << "\n-findRecord Called-" << std::endl;
        std::cout << "-account to find: " << accNum << " -" << std::endl;
    #endif

    int status = 1;
    
    if (this->start == NULL)
    {
        std::cout << "\n-- No records are contained to search --\n";
    }

    record * itr = this->start;

    while (status == 1)
    {
        if(itr == NULL)
        {   
            std::cout << "\n-- Account # of " << accNum << " in database does not exist --\n";
            status = -1;
        }

        else if(itr->accountno == accNum)
        {
            std::cout << "\n-- Record Found--\nAccount #: " << itr->accountno;
            std::cout << "\nAccount Name: " << itr->name << "\nAccount Address: " << itr->address << std::endl;
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
//  Function name: printAllRecords()
//
//  DESCRIPTION:   Prints all records held in llist.
//
****************************************************************/

void llist::printAllRecords()
{
    #ifdef DEBUGMODE
        std::cout << "\n-printAllRecords Called-" << std::endl;
    #endif

    if (this->start == NULL)
    {
        std::cout << "\n-- No valid records are contained to print --\n";
    }

    record * itr = this->start;

    while(itr != NULL)
    {
        std::cout << "\nAccount #: " << itr->accountno << "\nAccount Name: " << itr->name << std::endl;
        std::cout << "Account Address: " << itr->address << std::endl;  
        itr = itr->next;
    }
}
   
/*****************************************************************
//
//  Function name: deleteRecord()
//
//  DESCRIPTION:   Deletes a record given an account number.
//
//  Parameters:    accNum (int) : given account number.
//
//  Return values:  0 : Completed properly
//                 -1 : Nothing to delete
//
****************************************************************/

int llist::deleteRecord(int accNum)
{
    #ifdef DEBUGMODE
        std::cout << "\n-deleteRecord Called-" << std::endl;
        std::cout << "-account to delete: " << accNum << " -" << std::endl;
    #endif

    int status = 1;
    int itr = 0;   
    record *temp, *holder;
    
    if (this->start == NULL)
    {
        status = -1;
    }
 
    else
    {
        temp = this->start;

        while (status == 1)
        {
            if (temp == NULL)
            {
                status = -1;
            }
            else if (temp->accountno == accNum)
            {                
                holder = temp->next;
                delete(temp);
                temp = this->start;
                
                if (itr == 0)
                {
                    this->start = holder;
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
    return status;
}

