#include "generic.h"

#define PCRE2_STATIC
#define PCRE2_CODE_UNIT_WIDTH 16
#include "pcre2.h"

//#define dimResult	200		// size of the permanent array for returning data to XL

// Local function prototypes
WORD	ClipSize( XLOPER *multi );

// global function prototypes
__declspec(dllexport) void xlAutoFree( LPXLOPER pxFree );
__declspec(dllexport) LPXLOPER regexp_find(LPXLOPER inputstring, LPXLOPER pattern, long position);

