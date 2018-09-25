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

#ifndef UTIL_CLI_UTILS_HPP
#define UTIL_CLI_UTILS_HPP

#include <string>
#include <vector>

#include <boost/program_options.hpp>

#include "util/logger.hpp"
#include "vcf/validator.hpp"

namespace ebi
{
  namespace util
  {
    namespace po = boost::program_options;

    po::variables_map build_variables_map(int argc, char** argv, const po::options_description & desc)
    {
        po::variables_map vm;
        po::parsed_options parsed = po::command_line_parser(argc, argv).options(desc).allow_unregistered().run();
        po::store(parsed,vm);
        std::vector<std::string> unrecognised_parameters = collect_unrecognized(parsed.options, po::include_positional);

        for (auto & parameter: unrecognised_parameters) {
            BOOST_LOG_TRIVIAL(warning) << "unused parameter: " << parameter;
        }

        po::notify(vm);
        return vm;
    }
  }
}

#endif // UTIL_CLI_UTILS_HPP
