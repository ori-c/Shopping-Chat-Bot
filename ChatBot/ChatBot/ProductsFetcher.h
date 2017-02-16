#pragma once

#include <vector>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>   

#include "ChatBotCommon.h"

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams
using namespace web::json;


class ProductsFetcher
{
public:
	//methods:
	ProductsFetcher();
	~ProductsFetcher();

	BOOL QueryProduct(const CString& productToQuery, std::vector<CString> & outputProducts) const;

	//members:


};

