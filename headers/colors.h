#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLACK "\x1b[0m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define YELLOW "\x1b[33m"


//-------------------------------------------------------------------------------------------------
//! It is similar to the printf() function, but it takes an additional parameter - the color of the output text.
//! @param [in] color - color of the output text.
//! @param [in] fmt - format string
//! @return Returns the number of characters displayed on the screen.
//-------------------------------------------------------------------------------------------------
int cprintf(const char* color, const char* fmt, ...);
