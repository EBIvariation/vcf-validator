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
//  bool testNormalization(size_t pos, std::string reference, std::string alternate, 
//        size_t normalized_pos, std::string normalized_reference, std::string normalized_alternate)
//  {
//      
//  }
  
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
      SECTION("same length: different ending")
      {
          vcf::Record record{1, "1", 1000, {"."}, "TCACCC", {"TGACGG"}, 0,
                             {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/1", "1/1"}, source};

          std::vector<vcf::Record> expected_normalization = {vcf::Record{1, "1", 1000, {"."}, "TCACCC", {"TGACGG"}, 0,
                                                                         {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/1", "1/1"}, source}};
          CHECK( (vcf::normalize(record)) == expected_normalization);
      }
      
      SECTION("same length: same ending") 
      {
          vcf::Record record{1, "1", 1000, {"."}, "TCACCC", {"TGACGC"}, 0, 
                             {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/1", "1/1"}, source};
          
          
          std::vector<vcf::Record> expected_normalization = {vcf::Record{1, "1", 1000, {"."}, "TCACC", {"TGACG"}, 0, 
                             {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/1", "1/1"}, source}};
          
          CHECK(vcf::normalize(record) == expected_normalization);
      }
      
      SECTION("Multiallelic") {
          vcf::Record record{1, "1", 10040, {"rs123"}, "TGACGTAACGATT", {"T", "TGACGTAACGGTT", "TGACGTAATAC"}, 0, 
                             {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/2", "1/2"}, source};

          std::vector<vcf::Record> expected_normalization = {
              vcf::Record{1, "1", 10040, {"rs123"}, "TGACGTAACGATT", {"T"}, 0,
                          {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/.", "1/."}, source},
              vcf::Record{1, "1", 10048, {"rs123"}, "ACGATT", {"ATAC"}, 0,
                          {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/.", "0/.", "./."}, source},
              vcf::Record{1, "1", 10050, {"rs123"}, "A", {"G"}, 0,
                          {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/.", "0/1", "./1"}, source}};
          
          CHECK(vcf::normalize(record) == expected_normalization);
      }
  }
}

