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

#include <boost/filesystem/operations.hpp>
#include <boost/program_options.hpp>

#include "cmake_config.hpp"
#include "util/logger.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/string_constants.hpp"

namespace
{
  namespace po = boost::program_options;

  const std::string version_info = "vcf-assembly-checker version " + std::to_string(VERSION_MAJOR) + "."
                                     + std::to_string(VERSION_MINOR);

  po::options_description build_command_line_options()
  {
      po::options_description description(version_info + "\n\nUsage: vcf-assembly-checker [OPTIONS] [< input_file]\nAllowed options");

      description.add_options()
          (ebi::vcf::HELP_OPTION, "Display this help")
          (ebi::vcf::VERSION_OPTION, "Display version of the assembly-checker")
          (ebi::vcf::VCF_OPTION, po::value<std::string>(), "Path to the input VCF file")
          (ebi::vcf::FASTA_OPTION, po::value<std::string>(), "Path to the input FASTA file; please note that the index file must have the same name as the FASTA file and saved with a .idx extension")
      ;

      return description;
  }

  int check_command_line_options(po::variables_map const & vm, po::options_description const & desc)
  {
      if (vm.count(ebi::vcf::HELP)) {
          std::cout << desc << std::endl;
          return -1;
      }

      if (vm.count(ebi::vcf::VERSION)) {
          std::cout << version_info << std::endl;
          return -1;
      }

      if (!vm.count(ebi::vcf::VCF)) {
          std::cout << desc << std::endl;
          BOOST_LOG_TRIVIAL(error) << "Please specify the path to the VCF file (--vcf)";
          return 1;
      }

      if (!vm.count(ebi::vcf::FASTA)) {
          std::cout << desc << std::endl;
          BOOST_LOG_TRIVIAL(error) << "Please specify the path to the FASTA file (--fasta)";
          return 1;
      }

      return 0;
  }
}

int main(int argc, char** argv)
{
    ebi::util::init_boost_loggers();

    po::options_description desc = build_command_line_options();
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    int check_options = check_command_line_options(vm, desc);
    if (check_options < 0) { return 0; }
    if (check_options > 0) { return check_options; }

    try {
        auto vcf_path = vm[ebi::vcf::VCF].as<std::string>();
        auto fasta_path = vm[ebi::vcf::FASTA].as<std::string>();
        boost::filesystem::path fasta_boost_path{fasta_path};
        auto fasta_index_path = fasta_path + ".fai";
        auto problem_lines_path = vcf_path + "__" + fasta_boost_path.filename().string() + ".nonmatches";

        BOOST_LOG_TRIVIAL(info) << "Reading from input VCF file...";
        std::ifstream vcf_input{vcf_path};
        if (!vcf_input) {
            throw std::runtime_error{"Couldn't open VCF file " + vcf_path};
        }

        BOOST_LOG_TRIVIAL(info) << "Reading from input FASTA file...";
        std::ifstream fasta_input{fasta_path, std::ios::binary};
        if (!fasta_input) {
            throw std::runtime_error{"Couldn't open FASTA file " + fasta_path};
        }

        BOOST_LOG_TRIVIAL(info) << "Reading from input FASTA index file...";
        std::ifstream fasta_index_input{fasta_index_path, std::ios::binary};
        if (!fasta_index_input) {
            throw std::runtime_error{"Couldn't open FASTA index file " + fasta_index_path + ". Please use samtools "
                                     "faidx <fasta> to create the index file"};
        }

        std::ofstream problem_lines_output{problem_lines_path};
        if (!problem_lines_output) {
            throw std::runtime_error{"Couldn't open VCF problem lines file " + problem_lines_path};
        }

        if (!ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, problem_lines_output)) {
            BOOST_LOG_TRIVIAL(info) << "Problem lines written to: " << problem_lines_path;
        }

        return 0;

    } catch (std::exception const &ex) {
        BOOST_LOG_TRIVIAL(error) << "Aborting execution, error: " << ex.what();
        return 1;
    }
}
