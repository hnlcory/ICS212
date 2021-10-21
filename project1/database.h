/***************************************************************************
//
//    NAME:         Cory Parker
//
//    HOMEWORK:     3b
//
//    CLASS:        ICS 212
//
//    INSTRUCTOR:   Ravi Narayan
//
//    DATE:         September 20, 2021
//
//    FILE:         database.h
//
//    DESCRIPTION:  Header file for database.c
//
****************************************************************************/

    #include "record.h"

    int addRecord (struct record **, int, char [],char []);

    void printAllRecords(struct record *);

    int findRecord (struct record *, int);

    int deleteRecord(struct record **, int);

    int readfile(struct record **, char []);

    int writefile(struct record *, char []);

    void cleanup(struct record **);
