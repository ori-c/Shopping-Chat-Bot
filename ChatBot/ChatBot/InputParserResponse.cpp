#include "stdafx.h"
#include "InputParserResponse.h"

using namespace ChatBotCommon;

InputParserResponse::InputParserResponse()
{
	_responseType = EInputParserResponseType::UNKNOWN;
}

InputParserResponse::InputParserResponse(EInputParserResponseType responseType)
	:_responseType(responseType)
{
}


InputParserResponse::~InputParserResponse()
{
}

EInputParserResponseType InputParserResponse::GetResponseType() const
{
	return _responseType;
}
