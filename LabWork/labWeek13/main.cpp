#include <iostream>
#include "circle.h"

int main(int argc, char *argv[])
{
    Circle c1,c2;

    c1.setradius(5);
    c2.setradius(10);

    std::cout << "c1 radius: " << c1.getradius() << std::endl;
    std::cout << "c2 radius: " << c2.getradius() << std::endl;

    return 0;
}

