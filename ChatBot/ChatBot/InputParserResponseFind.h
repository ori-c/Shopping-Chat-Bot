#pragma once

#include <vector>
#include "InputParserResponse.h"

using namespace std;

class InputParserResponseFind :
	public InputParserResponse
{
	//methods:
public:
	InputParserResponseFind(CString& productName);
	~InputParserResponseFind();

	CString GetResponseValue() const;

	//members:
private:
	CString _productName;
};

