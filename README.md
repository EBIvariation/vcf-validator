# vcf-validator | [![Build Status](https://github.com/EBIvariation/vcf-validator/actions/workflows/build.yml/badge.svg?branch=master)](https://github.com/EBIvariation/vcf-validator/actions/workflows/build.yml/badge.svg?branch=master) [![Build status](https://ci.appveyor.com/api/projects/status/vt4ldlwhm91e3n49/branch/master?svg=true)](https://ci.appveyor.com/project/ebivariation-bot/vcf-validator/branch/master)
Validation suite for Variant Call Format (VCF) files. Please find below instructions on how to download and run, or read the wiki for more details about checks already implemented.

This suite includes all the checks from the vcftools suite as well as additional lexical, syntactic and semantic analysis of the VCF input. If any inconsistencies are found, they are classified in one of the following categories:

* Errors: Violations of the VCF specification
* Warnings: A recommendation is not followed or potentially wrong information appears in the file

These tools have been implemented using C++11.


## Installation

### From Binaries

The vcf-validator is built with all the dependencies included. It can be downloaded directly from the [latest release](https://github.com/EBIvariation/vcf-validator/releases) for the most stable experience using vcf-validator. Along with the release notes, you will find the executables `vcf_validator` and `vcf_assembly_checker` for Linux, macOS and Windows. For Windows, please also download the libraries in the [lib/windows_specific/](https://github.com/EBIvariation/vcf-validator/tree/master/lib/windows_specific/) folder.

### From conda

Starting from [v0.9.6](https://github.com/EBIvariation/vcf-validator/releases/tag/v0.9.6), you can install vcf-validator via conda using 

```
conda install -c bioconda vcf-validator
```

## Run

### Validator

vcf-validator accepts both compressed and non-compressed input VCF files. Supported compression formats are .gz and .bz2. For other formats such as .zip, the `zcat` command and a pipe can be used (see below).

Reading uncompressed files:
* File path as argument: `vcf_validator -i /path/to/file.vcf`
* Standard input: `vcf_validator < /path/to/file.vcf`
* Standard input from pipe: `cat /path/to/file.vcf | vcf_validator`

Reading compressed files:
* File path as argument: `vcf_validator -i /path/to/compressed_file.vcf.gz`
* Standard input: `vcf_validator < /path/to/compressed_file.vcf.bz2`
* Standard input from pipe: `zcat /path/to/compressed_file.vcf.zip | vcf_validator`

The validation level can be configured using `-l` / `--level`. This parameter is optional and accepts 3 values:

* error: Display only syntax errors
* warning: Display both syntax and semantic, both errors and warnings (default)
* stop: Stop after the first syntax error is found

Different types of validation reports can be written with the `-r` / `--report` option. Several ones may be specified in the same execution, using commas to separate each type (without spaces, e.g.: `-r summary,text`).

* summary: Write a human-readable summary report to a file. This includes one line for each type of error and the number of occurrences, along with the first line that shows that type of error (default)
* text: Write a human-readable report to a file, with one description line for each VCF line that has an error.

Each report is written into its own file and it is named after the input file, followed by a timestamp. The default output directory is the same as the input file's if provided using `-i`, or the current directory if using the standard input; it can be changed with the `-o` / `--outdir` option.

A flag for validating evidence can be passed with `--require-evidence`. This will validate whether the VCF includes either Genotypes or Allele Frequencies. This flag will be **false** by default.

### Debugulator

Removed debugulator support and ODB dependency.

### Assembly Checker

vcf-assembly-checker assesses the correctness of a VCF file with respect to a FASTA file (that should contain the reference sequence). The assembly checker reads the CHR, POS and REF columns from the VCF, and for each line, looks into the FASTA file to see if the REF allele matches that region. A VCF file is considered valid if all the variants match the sequence in the FASTA file.

vcf-assembly-checker requires a FASTA-index file with extension `.fai` for efficient reading of the FASTA file.

If the VCF and FASTA files to compare don't use the same contig name nomenclature (GenBank, RefSeq, UCSC...) you may provide an assembly report file to map between them, using the `-a` option.

vcf-assembly-checker accepts both compressed and non-compressed input VCF files. Supported compression formats are .gz and .bz2. For other formats such as .zip, the `zcat` command and a pipe can be used (see below).

Reading uncompressed files:
* File path as argument: `vcf_assembly_checker -i /path/to/vcf-file -f /path/to/fasta-file -a /path/to/assembly-report`
* Standard input: `vcf_assembly_checker -f /path/to/fasta-file -a /path/to/assembly-report < /path/to/vcf-file`
* Standard input from pipe: `cat /path/to/vcf-file | vcf_assembly_checker -f /path/to/fasta-file -a /path/to/assembly-report`

Reading compressed files:
* File path as argument: `vcf_assembly_checker -i /path/to/compressed-vcf-file -f /path/to/fasta-file -a /path/to/assembly-report`
* Standard input: `vcf_assembly_checker -f /path/to/fasta-file -a /path/to/assembly-report < /path/to/compressed-vcf-file`
* Standard input from pipe: `zcat /path/to/compressed-vcf-file | vcf_assembly_checker -f /path/to/fasta-file -a /path/to/assembly-report`

Different types of validation reports can be written with the `-r` / `--report` option. Several ones may be specified in the same execution, using commas to separate each type (without spaces, e.g.: `-r summary,valid,text`).

* `summary` - Logs the number of matches, total variants checked and percentage of correctness of VCF file on the terminal.
* `valid` - Write valid lines (including meta-info lines) from the input VCF file into an output file.
* `text` - Write a human readable into file, containing errors and warnings generated while checking a VCF file.

Each report is written into its own file and it is named after the input file, followed by a timestamp. The default output directory is the same as the input file's if provided using `-i`, or the current directory if using the standard input; it can be changed with the `-o` / `--outdir` option.

### Examples

Simple example: `vcf_validator -i /path/to/file.vcf`

Full example: `vcf_validator -i /path/to/file.vcf -l stop -r summary,stdout -o /path/to/output/folder/`

Assembly Checker example:

```
# Pass input (-i) and FASTA file (-f) paths 
vcf_assembly_checker -i /path/to/file.vcf -f /path/to/fasta_file.fa

# Pass input (-i) paths but read VCF input from command line (<)
# Report output required (-r)
vcf_assembly_checker -f /path/to/fasta.fa -r text < /path/to/file.vcf

# Pass input (-i), FASTA (-f) and assembly report (-a) paths
# Report output required (-r)
# If submitting to EVA, check if contigs have Genbank accessions (--require-genbank)
   # see https://www.ebi.ac.uk/eva/?Submit-Data  
vcf_assembly_checker -i /path/to/file.vcf -f /path/to/fasta_file.fa -r valid -a /path/to/assembly_report --require-genbank
```


## Build

If you would like to use an unreleased version of vcf-validator, you can clone the repository and build it under 3 platforms: Linux, macOS and Windows. A statically linked executable will be generated, which means you won't need to install any dependencies in the machine that will run it; only install the dependencies in the machine that will build it.

If you plan to make changes, make sure to check the [docs/developer-guide.md](docs/developer-guide.md).

### Linux

The build has been tested on the following compilers:
* Clang 10
* GCC 9

#### Dependencies

Some dependencies have to be installed manually and others can be installed automatically. We recommend using the automatic install when possible.

Dependency | Version | Instalation method
:--------: | :-----: | :----:
Cmake | \>=2.8 | manual
bzip2 | 1.0.6 | manual or automatic
zlib | 1.2.11 | manual or automatic
Boost* | \>=1.65 | manual or automatic

*: See below the exact subset of Boost packages required.

If you are using Ubuntu 16, you can prepare all dependencies and compile the Validation Suite with these commands:
```
sudo apt-get install cmake wget build-essential
./install_dependencies.sh linux
mkdir build && cd build && cmake -G "Unix Makefiles" ..
make
```

The VCF Validation Suite binaries will be created in the `build/bin` subfolder. Optionally, read below for the explanation of the previous commands.

##### CMake and automatic installation
The automatic install **requires** CMake and wget to be installed before running the script (as zlib require them to be installed). Also, the script will compile some dependencies so a compilation environment is needed. If you are using Ubuntu, you can install all that with the command `sudo apt-get install cmake wget build-essential`. After installing that, use the command `./install_dependencies.sh linux`.

A subfolder named `linux_dependencies` will be created, with all the required libraries copied into it. 

##### Boost

**Note**: You can ignore this section if you are using the `install_dependencies.sh` script.

The dependencies are the Boost library core, and its submodules: Boost.filesystem, Boost.iostreams, Boost.program_options, Boost.regex, Boost.log and Boost.system.
If you are using Ubuntu, you can install them with the command `sudo apt-get install libboost-dev libboost-filesystem-dev libboost-iostreams-dev libboost-program-options-dev libboost-regex-dev libboost-log-dev`.

##### ODB

ODB dependency is removed, ODB and debugulator are no longer in build.

#### Compile

In order to create the build scripts, please run `cmake` with your preferred generator. For instance, `mkdir build && cd build && cmake -G "Unix Makefiles" ..` will create Makefiles, and to build the binaries, you will need to run `make`.

The VCF Validation Suite binaries will be created in the `build/bin` subfolder.


### macOS

On macOS the binaries obtained will only have system libraries dynamically linked. This means you will need to install dependencies to build vcf-validator but not to run it.

#### Dependencies

Some dependencies have to be installed manually and others can be installed automatically. We recommend using the automatic install when possible.

Dependency | Version | Instalation method
:--------: | :-----: | :----:
Cmake | \>=2.8 | manual
bzip2 | 1.0.6 | manual or automatic
zlib | 1.2.11 | manual or automatic
Boost | \>=1.65 | manual

You can prepare all dependencies and compile the Validation Suite with these commands:
```
brew install cmake boost sqlite3
./install_dependencies.sh osx
mkdir build && cd build && cmake -G "Unix Makefiles" ..
make
```

The VCF Validation Suite binaries will be created in the `build/bin` subfolder. Optionally, read below for the explanation of the previous commands.

##### CMake and automatic installation

The automatic install requires CMake and wget to be installed before running the script (as zlib require them to be installed). In order to set up the environment to compile the dependencies, first you need to run `brew install cmake boost`.

A subfolder named `osx_dependencies` will be created, with all the required libraries copied into it.

#### Compile

In order to create the build scripts, please run `cmake` with your preferred generator. For instance, `mkdir build && cd build && cmake -G "Unix Makefiles" ..` will create Makefiles, and to build the binaries, you will need to run `make`.

The VCF Validation Suite binaries will be created in the `bin` subfolder.

#### Dependencies

##### Compression libraries

You will need to download the bzip2 and zlib source code, from [here](http://www.bzip.org/downloads.html) and [here](https://zlib.net/zlib1211.zip) respectively.

##### Boost

The dependencies are the Boost library core, and its submodules: Boost.filesystem, Boost.iostreams, Boost.program_options, Boost.regex, Boost.log and Boost.system. You will need to compile them with zlib and bzip2 support and statically linking the runtime libraries.

* Download Boost from [here](https://www.boost.org/users/download/) and uncompress it
* From the directory where Boost was uncompressed, run these commands:

```
bootstrap
.\b2 --with-atomic --with-chrono --with-date_time --with-filesystem --with-log --with-program_options --with-regex --with-system --with-thread --with-iostreams -sBZIP2_SOURCE=path\to\bzip2-1.x.x -sZLIB_SOURCE=path\to\zlib-1.x.x runtime-link=static --build-type=complete
```

* Add boost_1_xx_x/stage/lib folder to the environment variable `LIB`
* Add boost_1_xx_x folder to the environment variable `INCLUDE`

##### ODB

ODB dependency is removed, ODB and debugulator are no longer in build.

#### Compile

In order to create the build scripts and compile vcf-validator, please run the following commands from the project root folder:

```
cmake -DCMAKE_BUILD_TYPE=Release -G "NMake Makefiles" /path/to/CMakeLists.txt
nmake
```

Binaries will be created in the `bin` subfolder.

In order to run those binaries, you will need to add the `lib/windows_specific` directory to the `PATH`. This will allow the dll files inside that directory to be found.


## Deliverables

The following binaries are be created after successful build:

* `vcf_validator`: VCF validation tool
* `vcf_assembly_checker`: variant checking tool against FASTA sequence
* `test_validation_suite` and derivatives: testing correct behaviour of the tools listed above


## Tests

Unit tests can be run using the binary `bin/test_validation_suite` or, if the generator supports it, a command like `make test`. The first option may provide a more detailed output in case of test failure.

**Note**: Tests that require input files will only work when executed with `make test` or running the binary from the project root folder (not the `bin` subfolder).

## Generate code from descriptors

Code generated from descriptors shall be always up-to-date in the GitHub repository. If changes to the source descriptors were necessary, please generate the Ragel machines C code from `.ragel` files using:

```
ragel -G2 src/vcf/vcf_v41.ragel -o inc/vcf/validator_detail_v41.hpp
ragel -G2 src/vcf/vcf_v42.ragel -o inc/vcf/validator_detail_v42.hpp
ragel -G2 src/vcf/vcf_v43.ragel -o inc/vcf/validator_detail_v43.hpp
ragel -G2 src/vcf/vcf_v44.ragel -o inc/vcf/validator_detail_v44.hpp
```

## Miscellaneous
