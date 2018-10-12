/**
 * Copyright 2014-2018 EMBL - European Bioinformatics Institute
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

#ifndef ASSEMBLY_REPORT_HPP
#define ASSEMBLY_REPORT_HPP

#include <map>
#include <string>
#include <vector>

#include <boost/algorithm/string/trim.hpp>
#include "util/stream_utils.hpp"
#include "util/string_utils.hpp"

namespace ebi
{
  namespace assembly_report
  {
    /*
     * Struct to contain all the synonyms of a contig
     */
    struct Synonyms_list {
        std::vector<std::string> list;
        Synonyms_list() {

        }

        Synonyms_list(std::string contig) {
            list.push_back(contig);
        }

        Synonyms_list(std::vector<std::string> & list) : list(list) {

        }
    };

    /*
     * Map to map all contigs to their synonym_maps
     */
    class Synonyms_map {
        std::map<std::string,int> index_map;
        std::map<int,Synonyms_list> list_map;

        Synonyms_list extract_synonyms(std::vector<std::string> & list) {
            std::vector<int> synonym_indices{0,4,6,9};
            Synonyms_list synonyms_list;
            for (auto index : synonym_indices) {
                synonyms_list.list.push_back(list[index]);
            }

            return synonyms_list;
        }

        public:
        Synonyms_list get_synonym_list(std::string & contig) {
            if (index_map.find(contig) != index_map.end()) {
                return list_map[index_map[contig]];
            }
            else {
                return Synonyms_list(contig);
            }
        }

        void parse_file(std::istream &report) {
            std::vector<char> report_line;
            size_t const default_line_buffer_size = 64 * 1024;
            size_t const assembly_report_line_size = 10;
            report_line.reserve(default_line_buffer_size);

            int list_index = 0;
            while (util::readline(report, report_line).size() != 0) {
                if (report_line[0] == '#') {
                    continue;
                }

                std::vector<std::string> list;
                std::string line{report_line.begin(), report_line.end()};
                boost::algorithm::trim(line);
                util::string_split(line, "\t", list);
                if(list.size() != assembly_report_line_size) {
                    // report wrong line
                    continue;
                }

                auto synonyms_list = extract_synonyms(list);
                list_map[list_index] = synonyms_list;
                for (auto synonym : synonyms_list.list) {
                    index_map[synonym] = list_index;
                }
                list_index++;

            }
        }
    };
  }
}

#endif // ASSEMBLY_REPORT_HPP
