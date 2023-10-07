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

int writePInfo2File_v2(char *fileName, person *p, int totNum)
{
    /*
    input:
        - filename where to write struct elements.
        - struct pointer for person array.
    */
    char string_bucket[40];
    memset(string_bucket, '\0', sizeof(string_bucket));

    // file open for writing mode. It will overwrites the file contents what it has previously.
    FILE *fp = fopen(fileName, "w");

    if (p == NULL)
    {
        printf("now, no element in PhoneBook. \n");
        fclose(fp);
        return -1;
    }
    else
    {
        // 1st item.
        strcpy(string_bucket, p[0].name);
        strcat(string_bucket, ",");
        strcat(string_bucket, p[0].pNumber);
        fputs(string_bucket, fp);

        for(int i=1;i<totNum;i++){
            fputs("\n", fp);
            strcpy(string_bucket, p[i].name);
            strcat(string_bucket, ",");
            strcat(string_bucket, p[i].pNumber);
            fputs(string_bucket, fp);
        }

        fclose(fp);
        return 0;
    }
}

int fileMakeEmpty(char *fileName)
{
    // overwriting to new empty file.
    FILE *fp = fopen(fileName, "w");
    fclose(fp);

    return 0;
}