#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "comp.h"

bool CompareDoubleNumbers(double n1, double n2)
{
    assert(!isinf(n1));
    assert(!isnan(n1));
    assert(!isinf(n2));
    assert(!isnan(n2));

    return (fabs(n1 - n2) < EPSILON);
}
