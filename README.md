# vcf-validator
Validator for the Variant Call Format (VCF) implemented using C++11.

It includes all the checks from the vcftools suite, and some more that involve lexical, syntactic and semantic analysis of the VCF input. If any inconsistencies are found, they are classified in one of the following categories:

* Errors: Violations of the VCF specification
* Warnings: An indication that something weird happened (different ploidy in samples from the same species) or a recommendation is not followed (missing meta-data)

Please read the wiki for more details about checks already implemented.

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
