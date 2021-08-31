#include <stdio.h>
/*****************************************************************
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
//   Replicates the output of the provided java file in C
//
****************************************************************/



/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Prints out various words in order.
//       
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
