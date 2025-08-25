#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "../headers/colors.h"

int cprintf(const char* color, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    printf("%s",color);
    int ret = vprintf(fmt, args);
    printf(BLACK);
    return ret;
}
