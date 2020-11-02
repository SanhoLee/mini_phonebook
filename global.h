#ifndef GLOBAL_H
#define GLOBAL_H

#define delimeter ","
#define FILE_NAME "phone-number.csv"
#define FILE_TEST "test.csv"

#define SEARCH_NAME '1'
#define SEARCH_NUMBER '2'

#define VALUE "value"
#define PTR "ptr"

typedef struct
{
    /* data */
    int info_index;
    char name[20];
    char pNumber[20];
} person;

#endif