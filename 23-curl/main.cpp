#include <iostream>
#include <cstring>
#include "curl/curl.h"
#include <memory>
#include <cstdlib>

void GetRequest(){
    CURL *curl;
    CURLcode res;

    // if win32
    /* In Windows, this inits the Winsock stuff */
    //   curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    if(!curl){
        std::cout << "Error starting curl!!" << std::endl;
        return;
    }
    std::string url = "http://localhost:3000/";
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

    std::cout << "Response code: " << res <<std::endl;

    /* Always cleanup */
    curl_easy_cleanup(curl);
    return;
}

void PostRequest(){
    CURL *curl;
  CURLcode res;
 
  static const char *postthis = "moo mooo moo moossss";
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000/");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postthis);
 
    /* if we do not provide POSTFIELDSIZE, libcurl calls strlen() by itself */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
 
    /* Perform the request, res gets the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return;
}

int main(){
    GetRequest();
    PostRequest();
    return EXIT_SUCCESS;
}