#include "file_structure.hpp"

namespace opencb
{
  namespace vcf
  {
    
    Source::Source(std::string const & name,
                   unsigned const input_format,
                   std::string const & version,
                   std::vector<MetaEntry> const & meta_entries,
                   std::vector<std::string> const & samples_names) 
    : name{name},
      input_format{input_format},
      version{version},
      meta_entries{meta_entries},
      samples_names{samples_names}
    {
        
    }

  }
}
