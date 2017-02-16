#include "stdafx.h"
#include "InputParserResponseFind.h"

using namespace ChatBotCommon;

InputParserResponseFind::InputParserResponseFind(const CString& productName)
	:InputParserResponse(EInputParserResponseType::FIND_PRODUCT), _productName(productName)
{
}


InputParserResponseFind::~InputParserResponseFind()
{
}

CString InputParserResponseFind::GetResponseValue() const
{
	return _productName;
}
