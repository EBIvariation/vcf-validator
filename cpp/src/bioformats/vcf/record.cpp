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
                         std::map<std::string, std::string> const & info, 
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
            if (find_if(id.begin(), id.end(), [](char c) { return c == ' ' || c == ';'; }) != id.end()) {
                throw std::invalid_argument("ID must not contain semicolons or whitespaces");
            }
        }
    }

    void Record::check_alternate_alleles() const
    {
        std::pair<meta_iterator, meta_iterator> range = source->meta_entries.equal_range("ALT");
        
        boost::regex square_brackets_regex("<([a-zA-Z0-9:_]+)>");
        boost::cmatch pieces_match;
        
        for (auto & alternate : alternate_alleles) {
            // Check alternate allele structure against the reference
            check_alternate_allele_structure(alternate);
            
            // Check alternate ID is present in meta-entry (only applies to the form <SOME_ALT_ID>)
            if (regex_match(alternate.c_str(), pieces_match, square_brackets_regex)) {
                std::string alt_id = pieces_match[1];
                check_alternate_allele_meta(alt_id, range);
            }
        }
        
    }
    
    void Record::check_alternate_allele_structure(std::string const & alternate) const
    {
        if (alternate == ".") {
            if (alternate_alleles.size() > 1) {
                throw std::invalid_argument("The no-alternate alleles symbol (dot) can not be combined with others");
            }
        } else if (alternate[0] == '<') {
            return; // Custom ALTs can't be checked against the reference
        } else if (std::count(alternate.begin(), alternate.end(), '[') == 2 || 
            std::count(alternate.begin(), alternate.end(), ']') == 2) { 
            return; // Break-ends can't be checked against the reference
        } else if (alternate[0] != reference_allele[0] && alternate.size() != reference_allele.size()) {
            throw std::invalid_argument("Reference and alternate alleles must share the first nucleotide");
        } else if (alternate == reference_allele) {
            throw std::invalid_argument("Reference and alternate alleles must not be the same");
        }
    }
    
    void Record::check_alternate_allele_meta(std::string const & alt_id,
                                             std::pair<meta_iterator, meta_iterator> range) const
    {
        if (!is_record_subfield_in_header(alt_id, range.first, range.second)) {
            throw std::invalid_argument("Alternate '<" + alt_id + ">' is not listed in a meta-data ALT entry");
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
            if (filter == "PASS" || filter == ".") { continue; } // No need to check PASS or missing data
            
            if (!is_record_subfield_in_header(filter, range.first, range.second)) {
                throw std::invalid_argument("Filter '" + filter + "' is not listed in a meta-data FILTER entry");
            }
        }
    }
    
    void Record::check_info() const
    {
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("INFO");
        
        // Check that all INFO fields are listed in the meta section, 
        // and they match the Number and Type specified in there
        for (auto & field : info) {
            if (field.first == ".") { continue; } // No need to check missing data
            
            bool found_in_header = false;

            for (iter current = range.first; current != range.second; ++current) {
                auto & key_values = boost::get<std::map < std::string, std::string >> ((current->second).value);
                if (key_values["ID"] == field.first) {
                    found_in_header = true;
                    
                    try {
                        check_field_cardinality(field.second, key_values["Number"], 2); // TODO Assumes ploidy=2
                        check_field_type(field.second, key_values["Type"]);
                    } catch (std::invalid_argument ex) {
                        throw std::invalid_argument("Info " + key_values["ID"] + "=" + ex.what());
                    }
                    
                    break;
                }
            }

            if (!found_in_header) {
                throw std::invalid_argument("Info '" + field.first + "' is not listed in a meta-data INFO entry");
            }
        }
        
    }
    
    void Record::check_format() const
    {
        if (format.size() == 0) {
            return; // Nothing to check
        }
            
        if (format[0] != "GT") {
            throw std::invalid_argument("GT must be the first field in the FORMAT column");
        }
        
        typedef std::multimap<std::string, MetaEntry>::iterator iter;
        std::pair<iter, iter> range = source->meta_entries.equal_range("FORMAT");
        
        for (auto & fm : format) {
            if (!is_record_subfield_in_header(fm, range.first, range.second)) {
                throw std::invalid_argument("Format '" + fm + "' is not listed in a meta-data FORMAT entry");
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
            for (iter current = range.first; current != range.second; ++current) {
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
            
            // The number of subfields can't be greater than the number in the FORMAT column
            if (subfields.size() > format.size()) {
                throw std::invalid_argument("Sample #" + std::to_string(i+1) + 
                        " has more fields than specified in the FORMAT column");
            }
            
            std::vector<std::string> alleles;
            boost::split(alleles, subfields[0], boost::is_any_of("|,/"));
            
            // The allele indexes must not be greater than the total number of alleles
            check_samples_alleles(alleles);
            
            // The cardinality and type of the fields match the FORMAT meta information
            for (size_t j = 1; j < subfields.size(); ++j) {
                MetaEntry meta = format_meta[j];
                auto & subfield = subfields[j];
                
                auto & key_values = boost::get<std::map < std::string, std::string>>(meta.value);
                try {
                    check_field_cardinality(subfield, key_values["Number"], alleles.size());
                    check_field_type(subfield, key_values["Type"]);
                } catch (std::invalid_argument ex) {
                    throw std::invalid_argument("Sample #" + std::to_string(i+1) + ", " + 
                                                key_values["ID"] + "=" + ex.what());
                }
            }
        }
    }
    
    void Record::check_samples_alleles(std::vector<std::string> const & alleles) const
    {
        for (auto & allele : alleles) {
            if (allele == ".") { continue; } // No need to check missing alleles

            int num_allele = std::stoi(allele);
            if (num_allele > alternate_alleles.size()) {
                throw std::invalid_argument("Alternate allele index " + std::to_string(num_allele) + 
                        " is greater than the maximum allowed " + std::to_string(alternate_alleles.size()));
            }
        }
    }
    
    void Record::check_field_cardinality(std::string const & field,
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
            expected = boost::math::binomial_coefficient<float>(alternate_alleles.size() + ploidy, ploidy);
        } else if (number == ".") {
            // ...do nothing, it is unspecified
        } else {
            try {
                // ...check against the specified number
                expected = std::stoi(number);
            } catch (...) {}
        } 

        if (number != ".") { // Forget about the unspecified number
            // The number of values must match the expected or, if the expected is 0, 
            // there will be one empty value that needs to be specifically checked
            if (values.size() != expected && 
                values.size() > 1 && values[0] != "") {
                throw std::invalid_argument(field + " does not match the meta specification Number=" + number + 
                        ", expected " + std::to_string(expected) + " values");
            }
        }
    }
    
    void Record::check_field_type(std::string const & field,
                                  std::string const & type) const
    {
        // To check the field type, split by comma and...
        std::vector<std::string> values;
        boost::split(values, field, boost::is_any_of(","));
        
        for (auto & value : values) {
            if (value == ".") { continue; }
            
            try {
                if (type == "Integer") {
                    // ...try to cast to int
                    std::stoi(value);
                } else if (type == "Float") {
                    // ...try to cast to double (for extremely precise cases)
                    std::stod(value);
                } else if (type == "Flag") {
                    if (value.size() > 1) {
                        throw std::invalid_argument("There can be only 0 or 1 value");
                    } else if (value.size() == 1) {
                        int numeric_value = std::stoi(value);
                        if (numeric_value != 0 && numeric_value != 1) {
                            throw std::invalid_argument("A flag must be 0 or 1");
                        }
                    }
                    // If no flag is provided then there is nothing to check
                } else if (type == "Character") {
                    // ...check the length is 1
                    if (value.size() > 1) {
                        throw std::invalid_argument("There can be only one character");
                    }
                } else if (type == "String") {
                    // ...do nothing, it is guaranteed it will be a string
                } 
            } catch (...) {
                throw std::invalid_argument(field + " does not match the meta specification Type=" + type);
            }
        }
    }
    
    bool is_record_subfield_in_header(std::string const & field_value,
                                      std::multimap<std::string, MetaEntry>::iterator begin,
                                      std::multimap<std::string, MetaEntry>::iterator end)
    {
        for (std::multimap<std::string, MetaEntry>::iterator current = begin; current != end; ++current) {
            auto & key_values = boost::get<std::map < std::string, std::string >> ((current->second).value);

            if (key_values["ID"] == field_value) {
                return true;
            }
        }
        
        return false;
    }
    
  }
}
