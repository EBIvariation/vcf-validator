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

#include <memory>

#include <boost/algorithm/string/predicate.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/iostreams/copy.hpp>

#include "bioio/bioio.hpp"

#include "util/file_utils.hpp"
#include "util/logger.hpp"
#include "util/stream_utils.hpp"
#include "util/string_utils.hpp"
#include "vcf/compression.hpp"
#include "fasta/fasta.hpp"
#include "vcf/string_constants.hpp"

std::shared_ptr<std::istream> create_input_stream(const std::string &path)
{
    std::shared_ptr<std::ifstream> fstream(new std::ifstream());
    ebi::util::open_file(*fstream, path, std::ifstream::binary);
    return std::static_pointer_cast<std::istream>(fstream);
}

ebi::vcf::fasta::FileBasedFasta::FileBasedFasta(const std::string& fasta_path, const std::string& fasta_index_path)
{
    BOOST_LOG_TRIVIAL(info) << "Reading from input FASTA file...";
    fasta_input = create_input_stream(fasta_path);

    BOOST_LOG_TRIVIAL(info) << "Reading from input FASTA index file...";
    fasta_index = bioio::read_fasta_index(*(create_input_stream(fasta_index_path)));
}

std::string
ebi::vcf::fasta::FileBasedFasta::sequence(const std::string& contig, const size_t pos, const size_t length)
{
    return bioio::read_fasta_contig(*fasta_input, fasta_index.at(contig), pos, length);
}

size_t
ebi::vcf::fasta::FileBasedFasta::count(const std::string &contig) const
{
    return fasta_index.count(contig);
}

ebi::vcf::fasta::RemoteContig::RemoteContig()
        : curl_easy(new ebi::util::curl::Easy())
{}

class ebi::vcf::fasta::ContigFromENA {
public:
  ContigFromENA(const std::string& contigName)
  {
      contig_name = contigName;
      fasta_output.reset(new std::ofstream(contig_name));
  }

  ~ContigFromENA()
  {
      if (fasta_input.get()) {
          fasta_input->close();
      }
      fasta_output->close();
      boost::filesystem::remove(contig_name);
  }

  void write(const char* buffer, const size_t length)
  {
      fasta_output->write(buffer, length);
      contig_length += length;
  }

  std::string read(const size_t pos, const size_t length)
  {
      if (!fasta_input.get()) {
          fasta_input.reset(new std::ifstream(contig_name, std::ios_base::in));
      }

      if (pos >= contig_length) {
        return "";
      }

      std::string result;
      return ebi::util::read_n(*fasta_input, result, length, pos);
  }

private:
  size_t contig_length;
  std::string contig_name;
  std::unique_ptr<std::ifstream> fasta_input;
  std::unique_ptr<std::ofstream> fasta_output;
};

std::string
ebi::vcf::fasta::RemoteContig::sequence(const std::string& contig, const size_t pos, const size_t length)
{
    if (contigs.count(contig) == 0) {
        contigs[contig].reset(new ebi::vcf::fasta::ContigFromENA(contig));

        // This contig is not downloaded, try download it from ENA.
        std::string url = ebi::vcf::ENA_API_URL + ebi::vcf::ENA_API_FASTA_FORMAT + "/"+ contig;
        std::fstream response_stream;
        response_stream.open(contig+".tmp", std::ios::in | std::ios::out | std::ios::app);
        ebi::util::open_remote(response_stream, url);
        response_stream.seekg(0, std::ios::beg);

        std::string line;
        line.reserve(1024);
        if (ebi::util::readline(response_stream, line).size() != 0) {
            if (boost::starts_with(line, ">")) {
                while (ebi::util::readline(response_stream, line).size() != 0) {
                    ebi::util::remove_end_of_line(line); // ignore linebreak at the end of line
                    contigs[contig]->write(line.c_str(), line.size());
                }
            }
        }

        response_stream.close();
        boost::filesystem::remove(contig+".tmp");
    }

    return contigs[contig]->read(pos, length);
}

size_t
ebi::vcf::fasta::RemoteContig::count(const std::string &contig) const
{
    return contigs.count(contig);
}
