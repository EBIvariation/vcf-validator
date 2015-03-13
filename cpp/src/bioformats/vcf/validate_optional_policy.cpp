#include "validator.hpp"
#include "file_structure.hpp"
#include "record.hpp"

namespace opencb
{
  namespace vcf
  {
    
    void ValidateOptionalPolicy::optional_check_meta_section(ParsingState const & state) const
    {
        if (state.source->meta_entries.find("reference") == state.source->meta_entries.end()) {
          throw ParsingWarning("A valid 'reference' entry is not listed in the meta section");
        }
    }
    
    void ValidateOptionalPolicy::optional_check_body_entry(ParsingState & state, Record & record) //const
    {
        // All samples should have the same ploidy
        check_body_entry_ploidy(state, record);
        
        /*
         * Once some meta-data is marked as in/correct there is no need again, so all the following have been 
         * optimised using a map for correctly defined meta-data and another one for incorrectly defined.
         */
        
        // The chromosome/contig should be described in the meta section
        check_contig_meta(state, record);
        
        // Alternate alleles of the form <SOME_ALT> should be described in the meta section
        check_alternate_allele_meta(state, record);
        
        // Filters should be described in the meta section
        check_filter_meta(state, record);
        
        // Info fields should be described in the meta section
        check_info_meta(state, record);
        
        // Format fields should be described in the meta section
        check_format_meta(state, record);
    }
    
    void ValidateOptionalPolicy::optional_check_body_section(ParsingState const & state) const
    {
//        // TODO The file should be sorted
//        if (state.records->size() > 0) {
//            auto & previous_record = state.records->back();
//            std::string current_chromosome = ParsePolicy::column_tokens("CHROM")[0];
//            int current_position = std::stoi(ParsePolicy::column_tokens("POS")[0]);
//            if (previous_record.chromosome == current_chromosome && 
//                    previous_record.position > current_position) {
//                throw ParsingWarning("Genomic position " + current_chromosome + ":" + std::to_string(current_position) + 
//                                     " is listed after " + previous_record.chromosome + ":" + std::to_string(previous_record.position));
//            }
//        }
    }
    
    void ValidateOptionalPolicy::check_body_entry_ploidy(ParsingState & state, Record & record)
    {
        // All samples should have the same ploidy
        int ploidy = -1;
        size_t i = 1;
        for (auto & sample : record.samples) {
            std::vector<std::string> subfields;
            boost::split(subfields, sample, boost::is_any_of(":"));
            std::vector<std::string> alleles;
            boost::split(alleles, subfields[0], boost::is_any_of("|,/"));

            if (ploidy > 0) {
                if (alleles.size() != ploidy) {
                    throw ParsingWarning("Sample #" + std::to_string(i) + " has " + std::to_string(alleles.size()) + 
                                         " allele(s), but " + std::to_string(ploidy) + " were found in others");
                }
            } else {
                ploidy = alleles.size();
            }
            
            ++i;
        }
    }
  
    void ValidateOptionalPolicy::check_contig_meta(ParsingState & state, Record & record) const
    {
        // The associated 'contig' meta entry should exist (notify only once)
        std::string current_chromosome = record.chromosome;

        if (state.is_bad_defined_meta("contig", current_chromosome) ||
            state.is_well_defined_meta("contig", current_chromosome)) {
            return; // Notify only once
        }
        
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range("contig");

        if (is_record_subfield_in_header(current_chromosome, range.first, range.second)) {
            state.add_well_defined_meta("contig", current_chromosome);
        } else {
            state.add_bad_defined_meta("contig", current_chromosome);
            throw ParsingWarning("Chromosome/contig '" + current_chromosome + "' is not described in a 'contig' meta description");
        }
    }
    
    void ValidateOptionalPolicy::check_alternate_allele_meta(ParsingState & state, Record & record) const
    {
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range("ALT");
        
        boost::regex square_brackets_regex("<([a-zA-Z0-9:_]+)>");
        boost::cmatch pieces_match;
        
        for (auto & alternate : record.alternate_alleles) {
            // Check alternate ID is present in meta-entry (only applies to the form <SOME_ALT_ID>)
            if (regex_match(alternate.c_str(), pieces_match, square_brackets_regex)) {
                std::string alt_id = pieces_match[1];
                
                if (state.is_bad_defined_meta("ALT", alt_id)||
                    state.is_well_defined_meta("ALT", alt_id)) {
                    continue; // Notify only once
                }
                
                if (is_record_subfield_in_header(alt_id, range.first, range.second)) {
                    state.add_well_defined_meta("ALT", alt_id);
                } else {
                    state.add_bad_defined_meta("ALT", alt_id);
                    throw ParsingWarning("Alternate '<" + alt_id + ">' is not listed in a valid meta-data ALT entry");
                }
            }
        }
    }
    
    void ValidateOptionalPolicy::check_filter_meta(ParsingState & state, Record & record) const
    {
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range("FILTER");
        
        for (auto & filter : record.filters) {
            if (filter == "PASS" || filter == ".") { continue; } // No need to check PASS or missing data
            
            if (state.is_bad_defined_meta("FILTER", filter)||
                state.is_well_defined_meta("FILTER", filter)) {
                continue; // Notify only once
            }
            
            if (is_record_subfield_in_header(filter, range.first, range.second)) {
                state.add_well_defined_meta("FILTER", filter);
            } else {
                state.add_bad_defined_meta("FILTER", filter);
                throw ParsingWarning("Filter '" + filter + "' is not listed in a valid meta-data FILTER entry");
            }
        }
    }
    
    void ValidateOptionalPolicy::check_info_meta(ParsingState & state, Record & record) const
    {
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range("INFO");
        
        for (auto & field : record.info) {
            auto & id = field.first;
            if (field.first == ".") { continue; } // No need to check missing data
            
            if (state.is_bad_defined_meta("INFO", id)||
                state.is_well_defined_meta("INFO", id)) {
                continue; // Notify only once
            }
            
            if (is_record_subfield_in_header(id, range.first, range.second)) {
                state.add_well_defined_meta("INFO", id);
            } else {
                state.add_bad_defined_meta("INFO", id);
                throw ParsingWarning("Info '" + id + "' is not listed in a valid meta-data INFO entry");
            }
        }
    }
    
    void ValidateOptionalPolicy::check_format_meta(ParsingState & state, Record & record) const
    {
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range("FORMAT");
        
        for (auto & fm : record.format) {
            if (state.is_bad_defined_meta("FORMAT", fm)||
                state.is_well_defined_meta("FORMAT", fm)) {
                continue; // Notify only once
            }
            
            if (is_record_subfield_in_header(fm, range.first, range.second)) {
                state.add_well_defined_meta("FORMAT", fm);
            } else {
                state.add_bad_defined_meta("FORMAT", fm);
                throw ParsingWarning("Format '" + fm + "' is not listed in a valid meta-data FORMAT entry");
            }
        }
    }
  }
}
