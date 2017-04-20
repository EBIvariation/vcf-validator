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

#include <memory>
#include <fstream>

#include "catch/catch.hpp"

#include "vcf/validator.hpp"

namespace ebi
{

  TEST_CASE("Validate files with combined ploidy", "[ploidy]")
  {
      SECTION("File with 3 as default ploidy")
      {
          std::string path = "test/input_files/v4.1/ploidy/passed_ploidy_000.vcf";
          std::ifstream input{path};
          vcf::Ploidy ploidy{3};
          std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> outputs;

          CHECK(vcf::is_valid_vcf_file(input, path, vcf::ValidationLevel::warning, ploidy, outputs));
      }

      SECTION("File with 2 different ploidies")
      {
          std::string path = "test/input_files/v4.1/ploidy/passed_ploidy_001.vcf";
          std::ifstream input{path};
          vcf::Ploidy ploidy{2, {{"Y", 1}}};
          std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> outputs;

          CHECK(vcf::is_valid_vcf_file(input, path, vcf::ValidationLevel::warning, ploidy, outputs));
      }

      SECTION("File with several ploidies")
      {
          std::string path = "test/input_files/v4.1/ploidy/passed_ploidy_002.vcf";
          std::ifstream input{path};
          vcf::Ploidy ploidy{2, {{"Y", 1}, {"Triploid", 3}, {"Tetraploid", 4}}};
          std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> outputs;

          CHECK(vcf::is_valid_vcf_file(input, path, vcf::ValidationLevel::warning, ploidy, outputs));
      }
  }

}
