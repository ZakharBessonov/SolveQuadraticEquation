//! @file

#ifndef DEFEND_H
#define DEFEND_H

const int MAXSIZE = 41;

enum RootsCount
{
    ROOTS_COUNT_ZERO,
    ROOTS_COUNT_ONE,
    ROOTS_COUNT_TWO,
    ROOTS_COUNT_INF
};


//-------------------------------------------------------------------------------------------------
//! \brief An enumeration of three constants that the CompareDoubleNumbers function can return.
//-------------------------------------------------------------------------------------------------
enum ResultOfComp
{
    TRUE,
    FALSE,
    PROBLEM
};

struct Coefficients
{
    long double a;
    long double b;
    long double c;
};

struct Roots
{
    long double x1;
    long double x2;
};

struct QuadraticEqu
{
    Coefficients coefficients;
    Roots        roots;
    RootsCount   cntOfRoots;
};

#endif
