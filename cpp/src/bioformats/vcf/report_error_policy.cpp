#include "vcf_validator.hpp"

namespace opencb
{
  namespace vcf
  {

    void ReportErrorPolicy::handle_fileformat_section_error(ParsingState const & state)
    {
      std::cerr << "Line " << state.n_lines << ": Error in fileformat section" << std::endl;
    }

    void ReportErrorPolicy::handle_meta_section_error(ParsingState const & state)
    {
      std::cerr << "Line " << state.n_lines << ": Error in meta section" << std::endl;
    }

    void ReportErrorPolicy::handle_header_section_error(ParsingState const & state)
    {
      std::cerr << "Line " << state.n_lines << ": Error in header section" << std::endl;
    }

    void ReportErrorPolicy::handle_body_section_error(ParsingState const & state)
    {
      std::cerr << "Line " << state.n_lines << ": Error in body section" << std::endl;
    }

  }
}


