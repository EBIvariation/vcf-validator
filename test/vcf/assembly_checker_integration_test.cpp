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

#include <boost/filesystem.hpp>
#include <fstream>
#include <memory>
#include <string>

#include "catch/catch.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/assembly_report_writer.hpp"
#include "vcf/string_constants.hpp"

namespace ebi
{
    TEST_CASE("Matching FASTA and VCF combination", "[assembly_checker]")
    {
        std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> outputs;
        outputs.emplace_back(new ebi::vcf::SummaryAssemblyReportWriter());

        SECTION("Empty VCF File")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_empty_vcf/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::ifstream vcf_input{folder.string() + file_prefix + ebi::vcf::VCF_EXT};
            std::ifstream fasta_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::ifstream fasta_index_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT + ebi::vcf::INDEX_EXT};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs));
        }

        SECTION("Single entry")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_single_variant/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::ifstream vcf_input{folder.string() + file_prefix + ebi::vcf::VCF_EXT};
            std::ifstream fasta_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::ifstream fasta_index_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT + ebi::vcf::INDEX_EXT};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs));
        }

        SECTION("Full sample VCF, all match")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_fullsample/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::ifstream vcf_input{folder.string() + file_prefix + ebi::vcf::VCF_EXT};
            std::ifstream fasta_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::ifstream fasta_index_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT + ebi::vcf::INDEX_EXT};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs));
        }
    }

    TEST_CASE("Not fully matching VCF and Fasta combination", "[assembly_checker]")
    {
        std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> outputs;
        outputs.emplace_back(new ebi::vcf::SummaryAssemblyReportWriter());

        SECTION("Single entry, single mismatch")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_singlemismatch_singleentry/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::ifstream vcf_input{folder.string() + file_prefix + ebi::vcf::VCF_EXT};
            std::ifstream fasta_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::ifstream fasta_index_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT + ebi::vcf::INDEX_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs));
        }

        SECTION("Multiple entry, multiple mismatch")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_multiplemismatch_multipleentry/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::ifstream vcf_input{folder.string() + file_prefix + ebi::vcf::VCF_EXT};
            std::ifstream fasta_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::ifstream fasta_index_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT + ebi::vcf::INDEX_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs));
        }

        SECTION("Empty FASTA file, single entry")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_empty_fasta/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::ifstream vcf_input{folder.string() + file_prefix + ebi::vcf::VCF_EXT};
            std::ifstream fasta_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::ifstream fasta_index_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT + ebi::vcf::INDEX_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs));
        }

        SECTION("Multiple entry, all mismatch")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_allmismatch_multipleentry/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::ifstream vcf_input{folder.string() + file_prefix + ebi::vcf::VCF_EXT};
            std::ifstream fasta_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::ifstream fasta_index_input{folder.string() + file_prefix + ebi::vcf::FASTA_EXT + ebi::vcf::INDEX_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, outputs));
        }
    }
}
