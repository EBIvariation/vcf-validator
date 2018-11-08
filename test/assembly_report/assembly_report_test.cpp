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


#include <fstream>
#include <string>

#include "catch/catch.hpp"

#include "assembly_report/assembly_report.hpp"

namespace ebi
{
    TEST_CASE("Tests for parsing assembly report", "[assembly report]")
    {
        SECTION("Parsing good assembly report")
        {
            ebi::assembly_report::SynonymsMap synonyms_map;
            std::string assembly_report_path = "test/input_files/assembly_report/assembly_report.txt";
            std::ifstream input{assembly_report_path};
            CHECK_NOTHROW(synonyms_map.parse_file(input));
        }

        SECTION("Parsing official assembly report")
        {
            ebi::assembly_report::SynonymsMap synonyms_map;
            std::string assembly_report_path = "test/input_files/assembly_report/full_assembly_report/assembly_report.txt";
            std::ifstream input{assembly_report_path};
            CHECK_NOTHROW(synonyms_map.parse_file(input));
        }

        SECTION("failing to parse assembly report throw runtime error")
        {
            ebi::assembly_report::SynonymsMap synonyms_map;
            std::string assembly_report_path = "test/input_files/assembly_report/failed_different_col_size.txt";
            std::ifstream input{assembly_report_path};
            CHECK_THROWS_AS(synonyms_map.parse_file(input),std::runtime_error);
        }

        SECTION("failing to parse assembly report throw runtime error")
        {
            ebi::assembly_report::SynonymsMap synonyms_map;
            std::string assembly_report_path = "test/input_files/assembly_report/failed_same_synonym_for_different_contigs.txt";
            std::ifstream input{assembly_report_path};
            CHECK_THROWS_AS(synonyms_map.parse_file(input),std::runtime_error);
        }
    }

    TEST_CASE("Tests for fetching synonyms list", "[assembly report]")
    {
        ebi::assembly_report::SynonymsMap synonyms_map;
        std::string assembly_report_path = "test/input_files/assembly_report/assembly_report.txt";
        std::ifstream input{assembly_report_path};
        CHECK_NOTHROW(synonyms_map.parse_file(input));

        SECTION("Check availability of contig")
        {
            CHECK(synonyms_map.is_contig_available("chr1"));
            CHECK_FALSE(synonyms_map.is_contig_available("chr0"));
        }

        SECTION("Get Contig Synonyms")
        {
            ebi::assembly_report::ContigSynonyms contig_synonyms = synonyms_map.get_contig_synonyms("chr1");
            CHECK(contig_synonyms.synonyms.size() == 4);
            CHECK_THROWS_AS(synonyms_map.get_contig_synonyms("chr0"),std::invalid_argument);
        }
    }
}
