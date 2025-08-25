#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "../headers/comp.h"
#include "../headers/structs.h"
#include "../headers/dassert.h"

ResultOfComp CompareDoubleNumbers(long double n1, long double n2)
{
    DASSERT(!isinf(n1));
    DASSERT(!isnan(n1));

    DASSERT(!isinf(n2));
    DASSERT(!isnan(n2));

    if (isinf(n1) || isnan(n1) || isinf(n2) || isnan(n2)) {
        return PROBLEM;
    }

    if (fabs(n1 - n2) < EPSILON) {
        return TRUE;
    }
    return FALSE;
}
