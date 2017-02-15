#pragma once

#include <iostream>
#include <string>

using namespace std;

class IOHandler
{
public:
	//methods:
	IOHandler();
	~IOHandler();

	void GetLine(CString& input) const;
	void WriteLine(const CString& output) const;
};

