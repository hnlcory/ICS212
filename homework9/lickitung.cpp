/*****************************************************************
//
//  NAME:        Cory Parker
//
//  HOMEWORK:    Homework 9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 30, 2021
//
//  FILE:        lickitung.cpp
//
//  DESCRIPTION:
//   Pokemon member function file for Lickitung
//
****************************************************************/

#include "lickitung.h"

lickitung::lickitung()
{
    std::cout << "\nLickitung Constructor\n";
    this->name = "Lickitung";
    this->weight = 144.4;
    this->type = "Normal";
}

lickitung::~lickitung()
{
    std::cout << "\nLickitung Destructor\n";
}

void lickitung::printData()
{
    std::cout << "\nName: " << this->name << "\nWeight: " << this->weight << "\nType: " << this->type << std::endl;
}
