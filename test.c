#define IEC_SPEC
#include <stdio.h>
#include <stdlib.h>

#include "hubytes.h"

int main()
{
    FILE *fp;
    char *hb;

    fp = fopen("a.out", "rb");

    if (fp == NULL) {
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    hb = human_bytes_from_file(fp);
    fprintf(stdout, "%s\n", hb);

    hb = human_bytes(10000);
    fprintf(stdout, "%s\n", hb);

    free(hb);
}
