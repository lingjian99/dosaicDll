//dosaic.h - Contains declarations of dosac functions to be exported.

#ifdef LOSAIC_EXPORTS
#define LOSAIC_API __declspec(dllexport)
#else
#define LOSAIC_API __declspec(dllimport)
#endif

extern "C" LOSAIC_API void dosaic(wchar_t* file); 
