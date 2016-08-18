# vcf-validator [![Build Status](https://travis-ci.org/EBIvariation/vcf-validator.svg?branch=develop)](https://travis-ci.org/EBIvariation/vcf-validator)

Validator for the Variant Call Format (VCF) implemented using C++11.

It includes all the checks from the vcftools suite, and some more that involve lexical, syntactic and semantic analysis of the VCF input. If any inconsistencies are found, they are classified in one of the following categories:

* Errors: Violations of the VCF specification
* Warnings: An indication that something weird happened (different ploidy in samples from the same species) or a recommendation is not followed (missing meta-data)

Please read the wiki for more details about checks already implemented.

## Dependencies

### Boost

The dependencies are the Boost library core, and its submodules: Boost.filesystem, Boost.program_options, Boost.regex and Boost.system.
If you are using Ubuntu, the required packages names will be `libboost-dev`, `libboost-filesystem-dev`, `libboost-program-options-dev` and `libboost-regex-dev`.

### ODB

You will need to download the odb compiler, the odb common runtime library, and the sqlite database runtime library from [this page](http://codesynthesis.com/products/odb/download.xhtml).

ODB requires sqlite3 to be installed. The Ubuntu `apt-get`'s packages are `libsqlite3-0` and `libsqlite3-dev`.

To install the odb compiler, the easiest way is to download the `.deb` or `.rpm` version, in order to be installed automatically with `dpkg`. Both the odb runtime and sqlite libraries can be installed with the usual `./configure && make && sudo make install`.

## Build

The build has been tested on the following compilers:
* Clang 3.5 to 3.7
* GCC 4.8 to 5.0

In order to create the build scripts, please run `cmake` with your preferred generator. For instance, `cmake -G "Unix Makefiles"` will create Makefiles, and to build the binaries, you will need to run `make`. For those users who need static linkage, the option `-DBUILD_STATIC=1` must be provided to the `cmake` command.

In any case, two binaries will be created in the `bin` subfolder: `vcf_validator` (the main application) and `test_validator` (unit tests).

## Test

Unit tests can be run using the binary `bin/test_validator` or, if the generator supports it, a command like `make test`. The first option may provide a more detailed output in case of test failure.

**Note**: Tests that require input files will only work when executed with `make test` or running the binary from the project root folder (not the `bin` subfolder).

## Run

vcf-validator only needs an input VCF file to be run. It accepts input in the following ways:

* File path as argument: `vcf_validator -v v4.1 -i /path/to/file.vcf`
* Standard input: `vcf_validator -v v4.1 < /path/to/file.vcf`
* Standard input from pipe: `zcat /path/to/file.vcf.gz | vcf_validator -v v4.1`

The VCF version must be always specified, using the `-v` / `--version`. 

The validation level can be configured using `-l` / `--level`. This parameter is optional and accepts 3 values:

* error: Display only syntax errors
* warning: Display both syntax and semantic, both errors and warnings (default)
* stop: Stop after the first syntax error is found

The validation report can be exported in several ways with the `-r` / `--report` option. Several ones may be specified in the same execution.

* stdout: Write human-readable report to the standard output (default)
* database: Write structured report to a database file. The database engine used is SQLite3, so the results can be inspected manually, but they are intended to be consumed by other applications.

The reports written into a file are named after the input file, followed by a timestamp. The default output directory is the same as the input file's if provided using `-i`, or the current directory if using the standard input; it can be changed with the `-o` / `--outdir` option.

### Examples

Simple example: `vcf_validator -i /path/to/file.vcf -v v4.1`  
Full example: `vcf_validator -i /path/to/file.vcf -v 4.1 -l stop -r database,stdout -o /path/to/output/folder/`

