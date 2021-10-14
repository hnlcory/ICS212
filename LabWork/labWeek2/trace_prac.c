#include <stdio.h>

int main(int argc, char *argv[])
{
    int a[2];
    int *p;

    p = &a[1];
    a[0] = 10;

    return 0;
}

