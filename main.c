#include <stdio.h>
#include <stdlib.h> // malloc, free가 포함된 라이브러리
#include <string.h>
#include "global.h"
#include "menu.h"
#include "string_.h"

int main()
{
    char userChoice;
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
                else
                {
                    while (!feof(fp))
                    {
                        char singleLine[40] = "";
                        // fgets(singleLine, 40, fp);
                        if (fgets(singleLine, 40, fp))
                        {
                            person *p21 = splitString(singleLine);
                            printf("check read on struct elemet ---+ \n");
                            printf("name: %s\n", p21->name);
                            printf("number: %s\n", p21->pNumber);

                            // To do : filtering p21 info by name.....
                            // add filtered data into result array.

                            free(p21);
                        }
                        else
                        {
                            break;
                        }
                    }

                    fclose(fp);
                }
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