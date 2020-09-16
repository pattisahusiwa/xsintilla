// Scintilla source code edit control
/** @file Catalogue.cxx
 ** Colourise for particular languages.
 **/
// Copyright 1998-2002 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.

#include <cstdlib>
#include <cassert>
#include <cstring>

#include <stdexcept>
#include <vector>

#include "ILexer.h"
#include "Scintilla.h"
#include "SciLexer.h"

#include "LexerModule.h"
#include "Catalogue.h"

#ifdef SCI_NAMESPACE
using namespace Scintilla;
#endif

static std::vector<LexerModule *> lexerCatalogue;
static int nextLanguage = SCLEX_AUTOMATIC+1;

const LexerModule *Catalogue::Find(int language) {
	Scintilla_LinkLexers();
	for (const LexerModule *lm : lexerCatalogue) {
		if (lm->GetLanguage() == language) {
			return lm;
		}
	}
	return 0;
}

const LexerModule *Catalogue::Find(const char *languageName) {
	Scintilla_LinkLexers();
	if (languageName) {
		for (const LexerModule *lm : lexerCatalogue) {
			if (lm->languageName && (0 == strcmp(lm->languageName, languageName))) {
				return lm;
			}
		}
	}
	return 0;
}

void Catalogue::AddLexerModule(LexerModule *plm) {
	if (plm->GetLanguage() == SCLEX_AUTOMATIC) {
		plm->language = nextLanguage;
		nextLanguage++;
	}
	lexerCatalogue.push_back(plm);
}

// To add or remove a lexer, add or remove its file and run LexGen.py.

// Force a reference to all of the Scintilla lexers so that the linker will
// not remove the code of the lexers.
int Scintilla_LinkLexers() {

	static int initialised = 0;
	if (initialised)
		return 0;
	initialised = 1;

// Shorten the code that declares a lexer and ensures it is linked in by calling a method.
#define LINK_LEXER(lexer) extern LexerModule lexer; Catalogue::AddLexerModule(&lexer);

//++Autogenerated -- run scripts/LexGen.py to regenerate
//**\(\tLINK_LEXER(\*);\n\)
	LINK_LEXER(lmBash);
	LINK_LEXER(lmBatch);
	LINK_LEXER(lmBibTeX);
	LINK_LEXER(lmBlitzBasic);
	LINK_LEXER(lmCmake);
	LINK_LEXER(lmConf);
	LINK_LEXER(lmCPP);
	LINK_LEXER(lmCPPNoCase);
	LINK_LEXER(lmCss);
	LINK_LEXER(lmD);
	LINK_LEXER(lmDiff);
	LINK_LEXER(lmErrorList);
	LINK_LEXER(lmF77);
	LINK_LEXER(lmFortran);
	LINK_LEXER(lmFreeBasic);
	LINK_LEXER(lmHTML);
	LINK_LEXER(lmIndent);
	LINK_LEXER(lmInno);
	LINK_LEXER(lmJSON);
	LINK_LEXER(lmLatex);
	LINK_LEXER(lmLua);
	LINK_LEXER(lmMake);
	LINK_LEXER(lmMarkdown);
	LINK_LEXER(lmMatlab);
	LINK_LEXER(lmMSSQL);
	LINK_LEXER(lmMySQL);
	LINK_LEXER(lmNsis);
	LINK_LEXER(lmNull);
	LINK_LEXER(lmOctave);
	LINK_LEXER(lmPascal);
	LINK_LEXER(lmPB);
	LINK_LEXER(lmPerl);
	LINK_LEXER(lmPHPSCRIPT);
	LINK_LEXER(lmProps);
	LINK_LEXER(lmPureBasic);
	LINK_LEXER(lmPython);
	LINK_LEXER(lmRuby);
	LINK_LEXER(lmSQL);
	LINK_LEXER(lmTCMD);
	LINK_LEXER(lmTeX);
	LINK_LEXER(lmTxt2tags);
	LINK_LEXER(lmVB);
	LINK_LEXER(lmVBScript);
	LINK_LEXER(lmXML);

//--Autogenerated -- end of automatically generated section

	return 1;
}
