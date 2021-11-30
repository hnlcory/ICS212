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
//  FILE:        user-interface.cpp
//
//  DESCRIPTION:
//   Validates info and calls the 
//   correct functions of the Database.
//
****************************************************************/

#include <cstring>
#include <iostream>
#include "llist.h"
#include <string.h>
#include <stdlib.h>
#include <fstream>

int getAccNum();
llist mylist;

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
    #ifdef DEBUGMODE
        std::cout << "\n--DEBUG BUILD--\n" std::endl;
        std::cout << "Main Function Called" std::endl;
    #endif
   
    int working = 0;
    int accNum;
    int usrInpSize;
    std::string usrInp;
  
    std::string blank = "\n";
    const char *blankPtr = blank.c_str();    

    std::string add = "add";
    const char *addPtr = add.c_str();

    std::string prnt = "printall";
    const char *prntPtr = prnt.c_str();

    std::string find = "find";
    const char *findPtr = find.c_str();

    std::string delt = "delete";
    const char *deltPtr = delt.c_str();

    std::string qut = "quit";
    const char *qutPtr = qut.c_str();

    while (working != 1)
    {
        std::cout << "\n-  Parker Banking -\n";
        std::cout << "\nPlease type the name of the option you\nwould like to access:\n\n";
        std::cout << "add: Add a new record in the database\n";
        std::cout << "printall: Print all records in the database\n";
        std::cout << "find: Find record(s) with a specified account #\n";
        std::cout << "delete: Delete existing record(s) from the database";
        std::cout << " using the account # as a key\nquit: Quit the program\n\n";

        std::getline(std::cin, usrInp);
        usrInpSize = usrInp.size();
        const char* usrInpPtr = usrInp.c_str();

        if (strncmp(usrInpPtr, blankPtr, usrInpSize) == 0)
        {
            std::cout << "\n--- Invalid Input, Try Again ---" << std::endl;
        }

        else if (strncmp(usrInpPtr, addPtr, usrInpSize) == 0)
        {
            std::cout << "add time" << std::endl;
            accNum = getAccNum();

            std::string nameTmp, addressTmp, buffer;
            nameTmp.clear();
            addressTmp.clear();

            std::cout << "\nEnter name: " << std::endl;
            std::getline(std::cin, nameTmp, '\n');
            std::cout << "name read is:" << nameTmp << std::endl;

            std::cout << "\nEnter address followed by # when done:\n" << std::endl;
            getline(std::cin, addressTmp, '#');
            if (!std::cin.eof())
            {
                getline(std::cin, buffer, '\n');
            }
            std::cout << "address is:" << addressTmp << std::endl;
            mylist.addRecord(accNum, (char*)(nameTmp.c_str()), (char*)(addressTmp.c_str()));
        }

        else if (strncmp(usrInpPtr, prntPtr, usrInpSize) == 0)
        {
            std::cout << "printall time" << std::endl;
            mylist.printAllRecords();
        }

        else if (strncmp(usrInpPtr, findPtr, usrInpSize) == 0)
        {
            std::cout << "find time" << std::endl;
            accNum = getAccNum();
            mylist.findRecord(accNum);
        }

        else if (strncmp(usrInpPtr, deltPtr, usrInpSize) == 0)
        {
            std::cout << "delete time" << std::endl;
            accNum = getAccNum();
            mylist.deleteRecord(accNum);
        }

        else if (strncmp(usrInpPtr, qutPtr, usrInpSize) == 0)
        {
            working = 1;

        }

        else
        {
            std::cout << "\n--- Invalid Input, Try Again ---" << std::endl;
        }
    }
    return 0;
}

/*****************************************************************
//
//  Function name: getAccNum()
//
//  DESCRIPTION:   Prompts the user for a valid account number,
//                 validates input.
//
//  Return values:  int, valid address given by user.
//
****************************************************************/

int getAccNum()
{ 
    #ifdef DEBUGMODE
        std::cout << "\n-Main Function Called-\n":
    #endif

    int input;
    std::cout << "\nEnter account number: \n";

    while ((!(std::cin >> input)) || (input <= 0))
    {
        std::cout << "-- Error, please enter valid account number --";
        std::cin.clear();
        std::cin.ignore(999, '\n');
        std::cout << "\nEnter account number: \n ";
    }

    std::cin.clear();
    std::cin.ignore(999, '\n');
    return input;
}


