#include <stdio.h>
#include <string.h>
#include "global.h"
#include "string_.h"

int writePInfo2File(char *fileName, person *p)
{
    /*
    input:
        - filename where to write struct elements.
        - struct pointer for person array.
    */
    int i = 0;
    char string_bucket[40];

    // file open for writing mode. It will overwrites the file contents what it has previously.
    FILE *fp = fopen(fileName, "w");

    printf("current person struct size : %lu \n", sizeof(p));

    if (p == NULL)
    {
        printf("now, no element in PhoneBook. \n");
        fclose(fp);
        return 1;
    }
    else
    {
        // write 1st element on the file.
        strcpy(string_bucket, p[i].name);
        strcat(string_bucket, ",");
        strcat(string_bucket, p[i].pNumber);
        fputs(string_bucket, fp);

        i++;
        // loop from 2nd element till the end element.
        while (getTotalPersonNum(p) != i)
        {
            fputs("\n", fp);
            strcpy(string_bucket, p[i].name);
            strcat(string_bucket, ",");
            strcat(string_bucket, p[i].pNumber);
            fputs(string_bucket, fp);
            i++;
        }
        fclose(fp);
        return 0;
    }
}