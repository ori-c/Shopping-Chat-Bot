#pragma once

namespace ChatBotCommon {

	//Web constants
	static const CString TOKEN = L"0_18401_253402300799_1_c78a591a5ecaf201c77c315dae461f0647bbbe90bc5f999d782de90e6b5bdb6f";
	static const CString HASH = L"b8b5adaf022fcbc2f70476b3d0181bd2a12b859d440cc40aa9638aa2513eaebe";

	//Parsing constants
	static const CString WELCOME_MESSAGE = L"Welcome to Chappy, the ChatBotApp! How can I help you?";
	static const CString EXIT_COMMAND = L"quit";
	static const CString TERMINATION_MESSAGE = L"Terminating...";
	static const CString NO_PRODUCTS_MESSAGE = L"No products querried";
	static const CString INVALID_INDEX_MESSAGE = L"Index out of products list bounds";
	static const CString UNKNOWN_COMMAND = L"Unknown command";
	static const CString PRODUCT_QUERY_ERROR = L"Encountered a network error";

	//Response constants
	static const CString FOUND_MESSAGE = L"I found you these %d items: %s";
	static const CString ADD_MESSAGE = L"I've added %s to your shopping list";
	static const CString SHOW_MESSAGE = L"you currently have: %s";
	

	enum EInputParserResponseType : int {
		UNKNOWN = -1,
		FIND_PRODUCT = 0,
		ADD_PRODUCT = 1,
		SHOW_LIST = 2,
	};
}