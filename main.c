#include <stdio.h>
#include <string.h>

struct person
{
    /* data */
    char name[20];
    int age;
    char address[40];
};

void askingInfo(int num, struct person *instance);

int main()
{
    int num;
    int i;

    printf("number of peeple : ");
    scanf("%d", &num);

    // 구조체 배열 정의?
    struct person p1[num - 1];

    // Asking Info for n-1 times.
    askingInfo(num, p1);

    printf("\n ***** output ***** \n");
    for (i = 0; i < num; i++)
    {
        printf(" ----- %d ----- \n", i + 1);
        printf("이름 : %s\n", p1[i].name);
    }

    return 0;
}

void askingInfo(int num, struct person *instance)
{
    for (int i = 0; i < num; i++)
    {
        printf(" ----- %d ----- \n", i + 1);
        printf("이름 : ");
        scanf("%s", instance[i].name);
    }
}