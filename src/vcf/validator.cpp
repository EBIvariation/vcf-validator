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

#include "vcf/validator.hpp"

namespace ebi
{
  namespace vcf
  {
    Version detect_version(const std::vector<char> &line);

    std::unique_ptr<Parser> build_parser(std::string const &path,
                                         ValidationLevel level,
                                         Version version,
                                         AdditionalChecks additionalChecks);

    bool validate(const std::vector<char> &firstLine,
                  std::istream &input,
                  ebi::vcf::Parser &validator,
                  std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs);

    void write_errors(const Parser &validator, const std::vector<std::unique_ptr<ReportWriter>> &outputs);

    ParserImpl::ParserImpl(std::shared_ptr<Source> source, AdditionalChecks additionalChecks)
            : ParsingState{source, additionalChecks}
    {

    }

    void ParserImpl::parse(std::vector<char> const & text)
    {
        char const * p = &text[0];
        char const * pe = &text[0] + text.size();
        char const * eof = nullptr;

        clear();
        parse_buffer(p, pe, eof);
    }

    void ParserImpl::parse(std::string const & text)
    {
        char const * p = text.data();
        char const * pe = text.data() + text.size();
        char const * eof = nullptr;

        clear();
        parse_buffer(p, pe, eof);
    }

    void ParserImpl::end()
    {
        char const * empty = "";
        clear();
        parse_buffer(empty, empty, empty);
    }

    bool ParserImpl::is_valid() const
    {
        return m_is_valid;
    }

    const std::vector<std::unique_ptr<Error>> & ParserImpl::errors() const
    {
        return ParsingState::errors;
    }

    const std::vector<std::unique_ptr<Error>> & ParserImpl::warnings() const
    {
        return ParsingState::warnings;
    }

    std::unique_ptr<Parser> build_parser(const std::string &path,
                                         ValidationLevel level,
                                         Version version,
                                         AdditionalChecks additionalChecks)
    {
        std::shared_ptr<Source> source = std::make_shared<Source>(path, InputFormat::VCF_FILE_VCF, version);
        auto records = std::vector<Record>{};

        switch (level) {
        case ValidationLevel::error:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::QuickValidator_v41(source, additionalChecks));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::QuickValidator_v42(source, additionalChecks));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::QuickValidator_v43(source, additionalChecks));
            case ebi::vcf::Version::v44:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::QuickValidator_v44(source, additionalChecks));
            default:
                throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
            }

        case ValidationLevel::warning:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::FullValidator_v41(source, additionalChecks));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::FullValidator_v42(source, additionalChecks));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::FullValidator_v43(source, additionalChecks));
            case ebi::vcf::Version::v44:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::FullValidator_v44(source, additionalChecks));
            default:
                throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
            }

        case ValidationLevel::stop:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::Reader_v41(source, additionalChecks));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::Reader_v42(source, additionalChecks));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::Reader_v43(source, additionalChecks));
            case ebi::vcf::Version::v44:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::Reader_v44(source, additionalChecks));
            default:
                throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
            }

        default:
            throw std::invalid_argument{"Please choose one of the accepted validation levels"};
        }
    }

    bool is_valid_vcf_file(std::istream &input,
                           const std::string &sourceName,
                           ValidationLevel validationLevel,
                           std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs,
                           AdditionalChecks additionalChecks) {
        std::vector<char> line;
        get_magic_num(input, line);
        std::string file_extension = get_compression(sourceName, line);
        check_readability_of_file(file_extension);

        if (file_extension == NO_EXT) {
            return process_vcf_stream(input, sourceName, validationLevel, outputs, additionalChecks);
        } else {
            boost::iostreams::filtering_istream uncompressed_input;
            create_uncompressed_stream(input, file_extension, uncompressed_input);
            return process_vcf_stream(uncompressed_input, sourceName, validationLevel, outputs, additionalChecks);
        }
    }

    bool process_vcf_stream(std::istream &input,
                            const std::string &sourceName,
                            ValidationLevel validationLevel,
                            std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs,
                            AdditionalChecks additionalChecks)
    {
        std::vector<char> firstline;
        ebi::util::readline(input, firstline);
        check_readability_of_stream(firstline);

        ebi::vcf::Version version;
        try {
            version = detect_version(firstline);
        } catch (FileformatError * error) {
            for (auto &output : outputs) {
                output->write_error(*error);
            }
            return false;
        }
        std::unique_ptr<Parser> validator = build_parser(sourceName, validationLevel, version, additionalChecks);
        return validate(firstline, input, *validator, outputs);
    }

    Version detect_version(const std::vector<char> &vector_line)
    {
        std::string common_substring{"##fileformat="};
        std::string line{vector_line.begin(), vector_line.end()};

        if (line.substr(0, common_substring.size()) == common_substring) {
            std::string provided_version{line.substr(common_substring.size())};
            util::remove_end_of_line(provided_version);

            if (provided_version == VCF_V41) {
                return Version::v41;
            } else if (provided_version == VCF_V42) {
                return Version::v42;
            } else if (provided_version == VCF_V43) {
                return Version::v43;
            } else if (provided_version == VCF_V44) {
                return Version::v44;
            }
        }
        throw new FileformatError{1, "The fileformat declaration is not valid (the line must start with "
                    + common_substring + " and the value must be one of 'VCFv4.1', 'VCFv4.2', 'VCFv4.3' or 'VCFv4.4')"};
    }

    bool validate(const std::vector<char> &firstLine,
                  std::istream &input,
                  ebi::vcf::Parser &validator,
                  std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs)
    {
        std::vector<char> line;
        line.reserve(default_line_buffer_size);

        validator.parse(firstLine);
        write_errors(validator, outputs);

        while (ebi::util::readline(input, line).size() != 0) {
            validator.parse(line);
            write_errors(validator, outputs);
        }

        validator.end();
        write_errors(validator, outputs);

        return validator.is_valid();
    }

    void write_errors(const Parser &validator, const std::vector<std::unique_ptr<ReportWriter>> &outputs)
    {
        for (auto &error : validator.errors()) {
            for (auto &output : outputs) {
                output->write_error(*error);
            }
        }
        for (auto &error : validator.warnings()) {
            for (auto &output : outputs) {
                output->write_warning(*error);
            }
        }
    }
  }
}
