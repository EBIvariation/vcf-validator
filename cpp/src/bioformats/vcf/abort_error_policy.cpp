#include "validator.hpp"

namespace
{
  using namespace opencb::vcf;

  void throw_syntax_error(ParsingState const &)
  {
    throw ParsingError("invalid VCF syntax");
  }
  
  void throw_syntax_error(std::string const & msg)
  {
    throw ParsingError(msg);
  }
}

namespace opencb
{
  namespace vcf
  {

    void AbortErrorPolicy::handle_fileformat_section_error(ParsingState const & state, std::string message)
    {
        throw_syntax_error("Line " + std::to_string(state.n_lines) + ": " + message);
    }

    void AbortErrorPolicy::handle_meta_section_error(ParsingState const & state, std::string message)
    {
        throw_syntax_error("Line " + std::to_string(state.n_lines) + ": " + message);
    }

    void AbortErrorPolicy::handle_header_section_error(ParsingState const & state, std::string message)
    {
        throw_syntax_error("Line " + std::to_string(state.n_lines) + ": " + message);
    }

    void AbortErrorPolicy::handle_body_section_error(ParsingState const & state, std::string message)
    {
        throw_syntax_error("Line " + std::to_string(state.n_lines) + ": " + message);
    }

    
    void AbortErrorPolicy::handle_fileformat_section_warning(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void AbortErrorPolicy::handle_meta_section_warning(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void AbortErrorPolicy::handle_header_section_warning(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void AbortErrorPolicy::handle_body_section_warning(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

  }
}
