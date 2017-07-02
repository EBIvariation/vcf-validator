/**
 * Copyright 2014-2017 EMBL - European Bioinformatics Institute
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

    const std::map<std::string, std::pair<std::string, std::string>> info_v41_v42 = {
            { "AA", { "String", "1" } },
            { "AC", { "Integer", "A" } },
            { "AF", { "Float", "A" } },
            { "AN", { "Integer", "1" } },
            { "BKPTID", { "String", "." } },
            { "BQ", { "Float", "1" } },
            { "CICN", { "Integer", "2" } },
            { "CICNADJ", { "Integer", "." } },
            { "CIEND", { "Integer", "2" } },
            { "CIGAR", { "String", "A" } },
            { "CILEN", { "Integer", "2" } },
            { "CIPOS", { "Integer", "2" } },
            { "CN", { "Integer", "1" } },
            { "CNADJ", { "Integer", "." } },
            { "DB", { "Flag", "0" } },
            { "DBRIPID", { "String", "1" } },
            { "DBVARID", { "String", "1" } },
            { "DGVID", { "String", "1" } },
            { "DP", { "Integer", "1" } },
            { "DPADJ", { "Integer", "." } },
            { "END", { "Integer", "1" } },
            { "EVENT", { "String", "1" } },
            { "HOMLEN", { "Integer", "." } },
            { "HOMSEQ", { "String", "." } },
            { "H2", { "Flag", "0" } },
            { "H3", { "Flag", "0" } },
            { "IMPRECISE", { "Flag", "0" } },
            { "MATEID", { "String", "." } },
            { "MEINFO", { "String", "4" } },
            { "METRANS", { "String", "4" } },
            { "MQ", { ".", "1" } },
            { "MQ0", { "Integer", "1" } },
            { "NOVEL", { "Flag", "0" } },
            { "NS", { "Integer", "1" } },
            { "PARID", { "String", "1" } },
            // TODO : SB metadata Type and Number is .
            { "SOMATIC", { "Flag", "0" } },
            { "SVLEN", { "Integer", "." } },
            { "SVTYPE", { "String", "1" } },
            { "VALIDATED", { "Flag", "0" } },
            { "1000G", { "Flag", "0" } }
    };

    const std::map<std::string, std::pair<std::string, std::string>> info_v43 = {
            { "AA", { "String", "1" } },
            { "AC", { "Integer", "A" } },
            { "AD", { "Integer", "R" } },
            { "ADF", { "Integer", "R" } },
            { "ADR", { "Integer", "R" } },
            { "AF", { "Float", "A" } },
            { "AN", { "Integer", "1" } },
            { "BKPTID", { "String", "." } },
            { "BQ", { "Float", "1" } },
            { "CICN", { "Integer", "2" } },
            { "CICNADJ", { "Integer", "." } },
            { "CIEND", { "Integer", "2" } },
            { "CIGAR", { "String", "A" } },
            { "CILEN", { "Integer", "2" } },
            { "CIPOS", { "Integer", "2" } },
            { "CN", { "Integer", "1" } },
            { "CNADJ", { "Integer", "." } },
            { "DB", { "Flag", "0" } },
            { "DBRIPID", { "String", "1" } },
            { "DBVARID", { "String", "1" } },
            { "DGVID", { "String", "1" } },
            { "DP", { "Integer", "1" } },
            { "DPADJ", { "Integer", "." } },
            { "END", { "Integer", "1" } },
            { "EVENT", { "String", "1" } },
            { "HOMLEN", { "Integer", "." } },
            { "HOMSEQ", { "String", "." } },
            { "H2", { "Flag", "0" } },
            { "H3", { "Flag", "0" } },
            { "IMPRECISE", { "Flag", "0" } },
            { "MATEID", { "String", "." } },
            { "MEINFO", { "String", "4" } },
            { "METRANS", { "String", "4" } },
            { "MQ", { ".", "1" } },
            { "MQ0", { "Integer", "1" } },
            { "NOVEL", { "Flag", "0" } },
            { "NS", { "Integer", "1" } },
            { "PARID", { "String", "1" } },
            // TODO : SB metadata Type and Number is .
            { "SOMATIC", { "Flag", "0" } },
            { "SVLEN", { "Integer", "." } },
            { "SVTYPE", { "String", "1" } },
            { "VALIDATED", { "Flag", "0" } },
            { "1000G", { "Flag", "0" } }
    };

    const std::map<std::string, std::pair<std::string, std::string>> format_v41_v42 = {
            { "AHAP", { "Integer", "1" } },
            { "CN", { "Integer", "1" } },
            { "CNL", { "Float", "." } },
            { "CNQ", { "Float", "1" } },
            { "DP", { "Integer", "1" } },
            { "EC", { "Integer", "A" } },
            { "FT", { "String", "1" } },
            { "GL", { "Float", "G" } },
            { "GP", { "Float", "G" } },
            { "GQ", { "Integer", "1" } },
            { "GT", { "String", "1" } },
            { "HAP", { "Integer", "1" } },
            { "HQ", { "Integer", "2" } },
            { "MQ", { "Integer", "1"} },
            { "NQ", { "Integer", "1" } },
            { "PL", { "Integer", "G"} },
            { "PQ", { "Integer", "1" } },
            { "PS", { "Integer", "1" } }
   };

    const std::map<std::string, std::pair<std::string, std::string>> format_v43 = {
            { "AD", { "Integer", "R" } },
            { "ADF", { "Integer", "R" } },
            { "ADR", { "Integer", "R" } },
            { "AHAP", { "Integer", "1" } },
            { "CN", { "Integer", "1" } },
            { "CNL", { "Float", "G" } },
            { "CNP", { "Float", "G" } },
            { "CNQ", { "Float", "1" } },
            { "DP", { "Integer", "1" } },
            { "EC", { "Integer", "A" } },
            { "FT", { "String", "1" } },
            { "GL", { "Float", "G" } },
            { "GP", { "Float", "G" } },
            { "GQ", { "Integer", "1" } },
            { "GT", { "String", "1" } },
            { "HAP", { "Integer", "1" } },
            { "HQ", { "Integer", "2" } },
            { "MQ", { "Integer", "1" } },
            { "NQ", { "Integer", "1" } },
            { "PL", { "Integer", "G" } },
            { "PQ", { "Integer", "1" } },
            { "PS", { "Integer", "1" } }
    };

    struct MetaEntry
    {
        enum class Structure { NoValue, PlainValue, KeyValue };

        size_t line;
        
        std::string id;
        Structure structure; // Union discriminant

        boost::variant< std::string, 
                        std::map<std::string, std::string> > value;

        std::shared_ptr<Source> source;
        
        MetaEntry(size_t line,
                  std::string const & id,
                  std::shared_ptr<Source> source);
        
        MetaEntry(size_t line,
                  std::string const & id,
                  std::string const & plain_value,
                  std::shared_ptr<Source> source);
        
        MetaEntry(size_t line,
                  std::string const & id,
                  std::map<std::string, std::string> const & key_values,
                  std::shared_ptr<Source> source);
        
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
         * Checks that all the filters are listed in the meta section and do not contain duplicates
         * 
         * @throw FilterBodyError
         */
        void check_filter() const;
        
        /**
         * Checks that FILTER contains no duplicate failed filters
         * 
         * @throw FilterBodyError
         */
        void check_filter_no_duplicates() const;

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
         * Checks that predefined tags are consistent with the specification
         *
         * @throw std::invalid_argument
         */
        void check_predefined_tag(std::string const & field_key, std::string const & field_value, std::vector<std::string> const & values,
                                  std::map<std::string, std::pair<std::string, std::string>> const & tags) const;

        /**
         * Strict validation of predefined INFO tags
         *
         * @throw InfoBodyError
         */
        void strict_validation_info_predefined_tags(std::string const & field_key, std::string const & field_value) const;

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
         * Checks that fields have no duplicates
         *
         * @throw Error
         */
        void check_no_duplicates(std::vector<std::string> const & values) const;

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
         * @param cardinality return by reference [0, +inf) for valid numbers. -1 if unknown number. 
         * @throw std::invalid_argument if it's not a number
         * @throw std::out_of_range if it's out of range.
         * @return bool: whether the number was valid or not
         */
        bool is_valid_cardinality(std::string const & number, size_t alternate_allele_number, long & cardinality) const;

        /**
         * Checks that the values match either their type specified in the meta or the VCF specification for predefined tags not in meta
         */
        void check_value_type(std::string const & type, std::string const & value, std::string & message) const;


        /**
         * Checks that every field in a sample matches the Number specification in the meta
         * Or if it is not present in the meta and is a predefined tag, check that it matches the VCF specification
         * 
         * @throw std::invalid_argument
         */
        void check_field_cardinality(std::string const & field,
                                     std::vector<std::string> const & values,
                                     std::string const & number) const;
        
        /**
         * Checks that every field in a column matches the Type specification in the meta
         * Or if it is not present in the meta and is a predefined tag, check that it matches the VCF specification
         *
         * @throw std::invalid_argument
         */
        void check_field_type(std::vector<std::string> const & values,
                              std::string const & type) const;

        /**
         * Checks that predefined tags with Type Integer have non-negative values
         *
         * @throw std::invalid_argument
         */
        void check_field_integer_range(std::string const & field, std::vector<std::string> const & value) const;
    };

    std::ostream &operator<<(std::ostream &os, const Record &record);

  }
}

#endif // VCF_FILE_STRUCTURE_HPP

