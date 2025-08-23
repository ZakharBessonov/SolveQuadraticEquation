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
            printf("\nУравнение имеет бесконечно много решений.\n");
            break;
        case ROOTS_COUNT_ZERO:
            printf("\nУравнение не имеет решений.\n");
            break;
        case ROOTS_COUNT_ONE:
            printf("\nУравнение имеет единственное решение: x = %.13lg\n", quadraticEqu->roots.x1);
            break;
        case ROOTS_COUNT_TWO:
            printf("\nУравнение имеет два решения: x1 = %.13lg, x2 = %.13lg\n", quadraticEqu->roots.x1, quadraticEqu->roots.x2);
            break;
    }
}
