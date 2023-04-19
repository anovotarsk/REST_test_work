#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <curl/curl.h>
#include "dist/json/json.h"

class RESTClient {
private:
    inline static  std::string url = "https://frontend-test-assignment-api.abz.agency/api/v1/";

    static size_t get_response_to_string(void* contents, size_t size, size_t nmemb, void* userp);
    static std::pair<size_t, std::string> get_request(std::string url);

    // return ready token as string. all failure checks implemented here
    static std::string get_token();

public:
    static std::string get_users(size_t page, size_t count, size_t offset = 0, bool default_ = false);
    static std::string get_user_by_id(size_t id);
    static std::string get_positions();

    static std::pair<size_t, std::string> post_user(std::string name, std::string email, std::string phone, size_t position_id, std::string photo);
};