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

#include "vcf/normalizer.hpp"

namespace ebi
{
  namespace vcf
  {

    bool RecordCore::operator<(const RecordCore &other) const
    {
        int compare = chromosome.compare(other.chromosome); // <0: a<b; 0: a==b; >0: a>b
        if (compare != 0) {
            return compare < 0;
        }
        // else: chromosome is the same

        if (position != other.position) {
            return position < other.position;
        }
        compare = reference_allele.compare(other.reference_allele);
        if (compare != 0) {
            return compare < 0;
        }
        compare = alternate_alleles.compare(other.alternate_alleles);
        return compare < 0;
    }

    bool RecordCore::operator==(const RecordCore &other) const
    {
        return chromosome == other.chromosome 
               && position == other.position 
               && reference_allele == other.reference_allele
               && alternate_alleles == other.alternate_alleles;
    }
    
    std::ostream &operator<<(std::ostream &os, const RecordCore &record)
    {
        using util::operator<<;
        os << "{";
        os << record.line << ", " << record.chromosome << ", " << record.position << ", ";
        os << record.reference_allele << ", " << record.alternate_alleles;
        os << "}";
        return os;
    }
    
    //result is undefined if passed container.rend()
    template <class ReverseIterator>
    typename ReverseIterator::iterator_type make_forward(ReverseIterator rit)
    {
        return --(rit.base()); // move result of .base() back by one.
    }
    
    std::vector<RecordCore> normalize(const Record &record/* , ParsingState?*/)
    {
        std::vector<RecordCore> records;

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

            // assertions / preconditions
            if (alternate.size() < 1) {
                throw new BodySectionError{record.line, "Alternate should not be empty"};
            }
            if (reference.size() < 1) {
                throw new BodySectionError{record.line, "Reference should not be empty"};
            }
            if (reference == alternate) {
                throw new BodySectionError{record.line, "Reference and alternate should not be identical"};
            }

            // count trailing matching bases using mismatch with reverse iterators
            std::pair<std::string::reverse_iterator, std::string::reverse_iterator> trail_mismatch_reverse = 
                    std::mismatch(reference.rbegin(), reference.rend(), alternate.rbegin());
            // trail_mismatch_reverse is zero: no equal trailing bases
            // trail_mismatch_reverse is rend: reference and alternate are equal: error
            std::pair<std::string::iterator, std::string::iterator> lead_mismatch_indices;
            if (reference.size() == alternate.size()) {
                // polymorphism

                std::string::iterator trail_mismatch_ref = make_forward(trail_mismatch_reverse.first);
                std::string::iterator trail_mismatch_alt = make_forward(trail_mismatch_reverse.second);
                lead_mismatch_indices = std::mismatch(reference.begin(), trail_mismatch_ref, alternate.begin());

                // +1 because end is not inclusive: [start, end), and we need to include the mismatch
                corrected_reference.assign(lead_mismatch_indices.first, trail_mismatch_ref+1);
                corrected_alternate.assign(lead_mismatch_indices.second, trail_mismatch_alt+1);
                corrected_position = position + (lead_mismatch_indices.first - reference.begin());

            } else if (reference.size() < alternate.size()){
                // insertion
                if (trail_mismatch_reverse.first == reference.rend()) {
                    // reference is a substring of alternate, located at the end of alternate
                    // need to reduce reference to 1 base, as trailing context
                    std::string::iterator trail_mismatch_ref = make_forward(trail_mismatch_reverse.first);
                    std::string::iterator trail_mismatch_alt = make_forward(trail_mismatch_reverse.second);
                    lead_mismatch_indices.first = reference.begin();
                    
                    corrected_reference.assign(reference.begin(), reference.begin()+1); // preconditions grant it's big enough
                    corrected_alternate.assign(trail_mismatch_alt, trail_mismatch_alt+1);
                    corrected_position = position + (lead_mismatch_indices.first - reference.begin());
                    corrected_reference.assign(lead_mismatch_indices.first, trail_mismatch_ref+1);
                    corrected_alternate.assign(lead_mismatch_indices.second, trail_mismatch_alt+1);
                    corrected_position = position + (lead_mismatch_indices.first - reference.begin());

                } else {

                    std::string::iterator trail_mismatch_ref = make_forward(trail_mismatch_reverse.first);
                    std::string::iterator trail_mismatch_alt = make_forward(trail_mismatch_reverse.second);
                    lead_mismatch_indices = std::mismatch(reference.begin(), trail_mismatch_ref, alternate.begin());

                    if (lead_mismatch_indices.first > reference.begin()
                        /* && lead_mismatch_indices.second > alternate.begin() */ ) {
                        // we leave an initial base for context
                        --lead_mismatch_indices.first;
                        --lead_mismatch_indices.second;
                    } else if (trail_mismatch_ref < reference.end() && trail_mismatch_alt < alternate.end()) {
                        // we leave a trailing base for context
                        ++trail_mismatch_ref;
                        ++trail_mismatch_alt;
                    }
                    
                    // +1 because end is not inclusive: [start, end), and we need to include the base pointed by trail_mismatch
                    corrected_reference.assign(lead_mismatch_indices.first, trail_mismatch_ref+1);
                    corrected_alternate.assign(lead_mismatch_indices.second, trail_mismatch_alt+1);
                    corrected_position = position + (lead_mismatch_indices.first - reference.begin());

                }

            } else {
                // deletion
                
            }
//            std::string::iterator trail_mismatch = make_forward(trail_mismatch_reverse.first);
//            lead_mismatch_indices = std::mismatch(reference.begin(), trail_mismatch, alternate.begin());

            records.emplace_back(record.line, record.chromosome, corrected_position,
                                 corrected_reference, corrected_alternate);
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



