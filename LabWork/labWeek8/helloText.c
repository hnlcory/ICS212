#include <stdio.h>

int main()
{
    int i;
    FILE * fileOut;
    fileOut = fopen("output.txt","w");
    
    if (fileOut == NULL)
    {
        return -1;
    }
   

    for (i=0; i<5; i++)
    {
        fprintf(fileOut,"hello\n");
    }


    return 0;
}
