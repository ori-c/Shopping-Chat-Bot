#include "stdafx.h"
#include "ProductsFetcher.h"

ProductsFetcher::ProductsFetcher()
{

}


ProductsFetcher::~ProductsFetcher()
{
}

BOOL ProductsFetcher::QueryProduct(const CString & productToQuery, std::vector<CString> & outputProducts) const
{
	// Create http_client to send the request.
	http_client client(U("https://platform.shopyourway.com/"));

	web::json::value json;
	BOOL res;
	std::vector<CString> responseProducts;
	// Build request URI and start the request.
	uri_builder builder(U("/products/search"));
	builder.append_query(U("q"), productToQuery.GetString());
	builder.append_query(U("token"), ChatBotCommon::TOKEN.GetString());
	builder.append_query(U("hash"), ChatBotCommon::HASH.GetString());
	client.request(methods::GET, builder.to_string()).then([&json, &responseProducts, &res](web::http::http_response response) {
		if (response.status_code() != 200) {
			res = FALSE;
			return;
		}
		json = response.extract_json().get();
		auto array = json.at(U("products")).as_array();
		CString productString;
		for (size_t i = 0; i < array.size(); ++i) {
			auto val = array[i].at(U("name")).as_string();
			productString.Format((L"%s"), val.c_str());
			responseProducts.push_back(productString);
		}
		res = TRUE;
	}).wait();

	if (res == TRUE) {
		outputProducts = responseProducts;
	}
	return res;


}
