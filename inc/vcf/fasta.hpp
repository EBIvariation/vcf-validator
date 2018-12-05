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
        virtual std::string sequence(const std::string& contig, const size_t pos, const size_t length) = 0;
        virtual size_t count(const std::string& contig) const = 0;
      };

      class FileBasedFasta : public IFasta
      {
      public:
        FileBasedFasta(const std::string& fasta_path, const std::string& fasta_index_path);
        virtual ~FileBasedFasta(){}

        std::string sequence(const std::string& contig, const size_t pos, const size_t length);
        size_t count(const std::string& contig) const;

      private:
        FileBasedFasta(){}

        std::shared_ptr<std::istream> mFastaInput;
        bioio::FastaIndex mFastaIndex;
      };

      class RemoteContig : public IFasta
      {
      public:
        RemoteContig();
        virtual ~RemoteContig(){}

        std::string sequence(const std::string& contig, const size_t pos, const size_t length);
        size_t count(const std::string& contig) const;

      private:
        std::unique_ptr<ebi::util::curl::Easy> mCurl;
        std::unordered_map<std::string, std::string> mContig;
      };
    }
  }
}

#endif //VCF_VALIDATOR_FASTA_HPP
