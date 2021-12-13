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
//  FILE:        unown.h
//
//  DESCRIPTION:
//   Pokemon class file for Unown
//
****************************************************************/

#include "pokemon.h"

class unown: public pokemon
{
protected:
    std::string name;

public:
    unown();
    virtual ~unown();
    void printData(); 
};              
