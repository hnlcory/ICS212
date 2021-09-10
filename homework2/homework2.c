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
//  DATE:        September 9, 2021
//
//  FILE:        homework2.c
//
//  DESCRIPTION: A program that prints out numbers given and
//               prints out if they are a multiple of 3.
//   
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int userInterface(void);
void print_table(int);
int is_multiple3(int);
int clean_stdin();

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
//
//  Parameters:    valid (int) : used to check if user imput
//                 is valid (1) or invalid (0).
//
//                 input (int) : the int given from user.
//
//  Return values: input : int given from user.
//
****************************************************************/

int userInterface(void)
{
  int valid;
  int input;
  printf("This is a simple program to generate s table of numbers from 0 to \n the maximum number given. It will also show if it is a multiple of 3.\n"); 
  valid=0;

  while(valid !=1)
  {
    printf("Enter a max number:\n");
    valid = scanf("%d", &input);

    if (valid<1 || input <= 0)
    {
      clean_stdin();
      printf("error, please enter valid input");
      valid=0;
    }
 
  }
    
  return input; 
}

/*****************************************************************
//
//  Function name: clean_stdin
//
//  DESCRIPTION:   Catches possible char inputs in userInterface.
//                 Cleans stdin in event of.
//
//  Return values:  1 : there is a character caught with getchar.
//
****************************************************************/

int clean_stdin()
{
  while (getchar()!='\n');
  return 1;
}

/*******************************************************************
//
//  Function name: is_multiple3
//
//  DESCRIPTION:   Checks given int to see if it is a multiple of 3.
//
//  Parameters:    inp (int) : The int given when called.
//
//  Return values:  0 : not a multiple of 3.
//                  1 : is a multiple of 3.
//
*******************************************************************/

int is_multiple3(int inp)
{
  if (inp%3==0)
  {
    return 1;
  }  
  return 0;
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

  printf("Number  Multiple of 3?\n");
  for (i=0;i<=inp;i=i+1)
  {
    printf("%*i",6,i);
    if(is_multiple3(i)==1)
    {
      printf("%*s\n",5,"Yes");  
    }
    else
    {
      printf("%*s\n",4,"No");
    }  
  }
}
