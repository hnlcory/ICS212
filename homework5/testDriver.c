#include <stdio.h>
#include "iofunctions.h"

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
