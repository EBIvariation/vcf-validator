/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "util/algo_utils.hpp"
#include "vcf/optional_policy.hpp"

namespace ebi
{
  namespace vcf
  {
    
    void ValidateOptionalPolicy::optional_check_meta_section(ParsingState const & state) const
    {
        if (state.source->meta_entries.find(REFERENCE) == state.source->meta_entries.end()) {
            throw new MetaSectionError{state.n_lines, "A valid 'reference' entry is not listed in the meta section"};
        }
    }
    
    void ValidateOptionalPolicy::optional_check_body_entry(ParsingState & state, Record const & record) //const
    {
        // Position zero should only be used for telomeres
        check_body_entry_position_zero(state, record);
        
        // The standard separator is semi-colon, commas are accepted but most probably a mistake
        check_body_entry_id_commas(state, record);
        
        // Reference and alternate alleles in indels should share the first nucleotide
        check_body_entry_reference_alternate_matching(state, record);

        // 0/0 genotypes should be present when ALT is <*>, as it is supposed to be a reference region
        check_body_entry_alt_gvcf_gt_value(state, record);

        // gVCF fields should provide END, as <*> is supposed to represent a region
        check_body_entry_info_gvcf_end(state, record);

        // If a variant is flagged as precise, then it should not contain imprecise variant fields like CIPOS or CIEND
        check_body_entry_info_imprecise(state, record);

        // The number of values in SVLEN should match the number of alternate alleles and value checks
        check_body_entry_info_svlen(state, record);

        // SVCLAIM check
        check_body_entry_info_svclaim(state, record);

        // RB RUC check
        check_body_entry_info_rb_ruc(state, record);

        // RUL RUS check
        check_body_entry_info_rul_rus(state, record);

        // Confidence interval tags should have first value <=0 and second value >= 0
        check_body_entry_info_confidence_interval(state, record);

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
    }

    void ValidateOptionalPolicy::check_body_entry_position_zero(ParsingState & state, Record const & record) const
    {
        if (record.position == 0) {
            throw new PositionBodyError{state.n_lines,
                    "Position zero should only be used to reference a telomere"};
        }
    }
    
    void ValidateOptionalPolicy::check_body_entry_id_commas(ParsingState & state, Record const & record) const
    {
        for (auto & id : record.ids) {
            if (util::contains(id, ',')) {
                throw new IdBodyError{state.n_lines,
                        "Comma found in the ID column; if used as separator, please replace it with semi-colon"};
            }
        }
    }
    
    void ValidateOptionalPolicy::check_body_entry_reference_alternate_matching(ParsingState & state, Record const & record)
    {
        for (size_t i = 0; i < record.alternate_alleles.size(); ++i) {
            auto & alternate = record.alternate_alleles[i];
            auto type = record.types[i];

            if (type == RecordType::INDEL && alternate[0] != record.reference_allele[0]) {
                throw new ReferenceAlleleBodyError{state.n_lines,
                        "Reference and alternate alleles do not share the first nucleotide"};
            }
        }
    }

    void ValidateOptionalPolicy::check_body_entry_alt_gvcf_gt_value(ParsingState & state, Record const & record) const
    {
        if (util::contains(record.alternate_alleles, GVCF_NON_VARIANT_ALLELE) && record.format[0] == vcf::GT) {
            for (auto & sample : record.samples) {
                if (sample_has_reference_in_all_alleles(sample)) {
                    return;
                }
            }
            throw new AlternateAllelesBodyError{state.n_lines,
                    "At least one sample should report a genotype with all reference alleles, when ALT is " + GVCF_NON_VARIANT_ALLELE
                    + " as it is supposed to be a reference region"};
        }
    }

    bool ValidateOptionalPolicy::sample_has_reference_in_all_alleles(std::string const & sample) const
    {
        std::string gt_subfield = sample.substr(0, sample.find(':'));
        std::vector<std::string> alleles;
        util::string_split(gt_subfield, "/|", alleles);
        for (auto & allele : alleles) {
            if (allele != "0") {
                return false;
            }
        }
        return true;
    }

    void ValidateOptionalPolicy::check_body_entry_info_gvcf_end(ParsingState & state, Record const & record) const
    {
        if (util::contains(record.alternate_alleles, GVCF_NON_VARIANT_ALLELE)
            && record.info.find(END) == record.info.end()) {
            throw new InfoBodyError{state.n_lines,
                    "INFO END should be provided when ALT is " + GVCF_NON_VARIANT_ALLELE
                    + " as it is supposed to be a region"};
        }
    }

    void ValidateOptionalPolicy::check_body_entry_info_imprecise(ParsingState & state, Record const & record) const
    {
        auto it = record.info.find(IMPRECISE);
        if (it != record.info.end() && it->second == "0") {
            check_body_entry_info_other_tag(state, record.info, CIPOS);
            check_body_entry_info_other_tag(state, record.info, CIEND);
        }
    }

    void ValidateOptionalPolicy::check_body_entry_info_other_tag(ParsingState & state, std::multimap<std::string, std::string> const & info,
                                                                 std::string const & tag) const
    {
        auto it = info.find(tag);
        if (it != info.end()) {
            throw new InfoBodyError{state.n_lines,
                    "INFO " + tag + " tag should not be defined for a precise variant"};
        }
    }

    void ValidateOptionalPolicy::check_body_entry_info_svlen(ParsingState & state, Record const & record) const
    {
        static boost::regex cnchk_regex("(<(CNV|DUP|DEL)(:[^>]+)*>)+");
        static boost::regex svchk_regex("(<(INS|DUP|INV|DEL|CNV)(:[^>]+)*>)+");
        static boost::regex non_symbolic_alt_regex("[ACGTN]+", boost::regex::icase);
        std::string svlenval;

        auto it = record.info.find(SVLEN);
        if (it != record.info.end()) {
            std::vector<std::string> values;
            util::string_split(it->second, ",", values);
            if (values.size() != record.alternate_alleles.size()) {
                throw new InfoBodyError{state.n_lines,
                        "INFO SVLEN should have same number of values as ALT", "Expected " + std::to_string(record.alternate_alleles.size())
                        + ", found " + std::to_string(values.size())};
            }

            if (record.source->version < Version::v44) {
                return;
            }
            auto itcn = std::find(record.format.begin(), record.format.end(), CN);
            for (auto i = 0; i < record.alternate_alleles.size(); ++i) {
                //SVLEN should be '.' for non SV alleles
                if (boost::regex_match(record.alternate_alleles[i], non_symbolic_alt_regex) || 
                    !boost::regex_match(record.alternate_alleles[i], svchk_regex)) {
                    //for alleles other than those in svchk_regex, value should be '.'
                    if (values[i] != MISSING_VALUE) {
                        throw new InfoBodyError{state.n_lines, "INFO SVLEN should be " + MISSING_VALUE + " for alleles other than structural variant INS/INV/DUP/DEL/CNV"};
                    }
                }
                if (itcn != record.format.end()) {
                    //with CN in format, CNV/DEL/DUP should have the same SVLEN value, v4.4 onwards
                    if (record.types[i] != RecordType::STRUCTURAL || !boost::regex_match(record.alternate_alleles[i], svchk_regex)) {
                        continue;
                    }
                    if (!svlenval.size()) {
                        svlenval = values[i];   //first
                        continue;
                    }
                    //CNV/DEL/DUP, should have the same SVLEN
                    if (svlenval != values[i]) {
                        throw new InfoBodyError{state.n_lines,
                        "INFO SVLEN should have same values for SV CNV/DEL/DUP", "Expected " + svlenval
                        + ", found " + values[i]};
                    }
                }
            }
        }
    }

    void ValidateOptionalPolicy::check_body_entry_info_svclaim(ParsingState & state, Record const & record) const
    {
        std::vector<std::string> values;

        if (record.source->version < Version::v44) {
            return;     //svclaim not present for version < v44
        }
        auto it = record.info.find(SVCLAIM);
        if (it == record.info.end()) {
            return;     //no svclaim
        }
        util::string_split(it->second, ",", values);
        if (values.size() != record.alternate_alleles.size()) {
            return;     //already checked in records
        }

        for (size_t i = 0; i < record.alternate_alleles.size(); ++i) {
            if (record.types[i] == RecordType::STRUCTURAL ||
                record.types[i] == RecordType::STRUCTURAL_BREAKEND) {
                continue;   //already taken care in records!
            }
            if (values[i] != MISSING_VALUE) {
                std::stringstream message;
                message << "INFO " << SVCLAIM << " should be " << MISSING_VALUE << " for allele " << record.alternate_alleles[i];
                throw new InfoBodyError{record.line, message.str(), "Found " + SVCLAIM + " was '" + values[i] + "'"};
            }
        }
    }

    void ValidateOptionalPolicy::check_body_entry_info_confidence_interval(ParsingState & state, Record const & record) const
    {
        std::vector<std::string> confidence_interval_tags = { CICN, CIEND, CILEN, CIPOS, CIRB, CIRUC };
        if (record.source->version < vcf::Version::v44) {
            std::vector<std::string> confidence_interval_tags_v43 = { CICN, CICNADJ, CIEND, CILEN, CIPOS, CIRB, CIRUC };
            confidence_interval_tags = confidence_interval_tags_v43;
        }
        for (auto & confidence_interval_tag : confidence_interval_tags) {
            auto it = record.info.find(confidence_interval_tag);
            if (it != record.info.end()) {
                std::vector<std::string> values;
                util::string_split(it->second, ",", values);
                if (values.size() % 2 != 0) {           //CI should have even count
                    throw new InfoBodyError{state.n_lines,
                            "INFO " + confidence_interval_tag +
                            " is a confidence interval tag, which should have even number entries"};
                }
                for (int i = 0; i < values.size(); i += 2) {
                    size_t scanned_first_value_length = 1, scanned_second_value_length = 1;
                    //considers missing value as 0 - valid value
                    int first_numeric_value = std::stoi(values[i] != MISSING_VALUE ? values[i] : "0", &scanned_first_value_length);
                    int second_numeric_value = std::stoi(values[i + 1] != MISSING_VALUE ? values[i + 1] : "0", &scanned_second_value_length);
                     if (first_numeric_value > 0 || second_numeric_value < 0
                        || values[i].size() != scanned_first_value_length || values[i + 1].size() != scanned_second_value_length) {
                        throw new InfoBodyError{state.n_lines,
                                "INFO " + confidence_interval_tag +
                                " is a confidence interval tag, which should have first value <= 0 and second value >= 0"};
                    }
                }
            }
        }
    }

    void ValidateOptionalPolicy::check_body_entry_info_rb_ruc(ParsingState & state, Record const & record) const
    {
        std::vector<std::string> valRB, valRUC, valLen;
        int rb = 0, ruc = 0 , rul = 0;
        const float limit = 0.05;   //5% variation

        if (record.source->version < Version::v44) {
            return;     //not valid for version < v44
        }
        auto itRB = record.info.find(RB);
        auto itRUC = record.info.find(RUC);
        auto itRUL = record.info.find(RUL);
        auto itRUS = record.info.find(RUS);
        if (itRB == record.info.end() || itRUC == record.info.end()) {
            return;     //nothing to check
        }
        util::string_split(itRB->second, ",", valRB);
        util::string_split(itRUC->second, ",", valRUC);
        if (itRUL != record.info.end()) {
            util::string_split(itRUL->second, ",", valLen);
        } else {
            util::string_split(itRUS->second, ",", valLen);
        }
        if (valRB.size() != valRUC.size() || valRB.size() != valLen.size()) {
            return;     //already checked in records
        }

        for (size_t i = 0; i < valRB.size(); ++i) {
            if (valRB[i] == MISSING_VALUE) {
                continue;
            }
            rb = std::stoi(valRB[i]);
            ruc = std::stoi(valRUC[i]);
            rul = itRUL != record.info.end()? std::stoi(valLen[i]) : valLen[i].size();
            //RB ~= RUL * RUC
            if ( (abs(rb - rul * ruc) / (float)rb) > limit) {
                std::stringstream message;
                message << "INFO " << "RB should be approximately RUC * unit_length";
                throw new InfoBodyError{record.line, message.str(), "Failed for position " + std::to_string(i)};
            }
        }
    }

    void ValidateOptionalPolicy::check_body_entry_info_rul_rus(ParsingState & state, Record const & record) const
    {
        if (record.source->version < Version::v44) {
            return;     //not valid for version < v44
        }
        auto itRUL = record.info.find(RUL);
        auto itRUS = record.info.find(RUS);
        if (itRUS != record.info.end() && itRUL != record.info.end()) { //RUS, RUL together - redundant info
            std::stringstream message;
            message << "INFO " << "RUS and RUL present together, RUL can be avoided";
            throw new InfoBodyError{record.line, message.str()};
        }
    }
    
    void ValidateOptionalPolicy::check_contig_meta(ParsingState & state, Record const & record) const
    {
        // The associated 'contig' meta entry should exist (notify only once)
        std::string current_chromosome = record.chromosome;

        if (state.is_well_defined_meta(CONTIG, current_chromosome)) {
            return; // Check only once
        }
        
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range(CONTIG);

        if (is_record_subfield_in_header(current_chromosome, range.first, range.second)) {
            state.add_well_defined_meta(CONTIG, current_chromosome);
        } else {
            throw new NoMetaDefinitionError{
                    state.n_lines,
                    "Chromosome/contig '" + current_chromosome + "' is not described in a 'contig' meta description"
            };
        }
    }
    
    void ValidateOptionalPolicy::check_alternate_allele_meta(ParsingState & state, Record const & record) const
    {
        static boost::regex square_brackets_regex("<([a-zA-Z0-9:_]+)>");
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range(ALT);
        boost::cmatch pieces_match;
        
        for (auto & alternate : record.alternate_alleles) {
            // Check alternate ID is present in meta-entry (only applies to the form <SOME_ALT_ID>)
            if (alternate[0] == '<' && boost::regex_match(alternate.c_str(), pieces_match, square_brackets_regex)) {
                std::string alt_id = pieces_match[1];
                
                if (state.is_well_defined_meta(ALT, alt_id)) {
                    continue; // Check only once
                }
                
                if (is_record_subfield_in_header(alt_id, range.first, range.second)) {
                    state.add_well_defined_meta(ALT, alt_id);
                } else {
                    throw new NoMetaDefinitionError{
                            state.n_lines,
                            "Alternate '<" + alt_id + ">' is not listed in a valid meta-data ALT entry"
                    };
                }
            }
        }
    }
    
    void ValidateOptionalPolicy::check_filter_meta(ParsingState & state, Record const & record) const
    {
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range(FILTER);
        
        for (auto & filter : record.filters) {
            if (filter == PASS || filter == MISSING_VALUE) { continue; } // No need to check PASS or missing data
            
            if (state.is_well_defined_meta(FILTER, filter)) {
                continue; // Check only once
            }
            
            if (is_record_subfield_in_header(filter, range.first, range.second)) {
                state.add_well_defined_meta(FILTER, filter);
            } else {
                throw new NoMetaDefinitionError{
                        state.n_lines,
                        "FILTER '" + filter + "' is not listed in a valid meta-data FILTER entry"
                };
            }
        }
    }
    
    void ValidateOptionalPolicy::check_info_meta(ParsingState & state, Record const & record) const
    {
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range(INFO);
        
        for (auto & field : record.info) {
            auto & id = field.first;
            if (field.first == MISSING_VALUE) { continue; } // No need to check missing data
            
            if (state.is_well_defined_meta(INFO, id)) {
                continue; // Check only once
            }
            
            if (is_record_subfield_in_header(id, range.first, range.second)) {
                state.add_well_defined_meta(INFO, id);
            } else {
                throw new NoMetaDefinitionError{
                        state.n_lines,
                        "INFO '" + id + "' is not listed in a valid meta-data INFO entry"
                };
            }
        }
    }
    
    void ValidateOptionalPolicy::check_format_meta(ParsingState & state, Record const & record) const
    {
        std::pair<meta_iterator, meta_iterator> range = state.source->meta_entries.equal_range(FORMAT);
        
        for (auto & fm : record.format) {
            if (state.is_well_defined_meta(FORMAT, fm)) {
                continue; // Check only once
            }
            
            if (is_record_subfield_in_header(fm, range.first, range.second)) {
                state.add_well_defined_meta(FORMAT, fm);
            } else {
                throw new NoMetaDefinitionError{
                        state.n_lines,
                        "FORMAT '" + fm + "' is not listed in a valid meta-data FORMAT entry"
                };
            }
        }
    }
  }
}
