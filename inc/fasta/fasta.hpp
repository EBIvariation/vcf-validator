/**
 * Copyright 2018 EMBL - European Bioinformatics Institute
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

#ifndef VCF_VALIDATOR_FASTA_HPP
#define VCF_VALIDATOR_FASTA_HPP

#include <fstream>
#include <memory>
#include <string>

#include <boost/iostreams/filtering_stream.hpp>
#include "bioio/bioio.hpp"
#include "util/curl_easy.hpp"

namespace ebi
{
  namespace vcf
  {
    namespace fasta
    {
      class IFasta
      {
      public:
        /**
         * Extract n base pairs from the contig starting from an offset
         * @param contig - the name of the contig to extract the sequence from
         * @param pos - the starting offset position
         * @param length - the number of base pairs to be extracted
         * @return the sequence string, empty if nothing can be extracted.
         */
        virtual std::string sequence(const std::string& contig, const size_t pos, const size_t length) = 0;

        /**
         * Get the number of times a contig appears in a FASTA.
         * @param contig - the name of the contig
         * @return the number of times a contig appears in a FASTA. 0 if the contig is not found.
         */
        virtual size_t count(const std::string &contig) const = 0;

        /**
         * Get the length of the sequence for a contig
         * @param contig - the name of the contig
         * @return the length of the sequence for the contig. 0 if the contig is not found.
         */
        virtual size_t len(const std::string &contig) const = 0;

        virtual ~IFasta(){}
      };

      class FileBasedFasta : public IFasta
      {
      public:
        FileBasedFasta(const std::string& fasta_path, const std::string& fasta_index_path);
        virtual ~FileBasedFasta(){}

        std::string sequence(const std::string& contig, const size_t pos, const size_t length);
        size_t count(const std::string &contig) const;
        size_t len(const std::string &contig) const;

      private:
        FileBasedFasta(){}

        std::shared_ptr<std::istream> fasta_input;
        bioio::FastaIndex fasta_index;
      };

      class ContigFromENA;

      class RemoteContig : public IFasta
      {
      public:
        RemoteContig();
        virtual ~RemoteContig(){}

        std::string sequence(const std::string& contig, const size_t pos, const size_t length);
        size_t count(const std::string &contig) const;
        size_t len(const std::string &contig) const;

      private:
        std::unique_ptr<ebi::util::curl::Easy> curl_easy;
        std::unordered_map<std::string, std::shared_ptr<ContigFromENA>> contigs;
      };
    }
  }
}

#endif //VCF_VALIDATOR_FASTA_HPP
