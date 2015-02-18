#include "file_structure.hpp"
#include "record.hpp"

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
//        std::pair<iter, iter> range = source->meta_entries.equal_range("INFO");
    }
    
    void Record::check_format() const
    {
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("FORMAT");
        
        for (auto & fm : format) {
            bool found_in_header = false;

            for (iter & current = range.first; current != range.second; ++current) {
                auto & key_values = boost::get<std::map < std::string, std::string >> ((current->second).value);
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
     
        if (samples.size() == 0) {
            return; // Nothing to check if no samples are listed in the file
        }
        
        // Get the MetaEntry objects in the same order as they are displayed in the samples
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("FORMAT");
        std::vector<MetaEntry> format_meta;
        
        for (auto & fm : format) {
            for (iter & current = range.first; current != range.second; ++current) {
                auto & key_values = boost::get<std::map < std::string, std::string>>((current->second).value);

                if (key_values["ID"] == fm) {
                    format_meta.push_back(current->second);
                    break;
                }
            }
        }
        
        // Check the samples contents and accordance to the meta section
        for (size_t i = 0; i < samples.size(); ++i) {
            std::vector<std::string> subfields;
            boost::split(subfields, samples[i], boost::is_any_of(":"));
            
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
            
            // TODO The cardinality and type of the fields match the FORMAT meta information
            for (size_t j = 1; j < subfields.size(); ++j) {
                MetaEntry meta = format_meta[j];
                auto & subfield = subfields[j];
                
                auto & key_values = boost::get<std::map < std::string, std::string>>(meta.value);
                try {
                    check_samples_cardinality(subfield, key_values["Number"], alleles.size());
//                check_samples_type(subfield, key_values["Type"]);
                } catch (std::invalid_argument ex) {
                    throw std::invalid_argument("Sample #" + std::to_string(i+1) + ", " + 
                                                key_values["ID"] + "=" + ex.what());
                }
            }
        }
    }
    
    void Record::check_samples_cardinality(std::string const & field,
                                           std::string const & number, 
                                           size_t ploidy) const
    {
        // To check the field cardinality, split by comma and...
        std::vector<std::string> values;
        boost::split(values, field, boost::is_any_of(","));
        size_t expected = -1;
        
        if (number == "A") {
            // ...check against the number of alternate alleles
            expected = alternate_alleles.size();
        } else if (number == "R") {
            // ...check against the number of alternate alleles + 1
            expected = alternate_alleles.size() + 1;
        } else if (number == "G") {
            // ...check against the number of possible genotypes
            // The binomial coefficient is calculated considering the ploidy of the sample
            expected = boost::math::binomial_coefficient<float>(alternate_alleles.size() + 1, ploidy);
        } else if (number == ".") {
            // ...if it unspecified, can't do anything about it
        } else {
            try {
                // ...check against the specified number
                expected = std::stoi(number);
            } catch (...) {}
        } 

        if (number != ".") { // Forget about the unspecified number
            if (values.size() != expected) {
                throw std::invalid_argument(field + " does not match the meta specification Number=" + number);
            }
        }
    }
    
    void Record::check_samples_type(std::string const & type, 
                                    std::string const & field) const
    {
        // TODO Check the field type
        throw std::runtime_error("Not implemented!");
    }
    
  }
}
