#ifndef STRING_H
#define STRING_H

#include "global.h"

person *splitString(char *original_string);
int checkTotalLines(char *fileName);
int getTotalPersonNum(person *p1);
char *deleteEndNull(char *original_string);

#endif