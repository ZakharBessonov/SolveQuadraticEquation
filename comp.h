//! @file

//-------------------------------------------------------------------------------------------------
//! Compares real numbers n1 and n2 and returns true if they are equal within the error limits.
//! @param [in] n1 n1-first double number
//! @param [in] n2 n2-second double number
//! @return  Are the numbers equal within the margin of error?
//! @note Crash the program if one of the numbers is inf or NaN.
//-------------------------------------------------------------------------------------------------

// Сравнивает вещественные числа n1 и n2 и возвращает true, если они равны в пределах погрешности.
bool CompareDoubleNumbers(double n1, double n2);

// Погрешность вычислений.
const double EPSILON = 1e-13;
