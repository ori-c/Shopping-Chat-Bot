#include "stdafx.h"
#include "InputParser.h"


InputParser::InputParser()
{
	_supportedPhrases[EInputParserResponseType::FIND_PRODUCT] = { L"I", L"want", L"to", L"buy", L"PRODUCT_NAME" };
	_supportedPhrases[EInputParserResponseType::ADD_PRODUCT] = { L"add", L"item",L"ITEM_INDEX", L"to", L"my", L"shopping", L"list" };
	_supportedPhrases[EInputParserResponseType::SHOW_LIST] = { L"show", L"me", L"my", L"shopping", L"list" };
}


InputParser::~InputParser()
{
}

BOOL InputParser::ParseInputString(CString & inputStr, InputParserResponse *& outputRes) const
{
	vector<CString> tokenizedInput;
	TokenizeString(inputStr, tokenizedInput);

	if (tokenizedInput.empty()) {
		return FALSE;
	}
	CString firstWord = tokenizedInput[0];
	map<EInputParserResponseType, vector<CString>>::size_type phraseCount = _supportedPhrases.size();
	vector<CString> comparePhrase;
	for (map<EInputParserResponseType, vector<CString>>::size_type i = 0; i < phraseCount; ++i) {
		comparePhrase = _supportedPhrases.at((EInputParserResponseType)i);
		if (firstWord.CompareNoCase(comparePhrase.front()) == 0) {
			return CompareInputTokens(tokenizedInput, comparePhrase, (EInputParserResponseType)i, outputRes);
		}
	}
	return FALSE;
}

void InputParser::TokenizeString(CString& inputStr, vector<CString>& outputVec, CString seperator) const
{
	int position = 0;
	CString token = inputStr.Tokenize(seperator, position);
	while (!token.IsEmpty()) {
		outputVec.push_back(token);
		token = inputStr.Tokenize(seperator, position);
	}
}

BOOL InputParser::CompareInputTokens(vector<CString>& tokenizedInput, vector<CString>& comparePhrase, EInputParserResponseType responseType, InputParserResponse *& outputRes) const
{
	if (tokenizedInput.size() != comparePhrase.size()) {
		return FALSE;
	}
	map<EInputParserResponseType, vector<CString>>::size_type i;
	switch (responseType) {
	case EInputParserResponseType::FIND_PRODUCT:
		for (i = 0; i < comparePhrase.size() - 1; ++i) {
			if (tokenizedInput.at(i).CompareNoCase(comparePhrase.at(i)) != 0) {
				return FALSE;
			}
		}
		outputRes = new InputParserResponseFind(tokenizedInput.back());
		return TRUE;
	case EInputParserResponseType::ADD_PRODUCT:
		int productIndex;
		for (i = 0; i < comparePhrase.size(); ++i) {
			if (i == ADD_ITEM_INDEX) {
				productIndex = _ttoi((tokenizedInput[ADD_ITEM_INDEX]));
				continue;
			}
			if (tokenizedInput.at(i).CompareNoCase(comparePhrase.at(i)) != 0) {
				return FALSE;
			}
		}
		outputRes = new InputParserResponseAdd(productIndex);
		return TRUE;
	case EInputParserResponseType::SHOW_LIST:
		for (i = 0; i < comparePhrase.size(); ++i) {
			if (tokenizedInput.at(i).CompareNoCase(comparePhrase.at(i)) != 0) {
				return FALSE;
			}
		}
		outputRes = new InputParserResponse(EInputParserResponseType::SHOW_LIST);
		return TRUE;
	case EInputParserResponseType::UNKNOWN:
	default:
		return FALSE;
	}
		
}

