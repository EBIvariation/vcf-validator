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

namespace ebi
{
  namespace assembly_report
  {
    /*
     * Struct to contain all the synonyms of a contig
     */
    struct Synonym_list {
        std::vector<std::string> list;
    };

    /*
     * Map to map all contigs to their synonym_maps
     */
    class Synonyms_map {
        std::map<std::string,Synonym_list*> synonym_map;
        public:
        Synonym_list get_synonym_list(std::string & contig) {
            if (synonym_map.find(contig) != synonym_map.end()) {
                return *synonym_map[contig];
            }
            else {
                return Synonym_list{{contig}};
            }
        }

        void parse_file(std::ifstream &report) {

        }
    };
  }
}

#endif // ASSEMBLY_REPORT_HPP
