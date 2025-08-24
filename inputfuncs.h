//! @file

//-------------------------------------------------------------------------------------------------
//! Entering the coefficients of a quadratic equation.
//! @param [out] quadraticEqu
//! @param [in] fp - pointer to the file from which the coefficients will be taken
//! @return  Nothing
//! @note Crash the program if meet EOF or if at least one of the coefficients is inf or NaN or quadraticEqu = NULL
//-------------------------------------------------------------------------------------------------

// Ввод коэффициентов квадратного уравнения.
void InputCoeffsQuadraticEqu(QuadraticEqu * quadraticEqu, FILE * fp);

//-------------------------------------------------------------------------------------------------
//! Clears the input buffer.
//! @param [in] fp - pointer to the file
//! @return  "\n" or "EOF"
//-------------------------------------------------------------------------------------------------

// Функция очистки непринятого ввода
char CleanInput(FILE * fp);

//-------------------------------------------------------------------------------------------------
//! Accepts the name of the file from which the input data will be taken.
//! @param [in] fp - pointer to pointer to the file
//! @return  Nothing
//! @note Stops the program if the file with the entered name does not exist or cannot be opened or if fp = NULL.
//-------------------------------------------------------------------------------------------------

// Функция ввода файла, откуда будут браться данные
void InputFileName(FILE ** fp);
