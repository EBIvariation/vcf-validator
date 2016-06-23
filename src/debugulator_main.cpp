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

#include "vcf/debugulator.hpp"

int main(int argc, char **argv)
{
    namespace po = boost::program_options;

    po::options_description desc = ebi::vcf::debugulator::build_command_line_options();
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    int check_options = ebi::vcf::debugulator::check_command_line_options(vm, desc);
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
        }

        std::ofstream output_file;
        if (output_path != "stdout") {
            output_file.open(output_path.c_str());
            if (!output_file) {
                throw std::runtime_error{"Couldn't open file " + output_path};
            }
        }

        ebi::vcf::SqliteReportRW errorDAO{errors};

        auto &input_stream = input_path == "stdin" ? std::cin : input_file;
        auto &output_stream = output_path == "stdout" ? std::cout : output_file;

        ebi::vcf::debugulator::fix_vcf_file(input_stream, errorDAO, output_stream);

        return 0;

    } catch (std::invalid_argument const &ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}
