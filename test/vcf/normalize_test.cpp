/**
 * Copyright 2016 EMBL - European Bioinformatics Institute
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
#include <iostream>
#include "catch/catch.hpp"

#include <vcf/file_structure.hpp>
#include <vcf/normalizer.hpp>

namespace ebi
{
//  TODO: extract common code
//  struct RecordTest
//  {
//      size_t normalized_pos;
//      std::string normalized_reference;
//      std::string normalized_alternate;
//  };
//  bool testNormalization(size_t pos, std::string reference, std::vector<std::string> alternate, 
//                         std::vector<RecordTest> results)
//  {
//      
//  }
//
  TEST_CASE("Record normalization", "[normalize]")
  {
      std::shared_ptr<vcf::Source> source{new vcf::Source{
          "filename.vcf", vcf::VCF_FILE_VCF, vcf::Version::v41, {}, {"NA001", "NA002", "NA003", "NA004"}}};

      source->meta_entries.emplace("FORMAT",
                                   vcf::MetaEntry{
                                       1,
                                       "FORMAT",
                                       {
                                           { "ID", "GT" },
                                           { "Number", "1" },
                                           { "Type", "String" },
                                           { "Description", "Genotype" }
                                       }
                                   });
      SECTION("same length: different ending") {
          try {
              vcf::Record record{1, "1", 1000, {"."}, "TCACCC", {"TGACGG"}, 0,
                                 {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/1", "1/1"}, source};

              std::vector<vcf::RecordCore> expected_normalization = {
                  vcf::RecordCore{1, "1", 1001, "CACCC", "GACGG"}};
              
              auto normalization = vcf::normalize(record);
              CHECK((normalization) == expected_normalization);
          } catch (vcf::Error *e) {
              // Catch doesn't seem to understand an exception thrown by a pointer. workaround to see the message: rethrow by value
              REQUIRE_NOTHROW(throw *e);
          }
      }

      SECTION("same length: same ending") {
          vcf::Record record{1, "1", 1000, {"."}, "TCACCC", {"TGACGC"}, 0,
                             {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/1", "1/1"}, source};


          std::vector<vcf::RecordCore> expected_normalization = {vcf::RecordCore{1, "1", 1001, "CACC", "GACG"}};

          CHECK(vcf::normalize(record) == expected_normalization);
      }

      SECTION("Multiallelic: same length or deletion") {
          vcf::Record record{1, "1", 10040, {"rs123"}, "TGACGTAACGATT", {"T", "TGACGTAACGGTT", "TGACGTAATAC"}, 0,
                             {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/2", "1/2"}, source};

          std::vector<vcf::RecordCore> expected_normalization = {
              vcf::RecordCore{1, "1", 10040, "TGACGTAACGATT", "T"},
              vcf::RecordCore{1, "1", 10048, "ACGATT", "ATAC"},
              vcf::RecordCore{1, "1", 10050, "A", "G"}};

          CHECK(vcf::normalize(record) == expected_normalization);
      }
  }
}

