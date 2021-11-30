/*****************************************************************
//
//  NAME:        Cory Parker
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 18, 2021
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   The class for a linked list of records. Contains the private
//   and public methods.
//
****************************************************************/

#ifndef llist_guard
#define llist_guard

#include "record.h"

class llist
{
private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    void        cleanup();

public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord(int, char [ ],char [ ]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
};

#endif
