#include "stdafx.h"
#include "ChatBotApp.h"


ChatBotApp::ChatBotApp()
{
}


ChatBotApp::~ChatBotApp()
{
}


void ChatBotApp::Start()
{
	_ioHandler.WriteLine(ChatBotCommon::WELCOME_MESSAGE);
	CString input;
	CString listString;
	CString response;
	do {
		_ioHandler.GetLine(input);
		if (input.CompareNoCase(ChatBotCommon::EXIT_COMMAND) == 0) {
			_ioHandler.WriteLine(ChatBotCommon::TERMINATION_MESSAGE);
			break;
		}
		if (_parser.ParseInputString(input, _res)) {
			switch (_res->GetResponseType()) {
			case EInputParserResponseType::FIND_PRODUCT:
				_productToFind = static_cast<InputParserResponseFind*>(_res)->GetResponseValue();
				if (!_productsFetcher.QueryProduct(_productToFind, _productsList)) {
					_ioHandler.WriteLine(ChatBotCommon::PRODUCT_QUERY_ERROR);
					break;
				}
				ParseItemList(_productsList, listString);
				response.Format(ChatBotCommon::FOUND_MESSAGE, _productsList.size(), listString);
				_ioHandler.WriteLine(response);
				break;
			case EInputParserResponseType::ADD_PRODUCT:
				if (_productsList.empty()) {
					_ioHandler.WriteLine(ChatBotCommon::NO_PRODUCTS_MESSAGE);
					break;
				}
				_addProductIndex = static_cast<InputParserResponseAdd*>(_res)->GetResponseValue();
				if (!AddProductToShoppingList()) {
					_ioHandler.WriteLine(ChatBotCommon::INVALID_INDEX_MESSAGE);
					break;
				}
				response.Format(ChatBotCommon::ADD_MESSAGE, _productToAdd);
				_ioHandler.WriteLine(response);
				break;
			case EInputParserResponseType::SHOW_LIST:
				ParseItemList(_shoppingList, listString);
				response.Format(ChatBotCommon::SHOW_MESSAGE, listString);
				_ioHandler.WriteLine(response);
				break;
			case EInputParserResponseType::UNKNOWN:
			default:
				//should not reach here
				_ioHandler.WriteLine(ChatBotCommon::UNKNOWN_COMMAND);
				break;
			}
		}
		else {
			_ioHandler.WriteLine(ChatBotCommon::UNKNOWN_COMMAND);
		}

		if (_res != nullptr) {
			delete(_res); //free only allocated memory
			_res = nullptr;
		}
	} while (input.CompareNoCase(ChatBotCommon::EXIT_COMMAND) != 0);
}

void ChatBotApp::ParseItemList(vector<CString> & listToParse, CString& outputString, CString seperator) const
{
	if (listToParse.empty()) {
		return;
	}
	outputString.Empty();
	vector<CString>::size_type i;
	for(i = 0; i <  listToParse.size() - 1; ++i) {
		outputString += listToParse[i];
		outputString += seperator;
	}
	outputString += listToParse[i];

}

BOOL ChatBotApp::AddProductToShoppingList()
{
	if (_addProductIndex > _productsList.size() || _addProductIndex <= 0) {
		return FALSE;
	}
	_productToAdd = _productsList[_addProductIndex - 1];
	_shoppingList.push_back(_productToAdd);
	return TRUE;
}
