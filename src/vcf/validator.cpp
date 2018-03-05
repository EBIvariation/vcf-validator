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
                                         Version version);

    bool validate(const std::vector<char> &firstLine,
                  std::istream &input,
                  ebi::vcf::Parser &validator,
                  std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs,
                  const std::string & file_ext);

    void compressed_file_warning(std::string const & file_extension);

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

    std::unique_ptr<Parser> build_parser(std::string const & path, ValidationLevel level, Version version)
    {
        std::shared_ptr<Source> source = std::make_shared<Source>(path, InputFormat::VCF_FILE_VCF, version);
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
                           std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs)
    {
        std::vector<char> line;
        ebi::util::readline(input, line);
        ebi::vcf::Version version;
        std::string file_ext = ebi::vcf::is_compressed_file(sourceName, line);
        if (file_ext != NO_EXT) {
            if (file_ext != BZ2) {
                throw std::invalid_argument{"Input file should not be compressed"};
            }
        }
        try {
            uncompress(line, file_ext);
            version = detect_version(line);
        } catch (FileformatError * error) {
            for (auto &output : outputs) {
                output->write_error(*error);
            }
            return false;
        }
        std::unique_ptr<Parser> validator = build_parser(sourceName, validationLevel, version);
        return validate(line, input, *validator, outputs, file_ext);
    }

    std::string is_compressed_file(const std::string &source,
                            const std::vector<char> &line)
    {
        std::string file_extension = is_compressed_extension(source);
        if (source != ebi::vcf::STDIN && file_extension != NO_EXT) {
            return file_extension;
        }
        return is_compressed_magic_num(line);
    }

    std::string is_compressed_extension(std::string const & source)
    {
        boost::filesystem::path source_name(source);
        std::string file_extension = source_name.extension().string();

        if (file_extension == BZ2 || file_extension == RAR || file_extension == TAR || file_extension == TAR_GZ ||
            file_extension == TAR_XZ || file_extension == TAR_Z || file_extension == ZIP) {
            compressed_file_warning(file_extension);
            return file_extension;
        }
        return NO_EXT;
    }

    void compressed_file_warning(std::string const & file_extension)
    {
        BOOST_LOG_TRIVIAL(warning) << "detected " << file_extension
            << " compression";
    }

    std::string is_compressed_magic_num(const std::vector<char> &line)
    {
        std::vector<std::pair<std::vector<char>, std::string>> types = {
            { { 66, 90, 104 }, BZ2 },
            { { 31, -117 }, TAR_GZ },
            { { -3, 55, 122, 88, 90 }, TAR_XZ },
            { { 31, -99 }, TAR_Z },
            { { 80, 75, 3, 4 }, ZIP }
        };

        for (auto & type : types) {
            if (std::equal(type.first.begin(), type.first.end(), line.begin())) {
                compressed_file_warning(type.second);
                return type.second;
            }
        }
        return NO_EXT;
    }

    void uncompress(std::vector<char> & line, const std::string & file_ext) {
        if (file_ext == NO_EXT) {
            return;
        }
        std::string str(line.begin(), line.end());
        std::stringstream input(str);
        std::stringstream decompressed;
        boost::iostreams::filtering_istream in;
        if (file_ext == BZ2) {
            in.push(boost::iostreams::bzip2_decompressor());
            in.push(input);
            boost::iostreams::copy(in, decompressed);
            decompressed >> str;
            line.clear();
            std::copy(str.begin(),str.end(),std::back_inserter(line));
        }
        return;
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
            }
        }
        throw new FileformatError{1, "The fileformat declaration is not valid (the line must start with "
                    + common_substring + " and the value must be one of 'VCFv4.1', 'VCFv4.2' or 'VCFv4.3')"};
    }

    bool validate(const std::vector<char> &firstLine,
                  std::istream &input,
                  ebi::vcf::Parser &validator,
                  std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs,
                  const std::string &file_ext)
    {
        std::vector<char> line;
        line.reserve(default_line_buffer_size);

        validator.parse(firstLine);
        write_errors(validator, outputs);

        while (ebi::util::readline(input, line).size() != 0) {
            uncompress(line, file_ext);
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
