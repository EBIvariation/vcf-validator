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
    struct ContigSynonyms {
        std::vector<std::string> synonyms;

        ContigSynonyms() {

        }

        ContigSynonyms(std::string contig) {
            synonyms.push_back(contig);
        }

        ContigSynonyms(std::vector<std::string> & synonyms) : synonyms(synonyms) {

        }
    };

    /*
     * Map to map all contigs to their synonym_maps
     */
    class Synonyms_map {
        std::map<std::string,int> index_map;
        std::vector<ContigSynonyms> contigs;

        ContigSynonyms extract_synonyms(std::vector<std::string> & synonyms) {
            std::vector<int> synonym_indices{0,4,6,9};
            ContigSynonyms contig_synonyms;
            for (auto index : synonym_indices) {
                contig_synonyms.synonyms.push_back(synonyms[index]);
            }

            return contig_synonyms;
        }

        public:
        bool is_contig_available(std::string & contig) {
            if (index_map.find(contig) != index_map.end()) {
                return true;
            } else {
                return false;
            }
        }

        ContigSynonyms get_contig_synonyms(std::string & contig) {
            if (index_map.find(contig) != index_map.end()) {
                return contigs[index_map[contig]];
            } else {
                throw std::invalid_argument("Contig : " + contig + " not present in synonyms map");
            }
        }

        void parse_file(std::istream &report) {
            std::vector<char> report_line;
            size_t const default_line_buffer_size = 64 * 1024;
            size_t const assembly_report_column_count = 10;
            report_line.reserve(default_line_buffer_size);

            int contig_index = 0, line_num = -1;
            while (util::readline(report, report_line).size() != 0) {
                line_num++;
                if (report_line[0] == '#') {
                    continue;
                }

                std::vector<std::string> columns;
                std::string line{report_line.begin(), report_line.end()};
                boost::algorithm::trim(line);
                util::string_split(line, "\t", columns);
                if(columns.size() != assembly_report_column_count) {
                    // todo : think some lazy way of it. process whole file before throwing the error
                    throw std::runtime_error("Error while parsing assembly report on line num : "
                                            + std::to_string(line_num) + ", "
                                            + " found " + std::to_string(columns.size()) + " columns, "
                                            + " expected " + std::to_string(assembly_report_column_count));
                }

                auto contig_synonyms = extract_synonyms(columns);
                contigs.push_back(contig_synonyms);
                for (auto contig : contig_synonyms.synonyms) {
                    index_map[contig] = contig_index;
                }
                contig_index++;

            }
        }
    };
  }
}

#endif // ASSEMBLY_REPORT_HPP
