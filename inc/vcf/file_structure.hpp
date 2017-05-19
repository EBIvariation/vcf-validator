/**
 * Copyright 2014-2015 EMBL - European Bioinformatics Institute
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

#ifndef VCF_FILE_STRUCTURE_HPP
#define VCF_FILE_STRUCTURE_HPP

#include <algorithm>
#include <cmath>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/variant.hpp>

#include "util/stream_utils.hpp"
#include "vcf/error.hpp"
#include "vcf/ploidy.hpp"

namespace ebi
{
  namespace vcf
  {
    struct Source;
    struct MetaEntry;
    struct Record;
    
    typedef std::multimap<std::string, MetaEntry>::iterator meta_iterator;

    enum InputFormat 
    {
        VCF_FILE_VCF    = 0x01,
        VCF_FILE_GVCF   = 0x02,
        VCF_FILE_GZIP   = 0x04,
        VCF_FILE_BGZIP  = 0x08,
        VCF_FILE_BCF    = 0x10,
    };
    
    enum class Version 
    {
        v41, 
        v42, 
        v43 
    };
    
    enum class RecordType
    {
        SNV,
        MNV,
        INDEL,
        STRUCTURAL,
        STRUCTURAL_BREAKEND,
        NO_VARIATION
    };
    
    const std::map<std::string, std::pair<std::string, std::string>> info_type = {
            { "AA", { "String", "INFO AA metadata Type is not String" } },
            { "AC", { "Integer", "INFO AC metadata Type is not Integer" } },
            { "AD", { "Integer", "INFO AD metadata Type is not Integer" } },
            { "ADF", { "Integer", "INFO ADF metadata Type is not Integer" } },
            { "ADR", { "Integer", "INFO ADR metadata Type is not Integer" } },
            { "AF", { "Float", "INFO AF metadata Type is not Float" } },
            { "AN", { "Integer", "INFO AN metadata Type is not Integer" } },
            { "BQ", { "Float", "INFO BQ metadata Type is not Float" } },
            { "CIGAR", { "String", "INFO CIGAR metadata Type is not String" } },
            { "DB", { "Flag", "INFO DB metadata Type is not Flag" } },
            { "DP", { "Integer", "INFO DP metadata Type is not Integer" } },
            { "END", { "Integer", "INFO END metadata Type is not Integer" } },
            { "H2", { "Flag", "INFO H2 metadata Type is not Flag" } },
            { "H3", { "Flag", "INFO H3 metadata Type is not Flag" } },
            // TODO : MQ metadata Type is .
            { "MQ0", { "Integer", "INFO MQ0 metadata Type is not Integer" } },
            { "NS", { "Integer", "INFO NS metadata Type is not Integer" } },
            // TODO : SB metadata Type is .
            { "SOMATIC", { "Flag", "INFO SOMATIC metadata Type is not Flag" } },
            { "VALIDATED", { "Flag", "INFO VALIDATED metadata Type is not Flag" } },
            { "1000G", { "Flag", "INFO 1000G metadata Type is not Flag" } }
    };

    const std::map<std::string, std::pair<std::string, std::string>> info_number = {
            { "AA", { "1", "INFO AA metadata Number is not 1" } },
            { "AC", { "A", "INFO AC metadata Number is not A" } },
            { "AD", { "R", "INFO AD metadata Number is not R" } },
            { "ADF", { "R", "INFO ADF metadata Number is not R" } },
            { "ADR", { "R", "INFO ADR metadata Number is not R" } },
            { "AF", { "A", "INFO AF metadata Number is not A" } },
            { "AN", { "1", "INFO AN metadata Number is not 1" } },
            { "BQ", { "1", "INFO BQ metadata Number is not 1" } },
            { "CIGAR", { "A", "INFO CIGAR metadata Number is not A" } },
            { "DB", { "0", "INFO DB metadata Number is not 0" } },
            { "DP", { "1", "INFO DP metadata Number is not 1" } },
            { "END", { "1", "INFO END metadata Number is not 1" } },
            { "H2", { "0", "INFO H2 metadata Number is not 0" } },
            { "H3", { "0", "INFO H3 metadata Number is not 0" } },
            { "MQ", { "1", "INFO MQ metadata Number is not 1" } },
            { "MQ0", { "1", "INFO MQ0 metadata Number is not 1" } },
            { "NS", { "1", "INFO NS metadata Number is not 1" } },
            // TODO : SB metadata Number is .
            { "SOMATIC", { "0", "INFO SOMATIC metadata Number is not 0" } },
            { "VALIDATED", { "0", "INFO VALIDATED metadata Number is not 0" } },
            { "1000G", { "0", "INFO 1000G metadata Number is not 0" } }
    };
    
    struct MetaEntry
    {
        enum class Structure { NoValue, PlainValue, KeyValue };

        size_t line;
        
        std::string id;
        Structure structure; // Union discriminant
        
        boost::variant< std::string, 
                        std::map<std::string, std::string> > value;
        
        MetaEntry(size_t line,
                  std::string const & id);
        
        MetaEntry(size_t line,
                  std::string const & id,
                  std::string const & plain_value);
        
        MetaEntry(size_t line,
                  std::string const & id,
                  std::map<std::string, std::string> const & key_values);
        
        bool operator==(MetaEntry const &) const;

        bool operator!=(MetaEntry const &) const;
        
    private:
        /**
         * Checks that the entry value satisfies the VCF specification.
         * 
         * @throw std::invalid_argument
         */
        void check_value();
    };
    
    struct Source 
    {
        std::string name;           /**< Name of the source to interact with (file, stdin...) */
        unsigned int input_format;  /**< Mask that stores whether the input is plain/gzipped VCF, BCF, etc */
        Version version;            /**< VCF version */
        Ploidy ploidy;              /**< Class that keeps track of the ploidy of every contig */

        std::multimap<std::string, MetaEntry> meta_entries; /**< Entries in the file meta-data */
        std::vector<std::string> samples_names; /**< Names of the sequenced samples */
        
        Source(std::string const & name,
               unsigned const input_format,
               Version version,
               Ploidy ploidy,
               std::multimap<std::string, MetaEntry> const & meta_entries = {},
               std::vector<std::string> const & samples_names = {});
        
    };
    
    struct Record 
    {
        size_t line;

        std::string chromosome;
        size_t position;
        std::vector<std::string> ids;

        std::string reference_allele;
        std::vector<std::string> alternate_alleles;
        std::vector<RecordType> types;
        
        float quality;
        std::vector<std::string> filters;
        std::map<std::string, std::string> info;
        std::vector<std::string> format;

        std::vector<std::string> samples;

        std::shared_ptr<Source> source;

        Record(size_t line,
                std::string const & chromosome,
                size_t position,
                std::vector<std::string> const & ids,
                std::string const & reference_allele,
                std::vector<std::string> const & alternate_alleles,
                float quality,
                std::vector<std::string> const & filters,
                std::map<std::string, std::string> const & info,
                std::vector<std::string> const & format,
                std::vector<std::string> const & samples,
                std::shared_ptr<Source> source);
        
        bool operator==(Record const &) const;

        bool operator!=(Record const &) const;
        
    private:
        
        void set_types();
        
        /**
         * Checks that chromosome does not contain colons or white-spaces
         * 
         * @throw ChromosomeBodyError
         */
        void check_chromosome() const;

        /**
         * Checks that chromosome does not contain any colons
         * 
         * @throw ChromosomeBodyError
         */
        void check_chromosome_no_colons() const;

        /**
         * Checks that chromosome does not contain any white-spaces
         * 
         * @throw ChromosomeBodyError
         */
        void check_chromosome_no_whitespaces() const;

        /**
         * Checks that IDs are alphanumeric and do not contain duplicate values
         * 
         * @throw IdBodyError
         */
        void check_ids() const;
        
        /**
         * Checks that ID contains no semicolons or white-spaces
         * 
         * @throw IdBodyError
         */
        void check_ids_no_semicolons_whitespaces() const;

        /**
         * Checks that ID contains no duplicate values in the same line
         * 
         * @throw IdBodyError
         */
        void check_ids_no_duplicates() const;

        /**
         * Checks the structure of an alternate allele and its accordance to the meta section
         * 
         * @throw AlternateAllelesBodyError
         */
        void check_alternate_alleles() const;
        
        /**
         * Checks the structure of an alternate allele against the reference:
         * - The dot is not combined with others
         * - Is not the same as the reference
         * - Shares the first nucleotide with the reference (does not apply to SV, break-ends and custom ALTs)
         * 
         * @throw AlternateAllelesBodyError
         */
        void check_alternate_allele_structure(std::string const & alternate, RecordType type) const;
        
        /**
         * Check that alternates of the form <SOME_ALT> begin with DEL, INS, DUP, INV or CNV
         * 
         * @throw AlternateAllelesBodyError
         */
        void check_alternate_allele_symbolic_prefix(std::string const & alternate) const;
        
        /**
         * Checks that quality is zero or greater
         * 
         * @throw QualityBodyError
         */
        void check_quality() const;
        
        /**
         * Checks that all the filters are listed in the meta section
         * 
         * @throw FilterBodyError
         */
        void check_filter() const;
        
        /**
         * Checks that all the INFO fields are listed in the meta section, and their number and 
         * type match those specifications
         * 
         * @throw InfoBodyError
         */
        void check_info() const;
        
        /**
         * Checks that format starts with GT and has no duplicate fields
         * 
         * @throw FormatBodyError
         */
        void check_format() const;

        /**
         * Checks that GT is the first field in the FORMAT column
         * 
         * @throw FormatBodyError
         */
        void check_format_GT() const;

        /**
         * Checks that format has no duplicate fields
         * 
         * @throw FormatBodyError
         */
        void check_format_no_duplicates() const;

        /**
         * Checks that the samples in the record:
         * - Are the same number as specified in the Source object
         * - Their allele indexes are not greater than the total number of alleles
         * - The number and type of the fields match the FORMAT meta information
         * 
         * @throw SamplesBodyError
         */
        void check_samples() const;

        /**
         * Checks that the number of samples matches those listed in the header line
         * 
         * @throw SamplesBodyError
         */
        void check_samples_count() const;

        /**
         * Returns a vector of MetaEntry objects in the same order as they are displayed in the samples
         */
        std::vector<MetaEntry> get_meta_entry_objects() const;

        /**
         * Checks the sample contents and accordance to the meta section
         * 
         * @throw SamplesBodyError
         * @throw SamplesFieldBodyError
         */
        void check_sample(size_t i, std::vector<MetaEntry> const & format_meta) const;

        /**
         * Checks that the number of subfields in the sample is not greater than the number in the FORMAT column
         * 
         * @throw SamplesBodyError
         */
        void check_sample_subfields_count(size_t i, std::vector<std::string> const & subfields) const;

        /**
         * Checks that the cardinality and type of the fields in the sample match the FORMAT meta information
         * 
         * @throw SamplesFieldBodyError
         */
        void check_sample_subfields_cardinality_type(size_t i, std::vector<std::string> const & subfields, std::vector<MetaEntry> const & format_meta) const;
        
        /**
         * Check that the allele indexes in a sample are not greater than the total number of alleles
         * 
         * @throw SamplesFieldBodyError
         */
        void check_sample_alleles(std::vector<std::string> const & subfields) const;

        /**
         * Checks that the allele index in a sample is an integer number
         * 
         * @throw SamplesFieldBodyError
         */        
        void check_sample_alleles_is_integer(std::string const & allele, long ploidy) const;

        /**
         * Checks that the allele index is in range
         * 
         * @throw SamplesFieldBodyError
         */
        void check_sample_alleles_range(std::string const & allele, long ploidy) const;

        /**
         * Checks that every field in a sample matches the Number specification in the FORMAT meta
         * 
         * @throw std::invalid_argument
         */
        void check_field_cardinality(std::string const & field,
                                     std::vector<std::string> const & values,
                                     std::string const & number, 
                                     size_t ploidy) const;
        
        /**
         * Checks that every field in a column matches the Type specification in the meta
         * 
         * @throw std::invalid_argument
         */
        void check_field_type(std::string const & field,
                              std::vector<std::string> const & values,
                              std::string const & type) const;
    };

    /**
     * returns the expected number of elements, given a string code
     * @param number one of ["A", "R", "G", ".", number], where
     *  - "A" is the amount of alleles,
     *  - "R" the amount of reference (1) plus alleles (A)
     *  - "G" is `ploidy`-combination with repetition: ((R + ploidy -1) choose ploidy)
     *  (e.g. with 1 reference, 2 alternate alleles (3 total alleles) and ploidy 2, it's 3 + 2 -1 choose 2, which is 6: 00, 01, 11, 02, 12, 22)
     *  - "." means unknown number of elements
     *  - number is a positive number [0, +inf)
     * @param ploidy is the number of sets of chromosomes, so a given position in a chromosome needs `ploidy` bases to be completely specified
     * @param cardinality return by reference [0, +inf) for valid numbers. -1 if unknown number. throws std::invalid_argument if it's not a number or std::out_of_range if it's out of range.
     * @return bool: whether the number was valid or not
     */
    bool is_valid_cardinality(const std::string &number, size_t alternate_allele_number, size_t ploidy, long &cardinality);

    std::ostream &operator<<(std::ostream &os, const Record &record);

  }
}

#endif // VCF_FILE_STRUCTURE_HPP

