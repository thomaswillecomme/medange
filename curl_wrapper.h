/* 
 * File:   curl_wrapper.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 13:45
 */

#ifndef CURL_WRAPPER_H
#define	CURL_WRAPPER_H

#include <string>
#include <exception>
#include <curl/curl.h>

class curl_wrapper {
    void* handle;
    char last_error[CURL_ERROR_SIZE];
public:
    explicit curl_wrapper();
    virtual ~curl_wrapper();
    
    std::string perform(const std::string& url) throw(std::exception);
    
private:

    static size_t curl_receive(char* content, size_t size, size_t nmemb, void *userp);
};

#endif	/* CURL_WRAPPER_H */

