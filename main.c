#include <stdio.h>
#include <stdlib.h> // malloc, free가 포함된 라이브러리
#include <string.h>

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
            fp = fopen("phone-number.csv", "a");

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
    };

    // 구조체 배열 정의?
    // struct person p1[num - 1];

    // Asking Info for n-1 times.
    // askingInfo(num, p1);

    return 0;
}