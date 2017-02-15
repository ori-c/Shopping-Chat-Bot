#include "stdafx.h"
#include "InputParserResponseAdd.h"


InputParserResponseAdd::InputParserResponseAdd(int productIndex)
	:InputParserResponse(EInputParserResponseType::ADD_PRODUCT), _productIndex(productIndex)
{
}


InputParserResponseAdd::~InputParserResponseAdd()
{
}

int InputParserResponseAdd::GetResponseValue() const
{
	return _productIndex;
}
