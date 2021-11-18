#include <iostream>
#include "circle.h"

Circle::Circle()
{
    std::cout << "Circle constructor" << std::endl;
}

Circle::~Circle()
{
    std::cout << "Circle deconstructor" << std::endl;
}

int Circle::getradius()
{
    return this->radius;
}

void Circle::setradius(int r)
{
    this->radius = r;
}


