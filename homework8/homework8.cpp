/*****************************************************************
//
//  NAME:        Cory Parker
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Cory Parker
//
//  DATE:        November 7, 2021
//
//  FILE:        homework8.cpp
//
//  DESCRIPTION: A program that prints out numbers given and
//               prints out if they are a multiple of 3.
//   
****************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int userInterface(void);
void print_table(int);
void is_multiple3(int, int &);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Calls the print_table function with the number
//                 given in userInterface.
//                 
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : program completed.
//                 
****************************************************************/

int main(int argc, char* argv[])
{
    print_table(userInterface());
    return 0;
}

/*****************************************************************
//
//  Function name: userInterface
//
//  DESCRIPTION:   Prints an intro message, asks for an int
//                 and returns the gained value. 
//
//  Parameters:    valid (int) : used to check if user imput
//                 is valid (1) or invalid (0).
//
//                 num (int) : the int given from user.
//
//  Return values: num : int given from user.
//
****************************************************************/

int userInterface(void)
{
    int valid, num;
    std::cout << "This is a simple program to generate s table of numbers from 0 to";
    std::cout <<"\nthe maximum number given. It will also show if it is a multiple of 3" << std::endl; 
    valid=0;

    while(valid != 1)
    {
        std::cout << "Enter a max number:" << std::endl;
         
        if(!(std::cin >> num))
        {   
            std::cout << "error, please enter valid input" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
 
        else
        {
            if (num <= 0)
            {
                std::cout << "error, enter number greater than 0" << std::endl;
            }

            else
            {
                valid = 1;
            }
        } 
    } 
    return num; 
}

/*******************************************************************
//
//  Function name: is_multiple3
//
//  DESCRIPTION:   Checks given int to see if it is a multiple of 3.
//
//  Parameters:    input (int) : The int given. check if multiple of 3
//                 mult (int&) : referance to multiple. 1 if a multiple
//                 of 3, 0 if not.
//
//  Return values:  0 : not a multiple of 3.
//                  1 : is a multiple of 3.
//
*******************************************************************/
void is_multiple3(int input, int& mult)
{
    if (input % 3 == 0)
    {
        mult = 1;
    }
    else
    {
        mult = 0;
    }
}

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   Uses a for-loop to generate a table, starting
//                 from 0 to the given maximum number, with the 
//                 additional column.
//
//  Parameters:    i (int) : Used to loop from 0 to inp.
//
****************************************************************/

void print_table(int inp)
{
    int i;
    int multiple;
    int& multipleRef = multiple;

    std::cout << "Number  Multiple of 3?" << std::endl;
    for (i=0;i<=inp;i=i+1)
    {
        std::cout << std::setw(5) << i << " ";

        is_multiple3(i, multipleRef);       

        if(multiple == 1)
        {
            std::cout << std::setw(5) <<  "Yes" << std::endl;  
        } 

        else
        {
            std::cout << std::setw(5) << "No" << std::endl;
        }  
    }
}
