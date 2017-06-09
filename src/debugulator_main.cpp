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

#include <fstream>
#include <string>

#include <boost/program_options.hpp>

#include "vcf/odb_report.hpp"
#include "vcf/debugulator.hpp"

namespace
{
  namespace po = boost::program_options;

  enum class ValidationLevel
  {
      error, warning, stop
  };

  po::options_description build_command_line_options()
  {
      po::options_description description("Usage: vcf-debugulator [OPTIONS] [< input_file]\nAllowed options");

      description.add_options()
              ("help,h", "Display this help")
              ("input,i", po::value<std::string>()->default_value("stdin"), "Path to the input VCF file, or stdin")
              ("errors,e", po::value<std::string>(), "Path to the errors report from the input VCF file")
              ("level,l", po::value<std::string>()->default_value("warning"), "Validation level (error, warning, stop)")
              ("output,o", po::value<std::string>()->default_value("stdout"), "Write to a file or stdout")
      ;

      return description;
  }

  int check_command_line_options(po::variables_map const &vm, po::options_description const &desc)
  {
      if (vm.count("help")) {
          std::cout << desc << std::endl;
          return -1;
      }

      std::string level = vm["level"].as<std::string>();
      if (level != "error" && level != "warning" && level != "stop") {
          std::cout << desc << std::endl;
          std::cout << "Please choose one of the accepted validation levels" << std::endl;
          return 1;
      }

      if (!vm.count("errors")) {
          std::cout << desc << std::endl;
          std::cout << "Please specify the path to the errors report (--errors)" << std::endl;
          return 1;
      }

      return 0;
  }
}

int main(int argc, char **argv)
{
    namespace po = boost::program_options;

    po::options_description desc = build_command_line_options();
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    int check_options = check_command_line_options(vm, desc);
    if (check_options < 0) { return 0; }
    if (check_options > 0) { return check_options; }

    try {
        auto input_path = vm["input"].as<std::string>();
        auto level = vm["level"].as<std::string>();
        auto errors = vm["errors"].as<std::string>();
        auto output_path = vm["output"].as<std::string>();


        std::ifstream input_file;
        if (input_path != "stdin") {
            input_file.open(input_path.c_str());
            if (!input_file) {
                throw std::runtime_error{"Couldn't open file " + input_path};
            }
        } else {
            std::cerr << "Reading from standard input..." << std::endl;
        }

        std::ofstream output_file;
        if (output_path != "stdout") {
            output_file.open(output_path.c_str());
            if (!output_file) {
                throw std::runtime_error{"Couldn't open file " + output_path};
            }
        } else {
            std::cerr << "Writing to standard output..." << std::endl;
        }

        ebi::vcf::OdbReportRW errorDAO{errors};

        auto &input_stream = input_path == "stdin" ? std::cin : input_file;
        auto &output_stream = output_path == "stdout" ? std::cout : output_file;

        ebi::vcf::debugulator::fix_vcf_file(input_stream, errorDAO, output_stream);

        return 0;

    } catch (std::exception const &ex) {
        std::cerr << "Aborting execution, error: " << ex.what() << std::endl;
        return 1;
    }
}
