#ifndef OPENCB_VCF_VALIDATOR_HPP
#define OPENCB_VCF_VALIDATOR_HPP

#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <set>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "file_structure.hpp"

namespace opencb
{
  namespace vcf
  {
    
    struct ParsingState
    {
        size_t n_lines;
        size_t n_columns;
        size_t n_batches;

        int cs;
        bool m_is_valid;
        
        std::shared_ptr<Source> source;
        std::shared_ptr<std::vector<Record>> records;
     
        std::set<std::string> bad_defined_contigs;
        
        ParsingState(std::shared_ptr<Source> source,
                     std::shared_ptr<std::vector<Record>> records);
        
        void set_version(std::string & fileformat) const;
        
        void add_meta(MetaEntry const & meta) const;
        
        void add_record(Record const & record) const;
        
        void clear_records() const;
        
        std::vector<std::string> const & samples() const;
        
        void set_samples(std::vector<std::string> & samples) const;
        
        void add_bad_defined_contig(std::string const & contig);
    };

    class ParsingError : public std::runtime_error
    {
        using runtime_error::runtime_error;
    };

    class ParsingWarning : public std::runtime_error
    {
        using runtime_error::runtime_error;
    };

    class IgnoreParsePolicy
    {
      public:
        void handle_token_begin(ParsingState const & state) {}
        void handle_token_char(ParsingState const & state, char c) {}
        void handle_token_end(ParsingState const & state) {}
        void handle_newline(ParsingState const & state) {}
        
        void handle_fileformat(ParsingState const & state) {}
        
        void handle_meta_typeid(ParsingState const & state) {}
        void handle_meta_typeid(ParsingState const & state, std::string type_id) {}
        void handle_meta_key(ParsingState const & state) {}
        void handle_meta_key(ParsingState const & state, std::string key) {}
        void handle_meta_value(ParsingState const & state) {}
        void handle_meta_line(ParsingState const & state) {}
        
        void handle_sample_name(ParsingState const & state);
        void handle_header_line(ParsingState const & state);
        
        void handle_column_end(ParsingState const & state, size_t n_columns);
        void handle_body_line(ParsingState & state) {}
        
        std::string current_token() const { return ""; }
        
        std::vector<std::string> column_tokens(std::string const & column) const { return {}; }
    };

    class StoreParsePolicy
    {
      public:
        void handle_token_begin(ParsingState const & state);
        void handle_token_char(ParsingState const & state, char c);
        void handle_token_end(ParsingState const & state);
        void handle_newline(ParsingState const & state) ;
        
        void handle_fileformat(ParsingState const & state);
        
        void handle_meta_typeid(ParsingState const & state);
        void handle_meta_typeid(ParsingState const & state, std::string type_id);
        void handle_meta_key(ParsingState const & state);
        void handle_meta_key(ParsingState const & state, std::string key);
        void handle_meta_value(ParsingState const & state);
        void handle_meta_line(ParsingState const & state);
        
        
        void handle_sample_name(ParsingState const & state);
        void handle_header_line(ParsingState const & state);
        
        void handle_column_end(ParsingState const & state, size_t n_columns);
        void handle_body_line(ParsingState const & state);
        
        std::string current_token() const;
        
        std::vector<std::string> column_tokens(std::string const & column) const;

      private:
        /**
         * Token being currently parsed
         */
        std::string m_current_token;
        
        /**
         * Token that acts as type ID for the whole line, like ALT/FILTER in meta entries
         */
        std::string m_line_typeid;
        
        /**
         * Tokens that must be grouped, like all key-value pairs in the INFO column
         */
        std::vector<std::string> m_grouped_tokens;
        
        /**
         * Tokens read in a line and grouped by an ID
         */
        std::map<std::string, std::vector<std::string>> m_line_tokens;
    };

    class AbortErrorPolicy
    {
      public:
        void handle_fileformat_section_error(ParsingState const & state, 
                std::string message = "Error in file format section");
        
        void handle_meta_section_error(ParsingState const & state, 
                std::string message = "Error in meta-data section");
        
        void handle_header_section_error(ParsingState const & state, 
                std::string message = "Error in header section");
        
        void handle_body_section_error(ParsingState const & state, 
                std::string message = "Error in body section");
        
        
        void handle_fileformat_section_warning(ParsingState const & state, 
                std::string message = "Warning in file format section");
        
        void handle_meta_section_warning(ParsingState const & state, 
                std::string message = "Warning in meta-data section");
        
        void handle_header_section_warning(ParsingState const & state, 
                std::string message = "Warning in header section");
        
        void handle_body_section_warning(ParsingState const & state, 
                std::string message = "Warning in body section");
    };

    class ReportErrorPolicy
    {
      public:
        void handle_fileformat_section_error(ParsingState const & state, 
                std::string message = "Error in file format section");
        
        void handle_meta_section_error(ParsingState const & state, 
                std::string message = "Error in meta-data section");
        
        void handle_header_section_error(ParsingState const & state, 
                std::string message = "Error in header section");
        
        void handle_body_section_error(ParsingState const & state, 
                std::string message = "Error in body section");
        
        
        void handle_fileformat_section_warning(ParsingState const & state, 
                std::string message = "Warning in file format section");
        
        void handle_meta_section_warning(ParsingState const & state, 
                std::string message = "Warning in fmeta-data section");
        
        void handle_header_section_warning(ParsingState const & state, 
                std::string message = "Warning in header section");
        
        void handle_body_section_warning(ParsingState const & state, 
                std::string message = "Warning in body section");
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

        Parser(std::shared_ptr<Source> const & source,
               std::shared_ptr<std::vector<Record>> const & records);

        void parse(std::string const & text);
        void parse(std::vector<char> const & text);

        void end();

        bool is_valid() const;
        
      private:
        void parse_buffer(char const * p, char const * pe, char const * eof);
        
        void optional_check_meta_section() const;
        
        void optional_check_body_entry() ;//const;
        
        void optional_check_body_section() const;
    };

    // Predefined aliases for common uses of the parser
    using QuickValidator = Parser<QuickValidatorCfg>;
    using FullValidator = Parser<FullValidatorCfg>;
    using Reader = Parser<ReaderCfg>;
  }
}

#include "validator_detail.hpp"

#endif
