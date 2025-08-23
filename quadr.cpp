#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

// Погрешность вычислений.
const double EPSILON = 1e-13;

enum RootsCount
{
    ROOTS_COUNT_ZERO,
    ROOTS_COUNT_ONE,
    ROOTS_COUNT_TWO,
    ROOTS_COUNT_INF
};

struct Coefficients
{
    double a;
    double b;
    double c;
};

struct Roots
{
    double x1;
    double x2;
};

struct QuadraticEqu
{
    Coefficients coefficients;
    Roots roots;
    RootsCount cntOfRoots;
};

// Сравнивает вещественное число n с нулём с точностью 13 знаков после запятой.
bool CompareDoubleNumbers(double n1, double n2);

// Решает квадратное уравнение ax^2 + bx + c = 0
// и возвращает количество корней.
void SolveQuadraticEqu(QuadraticEqu * quadraticEqu);

// Решает линейное уравнение ax + b = 0 и возвращает
// количество корней.
void SolveLinealEqu(QuadraticEqu * quadraticEqu);

// Ввод коэффициентов квадратного уравнения.
void InputCoeffsQuadraticEqu(QuadraticEqu * quadraticEqu);

// Вывод решения квадратного уравнения.
void OutputSolveQuadraticEqu(const QuadraticEqu * quadraticEqu);

// Функция unit-тестирования
void TestSolveQuadraticEqu();

int main(void)
{
    //QuadraticEqu quadraticEqu;
    //InputCoeffsQuadraticEqu(&quadraticEqu);
    //SolveQuadraticEqu(&quadraticEqu);
    //OutputSolveQuadraticEqu(&quadraticEqu);
    TestSolveQuadraticEqu();

    return 0;
}

bool CompareDoubleNumbers(double n1, double n2)
{
    assert(!isinf(n1));
    assert(!isnan(n1));
    assert(!isinf(n2));
    assert(!isnan(n2));

    return (fabs(n1 - n2) < EPSILON);
}

void SolveQuadraticEqu(QuadraticEqu * quadraticEqu)
{
    assert(quadraticEqu != NULL);

    double a = quadraticEqu->coefficients.a;
    double b = quadraticEqu->coefficients.b;
    double c = quadraticEqu->coefficients.c;

    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    if (CompareDoubleNumbers(a, 0)) {
        SolveLinealEqu(quadraticEqu);
    } else {
        // Формула дискриминанта (см. любой учебник по математике за 5 класс).
        double discriminant = b * b - 4 * a * c;

        if (CompareDoubleNumbers(discriminant, 0)) {
            quadraticEqu->roots.x1 = -b / (2 * a);
            quadraticEqu->cntOfRoots = ROOTS_COUNT_ONE;
        } else if (discriminant < 0.0) {
            quadraticEqu->cntOfRoots = ROOTS_COUNT_ZERO;
        } else {
            double sqrtD = sqrt(discriminant);
            quadraticEqu->roots.x1 = (-b - sqrtD) / (2 * a);
            quadraticEqu->roots.x2 = (-b + sqrtD) / (2 * a);
            quadraticEqu->cntOfRoots = ROOTS_COUNT_TWO;
        }
    }
}

void SolveLinealEqu(QuadraticEqu * quadraticEqu)
{
    assert(quadraticEqu != NULL);

    double a = quadraticEqu->coefficients.b;
    double b = quadraticEqu->coefficients.c;

    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isnan(a));
    assert(!isnan(b));

    if (CompareDoubleNumbers(a, 0)) {
        if (CompareDoubleNumbers(b, 0)) {
            quadraticEqu->cntOfRoots = ROOTS_COUNT_INF;
        } else {
            quadraticEqu->cntOfRoots = ROOTS_COUNT_ZERO;
        }
    } else {
        quadraticEqu->roots.x1 = -b / a;
        quadraticEqu->cntOfRoots = ROOTS_COUNT_ONE;
    }
}

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

void OutputSolveQuadraticEqu(const QuadraticEqu * quadraticEqu)
{
    assert(quadraticEqu != NULL);

    switch(quadraticEqu->cntOfRoots) {
        case ROOTS_COUNT_INF:
            printf("\nУравнение имеет бесконечно много решений.\n");
            break;
        case ROOTS_COUNT_ZERO:
            printf("\nУравнение не имеет решений.\n");
            break;
        case ROOTS_COUNT_ONE:
            printf("\nУравнение имеет единственное решение: x = %.13lg\n", quadraticEqu->roots.x1);
            break;
        case ROOTS_COUNT_TWO:
            printf("\nУравнение имеет два решения: x1 = %.13lg, x2 = %.13lg", quadraticEqu->roots.x1, quadraticEqu->roots.x2);
            break;
    }
}

void TestSolveQuadraticEqu()
{
    const QuadraticEqu testArray[8] = {
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

    QuadraticEqu quadraticEqu;

    for (int i = 0; i < 8; i++) {
        quadraticEqu.coefficients.a = testArray[i].coefficients.a;
        quadraticEqu.coefficients.b = testArray[i].coefficients.b;
        quadraticEqu.coefficients.c = testArray[i].coefficients.c;
        SolveQuadraticEqu(&quadraticEqu);
        if (quadraticEqu.cntOfRoots != testArray[i].cntOfRoots) {
            printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> cntOfRoots = %d (should be %d)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.cntOfRoot, testArray[i].cntOfRoots);
            return;
        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_ONE) {
            if (!CompareDoubleNumbers(quadraticEqu.roots.x1, testArray[i].roots.x1)) {
                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testArray[i].roots.x1);
                return;
            }
        } else if (quadraticEqu.cntOfRoots == ROOTS_COUNT_TWO) {
            if (!CompareDoubleNumbers(quadraticEqu.roots.x1, testArray[i].roots.x1)) {
                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x1 = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x1, testArray[i].roots.x1);
                return;
            }
            if (!CompareDoubleNumbers(quadraticEqu.roots.x2, testArray[i].roots.x2)) {
                printf("FAILED: SolveQuadraticEqu(%lg, %lg, %lg) -> x2 = %lg (should be %lg)\n",
                    quadraticEqu.coefficients.a, quadraticEqu.coefficients.b, quadraticEqu.coefficients.c,
                    quadraticEqu.roots.x2, testArray[i].roots.x2);
                return;
            }
        }
    }
    printf("Все тесты пройдены успешно!\n");
}
