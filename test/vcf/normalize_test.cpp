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
  struct TestMultiRecord
  {
      size_t normalized_pos;
      std::string normalized_reference;
      std::vector<std::string> normalized_alternate;
  };
  struct TestRecord
  {
      size_t normalized_pos;
      std::string normalized_reference;
      std::string normalized_alternate;
  };
  
//  std::pair<std::vector<vcf::RecordCore>, std::vector<vcf::RecordCore>> test_normalization(
//      size_t pos, std::string reference, std::vector<std::string> alternates,
//      std::vector<TestRecord> results)
//  {
//      return test_normalization({pos, reference, alternates}, results);
//  }
  std::pair<std::vector<vcf::RecordCore>, std::vector<vcf::RecordCore>> test_normalization(
      std::function<std::vector<vcf::RecordCore> (const vcf::Record &record)> normalize_function,
      TestMultiRecord orig, std::vector<TestRecord> results)
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
          
          vcf::Record record{1, "1", orig.normalized_pos, {"."}, orig.normalized_reference, orig.normalized_alternate, 
                             0, {"."}, {{".", ""}}, {"GT"}, {"0/0", "0/1", "0/1", "1/1"}, source};

          std::vector<vcf::RecordCore> expected_normalization;
          for (auto result : results) {
              expected_normalization.push_back(
                  {1, "1", result.normalized_pos, result.normalized_reference, result.normalized_alternate});
          }
          
          return {normalize_function(record), expected_normalization};
          
      } catch (vcf::Error * e) {
          // Catch doesn't seem to understand an exception thrown by a pointer. workaround to see the message: rethrow by value
          throw *e;
      }
  }

  TEST_CASE("Record normalization", "[normalize]")
  {
      SECTION("same length: different ending")
      {
          TestMultiRecord origin{1000, "TCACCC", {"TGACGG"}};
          std::vector<TestRecord> result{{1001, "CACCC", "GACGG"}};
          
          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("same length: same ending")
      {
          TestMultiRecord origin{1000, "TCACCC", {"TGACGC"}};
          std::vector<TestRecord> result{{1001, "CACC", "GACG"}};
          
          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      
      
      SECTION("insertions: trailing context, 1-base context ambiguous, 1-base insertion")
      {
          TestMultiRecord origin{1000, "A", {"AA"}};
          
          auto comparison = test_normalization(vcf::normalize, origin, {{1000, "", "A"}});
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, {{1001, "", "A"}});
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("insertions: trailing context, 1-base context at left, 1-base insertion")
      {
          TestMultiRecord origin{1000, "T", {"TA"}};
          std::vector<TestRecord> result{{1001, "", "A"}};
          
          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("insertions: leading context, 1-base context at right, 2-base insertion")
      {
          TestMultiRecord origin{1000, "T", {"AT"}};
          std::vector<TestRecord> result{{1000, "", "A"}};
          
          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("insertions: leading context, 1-base context, 2-base insertion")
      {
          TestMultiRecord origin{1000, "A", {"ATC"}};
          std::vector<TestRecord> result{{1001, "", "TC"}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("insertions: leading context, 2-base context, 1-base insertion")
      {
          TestMultiRecord origin{1000, "AC", {"ACT"}};
          std::vector<TestRecord> result{{1002, "", "T"}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("insertions: leading and trailing context")
      {
          TestMultiRecord origin{1000, "AC", {"ATC"}};
          std::vector<TestRecord> result{{1001, "", "T"}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("insertions: trailing context")
      {
          TestMultiRecord origin{1000, "TC", {"ATC"}};
          std::vector<TestRecord> result{{1000, "", "A"}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("insertions: no context")
      {
          TestMultiRecord origin{1000, "TAC", {"CGATT"}};
          std::vector<TestRecord> result{{1000, "TAC", "CGATT"}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      
      SECTION("deletions: leading context, 1-base context, 1-base deletion")
      {
          TestMultiRecord origin{1000, "AT", {"A"}};
          std::vector<TestRecord> result{{1001, "T", ""}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("deletions: leading context, 1-base context, 3-base deletion")
      {
          TestMultiRecord origin{1000, "GATC", {"G"}};
          std::vector<TestRecord> result{{1001, "ATC", ""}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("deletions: leading context, 2-base context, 1-base deletion")
      {
          TestMultiRecord origin{1000, "GAT", {"GA"}};
          std::vector<TestRecord> result{{1002, "T", ""}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("deletions: leading and trailing context")
      {
          TestMultiRecord origin{1000, "ATC", {"AC"}};
          std::vector<TestRecord> result{{1001, "T", ""}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("deletions: trailing context, 1-base context, 1-base deletion")
      {
          TestMultiRecord origin{1000, "AA", {"A"}};

          auto comparison = test_normalization(vcf::normalize, origin, {{1000, "A", ""}});
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, {{1001, "A", ""}});
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("deletions: trailing context, 1-base context, 2-base deletion")
      {
          TestMultiRecord origin{1000, "ATC", {"GC"}};
          std::vector<TestRecord> result{{1000, "AT", "G"}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("deletions: no context")
      {
          TestMultiRecord origin{1000, "CGATT", {"TAC"}};
          std::vector<TestRecord> result{{1000, "CGATT", "TAC"}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }

      SECTION("Multiallelic splitting: same length")
      {
          TestMultiRecord origin{10040, "T", {"A", "C"}};
          std::vector<TestRecord> result{{10040, "T", "A"},
                                         {10040, "T", "C"}};

          auto comparison = test_normalization(vcf::normalize, origin, result);
          CHECK((comparison.first) == (comparison.second));
          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, result);
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
      SECTION("Multiallelic splitting: same length or deletion")
      {
          TestMultiRecord origin{10040, "TGACGTAACGATT", {"T", "TGACGTAACGGTT", "TGACGTAATAC"}};
          std::vector<TestRecord> result;

          auto comparison = test_normalization(vcf::normalize, origin, {
                  {10040, "TGACGTAACGAT", ""},
                  {10050, "A",            "G"},
                  {10048, "CGATT",        "TAC"}});
          CHECK((comparison.first) == (comparison.second));

          auto comparison_pad_at_left = test_normalization(vcf::normalize_pad_at_left, origin, {
                  {10041, "GACGTAACGATT", ""},
                  {10050, "A",            "G"},
                  {10048, "CGATT",        "TAC"}});
          CHECK((comparison_pad_at_left.first) == (comparison_pad_at_left.second));
      }
       
  }
}

