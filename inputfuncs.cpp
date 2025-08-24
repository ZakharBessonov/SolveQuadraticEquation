#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "structs.h"

const int MAXSIZE = 41;

char CleanInput(FILE * fp)
{
    //assert(fp != NULL);

    if (fp == NULL)
        return EOF;

    char ch = '\0';
    while ((ch = getc(fp)) != '\n' && ch != EOF)
            continue;
    return ch;
}

int InputFileName(FILE ** fp)
{
    //assert(fp != NULL);

    if (fp == NULL)
        return 1;

    FILE * fp_temp = NULL;
    char filename[MAXSIZE];

    printf("Эта программа решает квадратные уравнения. Введите имя файла (не более 40 символов), из которого будут браться\n"
    "входные данные, или введите stdin, если хотите вводить коэффициенты самостоятельно: ");

    scanf("%s", filename);
    if (strcmp(filename, "stdin") == 0) {
        *fp = stdin;

        printf("\nВводите коэффициенты квадратного уравнения ax^2 + bx + c = 0 через пробелы.\n\n"
                "ПРЕДУПРЕЖДЕНИЕ: программа работает на множестве действительных чисел,\n"
                "гарантируется точность не менее 13 знаков после запятой. Чтобы завершить ввод, введите символ\n"
                "конца файла (CTRL^D).\n\n");

        return 0;
    }

    if ((fp_temp = fopen(filename, "r")) == NULL) {
        return 1;
    }

    *fp = fp_temp;

    return 0;
}

int InputCoeffsQuadraticEqu(QuadraticEqu * quadraticEqu, FILE * fp)
{
    //assert(quadraticEqu != NULL);
    //assert(fp != NULL);

    if (quadraticEqu == NULL || fp == NULL) {
        printf("\nПередан нулевой указатель на структуру или файл.\n");

        return 1;
    }

    char tempCh = '\0';

    if (fp == stdin) {
        printf("Коэффициенты: ");
    }

    int cntOfReadNumbers = fscanf(fp, "%lg %lg %lg", &quadraticEqu->coefficients.a, &quadraticEqu->coefficients.b,
                                                         &quadraticEqu->coefficients.c);

    while (cntOfReadNumbers != 3) {
            tempCh = CleanInput(fp);
            if (tempCh == EOF){

                printf("\nВстречен символ конца файла.\n");

                return 1;
            }
            if (fp  == stdin)
                printf("Ввод некорректен. Повторите ввод: ");
            else
                printf("\nВвод некорректен. Строка пропущена.\n");


            cntOfReadNumbers = fscanf(fp, "%lg %lg %lg", &quadraticEqu->coefficients.a, &quadraticEqu->coefficients.b,
                                                         &quadraticEqu->coefficients.c);
    }

    return 0;
}
