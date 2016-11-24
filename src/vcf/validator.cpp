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

        auto source_ptr = new ebi::vcf::Source{path, ebi::vcf::InputFormat::VCF_FILE_VCF, version, ploidy};
        std::shared_ptr<Source> source{source_ptr};
        auto records = std::vector<ebi::vcf::Record>{};

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
                           ebi::vcf::Parser &validator,
                           std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs)
    {

        std::vector<char> line;
        line.reserve(default_line_buffer_size);

        while (ebi::util::readline(input, line)) {
            validator.parse(line);

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

        if (not line.empty()) {
            validator.parse(line);
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

        validator.end();
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

        return validator.is_valid();
    }
  }
}
