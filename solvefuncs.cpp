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
