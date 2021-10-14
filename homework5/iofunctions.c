/*****************************************************************
//
//  NAME:        Cory Parker
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        October 12, 2021
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION: holds functions to read and write pokemon
//               to and from files. 
//   
//
****************************************************************/

#include <stdio.h>
#include "iofunctions.h"

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   A function to write pokemon from an array
//                 to a file.
//
//  Parameters:    pokearray (struct pokemon) : an aray that holds pokemon
//                 num (int) : the number of pokemon
//                 filename (char[]) : the name of the output file
//
//  Return values:  0 : sucessful write
//                 -1 : unsucessful write
//
****************************************************************/

int writefile( struct pokemon pokearray[ ], int num, char filename[ ] )
{
    int status = 0;
    int i = 0;
    FILE * fileOut;
    fileOut = fopen(filename,"w");

    if (fileOut == NULL)
    {
        status = -1;
    }

    else
    {
        do{
            fprintf(fileOut,"%i\n%s\n",pokearray[i].level,pokearray[i].name);
            i = i + 1;
        }
        while (i < num);

        fclose(fileOut);
        num= i;
         
    }
    return status;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   A function to read pokemon from a text file
//
//  Parameters:    pokearray (struct pokemon) : an aray that holds pokemon
//                 num (* int) : pointer to the number of pokemon
//                 filename (char[]) : the name of the output file
//
//  Return values:  0 : sucessful write
//                 -1 : unsucessful write
//
****************************************************************/

int readfile( struct pokemon pokearray[ ], int* num, char filename[ ] )
{ 
    int status = 0;
    int i = 0;
    int end = 0;
    int tempLevel;
    FILE * fileIn;
    fileIn = fopen(filename,"r");    

    if (fileIn == NULL)
    {      
        status = -1;
    }
  
    else
    {
        do
        {
            if (fscanf(fileIn, "%d\n", &tempLevel) != 1 || i == *num)
            {
                end = 1;
                i = i -1;
            }
            
            else
            {
                pokearray[i].level = tempLevel;
                fgets(pokearray[i].name, 25,fileIn);                      
            }
            i++;    
        }
        while (end == 0 && feof(fileIn) == 0);
    }

    *num = i;
    fclose(fileIn);
    return status;    
}
