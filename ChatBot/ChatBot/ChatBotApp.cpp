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
		if (_parser.ParseInputString(input, _res) != TRUE) {
			response.Format(ChatBotCommon::UNKNOWN_COMMAND);
		}
		else {
			switch (_res->GetResponseType()) {
			case EInputParserResponseType::FIND_PRODUCT:
				_productToFind = static_cast<InputParserResponseFind*>(_res)->GetResponseValue();
				if (!_productsFetcher.QueryProduct(_productToFind, _productsList)) {
					response.Format(ChatBotCommon::PRODUCT_QUERY_ERROR);
					break;
				}
				ParseItemList(_productsList, listString);
				response.Format(ChatBotCommon::FOUND_MESSAGE, _productsList.size(), listString);
				break;
			case EInputParserResponseType::ADD_PRODUCT:
				if (_productsList.empty()) {
					response.Format(ChatBotCommon::NO_PRODUCTS_MESSAGE);
					break;
				}
				_addProductIndex = static_cast<InputParserResponseAdd*>(_res)->GetResponseValue();
				if (!AddProductToShoppingList()) {
					response.Format(ChatBotCommon::INVALID_INDEX_MESSAGE);
					break;
				}
				response.Format(ChatBotCommon::ADD_MESSAGE, _productToAdd);
				break;
			case EInputParserResponseType::SHOW_LIST:
				ParseItemList(_shoppingList, listString);
				response.Format(ChatBotCommon::SHOW_MESSAGE, listString);
				break;
			case EInputParserResponseType::UNKNOWN:
			default:
				//should not reach here
				response.Format(ChatBotCommon::UNKNOWN_COMMAND);
				break;
			}
		}
		_ioHandler.WriteLine(response);
		if (_res != nullptr) {
			delete(_res); //free only allocated memory
			_res = nullptr;
		}
	} while (input.CompareNoCase(ChatBotCommon::EXIT_COMMAND) != 0);
}

void ChatBotApp::ParseItemList(const vector<CString> & listToParse, CString& outputString, const CString seperator) const
{
	outputString.Empty();
	if (listToParse.empty()) {
		return;
	}
	
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
