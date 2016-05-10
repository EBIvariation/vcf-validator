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

namespace ebi
{
  namespace vcf
  {
    // parent of vcf errors
    class Error : public std::runtime_error
    {
      public:
        Error(size_t line, const std::string &message)
                : runtime_error(std::string("Line ") + std::to_string(line) + ": " + message),
                  line(line) {}

        // TODO: leave here or extract? if we will allow several levels of conservative-risky fixes
//        virtual void fix(Error, ParsingState &state);
//        virtual void fix(MetaError, ParsingState &state);
      private:
        size_t line;
    };

    // inheritance siblings depending on file location
    class MetaSectionError : public Error
    {
        using Error::Error;
    };

    class HeaderSectionError : public Error
    {
        using Error::Error;
    };

    class BodySectionError : public Error
    {
        using Error::Error;
    };

    // inheritance siblings about detailed errors
    class FileformatError : public MetaSectionError
    {
        using MetaSectionError::MetaSectionError;
    };

    class ChromosomeBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };

    class PositionBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };
    class IdBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };
    class ReferenceAlleleBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };
    class AlternateAllelesBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };
    class QualityBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };
    class FilterBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };
    class InfoBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };
    class FormatBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };
    class SamplesBodyError : public BodySectionError
    {
        using BodySectionError::BodySectionError;
    };

  }
}

#endif //VCF_ERROR_HPP
