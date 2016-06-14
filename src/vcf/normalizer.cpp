/**
 * Copyright 2016 EMBL - European Bioinformatics Institute
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

#include <vcf/file_structure.hpp>
#include "vcf/normalizer.hpp"

namespace ebi
{
  namespace vcf
  {
    //result is undefined if passed container.rend()
    template <class ReverseIterator>
    typename ReverseIterator::iterator_type make_forward(ReverseIterator rit)
    {
        return --(rit.base()); // move result of .base() back by one.
    }
    
    std::vector<Record> normalize(const Record &record/* , ParsingState?*/)
    {
        std::vector<Record> records;
        
        // This index is necessary for getting the samples where the mutated allele is present
        for (size_t i = 0; i < record.alternate_alleles.size(); i++) {
            std::string alternate = record.alternate_alleles[i];
            std::string reference = record.reference_allele;
            size_t position = record.position;
            
            size_t corrected_position;
            std::string corrected_alternate;
            std::string corrected_reference;
            std::vector<std::string> corrected_samples;
            corrected_samples.reserve(record.samples.size());

            //assertions
            if (alternate.size() < 1) {
                throw new BodySectionError{record.line, "Alternate should not be empty"};
            }
            if (reference.size() < 1) {
                throw new BodySectionError{record.line, "Reference should not be empty"};
            }
            if (reference == alternate) {
                throw new BodySectionError{record.line, "Reference and alternate should not be identical"};
            }
            
            // count trailing matching bases
            auto trail_mismatch_reverse = std::mismatch(reference.rbegin(), reference.rend(), alternate.rbegin());
            // rindex is zero: no equal trailing bases
            // rindex is rend: reference and alternate are equal: error
            if (reference.size() == alternate.size()) {
                // polymorphism

                std::string::iterator trail_mismatch_ref = make_forward(trail_mismatch_reverse.first);
                std::string::iterator trail_mismatch_alt = make_forward(trail_mismatch_reverse.second);
                auto lead_mismatch_indices = std::mismatch(reference.begin(), trail_mismatch_ref, alternate.begin());

                // +1 because end is not inclusive: [start, end), and we need to include the mismatch
                corrected_reference.assign(lead_mismatch_indices.first, trail_mismatch_ref+1);
                corrected_alternate.assign(lead_mismatch_indices.second, trail_mismatch_alt+1);
                corrected_position = position + (lead_mismatch_indices.first - reference.begin());
                for (auto &sample : record.samples) {
                    
                }
                
            } else if (reference.size() < alternate.size()){
                // insertion
                if (trail_mismatch_reverse.first == reference.rend()) {
                    // first base changes, with trailing context bases, have to reduce the context to 1 base

                }
            } else {
                // deletion
            }
            std::string::iterator trail_mismatch = make_forward(trail_mismatch_reverse.first);
            auto lead_mismatch_indices = std::mismatch(reference.begin(), trail_mismatch, alternate.begin());
            
                        
            /*
            
            
            if (alternate.size() == alternate.size()) {
                createVariantsFromSameLengthRefAlt(position, reference, alternate);
            } else if (referenceLen == 0) {
                createVariantsFromInsertionEmptyRef(position, alternate);
            } else if (alternateLen == 0) {
                createVariantsFromDeletionEmptyAlt(position, reference);
            } else {
                createVariantsFromIndelNoEmptyRefAlt(position, reference, alternate);
            }
    
            keyFields.setNumAllele(i);
    
            // Since the reference and alternate alleles won't necessarily match
            // the ones read from the VCF file but they are still needed for
            // instantiating the variants, they must be updated
            alternateAlleles[i] = keyFields.alternate;
            generatedKeyFields.add(keyFields);
            // Now create all the Variant objects read from the VCF record
            VariantKeyFields keyFields = generatedKeyFields.get(i);
            Variant variant = new Variant(chromosome, keyFields.start, keyFields.end, keyFields.reference, keyFields.alternate);
            String[] secondaryAlternates = getSecondaryAlternates(variant, keyFields.getNumAllele(), alternateAlleles);
            VariantSourceEntry file = new VariantSourceEntry(source.getFileId(), source.getStudyId(), secondaryAlternates, format);
            variant.addSourceEntry(file);
    
            try {
                parseSplitSampleData(variant, source, fields, alternateAlleles, secondaryAlternates, i + 1);
                // Fill the rest of fields (after samples because INFO depends on them)
                setOtherFields(variant, source, ids, quality, filter, info, format, keyFields.getNumAllele(), alternateAlleles, line);
                variants.add(variant);
            } catch (NonStandardCompliantSampleField ex) {
                Logger.getLogger(VariantFactory.class.getName()).log(Level.SEVERE,
                        String.format("Variant %s:%d:%s>%s will not be saved\n%s",
                                chromosome, position, reference, alternateAlleles[i], ex.getMessage()));
            }
             */
            // TODO leave empty ids?
            // TODO parse info and change the indices?
            records.emplace_back(
                record.line, record.chromosome, corrected_position, std::vector<std::string>{}, 
                corrected_reference, std::vector<std::string>{{corrected_alternate}},
                record.quality, record.filters, record.info, record.format, corrected_samples, record.source
            );
        }

        return std::move(records);
    }

    /**
     * Calculates the start, end, reference and alternate of a SNV/MNV where the 
     * reference and the alternate are not empty. 
     * 
     * This task comprises 2 steps: removing the trailing bases that are 
     * identical in both alleles, then the leading identical bases.
     * 
     * @param position Input starting position
     * @param reference Input reference allele
     * @param alt Input alternate allele
     * @return The new start, end, reference and alternate alleles
     // 
    protected VariantKeyFields createVariantsFromSameLengthRefAlt(int position, String reference, String alt) {
        int indexOfDifference;
        // Remove the trailing bases
        String refReversed = StringUtils.reverse(reference);
        String altReversed = StringUtils.reverse(alt);
        indexOfDifference = StringUtils.indexOfDifference(refReversed, altReversed);
        
        reference = StringUtils.reverse(refReversed.substring(indexOfDifference));
        alt = StringUtils.reverse(altReversed.substring(indexOfDifference));
        
        // Remove the leading bases
        indexOfDifference = StringUtils.indexOfDifference(reference, alt);
        if (indexOfDifference < 0) {
            return null;
        } else {
            int start = position + indexOfDifference;
            int end = position + reference.length() - 1;
            String ref = reference.substring(indexOfDifference);
            String inAlt = alt.substring(indexOfDifference);
            return new VariantKeyFields(start, end, ref, inAlt);
        }
    }

    protected VariantKeyFields createVariantsFromInsertionEmptyRef(int position, String alt) {
        return new VariantKeyFields(position, position + alt.length() - 1, "", alt);
    }

    protected VariantKeyFields createVariantsFromDeletionEmptyAlt(int position, String reference) {
        return new VariantKeyFields(position, position + reference.length() - 1, reference, "");
    }

    // **
     * Calculates the start, end, reference and alternate of an indel where the 
     * reference and the alternate are not empty. 
     * 
     * This task comprises 2 steps: removing the trailing bases that are 
     * identical in both alleles, then the leading identical bases.
     * 
     * @param position Input starting position
     * @param reference Input reference allele
     * @param alt Input alternate allele
     * @return The new start, end, reference and alternate alleles
     *
    protected VariantKeyFields createVariantsFromIndelNoEmptyRefAlt(int position, String reference, String alt) {
        int indexOfDifference;
        // Remove the trailing bases
        String refReversed = StringUtils.reverse(reference);
        String altReversed = StringUtils.reverse(alt);
        indexOfDifference = StringUtils.indexOfDifference(refReversed, altReversed);
        
        reference = StringUtils.reverse(refReversed.substring(indexOfDifference));
        alt = StringUtils.reverse(altReversed.substring(indexOfDifference));
        
        // Remove the leading bases
        indexOfDifference = StringUtils.indexOfDifference(reference, alt);
        if (indexOfDifference < 0) {
            return null;
        } else if (indexOfDifference == 0) {
            if (reference.length() > alt.length()) { // Deletion
                return new VariantKeyFields(position, position + reference.length() - 1, reference, alt);
            } else { // Insertion
                return new VariantKeyFields(position, position + alt.length() - 1, reference, alt);
            }
        } else {
            if (reference.length() > alt.length()) { // Deletion
                int start = position + indexOfDifference;
                int end = position + reference.length() - 1;
                String ref = reference.substring(indexOfDifference);
                String inAlt = alt.substring(indexOfDifference);
                return new VariantKeyFields(start, end, ref, inAlt);
            } else { // Insertion
                int start = position + indexOfDifference;
                int end = position + alt.length() - 1;
                String ref = reference.substring(indexOfDifference);
                String inAlt = alt.substring(indexOfDifference);
                return new VariantKeyFields(start, end, ref, inAlt);
            }
        }
    }
     
     // */
     

  }
}



