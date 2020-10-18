#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "global.h"

int add_person()
{
    /* 
    add_person function
    in : name(str), phone number(str)
    out : write the info on csv file.
    */
    person *p1 = malloc(sizeof(person));
    printf("\n NAME : ");
    scanf("%s", p1->name);
    getchar();
    printf(" PHONE NUMBER : ");
    scanf("%s", p1->pNumber);
    getchar();

    // 파일 입출력, csv file format
    FILE *fp;
    fp = fopen(FILE_NAME, "a");

    if (fp == NULL)
    {
        printf("Write Error \n");
        return 1;
    }
    fputs(p1->name, fp);
    fputs(",", fp);
    fputs(p1->pNumber, fp);
    fputs("\n", fp);
    free(p1);
    fclose(fp);

    return 0;
}
