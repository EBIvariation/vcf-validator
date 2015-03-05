#include "validator.hpp"
#include "file_structure.hpp"

namespace opencb
{
  namespace vcf
  {
    
    void ValidateOptionalPolicy::optional_check_meta_section(ParsingState const & state) const
    {
        if (state.source->meta_entries.find("reference") == state.source->meta_entries.end()) {
          throw ParsingWarning("It is recommended to include a 'reference' entry in the meta section");
        }
    }
    
    void ValidateOptionalPolicy::optional_check_body_entry(ParsingState & state, Record & record) //const
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

        /*
         * TODO This can be optimised using one map for correctly defined meta-data and other one for the incorrect, 
         * so there is no need to check again once a chromosome is marked as correct
         */
        // The associated 'contig' meta entry should exist (notify only once)
        //std::string current_chromosome = ParsePolicy::column_tokens("CHROM")[0];
        std::string current_chromosome = record.chromosome;

        if (!state.is_bad_defined_contig(current_chromosome)) {
            typedef std::multimap<std::string, MetaEntry>::iterator iter;
            std::pair<iter, iter> range = state.source->meta_entries.equal_range("contig");

            bool found_in_header = false;
            for (iter current = range.first; current != range.second; ++current) {
                auto & key_values = boost::get<std::map < std::string, std::string >> ((current->second).value);
                if (key_values.find("ID") != key_values.end() && key_values["ID"] == current_chromosome) {
                    found_in_header = true;
                    break;
                }
            }

            if (!found_in_header) {
                state.add_bad_defined_contig(current_chromosome);
                throw ParsingWarning("Chromosome/contig '" + current_chromosome + "' is not described in a 'contig' meta description");
            }
        }
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
  }
}
