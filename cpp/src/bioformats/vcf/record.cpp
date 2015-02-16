#include <iostream>
#include "file_structure.hpp"

namespace opencb
{
  namespace vcf
  {
    
    Record::Record(std::string const & chromosome, 
                         size_t const position, 
                         std::vector<std::string> const & ids, 
                         std::string const & reference_allele, 
                         std::vector<std::string> const & alternate_alleles, 
                         float const quality, 
                         std::vector<std::string> const & filters, 
                         std::vector<std::string> const & info, 
                         std::vector<std::string> const & format, 
                         std::vector<std::string> const & samples,
                         std::shared_ptr<Source> const & source) 
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
        check_filter();
        check_info();
        check_format();
        check_samples();
    }

    bool Record::operator==(Record const & other) const
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

    bool Record::operator!=(Record const & other) const
    {
        return !(*this == other);
    }

    void Record::check_chromosome() const
    {
        if (chromosome.find(':') != std::string::npos) {
            throw std::invalid_argument("Chromosome must not contain colons");
        }
        if (chromosome.find(' ') != std::string::npos) {
            throw std::invalid_argument("Chromosome must not contain white-spaces");
        }
    }

    void Record::check_ids() const
    {
        if (ids.size() == 1 && ids[0] == ".") {
            return; // No need to check if no IDs are provided
        }
        
        for (auto & id : ids) {
            if (find_if(id.begin(), id.end(), [](char c) { return !isalnum(c); }) != id.end()) {
                throw std::invalid_argument("ID must be alphanumeric");
            }
        }
    }

    void Record::check_alternate_alleles() const
    {
        // Check alternate allele structure against the reference
        for (auto & alternate : alternate_alleles) {
            if (alternate == ".") {
                if (alternate_alleles.size() > 1) {
                    throw std::invalid_argument("The no-alternate alleles symbol (dot) can not be combined with others");
                }
            } else if (alternate[0] == '<') {
                continue; // Custom ALTs can't be checked against the reference
            } else if (std::count(alternate.begin(), alternate.end(), '[') == 2 || 
                std::count(alternate.begin(), alternate.end(), ']') == 2) { 
                continue; // Break-ends can't be checked against the reference
            } else if (alternate[0] != reference_allele[0] && alternate.size() != reference_allele.size()) {
                throw std::invalid_argument("Reference and alternate alleles must share the first nucleotide");
            } else if (alternate == reference_allele) {
                throw std::invalid_argument("Reference and alternate alleles must not be the same");
            }
        }
        
        // Check alternate ID is present in meta-entry, if applicable
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("ALT");
        
        boost::regex square_brackets_regex("<([a-zA-Z0-9:_]+)>");
        boost::cmatch pieces_match;
        
        for (auto & alternate : alternate_alleles) {
            if (regex_match(alternate.c_str(), pieces_match, square_brackets_regex)) {
                std::string alt_id = pieces_match[1];
                bool found_in_header = false;
                
                for (; range.first != range.second; ++range.first) {
                    auto & element = range.first; // Current std::pair object
                    auto & key_values = boost::get<std::map < std::string, std::string >> ((element->second).value);
                    
                    if (key_values["ID"] == alt_id) {
                        found_in_header = true;
                        break;
                    }
                }
                
                if (!found_in_header) {
                    throw std::invalid_argument("Alternate '" + alt_id + "' is not listed in a meta-data ALT entry");
                }
            }
        }
    }

    void Record::check_quality() const
    {
        if (quality < 0) {
            throw std::invalid_argument("Quality is not equal or greater than zero");
        }
    }
    
    void Record::check_filter() const
    {
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("FILTER");
        
        for (auto & filter : filters) {
            if (filter != "PASS" && filter != ".") {
                bool found_in_header = false;
                for (; range.first != range.second; ++range.first) {
                    auto & element = range.first; // Current std::pair object
                    auto & key_values = boost::get<std::map < std::string, std::string >> ((element->second).value);
                    
                    if (key_values["ID"] == filter) {
                        found_in_header = true;
                        break;
                    }
                }
                
                if (!found_in_header) {
                    throw std::invalid_argument("Filter '" + filter + "' is not listed in a meta-data FILTER entry");
                }
            }
        }
    }
    
    void Record::check_info() const
    {
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("INFO");
    }
    
    void Record::check_format() const
    {
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("FORMAT");
        
        for (auto & fm : format) {
            bool found_in_header = false;

            for (; range.first != range.second; ++range.first) {
                auto & element = range.first; // Current std::pair object
                auto & key_values = boost::get<std::map < std::string, std::string >> ((element->second).value);

                if (key_values["ID"] == fm) {
                    found_in_header = true;
                    break;
                }
            }

            if (!found_in_header) {
                throw std::invalid_argument("Format field '" + fm + "' is not listed in a meta-data FORMAT entry");
            }
        }
    }

    void Record::check_samples() const
    {
        if (samples.size() != source->samples_names.size()) {
            throw std::invalid_argument("The number of samples must match those listed in the header line");
        }
        
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("FORMAT");
        
        for (auto & sample : samples) {
            std::vector<std::string> subfields;
            boost::split(subfields, sample, boost::is_any_of(":"));
            
            // Their allele indexes must not be greater than the total number of alleles
            std::vector<std::string> alleles;
            boost::split(alleles, subfields[0], boost::is_any_of("|,/"));
            for (auto & allele : alleles) {
                if (allele == ".") { continue; } // No need to check missing alleles
                
                int num_allele = std::stoi(allele);
                if (num_allele > alternate_alleles.size()) {
                    throw std::invalid_argument("Alternate allele index " + std::to_string(num_allele) + 
                            " is greater than the maximum allowed " + std::to_string(alternate_alleles.size()));
                }
            }
            
            // TODO The number and type of the fields match the FORMAT meta information
            for (size_t i = 1; i < subfields.size(); ++i) {
                
            }
        }
    }
  }
}
