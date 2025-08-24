#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "comp.h"
#include "structs.h"

ResultOfComp CompareDoubleNumbers(double n1, double n2)
{

#ifdef DEBUGMODE

    assert(isinf(n1));
    assert(isnan(n1));

    assert(isinf(n2));
    assert(isnan(n2));

#endif


    if (isinf(n1) || isnan(n1) || isinf(n2) || isnan(n2))
        return PROBLEM;


    if (fabs(n1 - n2) < EPSILON)
        return TRUE;
    return FALSE;
}
