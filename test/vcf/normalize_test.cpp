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
  struct RecordTest
  {
      size_t normalized_pos;
      std::string normalized_reference;
      std::string normalized_alternate;
  };
  std::pair<std::vector<vcf::RecordCore>, std::vector<vcf::RecordCore>> testNormalization(
          size_t pos, std::string reference, std::vector<std::string> alternates, 
          std::vector<RecordTest> results)
  {
      try {

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
          
          vcf::Record record{1, "1", pos, {"."}, reference, alternates, 0,
                             {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/1", "1/1"}, source};

          std::vector<vcf::RecordCore> expected_normalization;
          for (auto result : results) {
              expected_normalization.push_back(
                  {1, "1", result.normalized_pos, result.normalized_reference, result.normalized_alternate});
          }
          
          return {vcf::normalize(record), expected_normalization};
          
      } catch (vcf::Error * e) {
          // Catch doesn't seem to understand an exception thrown by a pointer. workaround to see the message: rethrow by value
          throw *e;
      }
  }

  TEST_CASE("Record normalization", "[normalize]")
  {
      SECTION("same length: different ending")
      {
          auto result = testNormalization(1000, "TCACCC", {"TGACGG"}, {{1001, "CACCC", "GACGG"}});
          CHECK((result.first) == (result.second));
      }
      SECTION("same length: same ending")
      {
          auto result = testNormalization(1000, "TCACCC", {"TGACGC"}, {{1001, "CACC", "GACG"}});
          CHECK((result.first) == (result.second));
      }
      
      SECTION("insertions: trailing context, 1-base context, 1-base insertion")
      {
          auto result = testNormalization(1000, "A", {"AA"}, {{1000, "", "A"}});
          CHECK((result.first) == (result.second));
      }
      SECTION("insertions: leading context, 1-base context, 2-base insertion")
      {
          auto result = testNormalization(1000, "A", {"ATC"}, {{1001, "", "TC"}});
          CHECK((result.first) == (result.second));
      }
      SECTION("insertions: leading context, 2-base context, 1-base insertion")
      {
          auto result = testNormalization(1000, "AC", {"ACT"}, {{1002, "", "T"}});
          CHECK((result.first) == (result.second));
      }
      SECTION("insertions: leading and trailing context")
      {
          auto result = testNormalization(1000, "AC", {"ATC"}, {{1001, "", "T"}});
          CHECK((result.first) == (result.second));
      }
      SECTION("insertions: trailing context")
      {
          auto result = testNormalization(1000, "TC", {"ATC"}, {{1000, "", "A"}});
          CHECK((result.first) == (result.second));
      }
      SECTION("insertions: no context")
      {
          auto result = testNormalization(1000, "TAC", {"CGATT"}, {{1000, "TAC", "CGATT"}});
          CHECK((result.first) == (result.second));
      }
      
      SECTION("deletions: leading context, 1-base context, 1-base deletion")
      {
          auto result = testNormalization(1000, "AT", {"A"}, {{1001, "T", ""}});
          CHECK((result.first) == (result.second));
      }
      SECTION("deletions: leading context, 1-base context, 3-base deletion")
      {
          auto result = testNormalization(1000, "GATC", {"G"}, {{1001, "ATC", ""}});
          CHECK((result.first) == (result.second));
      }
      SECTION("deletions: leading context, 2-base context, 1-base deletion")
      {
          auto result = testNormalization(1000, "GAT", {"GA"}, {{1002, "T", ""}});
          CHECK((result.first) == (result.second));
      }
      SECTION("deletions: leading and trailing context")
      {
          auto result = testNormalization(1000, "ATC", {"AC"}, {{1001, "T", ""}});
          CHECK((result.first) == (result.second));
      }
      SECTION("deletions: trailing context, 1-base context, 1-base deletion")
      {
          auto result = testNormalization(1000, "AA", {"A"}, {{1000, "A", ""}});
          CHECK((result.first) == (result.second));
      }
      SECTION("deletions: trailing context, 1-base context, 2-base deletion")
      {
          auto result = testNormalization(1000, "ATC", {"GC"}, {{1000, "AT", "G"}});
          CHECK((result.first) == (result.second));
      }
      SECTION("deletions: no context")
      {
          auto result = testNormalization(1000, "CGATT", {"TAC"}, {{1000, "CGATT", "TAC"}});
          CHECK((result.first) == (result.second));
      }

      SECTION("Multiallelic splitting: same length")
      {
          auto result = testNormalization(10040, "T", {"A", "C"}, {{10040, "T", "A"}, {10040, "T", "C"}});
          CHECK((result.first) == (result.second));
      }
      SECTION("Multiallelic splitting: same length or deletion")
      {
          auto result = testNormalization(10040, "TGACGTAACGATT", {"T", "TGACGTAACGGTT", "TGACGTAATAC"}, {
              {10040, "TGACGTAACGAT", ""},
              {10050, "A", "G"},
              {10048, "CGATT", "TAC"}});
          CHECK((result.first) == (result.second));
      }
  }
}

