#include <stdio.h>
#include "global.h"
#include "string_.h"

void writePInfo2File(char *fileName, person *p)
{
    /*
    input:
        - filename where to write struct elements.
        - struct pointer for person array.
    */
    int p_num = getTotalPersonNum(p);

    // file open for writing mode. It will overwrites the file contents what it has previously.
    FILE *fp = fopen(fileName, "w");

    // fclose(fp);
}