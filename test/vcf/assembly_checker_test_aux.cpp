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

#include "assembly_checker_test_aux.hpp"
#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string/classification.hpp"
#include <fstream>
#include "catch/catch.hpp"

namespace ebi
{	

  	std::string get_file_prefix(std::string folder)
  	{
  		std::vector<std::string> path_components;
  		boost::split(path_components, folder, boost::is_any_of("/"));
  		return path_components[path_components.size() - 2];
  	}

  	std::string get_command(std::string folder, std::string file_prefix)
  	{
  		std::string command = "bin/vcf_assembly_checker -c " + folder + file_prefix + ".vcf -f " + folder + file_prefix + ".fa";
  		return command;
  	}

  	std::string get_output_path(std::string folder, std::string file_prefix)
  	{
  		return folder + file_prefix + ".vcf__" + file_prefix + ".fa.nonmatches";
  	}

  	bool is_empty_file(std::string file_path)
	{	
		std::ifstream file{file_path};
		bool empty_flag = file.peek() == std::ifstream::traits_type::eof();
		file.close();
		return empty_flag;
	}

	bool file_exists(std::string file_path)
	{
		std::ifstream file{file_path};
		bool exists_flag;
		if(!file)
			exists_flag = false;
		else
			exists_flag = true;
		file.close();

		return exists_flag;
	}

	long count_lines(std::istream &input_stream)
	{
		return std::count(std::istreambuf_iterator<char>(input_stream),
		std::istreambuf_iterator<char>(),
		'\n');
	}

	long count_lines(std::string filename)
	{
		std::ifstream file{filename};
		return count_lines(file);
	}
}

#endif // EBI_ASSEMBLER_TEST_AUX_HPP

