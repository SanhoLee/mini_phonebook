#ifndef MENU_H
#define MENU_H
#include "global.h"

int add_person();
int searchInfo();
void printAll(FILE *fp);
int showAll();
person *getPersonInfo(char *fileName);

#endif