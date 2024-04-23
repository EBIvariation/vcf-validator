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
#include <memory>
#include <string>

#include <boost/filesystem.hpp>

#include "catch/catch.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/assembly_check_report_writer.hpp"
#include "vcf/string_constants.hpp"

namespace ebi
{
    TEST_CASE("Matching FASTA and VCF combination", "[assembly_checker]")
    {
        std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> outputs;
        outputs.emplace_back(new ebi::vcf::SummaryAssemblyCheckReportWriter());
        std::string assembly_report = ebi::vcf::NO_MAPPING;

        SECTION("Empty VCF File")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_empty_vcf/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("Single entry")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_single_variant/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("Full sample VCF, all match")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_fullsample/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("Mapping contigs , all match")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_with_mapping/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::string assembly_report_path = folder.string() + "assembly_report.txt";
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report_path, outputs));
        }

        SECTION("Mapping contigs but contig has same synonym on the same line, all match")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_with_mapping_multi_synonyms/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::string assembly_report_path = folder.string() + "assembly_report.txt";
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report_path, outputs));
        }

        SECTION("compressed VCF, gz compression")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/compressed/passed_compressed_gz/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_GZ_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("no fasta provided, using ENA API to retrieve fasta for contigs")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_ena_api/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_GZ_EXT;
            std::ifstream vcf_input{vcf_path};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, "", assembly_report, outputs));
        }

        SECTION("no fasta index provided, creating index from fasta file on-the-fly")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_missing_index/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_GZ_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }
    }

    TEST_CASE("Not fully matching VCF and Fasta combination", "[assembly_checker]")
    {
        std::vector<std::unique_ptr<ebi::vcf::AssemblyCheckReportWriter>> outputs;
        outputs.emplace_back(new ebi::vcf::SummaryAssemblyCheckReportWriter());
        std::string assembly_report = ebi::vcf::NO_MAPPING;

        SECTION("Single entry, single mismatch")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_singlemismatch_singleentry/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("Multiple entry, multiple mismatch")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_multiplemismatch_multipleentry/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("Empty FASTA file, single entry")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_empty_fasta/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("Multiple entry, all mismatch")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_allmismatch_multipleentry/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("Not mapping contigs , fail")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/passed/passed_with_mapping/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
        }

        SECTION("No fasta provided, using ENA API to retrieve fasta for contigs, but got no sequence, fail")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_ena_api/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, "", assembly_report, outputs));
        }

        SECTION("With a valid assembly report, but a synonym could not be found for chromosome, can't use ENA API to download fasta, fail")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_ena_api_with_mapping/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string assembly_report_path = folder.string() + "assembly_report.txt";
            CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, "", assembly_report_path, outputs));
        }

        SECTION("Bad assembly_report , throws exception")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_to_parse_assembly_report/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::string assembly_report_path = folder.string() + "assembly_report.txt";
            CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report_path, outputs), std::runtime_error);
        }

        SECTION("No Genbank equivalents for the contigs found in VCF, throws exception")
        {
            auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/failed/failed_no_genbank_contigs/");
            std::string file_prefix = folder.parent_path().filename().string();
            std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_EXT;
            std::ifstream vcf_input{vcf_path};
            std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
            std::string assembly_report_path = folder.string() + "assembly_report.txt";
            std::cout << fasta_path << vcf_path;
            CHECK_THROWS_AS(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report_path, outputs, true), std::runtime_error);
        }

// TODO test non-equivalent synonyms (Genbank <> RefSeq)

// TODO: make the next work in windows as well
#ifdef _WIN32
#else
         SECTION("compressed vcf, bz2 compression")
         {
             auto folder = boost::filesystem::path("test/input_files/v4.3/assembly_checker/compressed/failed_compressed_bz2/");
             std::string file_prefix = folder.parent_path().filename().string();
             std::string vcf_path = folder.string() + file_prefix + ebi::vcf::VCF_BZ2_EXT;
             std::ifstream vcf_input{vcf_path};
             std::string fasta_path{folder.string() + file_prefix + ebi::vcf::FASTA_EXT};
             CHECK_FALSE(ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, vcf_path, fasta_path, assembly_report, outputs));
         }
#endif
    }
}
