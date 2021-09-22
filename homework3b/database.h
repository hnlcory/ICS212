
/***************************************************************************
//
//    NAME:         
//    HOMEWORK:     Assignment 3b
//    CLASS:        ICS 212
//    INSTRUCTOR:   
//    DATE:         Sep 21, 2021
//    FILE:         database.h
//    DESCRIPTION:  This is the header file for database.c
//
****************************************************************************/ 
    #include "record.h"

    int addRecord (struct record **, int, char [],char []);

    void printAllRecords(struct record *);

    int findRecord (struct record *, int);

    int deleteRecord(struct record **, int);
