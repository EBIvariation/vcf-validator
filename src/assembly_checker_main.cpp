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

#include "bioio/bioio.hpp"
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
            (ebi::vcf::INPUT_OPTION, po::value<std::string>()->default_value(ebi::vcf::STDIN), "Path to the input VCF file, or stdin")
            (ebi::vcf::FASTA_OPTION, po::value<std::string>()->default_value(ebi::vcf::WARNING), "Path to the input FASTA file; please note that the index file must have the same name as the FASTA file and saved with a .idx extension")
            (ebi::vcf::OUTDIR_OPTION, po::value<std::string>()->default_value(""), "Directory for the output")
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

        return 0;
    }

    std::string get_output_path(const std::string &outdir, const std::string &file_path)
    {
        if (outdir == "") {
            return file_path;
        }

        boost::filesystem::path file_boost_path{file_path};
        boost::filesystem::path outdir_boost_path{outdir};
        if (not boost::filesystem::is_directory(outdir_boost_path)) {
            throw std::invalid_argument{"outdir should be a directory, not a file: " + outdir_boost_path.string()};
        }

        outdir_boost_path /= file_boost_path.filename();

        return outdir_boost_path.string();
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
        auto path = vm[ebi::vcf::INPUT].as<std::string>();
        auto outdir = get_output_path(vm[ebi::vcf::OUTDIR].as<std::string>(), path);

        if (path == ebi::vcf::STDIN) {
            BOOST_LOG_TRIVIAL(info) << "Reading from standard input...";
            // method call
        } else {
            BOOST_LOG_TRIVIAL(info) << "Reading from input VCF file...";
            std::ifstream input{path};
            // Read fasta and index file
            if (!input) {
                throw std::runtime_error{"Couldn't open file " + path};
            } else {
                // method call
            }
        }

    } catch (std::invalid_argument const & ex) {
        BOOST_LOG_TRIVIAL(error) << ex.what();
        return 1;
    } catch (std::exception const &ex) {
        BOOST_LOG_TRIVIAL(error) << ex.what();
        return 1;
    }
}
