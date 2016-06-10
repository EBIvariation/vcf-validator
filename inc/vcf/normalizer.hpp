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
#ifndef VCF_VALIDATOR_NORMALIZER_HPP
#define VCF_VALIDATOR_NORMALIZER_HPP

namespace ebi
{
  namespace vcf
  {
    std::vector<Record> normalize(const Record &record/* , ParsingState?*/);
  }
}

#endif //VCF_VALIDATOR_NORMALIZER_HPP
