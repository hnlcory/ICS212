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
//  DATE:        October 13, 2021
//
//  FILE:        driver.c
//
//  DESCRIPTION: Driver test code for iofunctions.c
//
****************************************************************/

#include <stdio.h>
#include "iofunctions.h"

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Tests the read and write functions to prove
//                 their sucess.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : driver code completed properly.
//                 
****************************************************************/

int main(int argc, char* argv[])
{
    struct pokemon pokemonbank[4];
    struct pokemon pokemonbankRead[5] = {10,"Pikachu",30,"Ditto",7,"Pidgey",85,"Weedle",6,"Magikarp"};
    int numpokemons = 5;
    int itrSize;
    int itr;

    printf("\nwriting to file output.txt...\n"); 
    if (writefile(pokemonbankRead,numpokemons,"output.txt") == 0)
    {
        printf("\nfile sucessfully written to!\n");
        printf("pokemon present: %i\n\n",numpokemons);
    }

    else
    {
        printf("\nfailed to write to file\n");
    } 
    
    printf("reading file output.txt to empty array smaller than data...\n");
    if (readfile(pokemonbank,&numpokemons,"output.txt") == 0)
    {
        printf("\nfile sucessfully read!\n");
        printf("pokemon present: %i\ndata in array:\n",numpokemons);
        itrSize = sizeof(pokemonbank)/sizeof(pokemonbank[0]);

        for (itr=0; itr < itrSize; itr++)
        {
            printf("%i\n%s\n",pokemonbank[itr].level,pokemonbank[itr].name);
        } 
       
    } 
   
    else
    {
        printf("\nfailed to read file\n");
    }

    return 0;
}
