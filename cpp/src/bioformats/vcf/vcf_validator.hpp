#ifndef OPENCB_VCF_VALIDATOR_H
#define OPENCB_VCF_VALIDATOR_H

#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace opencb
{
  namespace vcf
  {
    struct ParsingState
    {
      ParsingState();

      size_t n_lines;
      size_t n_columns;
      size_t n_batches;

      int cs;
      bool m_is_valid;
    };

    class ParsingError : public std::runtime_error
    {
      using runtime_error::runtime_error;
    };

    class IgnoreParsePolicy
    {
      public:
        void handle_token_begin(ParsingState const & state) {}
        void handle_token_char(ParsingState const & state, char c) {}
    };

    class StoreParsePolicy
    {
      public:
        void handle_token_begin(ParsingState const & state)
        {
          m_current_token = std::string();
        }

        void handle_token_char(ParsingState const & state, char c)
        {
//          m_current_token.push_back(c);
        }

      private:
        std::string m_current_token;
    };

    class AbortErrorPolicy
    {
      public:
        void handle_fileformat_section_error(ParsingState const & state, 
                std::string message = "Error in file format section");
        
        void handle_meta_section_error(ParsingState const & state, 
                std::string message = "Error in meta section");
        
        void handle_header_section_error(ParsingState const & state, 
                std::string message = "Error in header section");
        
        void handle_body_section_error(ParsingState const & state, 
                std::string message = "Error in body section");
    };

    class ReportErrorPolicy
    {
      public:
        void handle_fileformat_section_error(ParsingState const & state, 
                std::string message = "Error in file format section");
        
        void handle_meta_section_error(ParsingState const & state, 
                std::string message = "Error in meta section");
        
        void handle_header_section_error(ParsingState const & state, 
                std::string message = "Error in header section");
        
        void handle_body_section_error(ParsingState const & state, 
                std::string message = "Error in body section");
    };

    // Only check syntax
    struct QuickValidatorCfg
    {
      using ParsePolicy = IgnoreParsePolicy;
      using ErrorPolicy = ReportErrorPolicy;
    };

    // Check both syntax and semantics
    struct FullValidatorCfg
    {
      using ParsePolicy = StoreParsePolicy;
      using ErrorPolicy = ReportErrorPolicy;
    };

    // Read the file for processing, assuming it is correct
    struct ReaderCfg
    {
      using ParsePolicy = StoreParsePolicy;
      using ErrorPolicy = AbortErrorPolicy;
    };

    template <typename Configuration>
    class Parser
    : ParsingState,
      Configuration::ParsePolicy,
      Configuration::ErrorPolicy
    {
      public:
        using ParsePolicy = typename Configuration::ParsePolicy;
        using ErrorPolicy = typename Configuration::ErrorPolicy;

        Parser();

        void parse(std::string const & text);
        void parse(std::vector<char> const & text);

        void end();

        bool is_valid() const;

      private:
        void parse_buffer(char const * p, char const * pe, char const * eof);
    };

    // Predefined aliases for common uses of the parser
    using QuickValidator = Parser<QuickValidatorCfg>;
    using FullValidator = Parser<FullValidatorCfg>;
    using Reader = Parser<ReaderCfg>;
  }
}

#include "vcf_validator_detail.hpp"

#endif
