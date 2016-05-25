//
// Created by jmmut on 25/05/16.
//

#include "vcf/output.hpp"

namespace ebi
{
  namespace vcf
  {
    SqliteOutput::SqliteOutput(std::string db_name) { }

    void SqliteOutput::write(Error &error)
    {
        std::cout << "sqlite mock: " << error.what() << std::endl;
    }
  }
}