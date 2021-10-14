/*****************************************************************
//
//  NAME:        Ravi Narayan
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 3, 2112
//
//  FILE:        template.c
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
#include <stdio.h>

int main(int argc, char* argv[]){
  char name[25];
  int num;


  printf("name: ");
  
  fgets(name, 25, stdin);

  printf("num: ");

  fscanf(stdin, "%d", &num);
  
  printf("\nnum: %d\n",num);
  printf("\nname: %c\n",name[25]);

  return 0;
}

