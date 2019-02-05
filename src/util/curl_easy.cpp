/**
 * Copyright 2018 EMBL - European Bioinformatics Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "util/curl_easy.hpp"

size_t
stringWriterCallback(void *contents, size_t size, size_t nmemb, void *buffer)
{
    ((std::string*)buffer)->append((const char*)contents, size * nmemb);
    return size * nmemb;
}

size_t
streamWriterCallback(void *contents, size_t size, size_t nmemb, void *stream)
{
    ((std::ostream*)stream)->write((const char*)contents, static_cast<std::streamsize>(size * nmemb));
    return size * nmemb;
}

ebi::util::curl::Easy::Easy()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curlHandle = curl_easy_init();
    if (curlHandle) {
        curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curlHandle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    }
}

ebi::util::curl::Easy::~Easy()
{
    if (curlHandle) {
        curl_easy_cleanup(curlHandle);
    }
    curl_global_cleanup();
}

std::string
ebi::util::curl::Easy::request(const std::string &url)
{
    std::string buffer;
    if (curlHandle) {
        curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, stringWriterCallback);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &buffer);
        CURLcode res = curl_easy_perform(curlHandle);
        if (res != CURLE_OK) {
            std::cerr << "ebi::util::curl::Easy::request failed: " << url << std::endl;
            std::cerr << "Reason: " << curl_easy_strerror(res) << std::endl;
        }
    }
    return buffer;
}

std::ostream&
ebi::util::curl::Easy::request(std::ostream& stream, const std::string& url)
{
    if (curlHandle) {
        curl_easy_setopt(curlHandle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, streamWriterCallback);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &stream);
        CURLcode res = curl_easy_perform(curlHandle);
        if (res != CURLE_OK) {
            std::cerr << "ebi::util::curl::Easy::request failed: " << url << std::endl;
            std::cerr << "Reason: " << curl_easy_strerror(res) << std::endl;
        }
    }
    return stream;
}
