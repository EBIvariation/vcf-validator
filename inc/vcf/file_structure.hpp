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
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/variant.hpp>

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
    
    
    struct MetaEntry
    {
        enum class Structure { NoValue, PlainValue, KeyValue };
        
        std::string id;
        Structure structure; // Union discriminant
        
        boost::variant< std::string, 
                        std::map<std::string, std::string> > value;
        
        MetaEntry(std::string const & id);
        
        MetaEntry(std::string const & id,
                  std::string const & plain_value);
        
        MetaEntry(std::string const & id,
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
        std::map<std::string, std::string> info;
        std::vector<std::string> format;

        std::vector<std::string> samples;
        
        std::shared_ptr<Source> source;
        

        Record(size_t const line,
                std::string const & chromosome,
                size_t const position,
                std::vector<std::string> const & ids,
                std::string const & reference_allele,
                std::vector<std::string> const & alternate_alleles,
                float const quality,
                std::vector<std::string> const & filters,
                std::map<std::string, std::string> const & info,
                std::vector<std::string> const & format,
                std::vector<std::string> const & samples,
                std::shared_ptr<Source> const & source);
        
        bool operator==(Record const &) const;

        bool operator!=(Record const &) const;
        
    private:
        
        void set_types();
        
        /**
         * Checks that chromosome does not contain colons or white-spaces
         * 
         * @throw std::invalid_argument
         */
        void check_chromosome() const;
        
        /**
         * Checks that IDs are alphanumeric
         * 
         * @throw std::invalid_argument
         */
        void check_ids() const;
        
        /**
         * Checks the structure of an alternate allele and its accordance to the meta section
         * 
         * @throw std::invalid_argument
         */
        void check_alternate_alleles() const;
        
        /**
         * Checks the structure of an alternate allele:
         * - The dot is not combined with others
         * - Is not the same as the reference
         * - Shares the first nucleotide with the reference (does not apply to SV, break-ends and custom ALTs)
         * 
         * @throw std::invalid_argument
         */
        void check_alternate_allele_structure(std::string const & alternate, RecordType type) const;
        
        /**
         * Checks that alternates of the form <SOME_ALT_ID> are described in the meta section
         * 
         * @throw std::invalid_argument
         */
        void check_alternate_allele_meta(std::string const & alt_id,
                                         std::pair<meta_iterator, meta_iterator> range) const;
        
        /**
         * Checks that quality is zero or greater
         * 
         * @throw std::invalid_argument
         */
        void check_quality() const;
        
        /**
         * Checks that all the filters are listed in the meta section
         * 
         * @throw std::invalid_argument
         */
        void check_filter() const;
        
        /**
         * Checks that all the INFO fields are listed in the meta section, and their number and 
         * type match those specifications
         * 
         * @throw std::invalid_argument
         */
        void check_info() const;
        
        /**
         * Checks that format starts with GT
         * 
         * @throw std::invalid_argument
         */
        void check_format() const;
        
        /**
         * Checks that the samples in the record:
         * - Are the same number as specified in the Source object
         * - Their allele indexes are not greater than the total number of alleles
         * - The number and type of the fields match the FORMAT meta information
         * 
         * @throw std::invalid_argument
         */
        void check_samples() const;
        
        /**
         * Check that the allele indexes in a sample are not greater than the total number of alleles
         * 
         * @throw std::invalid_argument
         */
        void check_samples_alleles(std::vector<std::string> const & alleles) const;
        
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

  }
}

#endif

