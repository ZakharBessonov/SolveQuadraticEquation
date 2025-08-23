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

int main(void)
{
    TestSolveQuadraticEqu();
    QuadraticEqu quadraticEqu;
    InputCoeffsQuadraticEqu(&quadraticEqu);
    SolveQuadraticEqu(&quadraticEqu);
    OutputSolveQuadraticEqu(&quadraticEqu);

    return 0;
}
