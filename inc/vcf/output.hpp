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
#include <chrono>
#include <thread>
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
        virtual void write_error(Error &error) = 0;
        virtual void write_warning(Error &error) = 0;
    };

    class StdOutput : public Output
    {
      public:

      private:
        virtual void write_error(Error &error) override
        {
          std::cout << error.what() << std::endl;
        }
        virtual void write_warning(Error &error) override
        {
          std::cout << error.what() << " (warning)" << std::endl;
        }
    };
    class SqliteOutput : public Output
    {
      public:
        SqliteOutput(std::string db_name);
        ~SqliteOutput();
        void write_error(Error &error) override;
        void write_warning(Error &error) override;

      private:
        void write(Error &error, std::string table);
        void start_transaction();
        void finish_transaction();

        sqlite3* db;
        std::string db_name;
        size_t current_transaction_size;
        const size_t transaction_size;
        const std::chrono::milliseconds sleep_time;
    };
  }
}


#endif //VCF_VALIDATOR_OUTPUT_HPP
