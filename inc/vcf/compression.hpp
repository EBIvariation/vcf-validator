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

#include "util/string_utils.hpp"
#include "vcf/report_writer.hpp"
#include "vcf/string_constants.hpp"


namespace ebi
{
  namespace vcf
  {
    /*
     * method to get compression of a file.
     * Params:
     *  source - source_name
     *  line - vector of first 5 characters or first line(if length of first line < 5) of file.
     */
    std::string get_compression(std::string const & source,
                                const std::vector<char> &line);

    /*
     * Check if the given extension is readable or not
     * Throws std::invalid_argument exception if not readable
     */
    void check_readability_of_file(const std::string & file_ext);

    /*
     * Check if the given stream is readable or not
     * Throws std::invalid_argument exception if not readable
     */
    void check_readability_of_stream(const std::vector<char> & line);

    /*
     * Create uncompressed boost::iostream from given input istream
     * Params:
     *  input - compressed stream
     *  file_extension - format of compression
     *  uncompressed_input - boost::iostream that will be inflated with uncompressed data
     */
    void create_uncompressed_stream(std::istream & input,
                                    const std::string & file_extension,
                                    boost::iostreams::filtering_istream & uncompressed_input);

    /*
     * Get magic number from a file
     * magic number means first few characters of file from which we can detect the compression
     */
    void get_magic_num(std::istream & stream, std::vector<char> & container);
  }
}

#endif // COMPRESSION_HPP
