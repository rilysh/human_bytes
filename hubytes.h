#ifndef HUBYTES_H
#define HUBYTES_H   1

#ifdef __TINYC__
    #error Error: TCC is unsupported, please see the README, for more info 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define STOR_SIZE   30
#ifndef weak_alias
    #define weak_alias(name, aliasname) \
        extern typeof(name) aliasname __attribute__((weak, alias (#name)));
#endif

#ifdef IEC_SPEC
    static char *suff[12] = { "B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB", "RB", "QB" };
    #define UNIT    1024.0
#else
    static char *suff[10] = { "B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB" };
    #define UNIT    1000.0
#endif

static char *human_convert(unsigned long size)
{
    double base, res;
    int idx;
    char *buf;

    buf = (char *)malloc(STOR_SIZE);

    memset(buf, '\0', STOR_SIZE);

    if (size <= 0)
        return "0B";

    base = log10((double)size) / log10(UNIT);
    res = round(powf(UNIT, (float)base - floor(base)) * 10.0) / 10.0;
    idx = floor(base);

    sprintf(buf, "%0.1lf %s", res, suff[idx]);

    return buf;
}

static char *human_bytes_from_file(FILE *fp)
{
    long size;

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    return human_convert(size);
}

weak_alias(human_convert, human_bytes)

#endif
