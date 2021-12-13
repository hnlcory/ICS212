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
//  FILE:        sunkern.cpp
//
//  DESCRIPTION:
//   Pokemon member function file for Sunkern
//
****************************************************************/

#include "sunkern.h"

sunkern::sunkern()
{
    std::cout << "\nSunkern Constructor\n";
    this->name = "Sunkern";
    this->weight = 4.0;
    this->type = "Grass";
}

sunkern::~sunkern()
{
    std::cout << "\nSunkern Destructor\n";
}

void sunkern::printData()
{
    //pokemon::printData();
    std::cout << "\nName: " << this->name << "\nWeight: " << this->weight << "\nType: " << this->type << std::endl;
}
