#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "structs.h"
#include "comp.h"
#include "solvefuncs.h"

int TestSolveQuadraticEqu(char * filename)
{
    QuadraticEqu quadraticEqu = {{0, 0, 0}, {0, 0}, ROOTS_COUNT_ZERO};

    FILE * fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        return 1;
    }

    QuadraticEqu testStruct = {{0, 0, 0}, {0, 0}, ROOTS_COUNT_ZERO};
    int tempCntOFRoots = 0;

    bool st = 1;

    while (fscanf(fp, "%lf %lf %lf %lf %lf %d", &testStruct.coefficients.a, &testStruct.coefficients.b, &testStruct.coefficients.c,
                                                &testStruct.roots.x1, &testStruct.roots.x2, &tempCntOFRoots) == 6)
    {
        if (tempCntOFRoots == -1)
            testStruct.cntOfRoots = ROOTS_COUNT_INF;
        else if (tempCntOFRoots == 0)
            testStruct.cntOfRoots = ROOTS_COUNT_ZERO;
        else if (tempCntOFRoots == 1)
            testStruct.cntOfRoots = ROOTS_COUNT_ONE;
        else if (tempCntOFRoots == 2)
            testStruct.cntOfRoots = ROOTS_COUNT_TWO;
        else {
            return 1;
        }

        if (!isfinite(testStruct.coefficients.a) || !isfinite(testStruct.coefficients.b) || !isfinite(testStruct.coefficients.c) ||
            !isfinite(testStruct.roots.x1) || !isfinite(testStruct.roots.x2))
        {
            return 1;
        }

        quadraticEqu.coefficients.a = testStruct.coefficients.a;
        quadraticEqu.coefficients.b = testStruct.coefficients.b;
        quadraticEqu.coefficients.c = testStruct.coefficients.c;


        SolveQuadraticEqu(&quadraticEqu);

        if (quadraticEqu.cntOfRoots != testStruct.cntOfRoots) {

            printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> cntOfRoots = %d (should be %d)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.cntOfRoots, testStruct.cntOfRoots);

            st = 0;

        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_ONE) {
            if (CompareDoubleNumbers(quadraticEqu.roots.x1, testStruct.roots.x1) == FALSE) {

                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testStruct.roots.x1);

                st = 0;

            }
        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_TWO) {
            if (CompareDoubleNumbers(quadraticEqu.roots.x1, testStruct.roots.x1) == FALSE) {

                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x1 = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testStruct.roots.x1);

                st = 0;

            }
            if (CompareDoubleNumbers(quadraticEqu.roots.x2, testStruct.roots.x2) == FALSE) {

                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x2 = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x2, testStruct.roots.x2);

                st = 0;

            }
        }
    }

    printf("Программа теста завершена, так как на вход поступили некорректные данные или был достигнут символ конца файл.\n\n");
    if (st) {
        printf("Все тесты до сообщения выше пройдены успешно!\n\n");
    }

    fclose(fp);
    return 0;
}
