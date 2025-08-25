#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "../headers/structs.h"
#include "../headers/colors.h"
#include "../headers/dassert.h"

int OutputSolveQuadraticEqu(const QuadraticEqu * quadraticEqu)
{
    DASSERT(quadraticEqu != NULL);

    if (quadraticEqu == NULL) {
        return 1;
    }

    switch(quadraticEqu->cntOfRoots) {
        case ROOTS_COUNT_INF:
            cprintf(BLUE, "\nУравнение %Lgx^2%+Lgx%+Lg=0 имеет бесконечно много решений.\n", (quadraticEqu->coefficients).a,
                   (quadraticEqu->coefficients).b, (quadraticEqu->coefficients).c);
            break;
        case ROOTS_COUNT_ZERO:
            cprintf(BLUE, "\nУравнение %Lgx^2%+Lgx%+Lg=0 не имеет решений.\n", (quadraticEqu->coefficients).a,
                   (quadraticEqu->coefficients).b, (quadraticEqu->coefficients).c);
            break;
        case ROOTS_COUNT_ONE:
            cprintf(BLUE, "\nУравнение %Lgx^2%+Lgx%+Lg=0 имеет единственное решение: x = %Lg\n", (quadraticEqu->coefficients).a,
                   (quadraticEqu->coefficients).b, (quadraticEqu->coefficients).c, quadraticEqu->roots.x1);
            break;
        case ROOTS_COUNT_TWO:
            cprintf(BLUE, "\nУравнение %Lgx^2%+Lgx%+Lg=0 имеет два решения: x1 = %Lg, x2 = %Lg\n", (quadraticEqu->coefficients).a,
                   (quadraticEqu->coefficients).b, (quadraticEqu->coefficients).c, quadraticEqu->roots.x1, quadraticEqu->roots.x2);
            break;
        default:
            break;
    }

    return 0;
}
