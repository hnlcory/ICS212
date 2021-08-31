#include <stdio.h>
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

int main(int argc, char* argv[]){

    int num;
    int i;

    for (i=0;i<6;i=i+1){

        if (i<2){
            printf("Hello\n");
        }
        else if (i<4){
            printf("World\n");
        }
        else{
            printf("!!!\n");
        }
    }
    num=0;  
    while (num <3){
        printf("While loop!\n");
        num = num+1;    
    }
    num=0;   
    do{
        printf("Do-while loop!\n");
        num = num+1;
    }
    while(num < 3);
    
    return 0;   
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
