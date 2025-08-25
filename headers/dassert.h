#ifdef DEBUGMODE
    #define DASSERT(...) assert(__VA_ARGS__)
#else
    #define DASSERT(...)
#endif
