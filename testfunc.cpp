#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "structs.h"
#include "comp.h"
#include "solvefuncs.h"
#include "colors.h"

int TestSolveQuadraticEqu(char * filename)
{
    QuadraticEqu quadraticEqu = {{ .a = 0, .b = 0, .c = 0}, { .x1 = 0, 0}, ROOTS_COUNT_ZERO};

    FILE * fp;
    fp = fopen(filename, "r");

#ifdef DEBUGMODE

    assert(fp != NULL);

#endif

    if (fp == NULL) {
        printf(RED "Не удалось открыть тестовый файл или его не существует.\n" BLACK);
        return 1;
    }

    QuadraticEqu testStruct = {{ .a = 0, .b = 0, .c = 0}, { .x1 = 0, 0}, ROOTS_COUNT_ZERO};
    int tempCntOFRoots = 0;

    bool wasError = 1;

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

#ifdef DEBUGMODE

            assert(tempCntOFRoots >= -1 && tempCntOFRoots <= 2);

#endif

            printf(RED "Встречен некорректный тест.\n" BLACK);
            return 1;
        }

#ifdef DEBUGMODE

        assert(isfinite(testStruct.coefficients.a));
        assert(isfinite(testStruct.coefficients.b));
        assert(isfinite(testStruct.coefficients.c));
        assert(isfinite(testStruct.roots.x1));
        assert(isfinite(testStruct.roots.x2));

#endif

        if (!isfinite(testStruct.coefficients.a) || !isfinite(testStruct.coefficients.b) || !isfinite(testStruct.coefficients.c) ||
            !isfinite(testStruct.roots.x1) || !isfinite(testStruct.roots.x2))
        {
            printf(RED "Встречен некорректный тест.\n" BLACK);
            return 1;
        }

        quadraticEqu.coefficients.a = testStruct.coefficients.a;
        quadraticEqu.coefficients.b = testStruct.coefficients.b;
        quadraticEqu.coefficients.c = testStruct.coefficients.c;

        SolveQuadraticEqu(&quadraticEqu);

        if (quadraticEqu.cntOfRoots != testStruct.cntOfRoots) {

            printf(RED "FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> cntOfRoots = %d (should be %d)\n" BLACK,
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.cntOfRoots, testStruct.cntOfRoots);

            wasError = 0;

        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_ONE) {

            if (CompareDoubleNumbers(quadraticEqu.roots.x1, testStruct.roots.x1) == FALSE) {

                printf(RED "FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x = %lg (should be %lg)\n" BLACK,
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testStruct.roots.x1);

                wasError = 0;

            }
        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_TWO) {

            if (CompareDoubleNumbers(quadraticEqu.roots.x1, testStruct.roots.x1) == FALSE) {

                printf(RED "FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x1 = %lg (should be %lg)\n" BLACK,
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testStruct.roots.x1);

                wasError = 0;

            }
            if (CompareDoubleNumbers(quadraticEqu.roots.x2, testStruct.roots.x2) == FALSE) {

                printf(RED "FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x2 = %lg (should be %lg)\n" BLACK,
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x2, testStruct.roots.x2);

                wasError = 0;

            }
        }
    }

    printf("\nПрограмма теста завершена, так как был достигнут символ конца тестового файл.\n\n");

    if (wasError) {
        printf(GREEN "Все тесты пройдены успешно!\n\n" BLACK);
    }

    fclose(fp);

    return 0;
}
