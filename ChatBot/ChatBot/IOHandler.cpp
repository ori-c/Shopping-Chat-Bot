#include "stdafx.h"
#include "IOHandler.h"


IOHandler::IOHandler()
{
}


IOHandler::~IOHandler()
{
}

void IOHandler::GetLine(CString& input) const
{
	string temp;
	getline(cin, temp);
	input =  temp.c_str();
}

void IOHandler::WriteLine(const CString & output) const
{
	wcout << output.GetString() << "\n";
}
