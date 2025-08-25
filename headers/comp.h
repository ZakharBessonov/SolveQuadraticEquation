//! @file

//-------------------------------------------------------------------------------------------------
//! Compares real numbers n1 and n2.
//! @param [in] n1 n1-first double number
//! @param [in] n2 n2-second double number
//! @return  Are the numbers equal within the margin of error? If equal, return TRUE, else return FALSE.
//!          If at least one of numbers equal inf or NaN, return PROBLEM
//-------------------------------------------------------------------------------------------------

#include "structs.h"

// Сравнивает вещественные числа n1 и n2 и возвращает true, если они равны в пределах погрешности.
ResultOfComp CompareDoubleNumbers(long double n1, long double n2);

// Погрешность вычислений.
const long double EPSILON = 1e-13;
