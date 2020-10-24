#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "global.h"
#include "string_.h"

int addPerson()
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

int searchInfo()
{
    /*

    search_input can be name or phoneNumber.
    input  : index number for searching method.
        c or C - cancel searching method.
        1 - method by name
        2 - method by phone number

    todos :
        done .loop all elements [name, phone number] array type

        x
            .fitering by name or phone number
            .make array and append the element searched.
            .return data as array? pointer?

    return : filtered person struct info as array type.

    */

    char search_by;

    while (1)
    {
        printf("\n*----- search -----* \n\n");
        printf("( 1. name ?  2. Phone Number ? C : Cancel ) : ");
        scanf("%c", &search_by);
        getchar();

        char search_input[20] = "";

        if ((search_by == 'c') || (search_by == 'C'))
        {
            printf("\n Canceled...\n");
            return 0;
        }
        else if (search_by == '1')
        {
            // searching by name.--------------------------
            printf("\n searching by name : ");
            scanf("%s", search_input);
            getchar();

            FILE *fp;
            fp = fopen(FILE_NAME, "r");

            // check if target file is exist or not.
            if (fp == NULL)
            {
                printf("No file on specified diretory. \n");
                return 0;
            }
            else
            {
                while (!feof(fp))
                {
                    char single_line[40] = "";
                    if (fgets(single_line, 40, fp))
                    {
                        person *p21 = splitString(single_line);

                        // compare two string element. if true, it returns 0.
                        if (!strcmp(search_input, p21->name))
                        {
                            printf("\ncorrect ! \n");
                            printf("name: %s\n", p21->name);
                            printf("number: %s\n", p21->pNumber);
                        }

                        free(p21);
                    }
                    else
                    {
                        continue;
                    }
                }

                fclose(fp);
            }
        }
        else if (search_by == '2')
        {
            // searching by phone number.
            printf("\n searching by number...\n");
        }
        else
        {
            printf("Input Error. You should select from specified number or C(cancel) \n");
        }
    }
}