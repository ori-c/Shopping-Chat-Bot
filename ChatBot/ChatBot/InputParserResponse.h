#pragma once

#include "ChatBotCommon.h"

using namespace ChatBotCommon;

class InputParserResponse
{
	//methods:
public:
	InputParserResponse();

	InputParserResponse(EInputParserResponseType responseType);

	virtual ~InputParserResponse();

	EInputParserResponseType GetResponseType() const;


	//members:
protected:
	EInputParserResponseType _responseType;
};

