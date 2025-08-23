#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "structs.h"

const int MAXSIZE = 41;
bool st = true;

void CleanInput(FILE * fp) {
    char ch = 0;
    while ((ch = getc(fp)) != '\n' && ch != EOF)
            continue;
        if (ch == EOF) {
            printf("\nВстречен символ конца файла. Программа завершена.");
            exit(EXIT_FAILURE);
        }
}

void InputFileName(FILE** fp) {
    FILE * fp_temp;
    char filename[MAXSIZE];

    printf("Эта программа решает квадратные уравнения. Введите имя файла (не более 40 символов), из которого будут браться\n"
    "входные данные, или введите stdin, если хотите вводить коэффициенты самостоятельно: ");
    scanf("%s", filename);
    if (strcmp(filename, "stdin") == 0) {
        *fp = stdin;
        return;
    }

    if ((fp_temp = fopen(filename, "r")) == NULL) {
        printf("Не удаётся открыть файл \"%s\" или его не существует. Программа аварийно завершена!\n", filename);
        exit(EXIT_FAILURE);
    }

    *fp = fp_temp;
}

void InputCoeffsQuadraticEqu(QuadraticEqu * quadraticEqu, FILE * fp)
{
    assert(quadraticEqu != NULL);
    assert(fp != NULL);

    if (fp == stdin) {
        if (st) {
            st = false;
            printf("Вводите коэффициенты квадратного уравнения ax^2 + bx + c = 0 через пробелы.\n\n"
                "ПРЕДУПРЕЖДЕНИЕ: программа работает на множестве действительных чисел,\n"
                "гарантируется точность не менее 13 знаков после запятой. Чтобы завершить ввод, введите символ\n"
                "конца файла (CTRL^D).\n\n");
        }

        printf("Коэффициенты: ");
        int cntOfReadNumbers = fscanf(fp, "%lg %lg %lg", &quadraticEqu->coefficients.a, &quadraticEqu->coefficients.b, &quadraticEqu->coefficients.c);

        while (cntOfReadNumbers != 3) {
            CleanInput(fp);
            printf("Ввод некорректен. Повторите ввод: ");
            cntOfReadNumbers = fscanf(fp, "%lg %lg %lg", &quadraticEqu->coefficients.a, &quadraticEqu->coefficients.b,
                                                         &quadraticEqu->coefficients.c);
        }
    } else {
        int cntOfReadNumbers = fscanf(fp, "%lg %lg %lg", &quadraticEqu->coefficients.a, &quadraticEqu->coefficients.b,
                                                         &quadraticEqu->coefficients.c);

        while (cntOfReadNumbers != 3) {
            CleanInput(fp);
            printf("\nВвод некорректен. Строка пропущена.\n");
            cntOfReadNumbers = fscanf(fp, "%lg %lg %lg", &quadraticEqu->coefficients.a, &quadraticEqu->coefficients.b,
                                                         &quadraticEqu->coefficients.c);
        }
    }
}
