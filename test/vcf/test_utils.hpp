/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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

#ifndef EBI_TEST_UTILS_HPP
#define EBI_TEST_UTILS_HPP

#include <memory>
#include <vector>
#include <fstream>
#include <algorithm>

#include "vcf/file_structure.hpp"

namespace ebi
{
  // Note: This two structures are different from RecordCore used by the normalization. This is only for test purposes
  struct TestMultiRecord
  {
      size_t normalized_pos;
      std::string normalized_reference;
      std::vector <std::string> normalized_alternate;
  };
  struct TestRecord
  {
      size_t normalized_pos;
      std::string normalized_reference;
      std::string normalized_alternate;
  };

  inline vcf::Record build_mock_record(TestMultiRecord summary)
  {

//      std::shared_ptr<vcf::Source> source{std::make_shared<Source>(
      std::shared_ptr<vcf::Source> source{new vcf::Source{"filename.vcf",
                                                          vcf::VCF_FILE_VCF,
                                                          vcf::Version::v41,
                                                          vcf::Ploidy{2},
                                                          {},
                                                          {"NA001", "NA002", "NA003", "NA004"}}};

      source->meta_entries.emplace(vcf::FORMAT,
                                   vcf::MetaEntry{
                                           1,
                                           vcf::FORMAT,
                                           {
                                                   { vcf::ID, vcf::GT },
                                                   { vcf::NUMBER, "1" },
                                                   { vcf::TYPE, vcf::STRING },
                                                   { vcf::DESCRIPTION, "Genotype" }
                                           },
                                           source
                                   });

      return vcf::Record{1, "1", summary.normalized_pos, {vcf::DOT}, summary.normalized_reference, summary.normalized_alternate,
                         0, {vcf::DOT}, {{vcf::DOT, ""}}, {vcf::GT}, {"0/0", "0/1", "0/1", "1/1"}, source};
  }

  /** simple count for small tests, no need to optimize further */
  inline long count_lines(std::istream &input_stream)
  {
      return std::count(std::istreambuf_iterator<char>(input_stream),
                        std::istreambuf_iterator<char>(),
                        '\n');
  }

  inline long count_lines(std::string filename)
  {
      std::ifstream file{filename};
      return count_lines(file);
  }
}

#endif // EBI_TEST_UTILS_HPP
