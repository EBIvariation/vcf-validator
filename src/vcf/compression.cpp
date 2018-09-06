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

#include "vcf/compression.hpp"

namespace ebi
{
  namespace vcf
  {
    std::string get_compression_from_extension(std::string const & source);

    std::string get_compression_from_magic_num(const std::vector<char> &line);

    void compressed_file_warning(std::string const & file_extension);

    void create_uncompressed_stream(std::istream & input,
                                    const std::string & file_extension,
                                    boost::iostreams::filtering_istream & uncompressed_input)
    {
        if(file_extension == BZ2) {
            uncompressed_input.push(boost::iostreams::bzip2_decompressor());
        } else if(file_extension == GZ) {
            uncompressed_input.push(boost::iostreams::gzip_decompressor());
        }

        uncompressed_input.push(input);
    }

    void get_magic_num(std::istream & stream, std::vector<char> & container)
    {
        char c;
        int i = 0;
        container.clear();

        while (stream && stream.get(c)) {
            container.push_back(c);
            i++;
            if (c == '\n' || i > 4) break;
        }

        for (int j = (int)container.size()-1; j >= 0; --j) {
            stream.putback(container[j]);
            if (stream.fail()) {
                throw std::runtime_error("Stream failed while putting the magic numbers back into stream");
            }
        }
    }

    std::string get_compression(std::string const & source,
                                const std::vector<char> &line)
    {
        std::string file_extension = get_compression_from_extension(source);
        if (source != ebi::vcf::STDIN && file_extension != NO_EXT) {
            return file_extension;
        }

        return get_compression_from_magic_num(line);
    }

    std::string get_compression_from_extension(std::string const & source)
    {
        boost::filesystem::path source_name(source);
        std::string file_extension = source_name.extension().string();

        if (file_extension == BZ2 || file_extension == RAR || file_extension == TAR || file_extension == GZ ||
            file_extension == XZ || file_extension == Z || file_extension == ZIP || file_extension == ZLIB) {
            compressed_file_warning(file_extension);
            return file_extension;
        }
        return NO_EXT;
    }

    void compressed_file_warning(std::string const & file_extension)
    {
        BOOST_LOG_TRIVIAL(warning) << "Detected " << file_extension
            << " compression";
    }

    std::string get_compression_from_magic_num(const std::vector<char> &line)
    {
        std::vector<std::pair<std::vector<char>, std::string>> types = {
            { { 66, 90, 104 }, BZ2 },
            { { 31, -117 }, GZ },
            { { -3, 55, 122, 88, 90 }, XZ },
            { { 31, -99 }, Z },
            { { 80, 75, 3, 4 }, ZIP },
            { { 120, -100 }, ZLIB }
        };

        /*
         * If the first line of the VCF file is shorter than any magic number string (stored in the variable "types"),
         * std::equal will cause a segmentation fault, so if the line is shorter than the longest magic number string
         * (5 characters), then we assume there's no compression.
         */
        if (line.size() < 5) {
            return NO_EXT;
        }

        for (auto & type : types) {
            if (std::equal(type.first.begin(), type.first.end(), line.begin())) {
                compressed_file_warning(type.second);
                return type.second;
            }
        }

        return NO_EXT;
    }

    void check_readability_of_file(const std::string & file_ext)
    {
        std::set<std::string> readable_extensions = {BZ2, GZ, NO_EXT};

        if (!readable_extensions.count(file_ext)) {
            throw std::invalid_argument{"Compression type " +file_ext+ " is not supported"};
        }
    }

    void check_readability_of_stream(const std::vector<char> &line)
    {
        std::string compression_type = ebi::vcf::get_compression_from_magic_num(line);

        if (compression_type != NO_EXT) {
            throw std::invalid_argument{"Input file should not be compressed twice"};
        }
    }
  }
}
