/**
 * Copyright 2014-2015 EMBL - European Bioinformatics Institute
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
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

#include <boost/program_options.hpp>

#include "vcf/file_structure.hpp"
#include "vcf/validator.hpp"
#include "vcf/output.hpp"

// TODO any reason why this namespace is indented 4 spaces?
namespace
{
    size_t const default_line_buffer_size = 64 * 1024;
    namespace po = boost::program_options;

    enum class ValidationLevel { error, warning, stop };


    po::options_description build_command_line_options()
    {
        po::options_description description("Usage: vcf-validator [OPTIONS] [< input_file]\nAllowed options");

        description.add_options()
            ("help,h", "Display this help")
            ("input,i", po::value<std::string>()->default_value("stdin"), "Path to the input VCF file, or stdin")
            ("level,l", po::value<std::string>()->default_value("warning"), "Validation level (error, warning, stop)")
            ("version,v", po::value<std::string>(), "VCF fileformat version to validate the file against (v4.1, v4.2, v4.3)")
            ("output,o", po::value<std::string>()->default_value("stdout"), "Comma separated values for type of output (sqlite, stdout, silent)")
        ;

        return description;
    }

    int check_command_line_options(po::variables_map const & vm, po::options_description const & desc)
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

        if (!vm.count("version")) {
            std::cout << desc << std::endl;
            std::cout << "Please choose one of the accepted VCF fileformat versions" << std::endl;
            return 1;
        }

        std::string version = vm["version"].as<std::string>();
        if (version != "v4.1" && version != "v4.2" && version != "v4.3") {
            std::cout << desc << std::endl;
            std::cout << "Please choose one of the accepted VCF fileformat versions" << std::endl;
            return 1;
        }

        return 0;
    }

    ValidationLevel get_validation_level(std::string const & level_str)
    {
        if (level_str == "error") {
            return ValidationLevel::error;
        } else if (level_str == "warning") {
            return ValidationLevel::warning;
        } else if (level_str == "stop") {
            return ValidationLevel::stop;
        }

        throw std::invalid_argument{"Please choose one of the accepted validation levels"};
    }

    ebi::vcf::Version get_version(std::string const & version_str)
    {
        if (version_str == "v4.1") {
            return ebi::vcf::Version::v41;
        } else if (version_str == "v4.2") {
            return ebi::vcf::Version::v42;
        } else if (version_str == "v4.3") {
            return ebi::vcf::Version::v43;
        }

        throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
    }

    std::vector<std::shared_ptr<ebi::vcf::ReportWriter>> get_outputs(std::string const &output_str, std::string const &input) {
        std::vector<std::string> outs;
        ebi::util::string_split(output_str, ",", outs);
        size_t initial_size = outs.size();

        // don't write several times to the same output
        std::sort(outs.begin(), outs.end());
        std::unique(outs.begin(), outs.end());
        if (initial_size != outs.size()) {
            // TODO if there are repeated outputs, throw? or just warn?
        }

        std::vector<std::shared_ptr<ebi::vcf::ReportWriter>> outputs;

        for (auto out : outs) {
            if (out == "sqlite") {
                outputs.push_back(std::make_shared<ebi::vcf::SqliteReportWriter>(input + ".errors.db"));
            } else if (out == "stdout") {
                outputs.push_back(std::make_shared<ebi::vcf::StdoutReportWriter>());
            } else {
                // TODO if there are unrecognized options, throw? or just warn
            }
        }

        return outputs;
    }

    std::unique_ptr<ebi::vcf::Parser> build_parser(std::string const & path, ValidationLevel level, ebi::vcf::Version version)
    {
        auto source = ebi::vcf::Source{path, ebi::vcf::InputFormat::VCF_FILE_VCF, version};
        auto records = std::vector<ebi::vcf::Record>{};

        switch (level) {
        case ValidationLevel::error:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::QuickValidator_v41(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::QuickValidator_v42(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::QuickValidator_v43(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            default:
                throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
            }

        case ValidationLevel::warning:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::FullValidator_v41(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::FullValidator_v42(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::FullValidator_v43(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            default:
                throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
            }

        case ValidationLevel::stop:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::Reader_v41(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::Reader_v42(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(
                        new ebi::vcf::Reader_v43(
                            std::make_shared<ebi::vcf::Source>(source),
                            std::make_shared<std::vector<ebi::vcf::Record>>(records)));
            default:
                throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
            }

        default:
            throw std::invalid_argument{"Please choose one of the accepted validation levels"};
        }
    }

    template <typename Container>
    std::istream & readline(std::istream & stream, Container & container)
    {
        char c;

        container.clear();

        do {
            stream.get(c);
            container.push_back(c);
        } while (!stream.eof() && c != '\n');

        return stream;
    }

    bool is_valid_vcf_file(std::istream &input,
                           ebi::vcf::Parser &validator,
                           std::vector<std::shared_ptr<ebi::vcf::ReportWriter>> outputs)
    {
        std::vector<char> line;
        line.reserve(default_line_buffer_size);

        while (readline(input, line)) {
            validator.parse(line);

            for (auto error : *validator.errors()) {
                for (auto output : outputs) {
                    output->write_error(*error);
                }
            }
            for (auto error : *validator.warnings()) {
                for (auto output : outputs) {
                    output->write_warning(*error);
                }
            }
        }

        validator.end();

        return validator.is_valid();
    }
}

int main(int argc, char** argv)
{
    po::options_description desc = build_command_line_options();
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    
    int check_options = check_command_line_options(vm, desc);
    if (check_options < 0) { return 0; }
    if (check_options > 0) { return check_options; }
    
    bool is_valid;

    try {
        auto path = vm["input"].as<std::string>();
        auto level = vm["level"].as<std::string>();
        auto version = vm["version"].as<std::string>();
        auto validator = build_parser(path, get_validation_level(level), get_version(version));
        auto outputs = get_outputs(vm["output"].as<std::string>(), path);

        if (path == "stdin") {
            std::cout << "Reading from standard input..." << std::endl;
            is_valid = is_valid_vcf_file(std::cin, *validator, outputs);
        } else {
            std::cout << "Reading from input file..." << std::endl;
            std::ifstream input{path};
            is_valid = is_valid_vcf_file(input, *validator, outputs);
        }

        std::cout << "The input file is " << (is_valid ? "valid" : "not valid") << std::endl;
        return !is_valid; // A valid file returns an exit code 0
        
    } catch (std::invalid_argument const & ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    } catch (std::runtime_error const & ex) {
        std::cout << "The input file is not valid: " << ex.what() << std::endl;
        return 1;
    }
}
