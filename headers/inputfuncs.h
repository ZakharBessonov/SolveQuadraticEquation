//! @file

//-------------------------------------------------------------------------------------------------
//! Entering the coefficients of a quadratic equation.
//! @param [out] quadraticEqu
//! @param [in] fp - pointer to the file from which the coefficients will be taken
//! @return  Return 0 on success or returns 1 if errors occur during operation
//-------------------------------------------------------------------------------------------------

// Ввод коэффициентов квадратного уравнения.
int InputCoeffsQuadraticEqu(QuadraticEqu * quadraticEqu, FILE * fp);

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
//! @return  Return 0 on success or returns 1 if errors occur during operation
//-------------------------------------------------------------------------------------------------

// Функция ввода файла, откуда будут браться данные
int InputFileName(FILE ** fp);
