/**
 * Copyright 2017 EMBL - European Bioinformatics Institute
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

#include "vcf/assembly_report_writer.hpp"

namespace ebi
{
  namespace vcf
  {
    void SummaryAssemblyReportWriter::write_mismatch(const vcf::VcfVariant &vcf_variant)
    {
        match_stats.num_variants++;
    }

    void SummaryAssemblyReportWriter::write_match(const vcf::VcfVariant &vcf_variant)
    {
        match_stats.num_variants++;
        match_stats.num_matches++;
    }

    void SummaryAssemblyReportWriter::finish_report()
    {
        BOOST_LOG_TRIVIAL(info) << "Number of matches: " << match_stats.num_matches << "/" << match_stats.num_variants;
        BOOST_LOG_TRIVIAL(info) << "Percentage of matches: " << (static_cast<double>(match_stats.num_matches) / match_stats.num_variants) * 100 << "%";
    }

  }
}
