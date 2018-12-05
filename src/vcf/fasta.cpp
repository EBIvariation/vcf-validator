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
#include <boost/iostreams/copy.hpp>

#include "bioio/bioio.hpp"

#include "util/file_utils.hpp"
#include "util/logger.hpp"
#include "util/stream_utils.hpp"
#include "util/string_utils.hpp"
#include "vcf/compression.hpp"
#include "vcf/fasta.hpp"
#include "vcf/string_constants.hpp"

std::shared_ptr<std::istream> create_gunzipped_stream(std::shared_ptr<std::istream> stream) {
  std::shared_ptr<std::stringstream> ss(new std::stringstream());
  try {
    boost::iostreams::filtering_istream decompressedStream;
    ebi::vcf::create_uncompressed_stream(*stream, ebi::vcf::GZ, decompressedStream);
    boost::iostreams::copy(decompressedStream, *ss);
  } catch (std::exception const &ex) {
    BOOST_LOG_TRIVIAL(error) << ex.what();
  }

  return std::static_pointer_cast<std::istream>(ss);
}

std::shared_ptr<std::istream> create_decompressed_stream(std::shared_ptr<std::istream> stream) {
  std::vector<char> line;
  ebi::vcf::get_magic_num(*stream, line);
  std::string file_extension = ebi::vcf::get_compression("", line);

  if ( file_extension == ebi::vcf::GZ ) {
    return create_gunzipped_stream(stream);
  }

  return stream;
}

std::shared_ptr<std::istream> create_input_stream(const std::string &path) {
  if ( !ebi::util::is_remote_url(path) ) {
    std::shared_ptr<std::ifstream> fstream(new std::ifstream());
    ebi::util::open_local(*fstream, path, std::ifstream::binary);
    return create_decompressed_stream(std::static_pointer_cast<std::istream>(fstream));
  }

  std::shared_ptr<std::stringstream> sstream(new std::stringstream());
  ebi::util::open_remote(*sstream, path);
  return create_decompressed_stream(std::static_pointer_cast<std::istream>(sstream));
}

ebi::vcf::fasta::FileBasedFasta::FileBasedFasta(const std::string& fasta_path, const std::string& fasta_index_path)
{
  BOOST_LOG_TRIVIAL(info) << "Reading from input FASTA file...";
  mFastaInput = create_input_stream(fasta_path);

  BOOST_LOG_TRIVIAL(info) << "Reading from input FASTA index file...";
  mFastaIndex = bioio::read_fasta_index(*(create_input_stream(fasta_index_path)));
}

std::string
ebi::vcf::fasta::FileBasedFasta::sequence(const std::string& contig, const size_t pos, const size_t length) {
  return bioio::read_fasta_contig(*mFastaInput, mFastaIndex.at(contig), pos, length);
}

size_t
ebi::vcf::fasta::FileBasedFasta::count(const std::string &contig) const {
  return mFastaIndex.count(contig);
}

ebi::vcf::fasta::RemoteContig::RemoteContig()
        : mCurl(new ebi::util::curl::Easy())
{}

std::string
ebi::vcf::fasta::RemoteContig::sequence(const std::string& contig, const size_t pos, const size_t length) {
  if ( mContig.count(contig) == 0 ) {
    mContig[contig] = "";

    // This contig is not downloaded, try download it from ENA.
    if (contig.size() < 6) { // don't trust short contig names.
      return "";
    }

    // Download this contig
    std::string url = ebi::vcf::ENA_API_URL + contig + "&" + ebi::vcf::ENA_API_FASTA_FORMAT;
    std::stringstream ss;
    ebi::util::open_remote(ss, url);

    std::vector<char> vector_line;
    vector_line.reserve(1024);
    if (ebi::util::readline(ss, vector_line).size() != 0) {
      std::string line{vector_line.begin(), vector_line.end()};
      if (boost::starts_with(line, ">")) {
        std::string seq;
        while (ebi::util::readline(ss, vector_line).size() != 0) {
          seq.append(vector_line.data(), vector_line.size() - 1); // ignore linebreak at the end of line
        }
        mContig[contig] = seq;
      }
    }
  }

  if ( pos >= mContig[contig].size() ) {
    return "";
  }

  return mContig[contig].substr(pos, length);
}

size_t
ebi::vcf::fasta::RemoteContig::count(const std::string &contig) const {
  return mContig.count(contig);
}
