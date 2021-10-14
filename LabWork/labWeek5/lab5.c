#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    /* Write your code here */
    int len;
    int i;

    for (i = 0; i < argc ; i++){
        printf("\nArgument %i: ",i);
        printf("%s ",argv[i]);

        len =  strlen(argv[i]);
        printf("%i\n",len);
    }

  
    return 0;
}
