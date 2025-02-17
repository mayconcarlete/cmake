#include <iostream>
#include "curl/curl.h"

int main(){

    CURL *curl;
    CURLcode res;

    // if win32
  /* In Windows, this inits the Winsock stuff */
//   curl_global_init(CURL_GLOBAL_ALL);
 


    curl = curl_easy_init();

    if(!curl){
        std::cout << "Error starting curl!!" << std::endl;
        return -1;
    }
    std::string url = "http://localhost:3003/";
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    /* example.com is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    std::cout << "Sending request..."<<curl << std::endl;
    /* Perform the request, res gets the return code */
    res = curl_easy_perform(curl);

    /* Check for errors */
    if(res != CURLE_OK){
        std::cout << "Error: " << curl_easy_strerror(res);
    }

    std::cout << "REs" << res <<std::endl;

    /* Always cleanup */
    curl_easy_cleanup(curl);

    return EXIT_SUCCESS;
}