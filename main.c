#include <stdio.h>
#include <stdlib.h> // malloc, free가 포함된 라이브러리
#include <string.h>
#include "global.h"

int add_person();
person *splitString(char *originalString);

int main()
{
    char userChoice;
    int num;
    int i;

    while (1)
    {
        printf("*----- mini phonebook program -----*\n");
        printf("*-----          menu          -----*\n\n");
        printf("1. add \n");
        printf("2. search \n");
        printf("3. update \n");
        printf("4. delete \n");
        printf("5. showAll \n");
        printf("9. EXIT \n");
        printf("\nSelect ? ");
        scanf("%c", &userChoice);
        getchar();
        printf("\n");

        if (userChoice == '1')
        {
            add_person();
        }
        else if (userChoice == '2')
        {
            /* search function.
            get data by name or phone number.

            */
            char searchBy;
            char term[20] = "";
            char singleLine[40] = "";
            printf("\n*----- search -----* \n\n");
            printf("( 1. name ?  2. Phone Number ? C : Cancel ) : ");
            scanf("%c", &searchBy);
            getchar();
            if ((searchBy == 'c') || (searchBy == 'C'))
            {
                printf("\n Canceled...\n");
                continue;
            }
            else if (searchBy == '1')
            {
                // searching by name.
                printf("\n searching by name : ");
                scanf("%s", term);
                getchar();

                FILE *fp;
                fp = fopen(FILE_NAME, "r");
                if (fp == NULL)
                {
                    printf("No file on specified diretory. \n");
                    return 0;
                }

                fgets(singleLine, 40, fp);
                person *p21 = splitString(singleLine);
                printf("\ncheck read on struct elemet ---+ \n");
                printf("name: %s\n", p21->name);
                printf("number: %s\n", p21->pNumber);

                free(p21);
                fclose(fp);
            }
            else if (searchBy == '2')
            {
                // searching by phone number.
                printf("\n searching by number...\n");
            }
            else
            {
                printf("Input Error. You should select from specified number or C(cancel) \n");
                continue;
            }
        }
        else if (userChoice == '3')
        {
            printf("update");
        }
        else if (userChoice == '4')
        {
            printf("delete");
        }
        else if (userChoice == '5')
        {
            printf("*----- showAll -----* \n\n");
            FILE *fp;
            fp = fopen(FILE_NAME, "r");
            if (fp == NULL)
            {
                printf("Write Error. \n");
                return 0;
            }

            i = 0;
            while (!feof(fp))
            {
                char oneLine[100] = "";
                fgets(oneLine, 100, fp);
                printf("%d. %s", i + 1, oneLine);
                i++;
            }
            printf("\n\nLIST END\n");
            fclose(fp);
        }
        else if (userChoice == '9')
        {
            printf("***** PROGRAM END ***** \n");
            break;
        }
        else
        {
            printf("INPUT ERROR ! SELECT FROM MENU ! \n");
            return 1;
        }
        /*
        문자 입력으로 잘못 받을 경우, 버퍼에 이전에 입력했던 정수형 데이터를 가지고 있어서, else로 처리하지 못함.
        그렇기 때문에, userChoice 인덱스 값을 0으로 초기화 해줌.
        */
        userChoice = 0;
    };
    return 0;
}

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