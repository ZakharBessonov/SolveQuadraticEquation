//! @file

//-------------------------------------------------------------------------------------------------
//! Solves a quadratic equation.
//! @param [in] quadraticEqu - structure containing the coefficients of a quadratic equation
//! @return  Return 0 on success or returns 1 if errors occur during operation (for example, one of coefficients is inf or NaN).
//-------------------------------------------------------------------------------------------------


// Решает квадратное уравнение ax^2 + bx + c = 0
// и возвращает результат работы (0, если успешно, или 1, если произошла ошибка).
int SolveQuadraticEqu(QuadraticEqu * quadraticEqu);


//-------------------------------------------------------------------------------------------------
//! Solves a lineal equation.
//! @param [in] quadraticEqu quadraticEqu - structure containing the coefficients of a quadratic equation (at the same time a = 0)
//! @return Return 0 on success or returns 1 if errors occur during operation (for example, one of coefficients is inf or NaN).
//! @note Use with quadratic equation, in spite of name!
//-------------------------------------------------------------------------------------------------

// Решает линейное уравнение ax + b = 0 и возвращает
// результат работы (0, если успешно, или 1, если произошла ошибка).
int SolveLinealEqu(QuadraticEqu * quadraticEqu);
