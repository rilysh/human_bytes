### human_bytes
C library to convert bytes to human readable format

### Usage
A minimal example
```c
#define IEC_SPEC
#include <stdio.h>
#include <stdlib.h>

#include "hubytes.h"

int main()
{
    FILE *fp;
    char *hb;

    fp = fopen("example.txt", "r");

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
```

Here `IEC_SPEC` refers that it'll use format that doesn't have "i" in the middle or more simply with a unit size of 2^10 = 1024 and without `IEC_SPEC` unit size will be 10^3 = 1000

### Why
Because Rust has these kinds of libraries so why not C?

### Note
TCC doesn't support alias naming, which means `weak_alias` wouldn't work on TCC. You can fix this by directly using function definition or macroing the function to link with another.
