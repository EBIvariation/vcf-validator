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

#include <boost/regex.hpp>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string/trim.hpp>

#include "util/stream_utils.hpp"
#include "util/string_utils.hpp"

namespace ebi
{
  namespace assembly_report
  {
    /**
     * Class to contain all the synonyms of a contig
     */
    class ContigSynonyms
    {
      public:
        ContigSynonyms()
        {

        }

        ContigSynonyms(std::string contig)
        {
            synonyms.push_back(contig);
        }

        ContigSynonyms(std::vector<std::string> & synonyms) : synonyms(synonyms)
        {

        }

        std::vector<std::string> const & get_synonyms() const
        {
            return synonyms;
        }

        void add_synonym(std::string synonym)
        {
            // Only add the synonym if there isn't one already
            if (std::find(synonyms.begin(), synonyms.end(), synonym) == synonyms.end())
            {
                synonyms.push_back(synonym);
            }
        }

      private:
        std::vector<std::string> synonyms;

    };

    /**
     * Mapping from every contig to all its synonyms, using an additional vector to efficiently search for repeated
     * records in the assembly report.
     * This vector contains the structs that associate a contig with all its synonyms.
     * A map stores the correspondence between a name and the index its synonyms are located in the vector.
     */
    class SynonymsMap
    {
      public:
        /**
         * Check if a contig synonym is in a genbank accession format
         * @see <a href="https://www.ncbi.nlm.nih.gov/Sequin/acc.html">Genbank accession format</a>
        */
        static bool is_a_genbank_accession(const std::basic_string<char>& synonym) {
            static const boost::regex genbank_accession("[A-Z][0-9]{5}\.[0-9]+|"
                                                        "[A-Z]{2}[0-9]{6}\.[0-9]+|"
                                                        "[A-Z]{2}[0-9]{8}\.[0-9]+|"
                                                        "[A-Z]{4}[0-9]{8}\.[0-9]+|[A-Z]{6}[0-9]{9}\.[0-9]+" //WGS sequences
            );
            return boost::regex_match(synonym, genbank_accession);
        }

        bool is_contig_available(std::string contig) const
        {
            return index_map.find(contig) != index_map.end();
        }

        const std::vector<std::string> & get_contig_synonyms(std::string contig) const
        {
            if (is_contig_available(contig)) {
                return contigs[index_map.at(contig)].get_synonyms();
            } else {
                throw std::invalid_argument("Contig '" + contig + "' not found in synonyms map");
            }
        }

        void parse_assembly_report(std::istream & report)
        {
            std::vector<char> report_line;
            size_t const default_line_buffer_size = 64 * 1024;
            size_t const assembly_report_column_count = 10;
            report_line.reserve(default_line_buffer_size);
            std::vector<std::string> assembly_report_errors; // to contain errors while parsing
            std::map<std::string,std::set<int>> multiple_occurrence_of_contig_errors;

            int contig_index = 0, line_offset = 1;
            while (util::readline(report, report_line).size() != 0) {
                if (report_line[0] == '#') {
                    line_offset++;
                    continue;
                }

                std::vector<std::string> columns;
                std::string line{report_line.begin(), report_line.end()};
                boost::algorithm::trim(line);
                util::string_split(line, "\t", columns);
                if (columns.size() != assembly_report_column_count) {
                    std::string error = "Line num " + std::to_string(line_offset + contig_index)
                                        + " : Expected " + std::to_string(assembly_report_column_count)
                                        + " columns, found " + std::to_string(columns.size()) + "\n";
                    assembly_report_errors.push_back(error);
                    continue;
                }

                auto contig_synonyms = extract_synonyms(columns);
                contigs.push_back(contig_synonyms);
                for (auto contig : contig_synonyms.get_synonyms()) {
                    if (ignore_contig.find(contig) != ignore_contig.end()) {
                        continue;
                    }
                    if (index_map.find(contig) != index_map.end() && index_map[contig] != contig_index) {
                        // if a contig is found in two different lines that would be treated as error
                        multiple_occurrence_of_contig_errors[contig].insert(contig_index + line_offset);
                        multiple_occurrence_of_contig_errors[contig].insert(index_map[contig] + line_offset);
                        continue;
                    }
                    index_map[contig] = contig_index;
                }
                contig_index++;

            }

            for (auto contig_error: multiple_occurrence_of_contig_errors) {
                std::stringstream error;
                error << "Contig '" + contig_error.first + "' found in multiple lines : ";
                ebi::util::print_container(error, contig_error.second, "", ",", "");
                error << std::endl;
                assembly_report_errors.push_back(error.str());
            }

            if (!assembly_report_errors.empty()) {
                std::string error_report = "Some errors occurred while parsing assembly report file \n";
                for (auto error : assembly_report_errors) {
                    error_report += error;
                }
                throw std::runtime_error(error_report);
            }
        }

      private:
        std::map<std::string,int> index_map;
        std::vector<ContigSynonyms> contigs;
        /*
         * set of names that needs to be ignored if present in assembly report
         */
        const std::set<std::string> ignore_contig{"na"};

        ContigSynonyms extract_synonyms(std::vector<std::string> & synonyms)
        {
            std::vector<int> synonym_indices{0, 4, 6, 9};
            ContigSynonyms contig_synonyms;
            for (auto index : synonym_indices) {
                if (ignore_contig.find(synonyms[index]) != ignore_contig.end()) {
                    continue;
                }
                contig_synonyms.add_synonym(synonyms[index]);
            }

            return contig_synonyms;
        }

    };
  }
}

#endif // ASSEMBLY_REPORT_HPP
