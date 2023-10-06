#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "global.h"
#include "string_.h"
#include "handleFile.h"

void showMatchedResult(int search_index, person *matched_person[30]);

int addPerson()
{
    /*
    add_person function
    in : name(str), phone number(str)
    out : write the info on csv file.
    */
    printf(START_ADD);

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

    // fseek make a role as reseting current stream position.
    fseek(fp, 0, SEEK_END);
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

int isFileExist(char *filename)
{
    /*
    rtn
        0 : not exist
        1 : exist
    */

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf(WARN_NO_fileEXIST);
        return 0;
    }

    return 1;
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

    printf(START_SEARCH);

    // checking search target text file.
    if (!isFileExist(FILE_NAME)) return -1;
    FILE *fp = fopen(FILE_NAME, "r");

    char search_by;
    while (1)
    {
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

int showAll(char *filename)
{
    if (!isFileExist(filename)) return -1;
    FILE *fp = fopen(filename, "r");

    // printf(START_PALL);
    printAll(fp);
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

    int i = 0;
    int i_lines = 0;

    i_lines = checkTotalLines(fileName);

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("getPersonInfo File Input ERROR ! \n");
    }

    char temp_string[40] = "";
    person *pAll = (person *)malloc(sizeof(person) * 20);
    person *pOne;

    rewind(fp);
    while (!feof(fp))
    {
        fgets(temp_string, 40, fp);
        if (i_lines - 1 != i)
        {
            // 전화번호 파일의 마지막 줄은 개행문자가 없으므로, 마지막 줄은 제외!
            deleteEndNull(temp_string);
        }
        pOne = splitString(temp_string);
        pAll[i].info_index = i + 1;
        strcpy(pAll[i].name, pOne->name);
        strcpy(pAll[i].pNumber, pOne->pNumber);
        i++;
    }

    fclose(fp);

    return pAll;
}

int deletePerson(char *fileName)
{
    printf(START_DELETE);
    int rtn = 0;

    // checking search target text file.
    if (!isFileExist(fileName)) return -1;

    // show all person infos.
    rtn = showAll(fileName);

    // delete function start.
    char delete_confirm;
    int delete_number = 0;
    int total_lines = 0;

    printf("\n DELETE BY NUMBER : ");
    scanf("%d", &delete_number);
    getchar();

    int i_onStruct = 0;
    i_onStruct = delete_number - 1;

    // p4 : array type data
    person *p4 = getPersonInfo(fileName);
    total_lines = checkTotalLines(fileName);

    // check whether delete_number input is correct.
    if (delete_number > total_lines || delete_number < 1)
    {
        printf("ERROR delete number Input. Out of Range ! \n");
        printf("This Phonebook has %d Person info. \n", total_lines);
        return 1;
    }

    printf("delete this ? -> %d. %s ** %s ",
           p4[i_onStruct].info_index,
           p4[i_onStruct].name,
           p4[i_onStruct].pNumber);
    printf("( Y / N ) : ");
    scanf("%c", &delete_confirm);
    getchar();

    if (delete_confirm == 'Y' || delete_confirm == 'y')
    {
        if (total_lines == 1)
        {
            printf("last one element deleted ... \n");
            // make 0 index item to '\0' text.
            // by using memset
            memset(p4[0].name, '\0', sizeof(p4[0].name));
            memset(p4[0].pNumber, '\0', sizeof(p4[0].pNumber));

            fileMakeEmpty(fileName);
        }
        else
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
            // write on test file...
            writePInfo2File(fileName, p4);
        }
    }
    else if (delete_confirm == 'N' || delete_confirm == 'n')
    {
        printf("not deleting. \n");
        return 0;
    }
    else
    {
        printf("ERROR Input. Please Choose Y or N");
    }
    free(p4);
    return 0;
}

int updatePerson(char *fileName)
{
    printf(START_UPDATE);
    int rtn = 0;

    // checking search target text file.
    if (!isFileExist(FILE_NAME)) return -1;

    // show all person infos.
    rtn = showAll(fileName);

    // delete function start.
    char update_confirm;
    int update_number = 0;
    char new_name[20] = "";
    char new_number[20] = "";
    int total_lines = 0;
    total_lines = checkTotalLines(fileName);

    printf("\nSELECT BY NUMBER : ");
    scanf("%d", &update_number);
    getchar();

    int i_onStruct = 0;
    i_onStruct = update_number - 1;

    // p4 : array type data
    person *p3 = getPersonInfo(fileName);
    printf("UPDATE PERSON : %d. %s *** %s \n",
           p3[i_onStruct].info_index,
           p3[i_onStruct].name,
           p3[i_onStruct].pNumber);

    printf("NEW NAME : ");
    scanf("%s", new_name);
    getchar();
    printf("NEW NUMBER : ");
    scanf("%s", new_number);
    getchar();

    printf("Are you sure ? ( Y / N ) : ");
    scanf("%c", &update_confirm);
    getchar();

    // update the struct p3 element and write updated struct p3 on the file.
    if (update_confirm == 'Y' || update_confirm == 'y')
    {
        // initialize name and pNumber
        strcpy(p3[i_onStruct].name, "");
        strcpy(p3[i_onStruct].pNumber, "");

        // write new name and number on the specified struct element.
        strcpy(p3[i_onStruct].name, new_name);
        strcpy(p3[i_onStruct].pNumber, new_number);

        // write updated p3 on the file.
        writePInfo2File(fileName, p3);
    }
    else if (update_confirm == 'N' || update_confirm == 'n')
    {
        printf("Cancel Info Update. \n");
    }
    else
    {
        printf("Wrong Input. It takes Y or N \n");
    }

    free(p3);
    return 0;
}