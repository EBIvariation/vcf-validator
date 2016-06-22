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
#include <sstream>
#include <memory>

namespace ebi
{
  namespace vcf
  {
    enum class ErrorCode {
        error,
        meta_section,
        header_section,
        body_section,
        fileformat,
        chromosome_body,
        position_body,
        id_body,
        reference_allele_body,
        alternate_alleles_body,
        quality_body,
        filter_body,
        info_body,
        format_body,
        samples_body,
        normalization,
        duplication,
    };

    class Error;
    class MetaSectionError;
    class HeaderSectionError;
    class BodySectionError;
    class FileformatError;
    class ChromosomeBodyError;
    class PositionBodyError;
    class IdBodyError;
    class ReferenceAlleleBodyError;
    class AlternateAllelesBodyError;
    class QualityBodyError;
    class FilterBodyError;
    class InfoBodyError;
    class FormatBodyError;
    class SamplesBodyError;
    class NormalizationError;
    class DuplicationError;

    std::shared_ptr<Error> get_error_instance(ErrorCode code, size_t line, const std::string &message);

    class ErrorVisitor {
      public:
        virtual void visit(Error& error) = 0;
        virtual void visit(MetaSectionError &error) = 0;
        virtual void visit(HeaderSectionError &error) = 0;
        virtual void visit(BodySectionError &error) = 0;
        virtual void visit(FileformatError &error) = 0;
        virtual void visit(ChromosomeBodyError &error) = 0;
        virtual void visit(PositionBodyError &error) = 0;
        virtual void visit(IdBodyError &error) = 0;
        virtual void visit(ReferenceAlleleBodyError &error) = 0;
        virtual void visit(AlternateAllelesBodyError &error) = 0;
        virtual void visit(QualityBodyError &error) = 0;
        virtual void visit(FilterBodyError &error) = 0;
        virtual void visit(InfoBodyError &error) = 0;
        virtual void visit(FormatBodyError &error) = 0;
        virtual void visit(SamplesBodyError &error) = 0;
        virtual void visit(NormalizationError &error) = 0;
        virtual void visit(DuplicationError &error) = 0;
    };

    /**
     * class for VCF errors.
     *
     * Child classes may be used for more specific Errors. To add another error type, follow these steps:
     * - predeclare class before ErrorVisitor
     * - add a class at the end of this file
     * - change its name, its parent, its message and its error code
     * - add a new error code to the enum above
     * - add the new class in the get_error_instance function
     * - add a new method visit in ErrorVisitor
     */
    class Error : public std::runtime_error
    {
      public:
        Error(size_t line) : Error{line, "Error, invalid file."} {}

        Error(size_t line, const std::string &message)
                : runtime_error{std::string{"Line "} + std::to_string(line) + ": " + message},
                  line{line},
                  message{message} {}


        size_t get_line() const { return line; }
        const std::string &get_raw_message() const { return message; }
        virtual ErrorCode get_code() const { return ErrorCode::error; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }

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
        virtual ErrorCode get_code() const override { return ErrorCode::meta_section; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };

    class HeaderSectionError : public Error
    {
      public:
        using Error::Error;
        HeaderSectionError(size_t line) : HeaderSectionError{line, "Error in header section"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::header_section; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };

    class BodySectionError : public Error
    {
      public:
        using Error::Error;
        BodySectionError(size_t line) : BodySectionError{line, "Error in body section"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::body_section; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };

    // inheritance siblings about detailed errors
    class FileformatError : public MetaSectionError
    {
      public:
        using MetaSectionError::MetaSectionError;
        FileformatError(size_t line) : FileformatError{line, "Error in file format section"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::fileformat; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };

    class ChromosomeBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        ChromosomeBodyError(size_t line) : ChromosomeBodyError{line,
            "Chromosome is not a string without colons or whitespaces, optionally wrapped with angle brackets (<>)"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::chromosome_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };

    class PositionBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        PositionBodyError(size_t line) : PositionBodyError{line, "Position is not a positive number"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::position_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class IdBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        IdBodyError(size_t line) : IdBodyError{line, "ID is not a single dot or a list of strings without semicolons or whitespaces"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::id_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class ReferenceAlleleBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        ReferenceAlleleBodyError(size_t line) : ReferenceAlleleBodyError{line, "Reference is not a string of bases"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::reference_allele_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class AlternateAllelesBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        AlternateAllelesBodyError(size_t line) : AlternateAllelesBodyError{line, "Alternate is not a single dot or a comma-separated list of bases"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::alternate_alleles_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class QualityBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        QualityBodyError(size_t line) : QualityBodyError{line, "Quality is not a single dot or a positive number"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::quality_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class FilterBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        FilterBodyError(size_t line) : FilterBodyError{line, "Filter is not a single dot or a semicolon-separated list of strings"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::filter_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class InfoBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        InfoBodyError(size_t line) : InfoBodyError{line, "Error in info column, in body section"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::info_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class FormatBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        FormatBodyError(size_t line) : FormatBodyError{line, "Format is not a colon-separated list of alphanumeric strings"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::format_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class SamplesBodyError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        SamplesBodyError(size_t line) : SamplesBodyError{line, "Error in samples columns, in body section"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::samples_body; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class NormalizationError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        NormalizationError(size_t line) : NormalizationError{line, "Normalization could not be performed"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::normalization; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
    class DuplicationError : public BodySectionError
    {
      public:
        using BodySectionError::BodySectionError;
        DuplicationError(size_t line) : DuplicationError{line, "A duplicated record was found"} { }
        virtual ErrorCode get_code() const override { return ErrorCode::duplication; }
        virtual void apply_visitor(ErrorVisitor &visitor) { visitor.visit(*this); }
    };
  }
}

#endif //VCF_ERROR_HPP
