//! @file

//-------------------------------------------------------------------------------------------------
//! Solves a quadratic equation.
//! @param [in] quadraticEqu - structure containing the coefficients of a quadratic equation
//! @return  Nothing
//! @note Stop program if quadraticEqu = NULL or at least one of coefficients is inf or NaN.
//-------------------------------------------------------------------------------------------------


// Решает квадратное уравнение ax^2 + bx + c = 0
// и возвращает количество корней.
void SolveQuadraticEqu(QuadraticEqu * quadraticEqu);


//-------------------------------------------------------------------------------------------------
//! Solves a lineal equation.
//! @param [in] quadraticEqu quadraticEqu - structure containing the coefficients of a quadratic equation (at the same time a = 0)
//! @return  Nothing
//! @note Use with quadratic equation, in spite of name! Stop program if quadraticEqu = NULL or
//!       at least one of coefficients is inf or NaN.
//-------------------------------------------------------------------------------------------------

// Решает линейное уравнение ax + b = 0 и возвращает
// количество корней.
void SolveLinealEqu(QuadraticEqu * quadraticEqu);
