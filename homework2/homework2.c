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
//  DATE:        September 8, 2021
//
//  FILE:        homework2.c
//
//  DESCRIPTION:
//   Describe the file
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
  print_table(userInterface());
  return 0;
}

/*****************************************************************
//
//  Function name: userInterface
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

int userInterface(void)
{
  int valid;
  int input;
  printf("This is a simple program to generate s table of numbers from 0 to \n the maximum number given. It will also show if it is a multiple of 3.\n"); 
  valid=0;

  while(valid !=1){
    printf("Enter a max number:\n");
    valid = scanf("%d", &input);

    if (valid<1 || input <= 0){
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
    while (getchar()!='\n');
    return 1;
}

/*******************************************************************
//
//   Function name: is_multiple3
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
*******************************************************************/
int is_multiple3(int inp)
{

  if (inp % 3 ==0){
    return 1;
  }  
  return 0;
}
/*****************************************************************
//
//  Function name: print_table
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
void print_table(int inp){
  int i;

  printf("Number  Multiple of 3?\n");
  for (i=0;i<=inp;i=i+1){
    printf("%*i",6,i);
    if(is_multiple3(i)==1){
      printf("%*s\n",5,"Yes");  
    }
    else{
      printf("%*s\n",4,"No");
    }  

  }

}
