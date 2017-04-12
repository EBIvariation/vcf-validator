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

#include "vcf/validator.hpp"

namespace ebi
{
  namespace vcf
  {
    bool validate(const std::vector<char> &firstLine,
                           std::istream &input,
                           ebi::vcf::Parser &validator,
                           std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs);

    void write_errors(const Parser &validator, const std::vector<std::unique_ptr<ReportWriter>> &outputs);

    ParserImpl::ParserImpl(std::shared_ptr<Source> source)
            : ParsingState{source}
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

    std::unique_ptr<ebi::vcf::Parser> build_parser(std::string const &path,
                                                   ValidationLevel level,
                                                   ebi::vcf::Version version,
                                                   ebi::vcf::Ploidy ploidy)
    {
        std::shared_ptr<Source> source = std::make_shared<Source>(path, InputFormat::VCF_FILE_VCF, version, ploidy);
        auto records = std::vector<Record>{};

        switch (level) {
        case ValidationLevel::error:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::QuickValidator_v41(source));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::QuickValidator_v42(source));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::QuickValidator_v43(source));
            default:
                throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
            }

        case ValidationLevel::warning:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::FullValidator_v41(source));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::FullValidator_v42(source));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::FullValidator_v43(source));
            default:
                throw std::invalid_argument{"Please choose one of the accepted VCF fileformat versions"};
            }

        case ValidationLevel::stop:
            switch (version) {
            case ebi::vcf::Version::v41:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::Reader_v41(source));
            case ebi::vcf::Version::v42:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::Reader_v42(source));
            case ebi::vcf::Version::v43:
                return std::unique_ptr<ebi::vcf::Parser>(new ebi::vcf::Reader_v43(source));
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
                           Ploidy ploidy,
                           std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs)
    {
        std::vector<char> line;
        ebi::util::readline(input, line);
        ebi::vcf::Version version;
        try {
            version = detect_version(line);
        } catch (FileformatError * error) {
            for (auto &output : outputs) {
                output->write_error(*error);
            }
            return false;
        }
        std::unique_ptr<Parser> validator = build_parser(sourceName, validationLevel, version, ploidy);
        return validate(line, input, *validator, outputs);
    }

    Version detect_version(const std::vector<char> &line)
    {
        std::string common_substring{"##fileformat="};
        std::vector<char>::const_iterator lineIt;
        std::string::const_iterator commonIt;
        std::tie(commonIt, lineIt) = std::mismatch(common_substring.begin(), common_substring.end(), line.begin());
        if (commonIt != common_substring.end()) {
            throw new FileformatError{1, "The fileformat declaration is not valid (the line must start with "
                    + common_substring + " and the value must be one of 'VCFv4.1', 'VCFv4.2' or 'VCFv4.3')"};
        }

        std::string provided{lineIt, line.end()};
        util::remove_end_of_line(provided);

        if (std::string{"VCFv4.1"}.compare(provided) == 0) {
            return Version::v41;
        } else if (std::string{"VCFv4.2"}.compare(provided) == 0) {
            return Version::v42;
        } else if (std::string{"VCFv4.3"}.compare(provided) == 0) {
            return Version::v43;
        } else {
            throw new FileformatError{1, "The fileformat declaration is not valid "
                    "(the value must be one of 'VCFv4.1', 'VCFv4.2' or 'VCFv4.3')"};
        }
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
