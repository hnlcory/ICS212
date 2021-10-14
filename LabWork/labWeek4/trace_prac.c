#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[2];
    int *p;

    p = &a[1];
    a[0] = 10;

    printf("\nint a[0]  %i\n",a[0]);
    printf("int a[1]  %i\n",a[1]);
    printf("int p %i\n",*p);


    return 0;
}

