#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "structs.h"
#include "comp.h"
#include "solvefuncs.h"

int TestSolveQuadraticEqu()
{
    const QuadraticEqu testArray[] = {
        {{0, 0, 0}, {0,0}, ROOTS_COUNT_INF},
        {{1, 5, 6}, {-3, -2}, ROOTS_COUNT_TWO},
        {{0, 1, 3}, {-3, 0}, ROOTS_COUNT_ONE},
        {{5, 1, 3}, {0, 0}, ROOTS_COUNT_ZERO},
        {{5, 16, 3}, {-3, -0.2}, ROOTS_COUNT_TWO},
        {{1, 0, -9}, {-3, 3}, ROOTS_COUNT_TWO},
        {{0.05, 0.16, 0.03}, {-3, -0.2}, ROOTS_COUNT_TWO},
        {{0, 1, 3}, {-3, 0}, ROOTS_COUNT_ONE},
        {{1, 2, 1}, {-1, 0}, ROOTS_COUNT_ONE}
    };

    QuadraticEqu quadraticEqu = {{0, 0, 0}, {0, 0}, ROOTS_COUNT_ZERO};
    int sizeOfArray = sizeof(testArray) / sizeof(*testArray);

    for (int i = 0; i < sizeOfArray; i++) {
        quadraticEqu.coefficients.a = testArray[i].coefficients.a;
        quadraticEqu.coefficients.b = testArray[i].coefficients.b;
        quadraticEqu.coefficients.c = testArray[i].coefficients.c;
        SolveQuadraticEqu(&quadraticEqu);
        if (quadraticEqu.cntOfRoots != testArray[i].cntOfRoots) {
            printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> cntOfRoots = %d (should be %d)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.cntOfRoots, testArray[i].cntOfRoots);
            return 0;
        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_ONE) {
            if (!CompareDoubleNumbers(quadraticEqu.roots.x1, testArray[i].roots.x1)) {
                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testArray[i].roots.x1);
                return 0;
            }
        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_TWO) {
            if (!CompareDoubleNumbers(quadraticEqu.roots.x1, testArray[i].roots.x1)) {
                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x1 = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testArray[i].roots.x1);
                return 0;
            }
            if (!CompareDoubleNumbers(quadraticEqu.roots.x2, testArray[i].roots.x2)) {
                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x2 = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x2, testArray[i].roots.x2);
                return 0;
            }
        }
    }
    printf("Все тесты пройдены успешно!\n");
    return 1;
}
