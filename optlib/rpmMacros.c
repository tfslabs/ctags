/*
 * Generated by ./misc/optlib2c from optlib/rpmMacros.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"
#include "field.h"
#include "xtag.h"


static void initializeRpmMacrosParser (const langType language)
{

	addLanguageRegexTable (language, "main");
	addLanguageRegexTable (language, "contline");

	addLanguageTagMultiTableRegex (language, "main",
	                               "^#[^\n]*\n?",
	                               "", "", "", NULL);
	addLanguageTagMultiTableRegex (language, "main",
	                               "^%([_a-zA-Z0-9]+)(\\([^)]*\\))*[^\n]*([^\n])\n?",
	                               "\\1", "m", ""
		"{{\n"
		"    \\2 false ne {\n"
		"       . \\2 signature:\n"
		"    } if\n"
		"    \\3 (\\\\) eq {\n"
		"       % push the current tag for attaching end: later\n"
		"       .\n"
		"       % Skip next line if \\ is at the enf of the current line.\n"
		"       /contline _tenter\n"
		"    } if\n"
		"}}", NULL);
	addLanguageTagMultiTableRegex (language, "main",
	                               "^.",
	                               "", "", "", NULL);
	addLanguageTagMultiTableRegex (language, "contline",
	                               "^(\n)",
	                               "", "", ""
		"{{\n"
		"   1 /start _matchloc end:\n"
		"   _tleave\n"
		"}}", NULL);
	addLanguageTagMultiTableRegex (language, "contline",
	                               "^[^\n]*([^\n])\n?",
	                               "", "", ""
		"{{\n"
		"    \\1 (\\\\) eq not {\n"
		"       1 /end _matchloc end:\n"
		"       _tleave\n"
		"    } if\n"
		"}}", NULL);
}

extern parserDefinition* RpmMacrosParser (void)
{
	static const char *const extensions [] = {
		NULL
	};

	static const char *const aliases [] = {
		NULL
	};

	static const char *const patterns [] = {
		NULL
	};

	static kindDefinition RpmMacrosKindTable [] = {
		{
		  true, 'm', "macro", "macros",
		},
	};

	parserDefinition* const def = parserNew ("RpmMacros");

	def->versionCurrent= 0;
	def->versionAge    = 0;
	def->enabled       = true;
	def->extensions    = extensions;
	def->patterns      = patterns;
	def->aliases       = aliases;
	def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
	def->useCork       = CORK_QUEUE;
	def->kindTable     = RpmMacrosKindTable;
	def->kindCount     = ARRAY_SIZE(RpmMacrosKindTable);
	def->initialize    = initializeRpmMacrosParser;

	return def;
}
