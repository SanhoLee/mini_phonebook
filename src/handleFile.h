#ifndef HANDLE_FILE_H
#define HANDLE_FILE_H

int writePInfo2File(char *fileName, person *p);
int writePInfo2File_v2(char *fileName, person *p, int totNum);
int fileMakeEmpty(char *fileName);

#endif