# vcf-validator
Validator for VCF implemented using C++11

## Dependencies

The only dependencies are the Boost library core and the Boost.regex module.
If you are using Ubuntu, the required packages names will be `libboost-dev` and `libboost-regex-dev`.

## Build

In order to create the build scripts, please run `cmake` with your preferred generator. For instance, `cmake -G "Unix Makefiles"` will create Makefiles, and to build the binaries, you will need to run `make`.

In any case, two binaries should be created in the `bin` subfolder: `vcf_validator` (the main application) and `test_validator` (unit tests).

## Test

Unit tests can be run using the binary `bin/test_validator` or, if the generator supports it, a command like `make test`. The first option may provide a more detailed output in case of test failure.

## Run

vcf-validator only needs an input VCF file to be run. It accepts input in two different ways:

* File path as argument: `vcf_validator /path/to/file.vcf`
* Standard input: `vcf_validator stdin < /path/to/file.vcf` (the input can also come from a pipe)
