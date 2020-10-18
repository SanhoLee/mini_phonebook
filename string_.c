#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "string_.h"

person *splitString(char *originalString)
{
    int i = 0;

    person *p = malloc(sizeof(person));
    char *result;
    char *strArr[2];

    result = strtok(originalString, delimeter);
    while (result != NULL)
    {
        strArr[i] = result;
        result = strtok(NULL, delimeter);
        i++;
    }

    // save on struct address by using array elemet.
    strcpy(p->name, strArr[0]);
    strcpy(p->pNumber, strArr[1]);

    return p;
}