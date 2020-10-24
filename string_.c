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

    return p;
}