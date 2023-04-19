#include "RESTClient.h"

size_t RESTClient::get_response_to_string(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*) userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::pair<size_t, std::string> RESTClient::get_request(std::string request_url) {
    CURL* curl;
    CURLcode curl_result_code;
    std::string str_response;
    size_t http_code;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl == nullptr) {
        std::cerr << "FAILED INIT" << std::endl;
        assert(false);
    }

    curl_easy_setopt(curl, CURLOPT_URL, request_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_response_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_response);

    curl_result_code = curl_easy_perform(curl);
    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);

    if (curl_result_code != CURLE_OK) {
        std::cerr << curl_easy_strerror(curl_result_code) << std::endl;
        assert(false);
    }

    return std::pair<size_t, std::string>(http_code, str_response);
}

std::string RESTClient::get_token() {
    Json::Reader reader;
    Json::Value json_tocken_responce;
    auto token_responce = get_request(url + "token");

    if (token_responce.first != 200) {
        std::cerr << "Token GET failure" << std::endl;
        assert(false);
    }

    reader.parse(token_responce.second, json_tocken_responce);

    return std::string(json_tocken_responce["token"].asCString());
}

std::string RESTClient::get_positions() {
    auto positions_responce = get_request(url + "positions");

    if (positions_responce.first != 200) {
        std::cerr << "Positions GET failure" << std::endl;
        assert(false);
    }

    return positions_responce.second;
}

std::string RESTClient::get_user_by_id(size_t id) {
    auto user_by_id_responce = get_request(url + "users/" + std::to_string(id));

    if (user_by_id_responce.first != 200) {
        std::cerr << "User by ID GET failure" << std::endl;
        assert(false);
    }

    return user_by_id_responce.second;
}

std::string RESTClient::get_users(size_t page, size_t count, size_t offset, bool default_) {
    std::string request_url;
    std::pair<size_t, std::string> users_responce;

    if (default_) {
        request_url = url + "users";
    }
    else {
        request_url = url + "users?";
        request_url += "&count=" + std::to_string(count);
        request_url += "&page=" + std::to_string(page);
        if (offset > 0)
            request_url += "&offset=" + std::to_string(offset);
    }

    users_responce = get_request(request_url);
    
    if (users_responce.first != 200) {
        std::cerr << "Users GET failure" << std::endl;
        assert(false);
    }

    return users_responce.second;
}


std::pair<size_t, std::string> RESTClient::post_user(std::string name, std::string email, std::string phone, size_t position_id, std::string photo) {
    CURL *curl;
	CURLcode curl_result_code;
	struct curl_httppost *form_post = NULL;
	struct curl_httppost *last_ptr = NULL;
    struct curl_slist *header_list = NULL;
    std::string str_response;
    size_t http_code;

    header_list = curl_slist_append(header_list, ("Token: " + get_token()).c_str());

	curl_global_init(CURL_GLOBAL_ALL);

	curl_formadd(&form_post, &last_ptr,
		CURLFORM_COPYNAME, "name",
		CURLFORM_COPYCONTENTS, name.c_str(),
		CURLFORM_END);

	curl_formadd(&form_post, &last_ptr,
		CURLFORM_COPYNAME, "email",
		CURLFORM_COPYCONTENTS, email.c_str(),
		CURLFORM_END);
    
    curl_formadd(&form_post, &last_ptr,
		CURLFORM_COPYNAME, "phone",
		CURLFORM_COPYCONTENTS, phone.c_str(),
		CURLFORM_END);
    
    curl_formadd(&form_post, &last_ptr,
		CURLFORM_COPYNAME, "position_id",
		CURLFORM_COPYCONTENTS, std::to_string(position_id).c_str(),
		CURLFORM_END);
    
    curl_formadd(&form_post, &last_ptr,
		CURLFORM_COPYNAME, "photo",
		CURLFORM_FILE, photo.c_str(),
		CURLFORM_END);

    curl = curl_easy_init();

	if (curl == nullptr) {
        std::cerr << "FAILED INIT" << std::endl;
        assert(false);
    }

    curl_easy_setopt(curl, CURLOPT_URL, (url + "users").c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_response_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_response);
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, form_post);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

    curl_result_code = curl_easy_perform(curl);
    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);

    if (curl_result_code != CURLE_OK) {
        std::cerr << curl_easy_strerror(curl_result_code) << std::endl;
        assert(false);
    }

    curl_easy_cleanup(curl);
    curl_formfree(form_post);
    curl_slist_free_all(header_list);

    return std::pair<size_t, std::string>(http_code, str_response);
}

int main() {
    // std::cout << RESTClient::get_token() << "\n" << std::endl;

    // std::cout << RESTClient::get_positions() << "\n" << std::endl;

    // std::cout << RESTClient::get_user_by_id(5) << "\n" << std::endl;

    // std::cout << RESTClient::get_users(2, 10, 1) << "\n" << std::endl;

    // std::cout << RESTClient::get_request("https://frontend-test-assignment-api.abz.agency/api/v1/users").first;

    // std::cout << RESTClient::post_user("Artu\"r", "ary@gmail.com", "+380000009999", 3, "test.jpg").second << std::endl;

    // system("leaks a.out");
}