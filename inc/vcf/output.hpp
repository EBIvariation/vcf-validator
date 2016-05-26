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

#ifndef VCF_VALIDATOR_OUTPUT_HPP
#define VCF_VALIDATOR_OUTPUT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "sqlite/sqlite3.h"
#include "vcf/error.hpp"

namespace ebi
{
  namespace vcf
  {
    class Output
    {
      public:
//        virtual ~Output() {}  // needed if using raw pointers, instead of references or shared_ptrs
        virtual void write(Error &error) = 0;
    };

    class StdOutput : public Output
    {
      public:

      private:
        virtual void write(Error &error) override
        {
          std::cout << error.what() << std::endl;
        }
    };
    class SqliteOutput : public Output
    {
      public:
        SqliteOutput(std::string db_name);
        ~SqliteOutput();
        void write(Error &error) override;

      private:
        sqlite3* db;
        const size_t transaction_size = 1000000;
    };
  }
}


#endif //VCF_VALIDATOR_OUTPUT_HPP