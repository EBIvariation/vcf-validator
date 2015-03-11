/* 
 * File:   record.hpp
 * Author: Cristina Yenyxe Gonzalez Garcia <cyenyxe@ebi.ac.uk>
 *
 * Created on 18 February 2015, 11:33
 */

#ifndef OPENCB_VCF_RECORD_HPP
#define	OPENCB_VCF_RECORD_HPP

#include <iostream>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/math/special_functions/binomial.hpp>
#include <boost/regex.hpp>

<<<<<<< HEAD
=======
namespace opencb
{
  namespace vcf
  {
    
    bool is_record_subfield_in_header(std::string const & field_value,
                                      std::multimap<std::string, MetaEntry>::iterator begin,
                                      std::multimap<std::string, MetaEntry>::iterator end);
    
  }
}
>>>>>>> 1ef3621... Some more refactoring and test fixing in VCF record checks
#endif	/* OPENCB_VCF_RECORD_HPP */

