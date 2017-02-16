#pragma once

#include <vector>
#include <map>

#include "ChatBotCommon.h"
#include "InputParserResponse.h"
#include "InputParserResponseAdd.h"
#include "InputParserResponseFind.h"

using namespace std;
using namespace ChatBotCommon;

class InputParser
{
public:
	//methods:
	InputParser();
	~InputParser();

	BOOL ParseInputString(const CString & inputStr, InputParserResponse *& outputRes) const;

private:
	void TokenizeString(const CString& inputStr, vector<CString>& outputVec, const CString seperator = L" ") const;
	BOOL CompareInputTokens(const vector<CString>& tokenizedInput, const vector<CString>& comparePhrase, const EInputParserResponseType responseType, InputParserResponse *& outputRes) const;

	//members:
private:
	map<EInputParserResponseType, vector<CString>> _supportedPhrases;

	static const int ADD_ITEM_INDEX = 2;


};

