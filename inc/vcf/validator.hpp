/**
 * Copyright 2014-2017 EMBL - European Bioinformatics Institute
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

#ifndef VCF_VALIDATOR_HPP
#define VCF_VALIDATOR_HPP

#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <set>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/iostreams/filter/bzip2.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filtering_stream.hpp>

#include "file_structure.hpp"
#include "error_policy.hpp"
#include "optional_policy.hpp"
#include "parse_policy.hpp"
#include "parsing_state.hpp"
#include "record_cache.hpp"
#include "util/string_utils.hpp"
#include "vcf/report_writer.hpp"


namespace ebi
{
  namespace vcf
  {

    size_t const default_line_buffer_size = 64 * 1024;
    enum class ValidationLevel { error, warning, stop };

    // Only check syntax
    struct QuickValidatorCfg
    {
      using ParsePolicy = IgnoreParsePolicy;
      using ErrorPolicy = ReportErrorPolicy;
      using OptionalPolicy = IgnoreOptionalPolicy;
    };

    // Check both syntax and semantics
    struct FullValidatorCfg
    {
      using ParsePolicy = StoreParsePolicy;
      using ErrorPolicy = ReportErrorPolicy;
      using OptionalPolicy = ValidateOptionalPolicy;
    };

    // Read the file for processing, assuming it is correct
    struct ReaderCfg
    {
      using ParsePolicy = StoreParsePolicy;
      using ErrorPolicy = AbortErrorPolicy;
      using OptionalPolicy = ValidateOptionalPolicy;
    };

    class Parser
    {
      public:
        virtual ~Parser() = default;

        virtual void parse(std::string const & text) = 0;
        virtual void parse(std::vector<char> const & text) = 0;

        virtual void end() = 0;

        virtual bool is_valid() const = 0;
        virtual const std::vector<std::unique_ptr<Error>> & errors() const = 0;
        virtual const std::vector<std::unique_ptr<Error>> & warnings() const = 0;
    };

    class ParserImpl
    : public Parser,
      public ParsingState
    {
      public:
        ParserImpl(std::shared_ptr<Source> source);
        virtual ~ParserImpl() = default;

        void parse(std::string const & text) override;
        void parse(std::vector<char> const & text) override;

        void end() override;

        bool is_valid() const override;
        const std::vector<std::unique_ptr<Error>> & errors() const override;
        const std::vector<std::unique_ptr<Error>> & warnings() const override;


      protected:
        virtual void parse_buffer(char const * p, char const * pe, char const * eof) = 0;

        /**
         * Previously seen records
         */
        RecordCache previous_records;
    };

    template <typename Configuration>
    class ParserImpl_v41
    : public ParserImpl,
      Configuration::ParsePolicy,
      Configuration::ErrorPolicy,
      Configuration::OptionalPolicy
    {
      public:
        using ParsePolicy = typename Configuration::ParsePolicy;
        using ErrorPolicy = typename Configuration::ErrorPolicy;
        using OptionalPolicy = typename Configuration::OptionalPolicy;

        ParserImpl_v41(std::shared_ptr<Source> source);

      private:
        void parse_buffer(char const * p, char const * pe, char const * eof);
    };

    template <typename Configuration>
    class ParserImpl_v42
    : public ParserImpl,
      Configuration::ParsePolicy,
      Configuration::ErrorPolicy,
      Configuration::OptionalPolicy
    {
      public:
        using ParsePolicy = typename Configuration::ParsePolicy;
        using ErrorPolicy = typename Configuration::ErrorPolicy;
        using OptionalPolicy = typename Configuration::OptionalPolicy;

        ParserImpl_v42(std::shared_ptr<Source> source);

      private:
        void parse_buffer(char const * p, char const * pe, char const * eof);
    };

    template <typename Configuration>
    class ParserImpl_v43
    : public ParserImpl,
      Configuration::ParsePolicy,
      Configuration::ErrorPolicy,
      Configuration::OptionalPolicy
    {
      public:
        using ParsePolicy = typename Configuration::ParsePolicy;
        using ErrorPolicy = typename Configuration::ErrorPolicy;
        using OptionalPolicy = typename Configuration::OptionalPolicy;

        ParserImpl_v43(std::shared_ptr<Source> source);

      private:
        void parse_buffer(char const * p, char const * pe, char const * eof);
    };

    // Predefined aliases for common uses of the parser
    using QuickValidator_v41 = ParserImpl_v41<QuickValidatorCfg>;
    using FullValidator_v41 = ParserImpl_v41<FullValidatorCfg>;
    using Reader_v41 = ParserImpl_v41<ReaderCfg>;

    using QuickValidator_v42 = ParserImpl_v42<QuickValidatorCfg>;
    using FullValidator_v42 = ParserImpl_v42<FullValidatorCfg>;
    using Reader_v42 = ParserImpl_v42<ReaderCfg>;

    using QuickValidator_v43 = ParserImpl_v43<QuickValidatorCfg>;
    using FullValidator_v43 = ParserImpl_v43<FullValidatorCfg>;
    using Reader_v43 = ParserImpl_v43<ReaderCfg>;

    bool is_valid_vcf_file(std::istream &input,
                           const std::string &sourceName,
                           ValidationLevel validationLevel,
                           std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs);

    bool process_vcf_stream(std::istream &input,
                          const std::string &sourceName,
                          ValidationLevel validationLevel,
                          std::vector<std::unique_ptr<ebi::vcf::ReportWriter>> &outputs);

    std::string get_compression_from_extension(std::string const & source);

    std::string get_compression_from_magic_num(const std::vector<char> &line);

    void create_uncompressed_stream(std::istream & input,
                                    const std::string & file_extension,
                                    boost::iostreams::filtering_istream & uncompressed_input);

  }
}

#include "validator_detail_v41.hpp"
#include "validator_detail_v42.hpp"
#include "validator_detail_v43.hpp"

#endif // VCF_VALIDATOR_HPP
