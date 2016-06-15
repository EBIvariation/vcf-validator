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

                // trail_match_* point to the first match of the trailing bases
                // +1 because end is not inclusive: [start, end), and we need to include the mismatch
                std::string::iterator trail_match_ref = make_forward(trail_mismatch_reverse.first) + 1;
                std::string::iterator trail_match_alt = make_forward(trail_mismatch_reverse.second) + 1;
                lead_mismatch_indices = std::mismatch(reference.begin(), trail_match_ref, alternate.begin());

                corrected_reference.assign(lead_mismatch_indices.first, trail_match_ref);
                corrected_alternate.assign(lead_mismatch_indices.second, trail_match_alt);
                corrected_position = position + (lead_mismatch_indices.first - reference.begin());

            } else if (reference.size() < alternate.size()) {
                // insertion
                std::string::iterator trail_match_ref;
                std::string::iterator trail_match_alt;
                if (trail_mismatch_reverse.first == reference.rend()) {
                    // reference is a substring of alternate, located at the end of alternate
                    // need to reduce reference to empty string

                    // trail_match_* point to the first match of the trailing bases
                    // -1/+1 because end is not inclusive: [start, end), and we need to include the mismatch
                    trail_match_ref = make_forward(trail_mismatch_reverse.first - 1);
                    trail_match_alt = make_forward(trail_mismatch_reverse.second) + 1;
                    lead_mismatch_indices.first = reference.begin(); // == trail_match_ref
                    lead_mismatch_indices.second = alternate.begin();
                } else {
                    // There is at least 1 base mismatch before trailing mismatch, it may be leading context, or a change

                    // trail_match_* point to the first match of the trailing bases
                    // +1 because end is not inclusive: [start, end), and we need to include the mismatch
                    trail_match_ref = make_forward(trail_mismatch_reverse.first) + 1;
                    trail_match_alt = make_forward(trail_mismatch_reverse.second) + 1;
                    lead_mismatch_indices = std::mismatch(reference.begin(), trail_match_ref, alternate.begin());
                }
                
                corrected_reference.assign(lead_mismatch_indices.first, trail_match_ref);
                corrected_alternate.assign(lead_mismatch_indices.second, trail_match_alt);
                corrected_position = position + (lead_mismatch_indices.first - reference.begin());
            } else {
                // deletion

                std::string::iterator trail_match_ref;
                std::string::iterator trail_match_alt;
                if (trail_mismatch_reverse.second == alternate.rend()) {
                    // alternate is a substring of reference, located at the end of reference
                    // need to reduce alternate to empty string

                    // trail_match_* point to the first match of the trailing bases
                    // +1/-1 because end is not inclusive: [start, end), and we need to include the mismatch
                    trail_match_ref = make_forward(trail_mismatch_reverse.first) + 1;
                    trail_match_alt = make_forward(trail_mismatch_reverse.second - 1);
                    lead_mismatch_indices.first = reference.begin();
                    lead_mismatch_indices.second = alternate.begin(); // == trail_match_alt
                } else {
                    // There is at least 1 base mismatch before trailing mismatch, it may be leading context, or a change

                    // trail_match_* point to the first match of the trailing bases
                    // +1 because end is not inclusive: [start, end), and we need to include the mismatch
                    trail_match_ref = make_forward(trail_mismatch_reverse.first) + 1;
                    trail_match_alt = make_forward(trail_mismatch_reverse.second) + 1;
                    lead_mismatch_indices = std::mismatch(reference.begin(), trail_match_ref, alternate.begin());
                }
                
                corrected_reference.assign(lead_mismatch_indices.first, trail_match_ref);
                corrected_alternate.assign(lead_mismatch_indices.second, trail_match_alt);
                corrected_position = position + (lead_mismatch_indices.first - reference.begin());
            }

            records.emplace_back(record.line, record.chromosome, corrected_position,
                                 corrected_reference, corrected_alternate);
        }

        return std::move(records);
    }
  }
}



