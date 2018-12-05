/**
 * Copyright 2014-2017 EMBL - European Bioinformatics Institute
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

#ifndef COMPRESSION_HPP
#define COMPRESSION_HPP

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/iostreams/filter/bzip2.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filtering_stream.hpp>

#include "vcf/string_constants.hpp"


namespace ebi
{
  namespace vcf
  {
    /**
     * Computes which compression a file has.
     * @param source - this can be the file path, which may contain the file extension.
     * @param line - vector of first 5 characters or first line (if length of first line < 5) of file.
     */
    std::string get_compression(std::string const & source,
                                const std::vector<char> &line);

    /**
     * Checks if the given extension is readable or not
     * @throws std::invalid_argument exception if not readable
     */
    void check_readability_of_file(const std::string & file_ext);

    /**
     * Checks if the given stream is readable or not
     * @throws std::invalid_argument exception if not readable
     */
    void check_readability_of_stream(const std::vector<char> & line);

    /**
     * Creates uncompressed boost::iostream from given input istream
     * @param input - compressed stream
     * @param file_extension - format of compression
     * @param uncompressed_input - boost::iostream that will be inflated with uncompressed data
     */
    void create_uncompressed_stream(std::istream & input,
                                    const std::string & file_extension,
                                    boost::iostreams::filtering_istream & uncompressed_input);

    /**
     * Gets magic number from a file.
     * The magic number is the first few characters of a file from which we can detect the compression type.
     */
    void get_magic_num(std::istream & stream, std::vector<char> & container);

    /**
     * Checks if the given stream is compressed or not
     * @throws std::invalid_argument exception if compressed
     */
    void check_compressed_file(std::istream & input, std::string file_name);
  }
}

#endif // COMPRESSION_HPP
