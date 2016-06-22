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

#include "vcf/error.hpp"

namespace ebi
{
  namespace vcf
  {
    std::shared_ptr<Error> get_error_instance(ErrorCode code, size_t line, const std::string &message)
    {
        switch (code) {
            //default: // commenting out the default, to get warnings on new error types

        case ErrorCode::error:
            return std::shared_ptr<Error>(new Error{line, message});
        case ErrorCode::meta_section:
            return std::shared_ptr<Error>(new MetaSectionError{line, message});
        case ErrorCode::header_section:
            return std::shared_ptr<Error>(new HeaderSectionError{line, message});
        case ErrorCode::body_section:
            return std::shared_ptr<Error>(new BodySectionError{line, message});
        case ErrorCode::fileformat:
            return std::shared_ptr<Error>(new FormatBodyError{line, message});
        case ErrorCode::chromosome_body:
            return std::shared_ptr<Error>(new ChromosomeBodyError{line, message});
        case ErrorCode::position_body:
            return std::shared_ptr<Error>(new PositionBodyError{line, message});
        case ErrorCode::id_body:
            return std::shared_ptr<Error>(new IdBodyError{line, message});
        case ErrorCode::reference_allele_body:
            return std::shared_ptr<Error>(new ReferenceAlleleBodyError{line, message});
        case ErrorCode::alternate_alleles_body:
            return std::shared_ptr<Error>(new AlternateAllelesBodyError{line, message});
        case ErrorCode::quality_body:
            return std::shared_ptr<Error>(new QualityBodyError{line, message});
        case ErrorCode::filter_body:
            return std::shared_ptr<Error>(new FilterBodyError{line, message});
        case ErrorCode::info_body:
            return std::shared_ptr<Error>(new InfoBodyError{line, message});
        case ErrorCode::format_body:
            return std::shared_ptr<Error>(new FormatBodyError{line, message});
        case ErrorCode::samples_body:
            return std::shared_ptr<Error>(new SamplesBodyError{line, message});
        case ErrorCode::normalization:
            return std::shared_ptr<Error>(new NormalizationError{line, message});
        case ErrorCode::duplication:
            return std::shared_ptr<Error>(new DuplicationError{line, message});
        }

        std::stringstream ss;
        ss << "An Error instance was requested, with code " << static_cast<int>(code)
        << ", line " << line << " and message : \"" << message
        << "\" but no class is associated to it in the method ebi::vcf::get_error_instance. "
                "This is likely to be caused by adding a new Error type without updating this function, "
                "and it should be raised as a warning during compilation";
        throw std::logic_error{ss.str()};
    }
  }
}

