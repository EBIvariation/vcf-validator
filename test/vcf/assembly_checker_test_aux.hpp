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

#ifndef EBI_ASSEMBLER_TEST_AUX_HPP
#define EBI_ASSEMBLER_TEST_AUX_HPP

#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string/classification.hpp"
#include <boost/filesystem.hpp>
#include <fstream>
#include "catch/catch.hpp"
#include "vcf/assembly_checker.hpp"
#include "vcf/string_constants.hpp"

namespace ebi
{
  	inline std::string get_file_prefix(boost::filesystem::path folder_path)
  	{
  		boost::filesystem::path::iterator folder = folder_path.end();
  		folder--;
  		folder--;
  		return (*folder).string();
  	}
}

#endif // EBI_ASSEMBLER_TEST_AUX_HPP

