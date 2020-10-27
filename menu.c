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

    long size;

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

    size = ftell(fp);

    if (size != 0)
    {
        fputs("\n", fp);
    }
    fputs(p1->name, fp);
    fputs(",", fp);
    fputs(p1->pNumber, fp);
    free(p1);
    fclose(fp);

    return 0;
}

int searchInfo()
{
    /*

    search_input can be name or phoneNumber.
    input  : searched_index number for searching method.
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
        else if (search_by == SEARCH_NAME)
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
                printf("No file specified on diretory. \n");
                return 0;
            }
            else
            {
                // 구조체를 자료형을 가지는 배열을 선언
                // 임시로 배열 크기는 30으로 지정 -> 추후 전체 데이터 수를 참조해서 크기를 지정하는 방법으로 변경.
                person *filtered_person_array[30] = {};
                int searched_index = 0;
                int i = 0;

                // filtering person info by search term entered.
                while (!feof(fp))
                {
                    char single_line[40] = "";
                    if (fgets(single_line, 40, fp))
                    {
                        // delete return charater "\n" at end of string.
                        single_line[strlen(single_line) - 1] = '\0';
                        // split line by delimeter , and make struct data.
                        person *p21 = splitString(single_line);

                        // get the order among total info elements.
                        p21->info_index = i + 1;

                        // compare two string element. if true, it returns 0.
                        if (!strcmp(search_input, p21->name))
                        {
                            // 검색조건에 맞는 구조체이면, 배열에 담는다
                            filtered_person_array[searched_index] = p21;
                            searched_index++;
                        }
                        // Global index increase..
                        i++;
                    }
                    else
                    {
                        continue;
                    }
                }

                // show matched result....
                printf("number of matched : %d \n", searched_index);
                for (i = 0; i < searched_index; i++)
                {
                    printf("%d. %s %s",
                           filtered_person_array[i]->info_index,
                           filtered_person_array[i]->name,
                           filtered_person_array[i]->pNumber);
                }

                fclose(fp);
            }
        }
        else if (search_by == SEARCH_NUMBER)
        {
            // searching by phone number.
            printf("\n searching by number : ");
            scanf("%s", search_input);
            getchar();

            FILE *fp;
            fp = fopen(FILE_NAME, "r");

            // check if target file is exist or not.
            if (fp == NULL)
            {
                printf("No file specified on diretory. \n");
                return 0;
            }
            else
            {
                // 구조체를 자료형을 가지는 배열을 선언
                // 임시로 배열 크기는 30으로 지정 -> 추후 전체 데이터 수를 참조해서 크기를 지정하는 방법으로 변경.
                person *filtered_person_array[30] = {};
                int searched_index = 0;
                int i = 0;

                // filtering person info by search term entered.
                while (!feof(fp))
                {
                    char single_line[40] = "";
                    if (fgets(single_line, 40, fp))
                    {
                        // delete return charater "\n" at end of string.
                        single_line[strlen(single_line) - 1] = '\0';
                        // split line by delimeter , and make struct data.
                        person *p21 = splitString(single_line);

                        // get the order among total info elements.
                        p21->info_index = i + 1;

                        // compare two string element. if true, it returns 0.
                        if (!strcmp(search_input, p21->pNumber))
                        {
                            // 검색조건에 맞는 구조체이면, 배열에 담는다
                            filtered_person_array[searched_index] = p21;
                            searched_index++;
                        }
                        // Global index increase..
                        i++;
                    }
                    else
                    {
                        continue;
                    }
                }

                // show matched result....
                printf("number of matched : %d \n", searched_index);
                for (i = 0; i < searched_index; i++)
                {
                    printf("%d. %s %s\n",
                           filtered_person_array[i]->info_index,
                           filtered_person_array[i]->name,
                           filtered_person_array[i]->pNumber);
                }

                fclose(fp);
            }
        }
        else
        {
            printf("Input Error. You should select from specified number or C(cancel) \n");
        }
    }
}