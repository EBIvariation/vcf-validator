/* 
 * File:   meta_entry.hpp
 * Author: Cristina Yenyxe Gonzalez Garcia <cyenyxe@ebi.ac.uk>
 *
 * Created on 20 January 2015, 15:11
 */

#ifndef META_ENTRY_HPP
#define	META_ENTRY_HPP

#include <map>
#include <string>

#include <boost/variant/static_visitor.hpp>

#include "file_structure.hpp"

namespace opencb
{
  namespace vcf 
  {
        class MetaEntryVisitor : public boost::static_visitor<>
        {
            MetaEntry entry;
            
        public:
            MetaEntryVisitor(MetaEntry const & entry);
           
            void operator()(std::string & value) const;
            void operator()(std::map<std::string, std::string> & value) const;

        private:
            
            void check_alt(std::map<std::string, std::string> & value) const;
            void check_contig(std::map<std::string, std::string> & value) const;
            void check_filter(std::map<std::string, std::string> & value) const;
            void check_format(std::map<std::string, std::string> & value) const;
            void check_info(std::map<std::string, std::string> & value) const;
            void check_sample(std::map<std::string, std::string> & value) const;
        };
       
  }
}

#endif	/* META_ENTRY_HPP */

