#ifndef MENU_H
#define MENU_H
#include "global.h"

int addPerson();
int searchInfo();
void printAll(FILE *fp);
int showAll();
person *getPersonInfo(char *fileName);
int deletePerson(char *fileName);
int updatePerson(char *fileName);
int isFileExist(char *filename);

#endif