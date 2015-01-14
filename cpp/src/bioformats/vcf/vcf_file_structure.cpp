/* 
 * File:   vcf_file_structure.cpp
 * Author: Cristina Yenyxe Gonzalez Garcia <cyenyxe@ebi.ac.uk>
 * 
 * Created on 19 November 2014, 10:12
 */
#include "vcf_file_structure.hpp"

namespace opencb
{
  namespace vcf
  {
    
    VcfMetaEntry::VcfMetaEntry(std::string const & id, 
                         std::string const & plain_value)
    : id{id}, plain_value{plain_value}
    {
        
    }
        
    VcfMetaEntry::VcfMetaEntry(std::string const & id,
                         std::map<std::string, std::string> const & key_values)
    : id{id}, key_values{key_values}
    {
        
    }
   
    
    VcfSource::VcfSource(std::string const & name,
                         char const mode,
                         unsigned const input_format,
                         std::string const & version = "v4.1",
                         std::vector<VcfMetaEntry> const & meta_entries = {},
                         std::vector<std::string> const & samples_names = {}) 
    : name{name},
      mode{mode},
      input_format{input_format},
      version{version},
      meta_entries{meta_entries},
      samples_names{samples_names}
    {
        
    }


    VcfRecord::VcfRecord(std::string const & chromosome, 
                         size_t const position, 
                         std::vector<std::string> const & ids, 
                         std::string const & reference_allele, 
                         std::vector<std::string> const & alternate_alleles, 
                         float const quality, 
                         std::vector<std::string> const & filters, 
                         std::string const & info, 
                         std::string const & format, 
                         std::vector<std::string> const & samples,
                         std::shared_ptr<VcfSource> const & source) 
    : chromosome{chromosome}, 
        position{position}, 
        ids{ids}, 
        reference_allele{reference_allele}, 
        alternate_alleles{alternate_alleles}, 
        quality{quality}, 
        filters{filters}, 
        info{info}, 
        format{format}, 
        samples{samples},
        source{source}
    {
        check_chromosome();
        check_ids();
        check_alternate_alleles();
        check_quality();
        check_format();
    }

    bool VcfRecord::operator==(VcfRecord const & other) 
    {
        return chromosome == other.chromosome &&
                position == other.position &&
                ids == other.ids &&
                reference_allele == other.reference_allele &&
                alternate_alleles == other.alternate_alleles &&
                quality == other.quality &&
                filters == other.filters &&
                info == other.info &&
                format == other.format &&
                samples == other.samples;
    }

    bool VcfRecord::operator!=(VcfRecord const & other) 
    {
        return !(*this == other);
    }

    void VcfRecord::check_chromosome() 
    {
        if (chromosome.find(':') != std::string::npos) {
            throw std::invalid_argument("Chromosome must not contain colons");
        }
        if (chromosome.find(' ') != std::string::npos) {
            throw std::invalid_argument("Chromosome must not contain white-spaces");
        }
    }

    void VcfRecord::check_ids() 
    {
        for (auto & id : ids) {
            if (find_if(id.begin(), id.end(), [](char c) { return !isalnum(c); }) == id.end()) {
                throw std::invalid_argument("ID must be alphanumeric");
            }
        }
    }

    void VcfRecord::check_alternate_alleles() 
    {
        for (auto & alternate : alternate_alleles) {
            if (alternate[0] != reference_allele[0] && alternate.size() == reference_allele.size()) {
                throw std::invalid_argument("Reference and alternate alleles must share the first nucleotide");
            } else if (alternate == reference_allele) {
                throw std::invalid_argument("Reference and alternate alleles must not be the same");
            }
        }
    }

    void VcfRecord::check_quality() 
    {
        if (quality < 0) {
            throw std::invalid_argument("Quality must be equal or greater than zero");
        }
    }
    
    void VcfRecord::check_format()
    {
        std::size_t pos = format.find(':');
        if ((pos == std::string::npos && format != "GT") || (format.substr(pos) != "GT")) {
            throw std::invalid_argument("Format first field must be the genotype (GT)");
        }
    }

  }
}
