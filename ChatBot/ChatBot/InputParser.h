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

	BOOL ParseInputString(CString & inputStr, InputParserResponse *& outputRes) const;

private:
	void TokenizeString(CString& inputStr, vector<CString>& outputVec, CString seperator = L" ") const;
	BOOL CompareInputTokens(vector<CString>& tokenizedInput, vector<CString>& comparePhrase, EInputParserResponseType responseType, InputParserResponse *& outputRes) const;

	//members:
private:
	map<EInputParserResponseType, vector<CString>> _supportedPhrases;

	static const int ADD_ITEM_INDEX = 2;


};

