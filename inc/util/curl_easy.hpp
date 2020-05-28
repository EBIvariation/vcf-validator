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

#ifndef VCF_VALIDATOR_CURL_EASY_HPP
#define VCF_VALIDATOR_CURL_EASY_HPP

#include <iostream>
#include <string>

#include <curl/curl.h>

namespace ebi
{
  namespace util
  {
    namespace curl
    {
      class Easy final
      {
      public:
        Easy();
        Easy(const Easy&) = delete;
        Easy& operator=(const Easy&) = delete;
        ~Easy();

        std::string request(const std::string& url, long& httpReturnCode);
        std::ostream& request(std::ostream& stream, const std::string& url, long& httpReturnCode);

      private:
        CURL* curlHandle;
        void processCurlRequest(const std::string &basicString, long &code);
      };

      class URLRetrievalException : public std::exception {
      private:
        std::string message = " ";
      public:
        URLRetrievalException(const std::string &url, long &httpReturnCode) {
            message = "HTTP " + std::to_string(httpReturnCode) + " returned when downloading: " + url;
        }

        const char *what() const noexcept override {
            return message.c_str();
        }
      };
    }
  }
}

#endif //VCF_VALIDATOR_CURL_EASY_HPP
