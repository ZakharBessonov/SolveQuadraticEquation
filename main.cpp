#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "structs.h"
#include "comp.h"
#include "inputfuncs.h"
#include "outputfuncs.h"
#include "solvefuncs.h"
#include "testfunc.h"
#include "colors.h"

int main()
{
    // Часть для unit - тестов

#if defined(TESTMODE)
    char filename[MAXSIZE];

    printf("Введите имя файла с тестовыми данными: ");

    scanf("%s", filename);

    TestSolveQuadraticEqu(filename);

#else

    // Интерактивная часть

    FILE * fp = NULL;

    if (InputFileName(&fp))
    {
        printf(RED "\nПроизошла ошибка при открытии указанного файла (либо указанного файла не существует)\n\n" BLACK);

        return 0;
    }

    QuadraticEqu quadraticEqu = {{0, 0, 0}, {0, 0}, ROOTS_COUNT_ZERO};


    while (true) {
        if (InputCoeffsQuadraticEqu(&quadraticEqu, fp))
        {
            printf("\nПрограмма завершена.");

            break;
        }

        if (SolveQuadraticEqu(&quadraticEqu))
        {
            printf(RED "\nПрограмма завершена (функции SolveQuadraticEqu передан нулевой указатель, или\n"
                    "в качестве коэффициентов переданы inf или NaN)\n\n" BLACK);

            break;
        }

        if (OutputSolveQuadraticEqu(&quadraticEqu))
        {
            printf(RED "\nПрограмма завершена, так как функции OutputSolveQuadraticEqu передан нулевой указатель\n\n" BLACK);

            break;
        }
    }

    fclose(fp);

#endif

    return 0;
}
