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
    //TestSolveQuadraticEqu();
    FILE * fp = NULL;

    InputFileName(&fp);
    QuadraticEqu quadraticEqu = {{0, 0, 0}, {0, 0}, ROOTS_COUNT_ZERO};

    while (true) {
        InputCoeffsQuadraticEqu(&quadraticEqu, fp);
        SolveQuadraticEqu(&quadraticEqu);
        OutputSolveQuadraticEqu(&quadraticEqu);
    }

    fclose(fp);
    return 0;
}
