#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "../headers/structs.h"
#include "../headers/comp.h"
#include "../headers/inputfuncs.h"
#include "../headers/outputfuncs.h"
#include "../headers/solvefuncs.h"
#include "../headers/testfunc.h"
#include "../headers/colors.h"

int main()
{
    // Часть для unit - тестов
#ifdef TESTMODE

    char filename[MAXSIZE] = "";

    printf("%lg\n", DBL_TRUE_MIN);
    printf("%lg\n", DBL_MAX);
    printf("%.13lf\n", 2e+12 * 2e+12 - 4.0 * 1e+12 * 1e+12);

    printf("Введите имя файла с тестовыми данными: ");

    scanf("%s", filename);

    TestSolveQuadraticEqu(filename);

#else

    // Интерактивная часть

    FILE * fp = NULL;

    if (InputFileName(&fp))
    {
        cprintf(RED, "\nПроизошла ошибка при открытии указанного файла (либо указанного файла не существует)\n\n");

        return 0;
    }

    QuadraticEqu quadraticEqu = {{ .a = 0, .b = 0, .c = 0},
                                 { .x1 = 0, .x2 = 0}, ROOTS_COUNT_ZERO};

    while (true) {
        if (InputCoeffsQuadraticEqu(&quadraticEqu, fp))
        {
            printf("\nПрограмма завершена. Подарите автору 1 (один) бутерброд.");

            break;
        }

        if (SolveQuadraticEqu(&quadraticEqu))
        {
            cprintf(RED, "\nПрограмма завершена (функции SolveQuadraticEqu передан нулевой указатель, или\n"
                       "в качестве коэффициентов переданы inf или NaN)\n\n");

            break;
        }

        if (OutputSolveQuadraticEqu(&quadraticEqu))
        {
            cprintf(RED, "\nПрограмма завершена, так как функции OutputSolveQuadraticEqu передан нулевой указатель\n\n");

            break;
        }
    }

    fclose(fp); // Программа здесь заканчивается, поэтому закрытие stdin не приведёт ни к чему плохому.

#endif
    return 0;
}
