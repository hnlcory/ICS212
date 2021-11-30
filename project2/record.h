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
//    FILE:         record.h
//
//    DESCRIPTION:  Contains the struct record
//
****************************************************************************/

#ifndef record_guard
#define record_guard

struct record
{
    int                accountno;
    char               name[25];
    char               address[50];
    struct record*     next;
};

#endif
