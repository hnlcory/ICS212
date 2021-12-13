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
//  FILE:        pokemon.h
//
//  DESCRIPTION:
//   Pokemon class file for Pokemon
//
****************************************************************/

#ifndef pokemon_guard
#define pokemon_guard

#include <string>
#include <iostream>

class pokemon 
{

protected:
    std::string type;
    float weight;

public:
    pokemon();
    virtual ~pokemon();
    virtual void printData()=0;
};

#endif
