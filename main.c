#include <stdio.h>
#include <stdlib.h> // malloc, free가 포함된 라이브러리
#include <string.h>
#define FILE_NAME "phone-number.csv"

typedef struct
{
    /* data */
    char name[20];
    char pNumber[20];
} person;

int main()
{
    int userChoice;
    int num;
    int i;

    while (1)
    {
        printf("\n*----- mini phonebook program -----*\n");
        printf("*-----          menu          -----*\n\n");
        printf("1. add \n");
        printf("2. search \n");
        printf("3. update \n");
        printf("4. delete \n");
        printf("5. showAll \n");
        printf("9. EXIT \n");
        printf("\nSelect ? ");
        scanf("%d", &userChoice);
        printf("\n");

        if (userChoice == 1)
        {
            /* add_person function
            in : name(str), phone number(str)
            out : write the info on csv file.
            */
            person *p1 = malloc(sizeof(person));
            printf("\n NAME : ");
            scanf("%s", p1->name);
            printf(" PHONE NUMBER : ");
            scanf("%s", p1->pNumber);

            // 파일 입출력, csv file format
            FILE *fp;
            fp = fopen(FILE_NAME, "a");

            if (fp == NULL)
            {
                printf("Write Error \n");
                return 0;
            }
            fputs(p1->name, fp);
            fputs(",", fp);
            fputs(p1->pNumber, fp);
            fputs("\n", fp);
            free(p1);
            fclose(fp);
        }
        else if (userChoice == 2)
        {
            char searchBy;
            getchar();
            printf("\n*----- search -----* \n\n");
            printf("( 1. name ?  2. Phone Number ? C : Cancel ) : ");
            scanf("%c", &searchBy);
            if ((searchBy == 'c') || (searchBy == 'C'))
            {
                printf("\n Canceled...\n");
                continue;
            }
            else if (searchBy == '1')
            {
                // searching by name.
                printf("\n searching by name...\n");
            }
            else if (searchBy == '2')
            {
                // searching by phone number.
                printf("\n searching by number...\n");
            }
            else
            {
                printf("\n Input Error. You should select from specified number or C(cancel) \n");
                continue;
            }
        }
        else if (userChoice == 3)
        {
            printf("update");
        }
        else if (userChoice == 4)
        {
            printf("delete");
        }
        else if (userChoice == 5)
        {
            printf("\n*----- showAll -----* \n\n");
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
        else if (userChoice == 9)
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