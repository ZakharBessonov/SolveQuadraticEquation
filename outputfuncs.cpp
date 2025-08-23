#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "structs.h"

void OutputSolveQuadraticEqu(const QuadraticEqu * quadraticEqu)
{
    assert(quadraticEqu != NULL);

    switch(quadraticEqu->cntOfRoots) {
        case ROOTS_COUNT_INF:
            printf("\nУравнение %lgx^2%+lgx%+lg=0 имеет бесконечно много решений.\n", (quadraticEqu->coefficients).a,
                   (quadraticEqu->coefficients).b, (quadraticEqu->coefficients).c);
            break;
        case ROOTS_COUNT_ZERO:
            printf("\nУравнение %lgx^2%+lgx%+lg=0 не имеет решений.\n", (quadraticEqu->coefficients).a,
                   (quadraticEqu->coefficients).b, (quadraticEqu->coefficients).c);
            break;
        case ROOTS_COUNT_ONE:
            printf("\nУравнение %lgx^2%+lgx%+lg=0 имеет единственное решение: x = %.13lg\n", (quadraticEqu->coefficients).a,
                   (quadraticEqu->coefficients).b, (quadraticEqu->coefficients).c, quadraticEqu->roots.x1);
            break;
        case ROOTS_COUNT_TWO:
            printf("\nУравнение %lgx^2%+lgx%+lg=0 имеет два решения: x1 = %.13lg, x2 = %.13lg\n", (quadraticEqu->coefficients).a,
                   (quadraticEqu->coefficients).b, (quadraticEqu->coefficients).c, quadraticEqu->roots.x1, quadraticEqu->roots.x2);
            break;
    }
}
