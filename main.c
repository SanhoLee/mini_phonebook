#include <stdio.h>
#include <stdlib.h> // malloc, free가 포함된 라이브러리
#include <string.h>
#include "global.h"
#include "menu.h"
#include "string_.h"

int main()
{
    char user_choice;

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
        scanf("%c", &user_choice);
        getchar();
        printf("\n");

        if (user_choice == '1')
        {
            addPerson();
        }
        else if (user_choice == '2')
        {
            /* search function.
            get data by name or phone number.

            */
            searchInfo();
        }
        else if (user_choice == '3')
        {
            printf("update");
        }
        else if (user_choice == '4')
        {
            printf("delete");
        }
        else if (user_choice == '5')
        {
            FILE *fp;
            fp = fopen(FILE_NAME, "r");
            if (fp == NULL)
            {
                printf("Write Error. \n");
                return 0;
            }
            else
            {
                showAll(fp);
            }
        }
        else if (user_choice == '9')
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
        그렇기 때문에, user_choice 인덱스 값을 0으로 초기화 해줌.
        */
        user_choice = 0;
    };
    return 0;
}