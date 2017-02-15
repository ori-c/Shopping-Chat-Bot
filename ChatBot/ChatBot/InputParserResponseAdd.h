#pragma once

#include "InputParserResponse.h"

using namespace std;

class InputParserResponseAdd :
	public InputParserResponse
{
	//methods:
public:
	InputParserResponseAdd(int productIndex);
	~InputParserResponseAdd();

	int GetResponseValue() const;

	//members:
private:
	int _productIndex;
};

