#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "global.h"
#include "string_.h"

void showMatchedResult(int search_index, person *matched_person[30]);

int addPerson()
{
    /* 
    add_person function
    in : name(str), phone number(str)
    out : write the info on csv file.
    */
    printf("\n*----- addPerson -----* \n\n");

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
        else if (search_by == SEARCH_NAME || search_by == SEARCH_NUMBER)
        {

            FILE *fp;
            fp = fopen(FILE_NAME, "r");
            // check if target file is exist or not.
            if (fp == NULL)
            {
                printf("No file specified on diretory. \n");
                return 0;
            }

            // 구조체를 자료형을 가지는 배열을 선언
            // 임시로 배열 크기는 30으로 지정 -> 추후 전체 데이터 수를 참조해서 크기를 지정하는 방법으로 변경.
            person *filtered_person_array[30];
            int searched_index = 0;
            int i = 0;

            switch (search_by)
            {
            case SEARCH_NAME:
                // searching by name.--------------------------
                printf("\n searching by name : ");
                scanf("%s", search_input);
                getchar();
                // filtering person info by search term entered.
                while (!feof(fp))
                {
                    char single_line[40] = "";
                    if (fgets(single_line, 40, fp))
                    {
                        // delete return charater "\n" at end of string.
                        deleteEndNull(single_line);
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
                showMatchedResult(searched_index, filtered_person_array);

                fclose(fp);
                break;

            case SEARCH_NUMBER:
                // searching by number.--------------------------
                printf("\n searching by number : ");
                scanf("%s", search_input);
                getchar();

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
                showMatchedResult(searched_index, filtered_person_array);

                fclose(fp);
                break;
            default:
                //
                break;
            }
        }
        else
        {
            printf("Input Error. You should select from specified number or C(cancel) \n");
            return 1;
        }
    }
    return 0;
}

void printAll(FILE *fp)
{
    int i = 0;

    while (!feof(fp))
    {
        char one_line[40] = "";
        fgets(one_line, 40, fp);
        printf("%d. %s", i + 1, one_line);
        i++;
    }
    printf("\n\nLIST END\n");
    fclose(fp);
}

int showAll()
{
    FILE *fp;
    fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("File Input Error. \n");
        return 0;
    }
    else
    {
        printAll(fp);
    }
    fclose(fp);
    return 0;
}
void showMatchedResult(int search_index, person *matched_person[30])
{
    // show matched result....
    int i = 0;
    printf("number of matched : %d \n", search_index);
    for (i = 0; i < search_index; i++)
    {
        printf("%d. %s %s\n",
               matched_person[i]->info_index,
               matched_person[i]->name,
               matched_person[i]->pNumber);
    }
}

person *getPersonInfo(char *fileName)
{
    /*

    input(string) : filename for read/write.
    return(array of struct) : pAll - array of persons info.
    
    */
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("getPersonInfo File Input ERROR ! \n");
    }
    rewind(fp);

    char temp_string[40] = "";
    person *pAll = (person *)malloc(sizeof(person) * 20);
    person *pOne;

    fgets(temp_string, 40, fp);
    deleteEndNull(temp_string);
    pOne = splitString(temp_string);
    pAll[0].info_index = 1;
    strcpy(pAll[0].name, pOne->name);
    strcpy(pAll[0].pNumber, pOne->pNumber);

    fgets(temp_string, 40, fp);
    deleteEndNull(temp_string);
    pOne = splitString(temp_string);
    pAll[1].info_index = 2;
    strcpy(pAll[1].name, pOne->name);
    strcpy(pAll[1].pNumber, pOne->pNumber);

    fgets(temp_string, 40, fp);
    deleteEndNull(temp_string);
    pOne = splitString(temp_string);
    pAll[2].info_index = 3;
    strcpy(pAll[2].name, pOne->name);
    strcpy(pAll[2].pNumber, pOne->pNumber);

    printf("%d. %s ** %s \n", pAll[0].info_index, pAll[0].name, pAll[0].pNumber);
    printf("%d. %s ** %s \n", pAll[1].info_index, pAll[1].name, pAll[1].pNumber);
    printf("%d. %s ** %s \n", pAll[2].info_index, pAll[2].name, pAll[2].pNumber);

    fclose(fp);

    return pAll;
}