/**
 * Copyright 2016 EMBL - European Bioinformatics Institute
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

#ifndef VCF_ERROR_HPP
#define VCF_ERROR_HPP

#include <string>
#include <stdexcept>

namespace ebi
{
  namespace vcf
  {
    // parent of vcf errors
    class Error : public std::runtime_error
    {
      public:
        Error(size_t line) : Error{line, "Error, invalid file."} {}

        Error(size_t line, const std::string &message)
                : runtime_error{std::string{"Line "} + std::to_string(line) + ": " + message},
                  line{line},
                  message{message} {}


        // TODO: leave here or extract? if we will allow several levels of conservative-risky fixes, it's better to extract
//        virtual void fix(Error, ParsingState &state);
//        virtual void fix(MetaError, ParsingState &state);

        size_t get_line() const
        {
          return line;
        }
        const std::string &get_raw_message() const
        {
          return message;
        }

      private:
        size_t line;
        std::string message;
    };

    // inheritance siblings depending on file location
    class MetaSectionError : public Error
    {
      public:
        using Error::Error;
        MetaSectionError(size_t line) : MetaSectionError{line, "Error in meta-data section"} { }
    };

    class HeaderSectionError : public Error
    {
      public:
        using Error::Error;
        HeaderSectionError(size_t line) : HeaderSectionError{line, "Error in header section"} { }
    };

    class BodySectionError : public Error
    {
      public:
        using Error::Error;
        BodySectionError(size_t line) : BodySectionError{line, "Error in body section"} { }
    };

    // inheritance siblings about detailed errors
    class FileformatError : public MetaSectionError
    {
      public:
        using MetaSectionError::MetaSectionError;
        FileformatError(size_t line) : FileformatError{line, "Error in file format section"} { }
    };

    class ChromosomeBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        ChromosomeBodyError(size_t line) : ChromosomeBodyError{line,
            "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)"} { }
    };

    class PositionBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        PositionBodyError(size_t line) : PositionBodyError{line, "Position is not a positive number"} { }
    };
    class IdBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        IdBodyError(size_t line) : IdBodyError{line, "ID is not a single dot or a list of strings without semicolons or whitespaces"} { }
    };
    class ReferenceAlleleBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        ReferenceAlleleBodyError(size_t line) : ReferenceAlleleBodyError{line, "Reference is not a string of bases"} { }
    };
    class AlternateAllelesBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        AlternateAllelesBodyError(size_t line) : AlternateAllelesBodyError{line, "Alternate is not a single dot or a comma-separated list of bases"} { }
    };
    class QualityBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        QualityBodyError(size_t line) : QualityBodyError{line, "Quality is not a single dot or a positive number"} { }
    };
    class FilterBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        FilterBodyError(size_t line) : FilterBodyError{line, "Filter is not a single dot or a semicolon-separated list of strings"} { }
    };
    class InfoBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        InfoBodyError(size_t line) : InfoBodyError{line, "Error in info column, in body section"} { }
    };
    class FormatBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        FormatBodyError(size_t line) : FormatBodyError{line, "Format is not a colon-separated list of alphanumeric strings"} { }
    };
    class SamplesBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        SamplesBodyError(size_t line) : SamplesBodyError{line, "Error in samples columns, in body section"} { }
    };

  }
}

#endif //VCF_ERROR_HPP
