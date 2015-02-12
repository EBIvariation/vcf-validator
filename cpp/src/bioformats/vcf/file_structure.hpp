/* 
 * File:   file_structure.hpp
 * Author: Cristina Yenyxe Gonzalez Garcia <cyenyxe@ebi.ac.uk>
 *
 * Created on 19 November 2014, 10:12
 */

#ifndef OPENCB_VCF_FILESTRUCTURE_H
#define	OPENCB_VCF_FILESTRUCTURE_H

#include <algorithm>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include <boost/variant.hpp>

namespace opencb
{
  namespace vcf
  {
      
    struct Source;
    
    struct MetaEntry
    {
        enum class Structure { NoValue, PlainValue, KeyValue };
        
        std::string id;
        Structure structure; // Union discriminant
        
        boost::variant< std::string, 
                        std::map<std::string, std::string> > value;
        
        std::shared_ptr<Source> source;
        
        MetaEntry(std::string const & id,
                  std::shared_ptr<Source> const & source);
        
        MetaEntry(std::string const & id,
                  std::string const & plain_value,
                  std::shared_ptr<Source> const & source);
        
        MetaEntry(std::string const & id,
                  std::map<std::string, std::string> const & key_values,
                  std::shared_ptr<Source> const & source);
        
        bool operator==(MetaEntry const &);

        bool operator!=(MetaEntry const &);
        
    private:
        /**
         * Checks that the entry value satisfies the VCF specification.
         * 
         * @throw std::invalid_argument
         */
        void check_value();
    };
    
    enum InputFormat 
    {
        VCF_FILE_VCF    = 0x01,
        VCF_FILE_GVCF   = 0x02,
        VCF_FILE_GZIP   = 0x04,
        VCF_FILE_BGZIP  = 0x08,
        VCF_FILE_BCF    = 0x10,
    };
    
    struct Source 
    {
        std::string name;           /**< Name of the source to interact with (file, stdin...) */
        unsigned int input_format;  /**< Mask that stores whether the input is plain/gzipped VCF, BCF, etc */
        std::string version;        /**< VCF version */

        std::vector<MetaEntry> meta_entries;    /**< Entries in the file meta-data */
        std::vector<std::string> samples_names; /**< Names of the sequenced samples */
        
        Source(std::string const & name,
               unsigned const input_format,
               std::string const & version = "VCFv4.1",
               std::vector<MetaEntry> const & meta_entries = {},
               std::vector<std::string> const & samples_names = {});
    };
    
    struct Record 
    {
        std::string chromosome;
        size_t position;
        std::vector<std::string> ids;

        std::string reference_allele;
        std::vector<std::string> alternate_alleles;

        float quality;
        std::vector<std::string> filters;
        std::vector<std::string> info;
        std::vector<std::string> format;

        std::vector<std::string> samples;
        
        std::shared_ptr<Source> source;
        

        Record(std::string const & chromosome, 
               size_t const position, 
               std::vector<std::string> const & ids, 
               std::string const & reference_allele, 
               std::vector<std::string> const & alternate_alleles, 
               float const quality, 
               std::vector<std::string> const & filters, 
               std::vector<std::string> const & info, 
               std::vector<std::string> const & format, 
               std::vector<std::string> const & samples,
               std::shared_ptr<Source> const & source);

        bool operator==(Record const &);

        bool operator!=(Record const &);
        
    private:
        /**
         * Checks that chromosome does not contain colons or white-spaces
         * 
         * @throw std::invalid_argument
         */
        void check_chromosome();
        
        /**
         * Checks that IDs are alphanumeric
         * 
         * @throw std::invalid_argument
         */
        void check_ids();
        
        /**
         * Checks that alternate and reference alleles share the first nucleotide 
         * when they have the same length, but are not exactly the same
         * 
         * @throw std::invalid_argument
         */
        void check_alternate_alleles();
        
        /**
         * Checks that quality is zero or greater
         * 
         * @throw std::invalid_argument
         */
        void check_quality();
        
        /**
         * Checks that format starts with GT
         * 
         * @throw std::invalid_argument
         */
        void check_format();
    };

  }
}

#endif	/* OPENCB_VCF_VCFFILESTRUCTURE_H */

