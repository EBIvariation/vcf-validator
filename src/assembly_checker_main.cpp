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
#include <boost/log/trivial.hpp>

#include "cmake_config.hpp"
#include "util/logger.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/string_constants.hpp"
#include "vcf/assembly_report_writer.hpp"

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
          (ebi::vcf::INPUT_OPTION, po::value<std::string>(), "Path to the input VCF file")
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

      if (!vm.count(ebi::vcf::INPUT)) {
          std::cout << desc << std::endl;
          BOOST_LOG_TRIVIAL(error) << "Please specify the path to the VCF file ("<<ebi::vcf::INPUT_OPTION<<")";
          return 1;
      }

      if (!vm.count(ebi::vcf::FASTA)) {
          std::cout << desc << std::endl;
          BOOST_LOG_TRIVIAL(error) << "Please specify the path to the FASTA file ("<<ebi::vcf::FASTA_OPTION<<")";
          return 1;
      }

      return 0;
  }

  std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> get_outputs(std::string const &output_str) 
  {
      std::vector<std::unique_ptr<ebi::vcf::AssemblyReportWriter>> outputs;
      if (output_str.compare(std::string(ebi::vcf::STDOUT)) == 0) {
          outputs.emplace_back(new ebi::vcf::StdoutAssemblyReportWriter());
      } else {
          throw std::invalid_argument{"Please use only valid report types"};
      }

      return outputs;
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
    auto vcf_path = vm[ebi::vcf::INPUT].as<std::string>();
    auto fasta_path = vm[ebi::vcf::FASTA].as<std::string>();
    boost::filesystem::path fasta_boost_path{fasta_path};
    auto fasta_index_path = fasta_path + ".fai";
    auto outputs = get_outputs(std::string(ebi::vcf::STDOUT));
    ebi::vcf::assembly_checker::MatchStats match_stats;

    try {

        std::string file_error_msg;

        std::ifstream vcf_input{vcf_path};
        file_error_msg = "Couldn't open VCF file " + vcf_path;
        ebi::vcf::assembly_checker::check_file_validity(vcf_input, file_error_msg);

        std::ifstream fasta_input{fasta_path, std::ios::binary};
        file_error_msg = "Couldn't open FASTA file " + fasta_path;
        ebi::vcf::assembly_checker::check_file_validity(fasta_input, file_error_msg);

        std::ifstream fasta_index_input{fasta_index_path, std::ios::binary};
        file_error_msg = "Couldn't open FASTA index file " + fasta_index_path + ". Please use samtools "
                         "faidx <fasta> to create the index file";
        ebi::vcf::assembly_checker::check_file_validity(fasta_index_input, file_error_msg);

        if (!ebi::vcf::assembly_checker::check_vcf_ref(vcf_input, fasta_input, fasta_index_input, match_stats)) {
            BOOST_LOG_TRIVIAL(info) << "VCF and reference FASTA are not matching";
        }

    } catch (std::invalid_argument const & ex) {
        BOOST_LOG_TRIVIAL(error) << "Invalid VCF and FASTA combination: " << ex.what();
        return 1;
    } catch (std::runtime_error const & ex) {
        BOOST_LOG_TRIVIAL(error) << "Input file is missing from path: " << ex.what();
        return 1;
    } catch (std::exception const &ex) {
        BOOST_LOG_TRIVIAL(error) << "Aborting execution, error: " << ex.what();
        return 1;
    }

    for (auto &output : outputs) {
        output->write_number_matches(match_stats);
        output->write_percentage(match_stats);
    }

    return 0;
}
