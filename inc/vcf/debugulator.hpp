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

#ifndef VCF_VALIDATOR_DEBUGULATOR_HPP
#define VCF_VALIDATOR_DEBUGULATOR_HPP


#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

#include <boost/program_options.hpp>

#include "util/stream_utils.hpp"
#include "vcf/file_structure.hpp"
#include "vcf/fixer.hpp"
#include "vcf/validator.hpp"
#include "vcf/report_writer.hpp"
#include "vcf/sqlite_report.hpp"

namespace ebi
{
  namespace vcf
  {
    namespace debugulator
    {

      size_t const default_line_buffer_size = 64 * 1024;

      enum class ValidationLevel
      {
          error, warning, stop
      };

      boost::program_options::options_description build_command_line_options();
      int check_command_line_options(boost::program_options::variables_map const &vm,
                                     boost::program_options::options_description const &desc);
      ValidationLevel get_validation_level(std::string const &level_str);
      bool fix_vcf_file(std::istream &input,
                        ebi::vcf::SqliteReportRW &errorDAO,
                        std::ostream &output);
    }
  }
}

#endif //VCF_VALIDATOR_FIXER_HPP
