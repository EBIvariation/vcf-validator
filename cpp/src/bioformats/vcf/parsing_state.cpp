#include "validator.hpp"

namespace opencb
{
  namespace vcf
  {

    ParsingState::ParsingState(std::shared_ptr<Source> source)
    : n_lines{1}, n_columns{1}, n_batches{0}, cs{0}, source{source}
    {
    }

    void ParsingState::set_version(std::string & version) const
    {
        source->version = version;
    }
    
    
    void ParsingState::add_meta(MetaEntry const & meta) const
    {
        source->meta_entries.push_back(meta);
    }
    
  }
}
