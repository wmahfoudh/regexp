#include "regexp.h"
#include "interface.h"

#define PCRE2_STATIC
#define PCRE2_CODE_UNIT_WIDTH 16
#include "pcre2.h"

HANDLE	hArray;				// temporary handle for returning large arrays to XL

__declspec(dllexport) LPXLOPER regexp_find(LPXLOPER inputstring, LPXLOPER pattern, long position)
{
	return inputstring;
}

// This function is called by Excel if the xlbitDLLFree bit has been set in the
// return array of the interp function.  It allows us to free up allocated memory.

__declspec(dllexport) void xlAutoFree( LPXLOPER pxFree )
{
	if ( hArray )
	{
		GlobalUnlock( hArray );
		GlobalFree( hArray );
		hArray = 0;
	}
	return;
}

// ClipSize is a utility function that will determine the size of a "multi" array
// structure.  It checks to see if the data is organized in columns or rows (giving
// preference to columns), and ignores empty cells at the end of the array.
// It returns the size of the 1D table of valid data.

WORD ClipSize( XLOPER *multi )
{
	WORD		size, i;
	LPXLOPER	ptr;
	
	// get the number of columns in the data
	size = multi->val.array.columns;
	
	// if there's only one column, then it must be organized in multiple rows.
	if ( size == 1 )
		size = multi->val.array.rows;

	// ignore empty or error values at the end of the array.
	for ( i = size - 1; i >= 0; i-- )
	{
		ptr = multi->val.array.lparray + i;

		if ( ptr->xltype != xltypeNil )
			break;
	}
	
	return i + 1;
}
