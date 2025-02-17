#include <iostream>
#include <cstring>
#include "curl/curl.h"
#include <memory>
#include <cstdlib>
#include "nlohmann/json.hpp"

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


size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data){
  data->append((char*)ptr, size * nmemb);
  return size*nmemb;
}

void PostRequestData(){
    auto curl = curl_easy_init();
    if(!curl){
      std::cout << "Exiting..." << std::endl;
      return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:3000");
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.42.0");
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

    std::string response_string;
    std::string header_string;

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

    char *url;
    long response_code;
    double elapsed;

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
    curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl = nullptr;
    std::cout << "response_string: " << response_string << std::endl;
    std::cout << "Header_string: " << header_string << std::endl;
    std::cout << "Elapsed: " << elapsed << std::endl;

    nlohmann::json json;

    auto response = json.parse(response_string);

    std::cout << "Resultado final: " << response << std::endl;
    std::cout << "Resultado hello: " << response["hello"] << std::endl;

}

int main(){
    // GetRequest();
    // PostRequest();
    PostRequestData();
    return EXIT_SUCCESS;
}