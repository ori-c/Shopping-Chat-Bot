#pragma once

#include <iostream>
#include <string>

#include "InputParser.h"
#include "ProductsFetcher.h"
#include "ChatBotCommon.h"
#include "InputParserResponse.h"
#include "IOHandler.h"

using namespace std;
using namespace ChatBotCommon;

class ChatBotApp
{
	//methods:
public:
	ChatBotApp();
	~ChatBotApp();

	void Start();

private:
	void ParseItemList(const vector<CString> & listToParse, CString& outputString, const CString seperator = L", ") const;
	BOOL AddProductToShoppingList();

	//members:
private:

	//helper classes:
	const InputParser _parser;
	const ProductsFetcher _productsFetcher;
	const IOHandler _ioHandler;

	//data structures:
	vector<CString> _shoppingList;
	vector<CString> _productsList;
	
	InputParserResponse* _res = nullptr;
	CString _productToFind;
	CString _productToAdd;
	int _addProductIndex;
	
};

