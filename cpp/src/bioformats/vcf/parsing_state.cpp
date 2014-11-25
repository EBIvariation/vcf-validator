#include "vcf_validator.hpp"

namespace opencb
{
  namespace vcf
  {

    ParsingState::ParsingState()
    : n_lines{1}, n_columns{1}, n_batches{0}, cs{0}
    {
    }

  }
}
