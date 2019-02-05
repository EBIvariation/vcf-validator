/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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

#ifndef UTIL_FILE_UTILS_HPP
#define UTIL_FILE_UTILS_HPP

#include <fstream>
#include <iostream>
#include <string>

#include <boost/algorithm/string/predicate.hpp>

#include "util/curl_easy.hpp"
#include "util/string_utils.hpp"
#include "vcf/string_constants.hpp"

namespace ebi
{
  namespace util
  {

    inline void open_file(std::ifstream & input,
                          std::string path,
                          std::ios_base::openmode mode = std::ios_base::in)
    {
        input.open(path,mode);
        if (!input) {
            std::string file_error_msg = "Couldn't open file " + path;
            throw std::runtime_error{file_error_msg};
        }
    }

    inline std::ostream & open_remote(std::ostream & stream, const std::string & url)
    {
        if (!is_remote_url(url)) {
            std::string msg = "The URL is incorrect or the protocol is not supported: ";
            msg += url;
            throw std::invalid_argument{msg};
        }

        ebi::util::curl::Easy curl;
        return curl.request(stream, url);
    }

  }
}

#endif // UTIL_FILE_UTILS_HPP
