/**
 * Copyright 2014-2017 EMBL - European Bioinformatics Institute
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

#ifndef VCF_STRING_CONSTANTS_HPP
#define VCF_STRING_CONSTANTS_HPP

#include <string>

namespace ebi
{
  namespace vcf
  {
    // VCF versions
    const std::string VCF_V41 = "VCFv4.1";
    const std::string VCF_V42 = "VCFv4.2";
    const std::string VCF_V43 = "VCFv4.3";
    const std::string VCF_V44 = "VCFv4.4";

    // validator, debugulator and assembly_checker command line arguments
    const char STDIN[] = "stdin";
    const char STDOUT[] = "stdout";
    const char WARNING_LEVEL[] = "warning";
    const char ERROR_LEVEL[] = "error";
    const char ERRORS[] = "errors";
    const char STOP_LEVEL[] = "stop";
    const char HELP[] = "help";
    const char VERSION[] = "version";
    const char LEVEL[] = "level";
    const char DATABASE[] = "database";
    const char TEXT[] = "text";
    const char SUMMARY[] = "summary";
    const char VALID[] = "valid";
    const char INPUT[] = "input";
    const char VCF[] = "vcf";
    const char FASTA[] = "fasta";
    const char OUTPUT[] = "output";
    const char OUTDIR[] = "outdir";
    const char REPORT[] = "report";
    const char ASSEMBLY_REPORT[] = "assembly";
    const char NO_MAPPING[] = "no_mapping";

    // options for parser
    const char HELP_OPTION[] = "help,h";
    const char VERSION_OPTION[] = "version,v";
    const char INPUT_OPTION[] = "input,i";
    const char FASTA_OPTION[] = "fasta,f";
    const char ASSEMBLY_REPORT_OPTION[] = "assembly,a";
    const char ERRORS_OPTION[] = "errors,e";
    const char LEVEL_OPTION[] = "level,l";
    const char REPORT_OPTION[] = "report,r";
    const char OUTDIR_OPTION[] = "outdir,o";
    const char OUTPUT_OPTION[] = "output,o";
    const char CHECK_EVIDENCE[] = "require-evidence";
    const char REQUIRE_GENBANK[] = "require-genbank";

    // fields
    const std::string ID = "ID";
    const std::string NUMBER = "Number";
    const std::string TYPE = "Type";
    const std::string DESCRIPTION = "Description";

    // header line columns and metadata keys
    const std::string ALT = "ALT";
    const std::string ASSEMBLY = "assembly";
    const std::string CHROM = "CHROM";
    const std::string CHR = "chr";
    const std::string CONTIG = "contig";
    const std::string FILTER = "FILTER";
    const std::string FORMAT = "FORMAT";
    const std::string INFO = "INFO";
    const std::string PEDIGREE = "PEDIGREE";
    const std::string PEDIGREEDB = "pedigreeDB";
    const std::string POS = "POS";
    const std::string QUAL = "QUAL";
    const std::string REF = "REF";
    const std::string REFERENCE = "reference";
    const std::string SAMPLE = "SAMPLE";
    const std::string SAMPLES = "SAMPLES";

    // types
    const std::string CHARACTER = "Character";
    const std::string FLAG = "Flag";
    const std::string FLOAT = "Float";
    const std::string INTEGER = "Integer";
    const std::string STRING = "String";
    const std::string MISSING_VALUE = ".";

    // number
    const std::string A = "A";
    const std::string G = "G";
    const std::string R = "R";
    const std::string UNKNOWN_CARDINALITY = ".";
    const std::string P = "P";

    // Pass value for Filter
    const std::string PASS = "PASS";

    // ALT for structural variants
    const std::string BND = "BND";
    const std::string CNV = "CNV";
    const std::string DEL = "DEL";
    const std::string DUP = "DUP";
    const std::string INS = "INS";
    const std::string INV = "INV";

    // ALT for gVCF
    const std::string GVCF_NON_VARIANT_ALLELE = "<*>";

    // INFO predefined tags
    const std::string AA = "AA";
    const std::string AC = "AC";
    const std::string AD = "AD";
    const std::string ADF = "ADF";
    const std::string ADR = "ADR";
    const std::string AF = "AF";
    const std::string AN = "AN";
    const std::string BKPTID = "BKPTID";
    const std::string BQ = "BQ";
    const std::string CICN = "CICN";
    const std::string CICNADJ = "CICNADJ";
    const std::string CIEND = "CIEND";
    const std::string CIGAR = "CIGAR";
    const std::string CILEN = "CILEN";
    const std::string CIPOS = "CIPOS";
    const std::string CIRB = "CIRB";
    const std::string CIRUC = "CIRUC";
    const std::string CN = "CN";
    const std::string CNADJ = "CNADJ";
    const std::string DB = "DB";
    const std::string DBRIPID = "DBRIPID";
    const std::string DBVARID = "DBVARID";
    const std::string DGVID = "DGVID";
    const std::string DP = "DP";
    const std::string DPADJ = "DPADJ";
    const std::string END = "END";
    const std::string EVENT = "EVENT";
    const std::string EVENTTYPE = "EVENTTYPE";
    const std::string HOMLEN = "HOMLEN";
    const std::string HOMSEQ = "HOMSEQ";
    const std::string H2 = "H2";
    const std::string H3 = "H3";
    const std::string IMPRECISE = "IMPRECISE";
    const std::string MATEID = "MATEID";
    const std::string MEINFO = "MEINFO";
    const std::string METRANS = "METRANS";
    const std::string MQ = "MQ";
    const std::string MQ0 = "MQ0";
    const std::string NOVEL = "NOVEL";
    const std::string NS = "NS";
    const std::string PARID = "PARID";
    const std::string RB = "RB";
    const std::string RN = "RN";
    const std::string RUC = "RUC";
    const std::string RUL = "RUL";
    const std::string RUB = "RUB";
    const std::string RUS = "RUS";
    const std::string SB = "SB";
    const std::string SOMATIC = "SOMATIC";
    const std::string SVCLAIM = "SVCLAIM";
    const std::string SVLEN = "SVLEN";
    const std::string SVTYPE = "SVTYPE";
    const std::string VALIDATED = "VALIDATED";
    const std::string THOUSAND_G = "1000G";

    // FORMAT predefined tags
    const std::string AHAP = "AHAP";
    const std::string CNL = "CNL";
    const std::string CNP = "CNP";
    const std::string CNQ = "CNQ";
    const std::string EC = "EC";
    const std::string FT = "FT";
    const std::string GL = "GL";
    const std::string GLE = "GLE";
    const std::string GP = "GP";
    const std::string GQ = "GQ";
    const std::string GT = "GT";
    const std::string HAP = "HAP";
    const std::string HQ = "HQ";
    const std::string NQ = "NQ";
    const std::string PL = "PL";
    const std::string PQ = "PQ";
    const std::string PS = "PS";
    const std::string PSL = "PSL";
    const std::string PSO = "PSO";
    const std::string PSQ = "PSQ";

    // File extensions
    const std::string VCF_EXT = ".vcf";
    const std::string FASTA_EXT = ".fa";
    const std::string FASTA_GZ_EXT = ".fa.gz";
    const std::string INDEX_EXT = ".fai";
    const std::string VCF_GZ_EXT = ".vcf.gz";
    const std::string VCF_BZ2_EXT = ".vcf.bz2";

    // Compressed file extensions
    const std::string BZ2 = ".bz2";
    const std::string NO_EXT = "";
    const std::string RAR = ".rar";
    const std::string TAR = ".tar";
    const std::string GZ = ".gz";
    const std::string XZ = ".xz";
    const std::string Z = ".Z";
    const std::string ZIP = ".zip";
    const std::string ZLIB = ".z";

    // Network protocols
    const std::string HTTP = "http://";
    const std::string HTTPS = "https://";
    const std::string FTP = "ftp://";
    const std::string FTPS = "ftps://";

    // ENA REST API for remote fasta access
    const std::string ENA_API_FASTA_URL = "https://www.ebi.ac.uk/ena/browser/api/fasta/";

    //SVCLAIM types
    const std::string D = "D";
    const std::string J = "J";
    const std::string DJ = "DJ";

    //internal keys - with invalid chars to differentiate from valid IDs
    const std::string _BRKEND = "BRK<END,";
    const std::string _OTHER = "OTHER<,";
  }
}

#endif // VCF_STRING_CONSTANTS_HPP
