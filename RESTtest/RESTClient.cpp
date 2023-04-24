#include "RESTClient.h"

size_t RESTClient::get_responce_to_string(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

size_t RESTClient::get_responce_to_file(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

std::pair<size_t, std::string> RESTClient::get_request(std::string request_url) {
    CURL* curl;
    CURLcode curl_result_code;
    std::string str_response;
    size_t http_code = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl == nullptr) {
        curl_easy_cleanup(curl);
        throw std::string("Program has no connection to service");
    }

    curl_easy_setopt(curl, CURLOPT_URL, request_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_responce_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_response);

    curl_result_code = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);

    if (curl_result_code != CURLE_OK) {
        throw std::string("Program has no connection to service");
    }

    return std::pair<size_t, std::string>(http_code, str_response);
}

std::string RESTClient::get_token() {
    Json::Reader reader;
    Json::Value json_tocken_responce;
    auto token_responce = get_request(url + "token");

    if (token_responce.first != 200) {
        throw std::string("Program has no connection to service");
    }

    reader.parse(token_responce.second, json_tocken_responce);

    return std::string(json_tocken_responce["token"].asCString());
}

std::string RESTClient::get_positions() {
    auto positions_responce = get_request(url + "positions");

    if (positions_responce.first != 200) {
        throw std::string("Program has no connection to service");
    }

    return positions_responce.second;
}

std::string RESTClient::get_user_by_id(size_t id) {
    auto user_by_id_responce = get_request(url + "users/" + std::to_string(id));

    if (user_by_id_responce.first != 200) {
        throw std::string("Program has no connection to service");
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
        throw std::string("Program has no connection to service");
    }

    return users_responce.second;
}


std::pair<size_t, std::string> RESTClient::post_user(std::string name, std::string email, std::string phone, size_t position_id, std::string photo) {
    CURL* curl;
    CURLcode curl_result_code;
    struct curl_httppost* form_post = NULL;
    struct curl_httppost* last_ptr = NULL;
    struct curl_slist* header_list = NULL;
    std::string str_response;
    size_t http_code = 0;

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
        curl_easy_cleanup(curl);
        curl_formfree(form_post);
        curl_slist_free_all(header_list);
        throw std::string("Program has no connection to service");
    }

    curl_easy_setopt(curl, CURLOPT_URL, (url + "users").c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_responce_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_response);
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, form_post);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

    curl_result_code = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    curl_easy_cleanup(curl);
    curl_formfree(form_post);
    curl_slist_free_all(header_list);

    if (curl_result_code != CURLE_OK) {
        throw std::string("Program has no connection to service");
    }

    return std::pair<size_t, std::string>(http_code, str_response);
}

size_t RESTClient::get_picture_to_file(std::string file_name, std::string picture_url) {
    CURL* curl;
    CURLcode curl_result_code;
    size_t http_code = 0;
    FILE* file = fopen(file_name.c_str(), "wb");

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl == nullptr) {
        fclose(file);
        curl_easy_cleanup(curl);
        throw std::string("Program has no connection to service");
    }

    curl_easy_setopt(curl, CURLOPT_URL, picture_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_responce_to_file);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    curl_result_code = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);
    fclose(file);

    if (curl_result_code != CURLE_OK) {
        throw std::string("Program has no connection to service");
    }

    return http_code;
}
