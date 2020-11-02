#include <stdio.h>
#include <stdlib.h> // malloc, free가 포함된 라이브러리
#include <string.h>
#include "global.h"
#include "menu.h"
#include "string_.h"
#include "handleFile.h"

int main()
{
    char user_choice;

    while (1)
    {
        printf("\n*----- mini phonebook program -----*\n");
        printf("*-----          menu          -----*\n\n");
        printf("1. add \n");
        printf("2. search \n");
        printf("3. update \n");
        printf("4. delete \n");
        printf("5. printAll \n");
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
            printf("*----- delete -----* \n");

            // show all person infos.
            showAll();

            // delete function start.
            char delete_confirm;
            int delete_number = 0;
            int total_lines = 0;

            printf("\ndelete by NUMBER : ");
            scanf("%d", &delete_number);
            getchar();

            int i_onStruct = 0;
            i_onStruct = delete_number - 1;

            // p4 : array type data
            person *p4 = getPersonInfo(FILE_NAME);
            total_lines = checkTotalLines(FILE_NAME);

            // check whether delete_number input is correct.
            if (delete_number > total_lines || delete_number < 1)
            {
                printf("ERROR delete number Input. Out of Range ! \n");
                printf("This Phonebook has %d Person info. \n", total_lines);
                continue;
            }

            printf("delete this ? -> %d. %s ** %s ",
                   p4[i_onStruct].info_index,
                   p4[i_onStruct].name,
                   p4[i_onStruct].pNumber);
            printf("( Y / N ) : ");
            scanf("%c", &delete_confirm);
            getchar();

            // Todos...
            if (delete_confirm == 'Y' || delete_confirm == 'y')
            {
                // Delete the specified element by overwriting and update total number of array and its order.
                while (i_onStruct != total_lines)
                {
                    p4[i_onStruct] = p4[i_onStruct + 1];
                    p4[i_onStruct].info_index--;
                    i_onStruct++;
                }
                // updating total person info.
                total_lines--;

                printf("Person List after Deleting a Element. \n\n");
                for (int i_tmp = 0; i_tmp < total_lines; i_tmp++)
                {
                    printf("%d. %s *** %s \n", p4[i_tmp].info_index, p4[i_tmp].name, p4[i_tmp].pNumber);
                }

                printf("\n3. overwrite on the FILE.\n");
                // write on test file...
                writePInfo2File(FILE_TEST, p4);
            }
            else if (delete_confirm == 'N' || delete_confirm == 'n')
            {
                printf("not deleting. \n");
                continue;
            }
            else
            {
                printf("ERROR Input. Please Choose Y or N");
            }
            free(p4);
        }
        else if (user_choice == '5')
        {
            printf("\n*----- showAll -----* \n\n");
            showAll();
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