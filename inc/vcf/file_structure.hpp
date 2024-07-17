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
#include <set>

#include "util/stream_utils.hpp"
#include "vcf/error.hpp"
#include "vcf/string_constants.hpp"

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
        v43,
        v44
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
            { AA, { STRING, "1" } },
            { AC, { INTEGER, A } },
            { AF, { FLOAT, A } },
            { AN, { INTEGER, "1" } },
            { BKPTID, { STRING, UNKNOWN_CARDINALITY } },
            { BQ, { FLOAT, "1" } },
            { CICN, { INTEGER, "2" } },
            { CICNADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { CIEND, { INTEGER, "2" } },
            { CIGAR, { STRING, A } },
            { CILEN, { INTEGER, "2" } },
            { CIPOS, { INTEGER, "2" } },
            { CN, { INTEGER, "1" } },
            { CNADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { DB, { FLAG, "0" } },
            { DBRIPID, { STRING, "1" } },
            { DBVARID, { STRING, "1" } },
            { DGVID, { STRING, "1" } },
            { DP, { INTEGER, "1" } },
            { DPADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { END, { INTEGER, "1" } },
            { EVENT, { STRING, "1" } },
            { HOMLEN, { INTEGER, UNKNOWN_CARDINALITY } },
            { HOMSEQ, { STRING, UNKNOWN_CARDINALITY } },
            { H2, { FLAG, "0" } },
            { H3, { FLAG, "0" } },
            { IMPRECISE, { FLAG, "0" } },
            { MATEID, { STRING, UNKNOWN_CARDINALITY } },
            { MEINFO, { STRING, "4" } },
            { METRANS, { STRING, "4" } },
            { MQ, { MISSING_VALUE, "1" } },
            { MQ0, { INTEGER, "1" } },
            { NOVEL, { FLAG, "0" } },
            { NS, { INTEGER, "1" } },
            { PARID, { STRING, "1" } },
            // TODO : SB metadata Type and Number is "."
            { SOMATIC, { FLAG, "0" } },
            { SVLEN, { INTEGER, UNKNOWN_CARDINALITY } },
            { SVTYPE, { STRING, "1" } },
            { VALIDATED, { FLAG, "0" } },
            { THOUSAND_G, { FLAG, "0" } }
    };

    const std::map<std::string, std::pair<std::string, std::string>> info_v43 = {
            { AA, { STRING, "1" } },
            { AC, { INTEGER, A } },
            { AD, { INTEGER, R } },
            { ADF, { INTEGER, R } },
            { ADR, { INTEGER, R } },
            { AF, { FLOAT, A } },
            { AN, { INTEGER, "1" } },
            { BKPTID, { STRING, UNKNOWN_CARDINALITY } },
            { BQ, { FLOAT, "1" } },
            { CICN, { INTEGER, "2" } },
            { CICNADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { CIEND, { INTEGER, "2" } },
            { CIGAR, { STRING, A } },
            { CILEN, { INTEGER, "2" } },
            { CIPOS, { INTEGER, "2" } },
            { CN, { INTEGER, "1" } },
            { CNADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { DB, { FLAG, "0" } },
            { DBRIPID, { STRING, "1" } },
            { DBVARID, { STRING, "1" } },
            { DGVID, { STRING, "1" } },
            { DP, { INTEGER, "1" } },
            { DPADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { END, { INTEGER, "1" } },
            { EVENT, { STRING, "1" } },
            { HOMLEN, { INTEGER, UNKNOWN_CARDINALITY } },
            { HOMSEQ, { STRING, UNKNOWN_CARDINALITY } },
            { H2, { FLAG, "0" } },
            { H3, { FLAG, "0" } },
            { IMPRECISE, { FLAG, "0" } },
            { MATEID, { STRING, UNKNOWN_CARDINALITY } },
            { MEINFO, { STRING, "4" } },
            { METRANS, { STRING, "4" } },
            { MQ, { MISSING_VALUE, "1" } },
            { MQ0, { INTEGER, "1" } },
            { NOVEL, { FLAG, "0" } },
            { NS, { INTEGER, "1" } },
            { PARID, { STRING, "1" } },
            // TODO : SB metadata Type and Number is "."
            { SOMATIC, { FLAG, "0" } },
            { SVLEN, { INTEGER, UNKNOWN_CARDINALITY } },
            { SVTYPE, { STRING, "1" } },
            { VALIDATED, { FLAG, "0" } },
            { THOUSAND_G, { FLAG, "0" } }
    };

    const std::map<std::string, std::pair<std::string, std::string>> info_v44 = {
            { AA, { STRING, "1" } },
            { AC, { INTEGER, A } },
            { AD, { INTEGER, R } },
            { ADF, { INTEGER, R } },
            { ADR, { INTEGER, R } },
            { AF, { FLOAT, A } },
            { AN, { INTEGER, "1" } },
            { BKPTID, { STRING, UNKNOWN_CARDINALITY } },
            { BQ, { FLOAT, "1" } },
            { CICN, { INTEGER, "2" } },
            { CICNADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { CIEND, { INTEGER, "2" } },
            { CIGAR, { STRING, A } },
            { CILEN, { INTEGER, "2" } },
            { CIPOS, { INTEGER, "2" } },
            { CN, { FLOAT, "A" } },
            { CNADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { DB, { FLAG, "0" } },
            { DBRIPID, { STRING, "1" } },
            { DBVARID, { STRING, "1" } },
            { DGVID, { STRING, "1" } },
            { DP, { INTEGER, "1" } },
            { DPADJ, { INTEGER, UNKNOWN_CARDINALITY } },
            { END, { INTEGER, "1" } },
            { EVENT, { STRING, "1" } },
            { HOMLEN, { INTEGER, UNKNOWN_CARDINALITY } },
            { HOMSEQ, { STRING, UNKNOWN_CARDINALITY } },
            { H2, { FLAG, "0" } },
            { H3, { FLAG, "0" } },
            { IMPRECISE, { FLAG, "0" } },
            { MATEID, { STRING, UNKNOWN_CARDINALITY } },
            { MEINFO, { STRING, "4" } },
            { METRANS, { STRING, "4" } },
            { MQ, { MISSING_VALUE, "1" } },
            { MQ0, { INTEGER, "1" } },
            { NOVEL, { FLAG, "0" } },
            { NS, { INTEGER, "1" } },
            { PARID, { STRING, "1" } },
            // TODO : SB metadata Type and Number is "."
            { SOMATIC, { FLAG, "0" } },
            { SVLEN, { INTEGER, "A" } },
            { SVTYPE, { STRING, "1" } },
            { VALIDATED, { FLAG, "0" } },
            { THOUSAND_G, { FLAG, "0" } },
            { SVCLAIM, { STRING, "A" } },
            { RN, { INTEGER, "A" } },
            { RUS, { STRING, UNKNOWN_CARDINALITY } },
            { RUL, { INTEGER, UNKNOWN_CARDINALITY } },
            { RUC, { FLOAT, UNKNOWN_CARDINALITY } },
            { RB, { INTEGER, UNKNOWN_CARDINALITY } },
            { CIRUC, { FLOAT, UNKNOWN_CARDINALITY } },
            { CIRB, { INTEGER, UNKNOWN_CARDINALITY } },
            { RUB, { INTEGER, UNKNOWN_CARDINALITY } }
    };

    const std::map<std::string, std::pair<std::string, std::string>> format_v41_v42 = {
            { AHAP, { INTEGER, "1" } },
            { CN, { INTEGER, "1" } },
            { CNL, { FLOAT, UNKNOWN_CARDINALITY } },
            { CNQ, { FLOAT, "1" } },
            { DP, { INTEGER, "1" } },
            { EC, { INTEGER, A } },
            { FT, { STRING, "1" } },
            { GL, { FLOAT, G } },
            { GLE, { STRING, G } },
            { GP, { FLOAT, G } },
            { GQ, { INTEGER, "1" } },
            { GT, { STRING, "1" } },
            { HAP, { INTEGER, "1" } },
            { HQ, { INTEGER, "2" } },
            { MQ, { INTEGER, "1" } },
            { NQ, { INTEGER, "1" } },
            { PL, { INTEGER, G } },
            { PQ, { INTEGER, "1" } },
            { PS, { INTEGER, "1" } }
    };

    const std::map<std::string, std::pair<std::string, std::string>> format_v43 = {
            { AD, { INTEGER, R } },
            { ADF, { INTEGER, R } },
            { ADR, { INTEGER, R } },
            { AHAP, { INTEGER, "1" } },
            { CN, { INTEGER, "1" } },
            { CNL, { FLOAT, G } },
            { CNP, { FLOAT, G } },
            { CNQ, { FLOAT, "1" } },
            { DP, { INTEGER, "1" } },
            { EC, { INTEGER, A } },
            { FT, { STRING, "1" } },
            { GL, { FLOAT, G } },
            { GP, { FLOAT, G } },
            { GQ, { INTEGER, "1" } },
            { GT, { STRING, "1" } },
            { HAP, { INTEGER, "1" } },
            { HQ, { INTEGER, "2" } },
            { MQ, { INTEGER, "1" } },
            { NQ, { INTEGER, "1" } },
            { PL, { INTEGER, G } },
            { PQ, { INTEGER, "1" } },
            { PS, { INTEGER, "1" } }
    };

    const std::map<std::string, std::pair<std::string, std::string>> format_v44 = {
            { AD, { INTEGER, R } },
            { ADF, { INTEGER, R } },
            { ADR, { INTEGER, R } },
            { AHAP, { INTEGER, "1" } },
            { CN, { FLOAT, "1" } },
            { CNL, { FLOAT, G } },
            { CNP, { FLOAT, G } },
            { CNQ, { FLOAT, "1" } },
            { DP, { INTEGER, "1" } },
            { EC, { INTEGER, A } },
            { FT, { STRING, "1" } },
            { GL, { FLOAT, G } },
            { GP, { FLOAT, G } },
            { GQ, { INTEGER, "1" } },
            { GT, { STRING, "1" } },
            { HAP, { INTEGER, "1" } },
            { HQ, { INTEGER, "2" } },
            { MQ, { INTEGER, "1" } },
            { NQ, { INTEGER, "1" } },
            { PL, { INTEGER, G } },
            { PQ, { INTEGER, "1" } },
            { PS, { INTEGER, "1" } }
    };

    const std::set<std::string> PREDEFINED_INFO_SVTYPES{
            DEL,
            INS,
            DUP,
            INV,
            CNV,
            BND,
    };
    // symbolic structural variants as per v44
    const std::set<std::string> PREDEFINED_INFO_SV_v44{
            DEL,
            INS,
            DUP,
            INV,
            CNV,
    };
    // mapping of allele to svclaim values
    const std::map<std::string, const std::set<std::string>> PREDEFINED_INFO_ALLELE_SVCLAIM{
            { DEL, { D, J, DJ } },
            { DUP, { D, J, DJ } },
            { CNV, { D, MISSING_VALUE } },
            { INV, { J, DJ, MISSING_VALUE } },
            { INS, { J, DJ, MISSING_VALUE } },
            { _BRKEND, { J, MISSING_VALUE } },          //breakends
            { _OTHER, { MISSING_VALUE } }               //anything else - including seq alleles
    };

    inline std::string const &get_predefined_type(
            std::map<std::string, std::pair<std::string, std::string>>::const_iterator const &predefined_tag)
    {
        return predefined_tag->second.first;
    }

    inline std::string const &get_predefined_number(
            std::map<std::string, std::pair<std::string, std::string>>::const_iterator const &predefined_tag)
    {
        return predefined_tag->second.second;
    }

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

        bool is_defined_in_header() const;

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

        std::multimap<std::string, MetaEntry> meta_entries; /**< Entries in the file meta-data */
        std::vector<std::string> samples_names; /**< Names of the sequenced samples */

        Source(std::string const & name,
               unsigned const input_format,
               Version version,
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
        std::multimap<std::string, std::string> info;
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
                std::multimap<std::string, std::string> const & info,
                std::vector<std::string> const & format,
                std::vector<std::string> const & samples,
                std::shared_ptr<Source> source);

        bool operator==(Record const &) const;

        bool operator!=(Record const &) const;

    private:

        void set_types();

        /**
         * Checks that chromosome does not contain white-spaces
         *
         * @throw ChromosomeBodyError
         */
        void check_chromosome() const;

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
         * Checks that all the filters are listed in the meta section, do not contain duplicates and are non-zero
         *
         * @throw FilterBodyError
         */
        void check_filter() const;

        /**
         * Checks that FILTER contains no duplicate failed filters in the same line
         *
         * @throw FilterBodyError
         */
        void check_filter_no_duplicates() const;

        /**
         * Check that FILTER values are non-zero, as 0 is reserved and must not be used
         *
         * @throw FilterBodyError
         */
        void check_filter_not_zero() const;

        /**
         * Checks that all the INFO fields are listed in the meta section, their number and
         * type match those specifications, and contain no duplicates
         *
         * @throw InfoBodyError
         */
        void check_info() const;

        /**
         * Checks that INFO contains no duplicate keys in the same line
         *
         * @throw InfoBodyError
         */
        void check_info_no_duplicates() const;

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
         * Checks that format has no duplicate fields in the same line
         *
         * @throw FormatBodyError
         */
        void check_format_no_duplicates() const;

        /**
         * Checks that INFO predefined tags are consistent with the specification
         */
        void check_predefined_tag_info(std::string const &field_key, std::vector<std::string> const &values,
                                       std::map<std::string, std::pair<std::string, std::string>> const &tags) const;

        /**
         * Checks that FORMAT predefined tags are consistent with the specification
         */
        void check_predefined_tag_format(std::string const &field_key, std::vector<std::string> const &values,
                                         std::map<std::string, std::pair<std::string, std::string>> const &tags,
                                         size_t ploidy) const;
        /**
         * Strict validation of predefined INFO tags
         *
         * @throw InfoBodyError
         */
        void strict_validation_info_predefined_tags(std::string const & field_key, std::string const & field_value,
                                                    std::vector<std::string> const & values) const;

        /**
         * Returns true if an alternate allele is not symbolic
         */
        bool check_alt_not_symbolic(size_t allele_index) const;

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
         * Returns the ploidy of the GT sample field
         */
        size_t get_ploidy_from_GT(std::string const & sample) const;

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
         * Strict validation of predefined FORMAT tags
         *
         * @throw SamplesFieldBodyError
         */
        void strict_validation_format_predefined_tags(size_t i, std::string const & field_key, std::string const & field_value,
                                                      std::vector<std::string> const & values) const;

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
         * Checks that a list contains no duplicates
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
         * @param alternate_allele_number the number of alternate alleles
         * @param ploidy is the number of copies of a chromosome in a sample, so a given genotype in said chromosome needs `ploidy` alleles to be completely specified
         * @param expected_cardinality return by reference [0, +inf) for valid numbers. -1 if unknown number.
         * @throw std::invalid_argument if it's not a number
         * @throw std::out_of_range if it's out of range.
         * @return bool: whether the number was valid or not
         */
        bool is_valid_cardinality(std::string const &number, size_t alternate_allele_number, size_t ploidy,
                                  long &expected_cardinality) const;

        /**
         * Checks that the values match either their type specified in the meta or the VCF specification for predefined tags not in meta
         */
        void check_value_type(std::string const & type, std::string const & value, std::string & message) const;

        /**
         * Checks that every field in INFO column matches the Number specification in the meta
         * Or if it is not present in the meta and is a predefined tag, check that it matches the VCF specification
         *
         * @throw std::invalid_argument
         */
        void check_info_field_cardinality(std::vector<std::string> const &values, std::string const &number) const;

        /**
         * Checks that every field in a sample matches the Number specification in the meta
         * Or if it is not present in the meta and is a predefined tag, check that it matches the VCF specification
         *
         * @throw std::invalid_argument
         */
        void check_sample_field_cardinality(std::vector<std::string> const &values, std::string const &number,
                                            size_t ploidy, long &expected_cardinality) const;

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

        /**
         * Checks that INFO contains required mandatory fields when applicable
         *
         * @throw InfoBodyError
         */
        void check_info_have_mandatory() const;

        /**
         * gets total RN count
         */
        int getRNvalue() const;
    };

    std::ostream &operator<<(std::ostream &os, const Record &record);

  }
}

#endif // VCF_FILE_STRUCTURE_HPP

