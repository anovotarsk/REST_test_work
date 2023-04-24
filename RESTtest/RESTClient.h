#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

#include "jsoncpp/json/json.h"

#define CURL_STATICLIB
#include "curl/curl.h"

#pragma comment(lib, "curl/libcurl_a.lib")
#pragma comment(lib, "Normaliz.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Wldap32.lib")
#pragma comment(lib, "Crypt32.lib")
#pragma comment(lib, "advapi32.lib")


class RESTClient {
private:
    inline static  std::string url = "https://frontend-test-assignment-api.abz.agency/api/v1/";

    static size_t get_responce_to_string(void* contents, size_t size, size_t nmemb, void* userp);
    static size_t get_responce_to_file(void* ptr, size_t size, size_t nmemb, FILE* stream);
    static std::pair<size_t, std::string> get_request(std::string url);

    // return ready token as string. all failure checks implemented here
public:
    static std::string get_token();

public:
    static std::string get_users(size_t page, size_t count, size_t offset = 0, bool default_ = false);
    static std::string get_user_by_id(size_t id);
    static std::string get_positions();

    static size_t get_picture_to_file(std::string file_name, std::string picture_url);

    static std::pair<size_t, std::string> post_user(std::string name, std::string email, std::string phone, size_t position_id, std::string photo);
};

