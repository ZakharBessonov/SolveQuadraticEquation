#ifndef DEFEND_H
#define DEFEND_H

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

#endif
