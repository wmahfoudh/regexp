#define		kFunctionCount	1
#define		kMaxFuncParms	12

const char	*gModuleName = "\024RegExp XLL";

const int	gFunctionCount = kFunctionCount,
			gMaxFuncParms = kMaxFuncParms;

LPSTR functionParms[kFunctionCount][kMaxFuncParms] =
{
//	function title, argument types, function name, arg names, type (1=func,2=cmd),
//		group name (func wizard), hotkey, help ID, func help string, (repeat) argument help strings

	{
		// name of the c++ function
		" regexp_find",
		// type of the return value as well as the argument
		" RRRN",
		// name of the function as it appears in Excel
		" REGEXP.FIND",
		// name of the parameters as they appear in Excel
		" Within text,RegExp pattern,Match position",
		// type of the function (1=return a value 2=command)
		" 1",
		// name of the category that this function belongs in 
		" Text",
		// hotkey in case of a command
		" ", 
		// help file name and section id
		" ",
		// description of the function as shown in Excel
		" REGEXP.FIND uses regular expressions to find text.",
		// description of the parameters as shown in Excel
		" text string to be searched within.",
		" regular expression being matched.",
		" ordinal position of the match (1 = first)..",
	},

  };

LPSTR *gFuncParms = &functionParms[0][0];
