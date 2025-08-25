#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "../headers/structs.h"
#include "../headers/comp.h"
#include "../headers/solvefuncs.h"
#include "../headers/colors.h"
#include "../headers/dassert.h"

int TestSolveQuadraticEqu(char * filename)
{
    QuadraticEqu quadraticEqu = {{ .a = 0, .b = 0, .c = 0}, { .x1 = 0, .x2 = 0}, ROOTS_COUNT_ZERO};

    FILE * fp;
    fp = fopen(filename, "r");

    DASSERT(fp != NULL);

    if (fp == NULL) {
        cprintf(RED, "Не удалось открыть тестовый файл или его не существует.\n");
        return 1;
    }

    QuadraticEqu testStruct = {{ .a = 0, .b = 0, .c = 0}, { .x1 = 0, 0}, ROOTS_COUNT_ZERO};
    int tempCntOFRoots = 0;

    bool wasError = 1;

    while (fscanf(fp, "%Lf %Lf %Lf %Lf %Lf %d", &testStruct.coefficients.a, &testStruct.coefficients.b, &testStruct.coefficients.c,
                                                &testStruct.roots.x1, &testStruct.roots.x2, &tempCntOFRoots) == 6)
    {
        if (tempCntOFRoots == -1) {
            testStruct.cntOfRoots = ROOTS_COUNT_INF;
        } else if (tempCntOFRoots == 0)
            testStruct.cntOfRoots = ROOTS_COUNT_ZERO;
        else if (tempCntOFRoots == 1)
            testStruct.cntOfRoots = ROOTS_COUNT_ONE;
        else if (tempCntOFRoots == 2)
            testStruct.cntOfRoots = ROOTS_COUNT_TWO;
        else {
            DASSERT(tempCntOFRoots >= -1 && tempCntOFRoots <= 2);

            cprintf(RED, "Встречен некорректный тест.\n");
            return 1;
        }

        DASSERT(isfinite(testStruct.coefficients.a));
        DASSERT(isfinite(testStruct.coefficients.b));
        DASSERT(isfinite(testStruct.coefficients.c));
        DASSERT(isfinite(testStruct.roots.x1));
        DASSERT(isfinite(testStruct.roots.x2));

        if (!isfinite(testStruct.coefficients.a) || !isfinite(testStruct.coefficients.b) || !isfinite(testStruct.coefficients.c) ||
            !isfinite(testStruct.roots.x1) || !isfinite(testStruct.roots.x2))
        {
            cprintf(RED, "Встречен некорректный тест.\n");
            return 1;
        }

        quadraticEqu.coefficients.a = testStruct.coefficients.a;
        quadraticEqu.coefficients.b = testStruct.coefficients.b;
        quadraticEqu.coefficients.c = testStruct.coefficients.c;

        SolveQuadraticEqu(&quadraticEqu);

        if (quadraticEqu.cntOfRoots != testStruct.cntOfRoots) {

            cprintf(RED, "FAILED: SolveQuadraticEqu(%Lg, %Lg, %Lg) -> cntOfRoots = %d (should be %d)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.cntOfRoots, testStruct.cntOfRoots);

            wasError = 0;

        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_ONE) {

            if (CompareDoubleNumbers(quadraticEqu.roots.x1, testStruct.roots.x1) == FALSE) {

                cprintf(RED, "FAILED: SolveQuadraticEqu(%Lg, %Lg, %Lg) -> x = %Lg (should be %Lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testStruct.roots.x1);

                wasError = 0;

            }
        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_TWO) {

            if (CompareDoubleNumbers(quadraticEqu.roots.x1, testStruct.roots.x1) == FALSE) {

                cprintf(RED, "FAILED: SolveQuadraticEqu(%Lg, %Lg, %Lg) -> x1 = %Lg (should be %Lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testStruct.roots.x1);

                wasError = 0;

            }
            if (CompareDoubleNumbers(quadraticEqu.roots.x2, testStruct.roots.x2) == FALSE) {

                cprintf(RED, "FAILED: SolveQuadraticEqu(%Lg, %Lg, %Lg) -> x2 = %Lg (should be %Lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x2, testStruct.roots.x2);

                wasError = 0;

            }
        }
    }

    printf("\nПрограмма теста завершена, так как был достигнут символ конца тестового файл.\n\n");

    if (wasError) {
        cprintf(GREEN, "Все тесты пройдены успешно!\n\n");
    }

    fclose(fp);

    return 0;
}
