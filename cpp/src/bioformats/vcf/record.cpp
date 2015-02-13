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
        for (auto & id : ids) {
            if (find_if(id.begin(), id.end(), [](char c) { return !isalnum(c); }) != id.end()) {
                throw std::invalid_argument("ID must be alphanumeric");
            }
        }
    }

    void Record::check_alternate_alleles() const
    {
        for (auto & alternate : alternate_alleles) {
            if (std::count(alternate.begin(), alternate.end(), '[') == 2 || 
                std::count(alternate.begin(), alternate.end(), ']') == 2) { 
                continue; // Break-ends can't be checked against the reference
            } else if (alternate == ".") {
                if (alternate_alleles.size() > 1) {
                    throw std::invalid_argument("The no-alternate alleles symbol (dot) can not be combined with others");
                }
            } else if (alternate[0] != reference_allele[0] && alternate.size() != reference_allele.size()) {
                throw std::invalid_argument("Reference and alternate alleles must share the first nucleotide");
            } else if (alternate == reference_allele) {
                throw std::invalid_argument("Reference and alternate alleles must not be the same");
            }
        }
    }

    void Record::check_quality() const
    {
        if (quality < 0) {
            throw std::invalid_argument("Quality must be equal or greater than zero");
        }
    }
    
    void Record::check_format() const
    {
        if (format[0] != "GT") {
            throw std::invalid_argument("Format first field must be the genotype (GT)");
        }
    }

    void Record::check_samples() const
    {
        if (samples.size() != source->samples_names.size()) {
            throw std::invalid_argument("The number of samples must match those listed in the header line");
        }
    }
  }
}
