#ifndef OPENCB_VCF_VALIDATOR_H
#define OPENCB_VCF_VALIDATOR_H

#include <vector>

namespace opencb
{
  namespace vcf
  {
    class Validator
    {
      public:
	Validator();

        void parse(std::string const & text);
        void parse(std::vector<char> const & text);
        
	void end();

	bool is_valid() const;

      private:
        void parse_buffer(char const * p, char const * pe, char const * eof);

	size_t n_lines;
	size_t n_batches;
        int cs;	        
    };
  }
}

#endif
