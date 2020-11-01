#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "string_.h"

person *splitString(char *original_string)
{
    int i = 0;

    person *p = malloc(sizeof(person));
    char *result;
    char *str_array[2];

    result = strtok(original_string, delimeter);
    while (result != NULL)
    {
        str_array[i] = result;
        result = strtok(NULL, delimeter);
        i++;
    }

    // save on struct address by using array elemet.
    strcpy(p->name, str_array[0]);
    strcpy(p->pNumber, str_array[1]);
    p->info_index = 0;

    return p;
}

int checkTotalLines(char *fileName)
{

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("checkTotalLines File Input ERROR ! \n");
    }
    rewind(fp);

    // fp : 파일은 fopen 한 상태에서 호출해야함.
    int line_index = 0;
    char temp_string[40] = "";

    while (!feof(fp))
    {
        fgets(temp_string, 40, fp);
        line_index++;
    }

    fclose(fp);

    return line_index;
}

char *deleteEndNull(char *original_string)
{
    original_string[strlen(original_string) - 1] = '\0';
    return original_string;
}