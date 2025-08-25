#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "../headers/structs.h"
#include "../headers/comp.h"
#include "../headers/dassert.h"

int SolveLinealEqu(QuadraticEqu * quadraticEqu)
{
    DASSERT(quadraticEqu != NULL);

    if (quadraticEqu == NULL) {
        return 1;
    }

    long double a = quadraticEqu->coefficients.b;
    long double b = quadraticEqu->coefficients.c;

    DASSERT(!isinf(a));
    DASSERT(!isinf(b));
    DASSERT(!isnan(a));
    DASSERT(!isnan(b));

    if (CompareDoubleNumbers(a, 0) == PROBLEM) {
        return 1;
    } else if (CompareDoubleNumbers(a, 0) == TRUE) {
        if (CompareDoubleNumbers(b, 0) == PROBLEM) {
            return 1;
        } else if (CompareDoubleNumbers(b, 0) == TRUE) {
            quadraticEqu->cntOfRoots = ROOTS_COUNT_INF;
        } else {
            quadraticEqu->cntOfRoots = ROOTS_COUNT_ZERO;
        }
    } else {
        quadraticEqu->roots.x1 = -b / a;
        quadraticEqu->cntOfRoots = ROOTS_COUNT_ONE;
    }

    return 0;
}

int SolveQuadraticEqu(QuadraticEqu * quadraticEqu)
{
    DASSERT(quadraticEqu != NULL);

    if (quadraticEqu == NULL) {
        return 1;
    }

    long double a = quadraticEqu->coefficients.a;
    long double b = quadraticEqu->coefficients.b;
    long double c = quadraticEqu->coefficients.c;

    DASSERT(!isinf(a));
    DASSERT(!isinf(b));
    DASSERT(!isinf(c));
    DASSERT(!isnan(a));
    DASSERT(!isnan(b));
    DASSERT(!isnan(c));

    if (isnan(b) || isinf(b) || isnan(c) || isinf(c)) {
        return 1;
    }

    if (CompareDoubleNumbers(a, 0) == PROBLEM) {
        return 1;
    } else if (CompareDoubleNumbers(a, 0) == TRUE) {
        return SolveLinealEqu(quadraticEqu);
    } else {
        // Формула дискриминанта (см. любой учебник по математике за 5 класс).
        long double discriminant = b * b - 4 * a * c;

        if (CompareDoubleNumbers(discriminant, 0) == PROBLEM) {
            return 1;
        } else if (CompareDoubleNumbers(discriminant, 0) == TRUE) {
            quadraticEqu->roots.x1 = -b / (2 * a);
            quadraticEqu->cntOfRoots = ROOTS_COUNT_ONE;
        } else if (discriminant < 0.0) {
            quadraticEqu->cntOfRoots = ROOTS_COUNT_ZERO;
        } else {
            long double sqrtD = sqrt(discriminant);
            quadraticEqu->roots.x1 = (-b - sqrtD) / (2 * a);
            quadraticEqu->roots.x2 = (-b + sqrtD) / (2 * a);
            quadraticEqu->cntOfRoots = ROOTS_COUNT_TWO;
        }
    }

    return 0;
}
