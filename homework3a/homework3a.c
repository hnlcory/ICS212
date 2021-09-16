#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 10;
    char c1 = 'A';
    char c2 = 'B';
    float score1 = 20.5;
    char ca[3] = "Hi";

    printf("\n\nbefore dummy call:\n");

    printf("argc  %i\n",argc);
    /* printf("argv  %c\n",argv[]);*/


    printf("variable num1 is at address: %p\n", (void*)&num1);
    printf("num1 %i\n",num1);
    printf("variable num2 is at address: %p\n", (void*)&num2);
    printf("num2 %i\n",num2);


    printf("variable c1 is at address: %p\n", (void*)&c1);
    printf("c1 %c\n",c1);
    printf("variable c2 is at address: %p\n", (void*)&c2);
    printf("c2 %c\n",c2);

    printf("variable score1 is at address: %p\n", (void*)&score1);
    printf("score1 %f\n",score1);

    printf("variable ca[0] is at address: %p\n", (void*)&ca[0]);
    printf("ca[0] %c\n",ca[0]); 
    printf("variable ca[1] is at address: %p\n", (void*)&ca[1]);
    printf("ca[1] %c\n",ca[1]);
    printf("variable ca[2] is at address: %p\n", (void*)&ca[2]);
    printf("ca[2] %c\n",ca[2]);



    dummy(num2, c1, ca, score1);

    return 0;
}

void dummy(int x, char y, char* z, float w)
{
 
    printf("\ndummy called:\n");
    printf("variable x is at address: %p\n", (void*)&x);
    printf("x %i\n",x);
    printf("variable y is at address: %p\n", (void*)&y);
    printf("y %c\n",y);
    printf("variable z is at address: %p\n", (void*)&z);
    printf("z %s\n",z);
    printf("variable w is at address: %p\n", (void*)&w);
    printf("w %f\n",w);

    x++;
    y++;
    w = w + 2.1;


    printf("\npost dummy:\n");
    printf("variable x is at address: %p\n", (void*)&x);
    printf("x %i\n",x);
    printf("variable y is at address: %p\n", (void*)&y);
    printf("y %c\n",y);
    printf("variable w is at address: %p\n", (void*)&w);
    printf("w %f\n",w);
    /* pause here */
}
