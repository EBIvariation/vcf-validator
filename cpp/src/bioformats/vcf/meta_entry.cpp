#include "file_structure.hpp"

namespace opencb
{
  namespace vcf
  {
    
    MetaEntry::MetaEntry(std::string const & id, 
                         std::string const & plain_value)
    : id{id}, plain_value{plain_value}
    {
        
    }
        
    MetaEntry::MetaEntry(std::string const & id,
                         std::map<std::string, std::string> const & key_values)
    : id{id}, key_values{key_values}
    {
        
    }
    
  }
}