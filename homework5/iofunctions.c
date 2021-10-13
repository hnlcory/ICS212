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
   
   struct pokemon pArray[3] ={10,"Pikachu",30,"Ditto",7,"Pidgey"};
   struct pokemon pArray2[2] ={85,"Weedle",6,"Weedle"};


   struct pokemon pArrayW[2];
   int j = 2;
   int itr;
   int help = sizeof(pArrayW)/sizeof(pArrayW[0]);
   
   int inp;
   printf("\n1 or 2 array\n");
   fscanf(stdin, "%d", &inp);
   
   if (inp == 1)
   {
   writefile(pArray,3,"output.txt");
   }
   
   else
   {
   writefile(pArray2,2,"output.txt");
   }
    
     
   readfile(pArrayW,&j,"output.txt");
   

   for (itr=0; itr < help; itr++)
    {

    printf("%i\n%s\n",pArrayW[itr].level,pArrayW[itr].name);

    }  
   return 0;
}

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
    int i = 0;
    FILE * fileOut;
    fileOut = fopen(filename,"w");

    if (fileOut == NULL)
    {
        return -1;
    }

    else
    {
        do{
            fprintf(fileOut,"%i\n%s\n",pokearray[i].level,pokearray[i].name);
            i = i + 1;
        }
        while (i < num);

        fclose(fileOut);
        return 0; 
    }
}

/*****************************************************************
//
//  Function name: readfile
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

int readfile( struct pokemon pokearray[ ], int* num, char filename[ ] )
{ 
    int i = 0;
    int end = 0;
    int tempLevel;
    FILE * fileIn;
    fileIn = fopen(filename,"r");    
 
    if (fileIn == NULL)
    {      
        return -1;
    }
  
    else
    {
        do
        {
            if (fscanf(fileIn, "%d\n", &tempLevel) != 1)
            {
                end = 1;
                i = i-1;
            }
            
            else
            {
                pokearray[i].level = tempLevel;
                fgets(pokearray[i].name, 25,fileIn);
                i++;
            }
        }
        while (end == 0 && feof(fileIn) == 0);
    }

    *num = i;
    fclose(fileIn);
    return 0;    
}
