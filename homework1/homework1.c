/*****************************************************************
#include <stdio.h>

//
//  NAME:        Cory Parker
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        August 30, 2021
//
//  FILE:        Homework1.c
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

*** include necessary header files for this source file ***

*** if you need, you can have function prototypes here ***

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
    int num;
    int i;

    for (i=0;i<6;++i){

        if (i<2){
            printf("Hello");
        }
        else if (i<4){
            printf("World");
        }
        else{
            printf("!!!");
        }
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

int foo(int bar)
{
    ...
}
