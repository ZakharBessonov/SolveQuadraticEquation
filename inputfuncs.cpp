#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "structs.h"

void InputCoeffsQuadraticEqu(QuadraticEqu * quadraticEqu)
{
    assert(quadraticEqu != NULL);

    printf("Введите коэффициенты квадратного уравнения ax^2 + bx + c = 0 через пробелы.\n\n"
           "ПРЕДУПРЕЖДЕНИЕ: программа работает на множестве действительных чисел,\n"
           "гарантируется точность не менее 13 знаков после запятой\n\n"
           "Коэффициенты: ");

    int cntOfReadNumbers = scanf("%lg %lg %lg", &quadraticEqu->coefficients.a, &quadraticEqu->coefficients.b,
                                                &quadraticEqu->coefficients.c);
    char ch = 0;

    while (cntOfReadNumbers != 3) {

        while ((ch = getchar()) != '\n' && ch != EOF)
            continue;
        if (ch == EOF) {
            printf("\nВы ввели символ конца файла. Программа завершена, так как корректный ввод не был получен.");
            exit(EXIT_FAILURE);
        }

        printf("Ввод некорректен. Повторите ввод: ");

        cntOfReadNumbers = scanf("%lg %lg %lg", &quadraticEqu->coefficients.a, &quadraticEqu->coefficients.b,
                                                &quadraticEqu->coefficients.c);
    }
}
