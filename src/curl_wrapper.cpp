/* 
 * File:   curl_wrapper.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 13:45
 */

#include "curl_wrapper.h"

#include <curl/curl.h>
#include <boost/thread.hpp>


class curl_wrapper_error : public std::exception {
    CURLcode code;


public:

    curl_wrapper_error(CURLcode pCode) : code(pCode) {
    }

    virtual const char* what() const throw () {
        return curl_easy_strerror(code);
    }
};

class curl_request {
    std::stringstream response;
public:

    explicit curl_request() {
        
    }

    void add_response(const char* data, size_t size) {
        response << std::string(data, size);
    }

    const std::string get_response() const{
        return response.str();
    }

};

curl_wrapper::curl_wrapper() : handle(0) {
    handle = (void*)curl_easy_init();
    
    //initialize callback
    curl_easy_setopt((CURL*)handle, CURLOPT_ERRORBUFFER, last_error);
    curl_easy_setopt((CURL*)handle, CURLOPT_VERBOSE, (long)0);
    curl_easy_setopt((CURL*)handle, CURLOPT_WRITEFUNCTION, (size_t (*)(char*,size_t,size_t,void*)) &curl_wrapper::curl_receive);
    curl_easy_setopt((CURL*)handle, CURLOPT_TIMEOUT_MS, (long)10000);
}

curl_wrapper::~curl_wrapper() {
    curl_easy_cleanup((CURL*)handle);
}

std::string curl_wrapper::perform(const std::string& url) throw(std::exception) {
    curl_request request;
    CURLcode res;

    //place the request in curl object
    curl_easy_setopt((CURL*)handle, CURLOPT_WRITEDATA, (void *) &request);
    
    curl_easy_setopt((CURL*)handle, CURLOPT_URL, (char*)url.c_str());

    //perform
    res = curl_easy_perform((CURL*)handle);

    //error handling
    if (res != CURLE_OK)
        throw curl_wrapper_error(res);
    //wait response data
    return request.get_response();
}

size_t curl_wrapper::curl_receive(char* content, size_t size, size_t nmemb, void *userp) {
    static_cast<curl_request*> (userp)->add_response((const char*) content, nmemb * size);
    return nmemb*size;
}
