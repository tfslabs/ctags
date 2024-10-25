/*
 * Generated by ./misc/optlib2c from optlib/org.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"
#include "field.h"
#include "xtag.h"


static void initializeOrgParser (const langType language)
{

	addLanguageRegexTable (language, "toplevel");
	addLanguageRegexTable (language, "srcblock");

	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^[:blank:]*#\\+begin_src[ ]+([a-zA-Z0-9][-#+a-zA-Z0-9]*)",
	                               "", "", "{tenter=srcblock}{_guest=\\1,0end,}", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^\\*\\*\\*\\*\\*\\*\\*[ \t]+([[:graph:][:blank:]]+)([\n])?",
	                               "\\1", "G", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^\\*\\*\\*\\*\\*\\*[ \t]+([[:graph:][:blank:]]+)([\n])?",
	                               "\\1", "P", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^\\*\\*\\*\\*\\*[ \t]+([[:graph:][:blank:]]+)([\n])?",
	                               "\\1", "b", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^\\*\\*\\*\\*[ \t]+([[:graph:][:blank:]]+)([\n])?",
	                               "\\1", "u", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^\\*\\*\\*[ \t]+([[:graph:][:blank:]]+)([\n])?",
	                               "\\1", "s", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^\\*\\*[ \t]+([[:graph:][:blank:]]+)([\n])?",
	                               "\\1", "c", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^\\*[ \t]+([[:graph:][:blank:]]+)([\n])?",
	                               "\\1", "p", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^<<([^>]+)>>",
	                               "\\1", "d", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^#\\+(NAME|name):[[:blank:]]+([[:graph:][:blank:]]+)([\n])?",
	                               "\\2", "d", "", NULL);
	addLanguageTagMultiTableRegex (language, "toplevel",
	                               "^.",
	                               "", "", "", NULL);
	addLanguageTagMultiTableRegex (language, "srcblock",
	                               "^[:blank:]*#\\+end_src",
	                               "", "", "{tleave}{_guest=,,0end}", NULL);
	addLanguageTagMultiTableRegex (language, "srcblock",
	                               "^.",
	                               "", "", "", NULL);
}

extern parserDefinition* OrgParser (void)
{
	static const char *const extensions [] = {
		"org",
		NULL
	};

	static const char *const aliases [] = {
		NULL
	};

	static const char *const patterns [] = {
		NULL
	};

	static kindDefinition OrgKindTable [] = {
		{
		  true, 'd', "definition", "definitions",
		},
		{
		  true, 'p', "part", "parts",
		},
		{
		  true, 'c', "chapter", "chapters",
		},
		{
		  true, 's', "section", "sections",
		},
		{
		  true, 'u', "subsection", "subsections",
		},
		{
		  true, 'b', "subsubsection", "subsubsections",
		},
		{
		  true, 'P', "paragraph", "paragraphs",
		},
		{
		  true, 'G', "subparagraph", "subparagraphs",
		},
	};

	parserDefinition* const def = parserNew ("Org");

	def->versionCurrent= 0;
	def->versionAge    = 0;
	def->enabled       = true;
	def->extensions    = extensions;
	def->patterns      = patterns;
	def->aliases       = aliases;
	def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
	def->kindTable     = OrgKindTable;
	def->kindCount     = ARRAY_SIZE(OrgKindTable);
	def->initialize    = initializeOrgParser;

	return def;
}