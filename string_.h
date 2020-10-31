#ifndef STRING_H
#define STRING_H

#include "global.h"

person *splitString(char *original_string);
int checkTotalLines(FILE *fp);
char *deleteEndNull(char *original_string);

#endif