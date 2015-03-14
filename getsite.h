#ifndef GETSITE_H_INCLUDED
#define GETSITE_H_INCLUDED

#include <stdio.h>
#include <curl/curl.h>
#include <fstream>
#include <iostream>
using namespace std;

size_t writeFunction(char* buffer, size_t s, size_t num, ofstream* userPointer){
    *userPointer<<buffer;
    return s*num;
}

void getSite(const char* URL,const char* fileName){

    ofstream outFile(fileName);
    CURL *handle;
    CURLcode err;
    handle = curl_easy_init();

    if(handle){
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &outFile);
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(handle, CURLOPT_URL, URL);
        curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);

        err=curl_easy_perform(handle);

        if(err!=CURLE_OK){
            fprintf(stderr, "curl_easy_perform() has failed. %s \n \n", curl_easy_strerror(err));
            curl_easy_cleanup(handle);
        }
    }

}


#endif // GETSITE_H_INCLUDED
