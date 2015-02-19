#include "validator.hpp"

namespace opencb
{
  namespace vcf
  {

    void ReportErrorPolicy::handle_fileformat_section_error(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void ReportErrorPolicy::handle_meta_section_error(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void ReportErrorPolicy::handle_header_section_error(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void ReportErrorPolicy::handle_body_section_error(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    
    void ReportErrorPolicy::handle_fileformat_section_warning(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void ReportErrorPolicy::handle_meta_section_warning(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void ReportErrorPolicy::handle_header_section_warning(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

    void ReportErrorPolicy::handle_body_section_warning(ParsingState const & state, std::string message)
    {
      std::cerr << "Line " << state.n_lines << ": " << message << std::endl;
    }

  }
}


