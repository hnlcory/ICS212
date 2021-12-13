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
//  FILE:        lickitung.h
//
//  DESCRIPTION:
//   Pokemon class file for Lickitung
//
****************************************************************/

#include "pokemon.h"

class lickitung: public pokemon
{
protected:
    std::string name;

public:
    lickitung();
    virtual ~lickitung(); 
    void printData();
};
