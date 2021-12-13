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
//  FILE:        unown.cpp
//
//  DESCRIPTION:
//   Pokemon member function file for Unown
//
****************************************************************/

#include "unown.h"

unown::unown()
{
    std::cout << "\nUnown Constructor\n";
    this->name = "Unown";
    this->weight = 11.0;
    this->type = "Psychic";
}

unown::~unown()
{
    std::cout << "\nUnown Destructor\n";
}

void unown::printData()
{
    std::cout << "\nName: " << this->name << "\nWeight: " << this->weight << "\nType: " << this->type << std::endl;
}
