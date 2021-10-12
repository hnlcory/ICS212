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

#include <stdio.h>
#include "iofunctions.h"

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

int writefile( struct pokemon pokearray[ ], int num, char filename[ ] )
{
    int i=0;
    FILE * fileOut;
    fileOut = fopen(filename,"w");

    if (fileOut == NULL)
    {
        return -1;
    }

    else
    {
    /*check for data alrady in file*/  
        while (i < num )
        {
            /*do the actual add stuff*/
            fprintf(fileOut,"%i\n%s\n",pokearray[i].level,pokearray[i].name);
            i++;
        }
        fclose(fileOut);
        return 0;
         
    }

}

int readfile( struct pokemon pokearray[ ], int* num, char filename[ ] )
{
    FILE * fileOut;

    if (fileOut == NULL)
    {
        return -1;
    }
  
    else
    {
        return 0;

    }
 
}



