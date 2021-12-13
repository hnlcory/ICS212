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
//  FILE:        sunkern.h
//
//  DESCRIPTION:
//   Pokemon class file for Sunkern
//
****************************************************************/

#include "pokemon.h"

class sunkern: public pokemon
{
protected:
    std::string name;

public:
    sunkern();
    virtual ~sunkern();
    void printData();
};        
