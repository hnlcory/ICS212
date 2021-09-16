#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 10;
    char c1 = 'A';
    char c2 = 'B';
    float score1 = 20.5;
    char ca[3] = "Hi";

    printf("before dummy call:\n");
    printf("num1 %i\n",num1);
    printf("num2 %i\n",num2);

    printf("c1  %c\n",c1);
    printf("c2  %c\n",c2);

    printf("score1 %f\n",score1);

    printf("ca[0] %c\n",ca[0]); 
    printf("ca[1] %c\n",ca[1]);
    printf("ca[2] %c\n",ca[2]);



    dummy(num2, c1, ca, score1);

    return 0;
}

void dummy(int x, char y, char* z, float w)
{
 
    printf("\ndummy called:\n");
    printf("x %i\n",x);
    printf("y %c\n",y);
    printf("z %s\n",z);
    printf("w %f\n",w);

    x++;
    y++;
    w = w + 2.1;


    printf("\npost dummp:\n");
    printf("x %i\n",x);
    printf("y %c\n",y);
    printf("w %f\n",w);
    /* pause here */
}
