cmake_minimum_required (VERSION 2.8)
project (vcf-validator CXX C)

set (vcf-validator_VERSION_MAJOR 0)
set (vcf-validator_VERSION_MINOR 9)
set (vcf-validator_VERSION_PATCH 7)

configure_file (
        "${PROJECT_SOURCE_DIR}/inc/cmake_config.hpp.in"
        "${PROJECT_SOURCE_DIR}/inc/cmake_config.hpp"
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# Detect OS
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  message (STATUS "Operating system detected: Linux")
  set (LINUX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  message (STATUS "Operating system detected: OSX")
  set (OSX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  message (STATUS "Operating system detected: Windows")
  set (WINDOWS TRUE)
else ()
  message (ERROR "Operating system not recognised. Expected Windows, Linux or Darwin, but found ${CMAKE_SYSTEM_NAME}")
endif ()

# Include directories
message("include_directories (inc)")
message("include_directories (lib)")

include_directories (inc)
include_directories (lib)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-unknown-pragmas") # No unknown pragmas: it's ok that gcc doesn't know about ODB's pragmas

# Dynamic libraries for boost
set (Boost_USE_STATIC_LIBS OFF)

find_package (Threads REQUIRED)
find_package (Boost COMPONENTS filesystem iostreams program_options regex log thread system REQUIRED )
if(Boost_FOUND)
  message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
  include_directories(${Boost_INCLUDE_DIRS})
endif()

find_package(CURL REQUIRED)
if(CURL_FOUND)
  message("CURL_INCLUDE_DIRS: ${CURL_INCLUDE_DIRS}")
  include_directories(${CURL_INCLUDE_DIRS})
endif()

message("Boost_LIBRARIES: ${Boost_LIBRARIES}")
message("Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
message("CURL_LIBRARIES: ${CURL_LIBRARIES}")
message("CMAKE_THREAD_LIBS_INIT: ${CMAKE_THREAD_LIBS_INIT}")

set (THIRD_PARTY_LIBRARIES
        ${Boost_LIBRARIES}
        ${CURL_LIBRARIES}
        dl
        ${CMAKE_THREAD_LIBS_INIT}
        )


set (MOD_VCF_SOURCES
        inc/fasta/faidx.hpp
        inc/fasta/fasta.hpp
        inc/util/curl_easy.hpp
        inc/vcf/assembly_checker.hpp
        inc/vcf/assembly_check_report_writer.hpp
        inc/vcf/compression.hpp
        inc/vcf/error_policy.hpp
        inc/vcf/file_structure.hpp
        inc/vcf/meta_entry_visitor.hpp
        inc/vcf/normalizer.hpp
        inc/vcf/optional_policy.hpp
        inc/vcf/parse_policy.hpp
        inc/vcf/parsing_state.hpp
        inc/vcf/record.hpp
        inc/vcf/record_cache.hpp
        inc/vcf/report_reader.hpp
        inc/vcf/report_writer.hpp
        inc/vcf/string_constants.hpp
        inc/vcf/summary_report_writer.hpp
        inc/vcf/validator_detail_v41.hpp
        inc/vcf/validator_detail_v42.hpp
        inc/vcf/validator_detail_v43.hpp
        inc/vcf/validator_detail_v44.hpp
        inc/vcf/validator.hpp

        src/fasta/faidx.cpp
        src/fasta/fasta.cpp
        src/util/curl_easy.cpp
        src/vcf/abort_error_policy.cpp
        src/vcf/assembly_checker.cpp
        src/vcf/compression.cpp
        src/vcf/meta_entry.cpp
        src/vcf/normalizer.cpp
        src/vcf/parsing_state.cpp
        src/vcf/record.cpp
        src/vcf/report_error_policy.cpp
        src/vcf/source.cpp
        src/vcf/store_parse_policy.cpp
        src/vcf/validate_optional_policy.cpp
        src/vcf/validator.cpp
        )
add_library (mod_vcf STATIC ${MOD_VCF_SOURCES})
target_link_libraries (mod_vcf ${THIRD_PARTY_LIBRARIES})

set (LIBRARIES_TO_LINK
        mod_vcf
        ${Boost_LIBRARIES}
        ${CURL_LIBRARIES}
        dl
        ${CMAKE_THREAD_LIBS_INIT}
        )


# Build tests
set (V41_TESTS test/vcf/parser_v41_test.cpp)
set (V42_TESTS test/vcf/parser_v42_test.cpp)
set (V43_TESTS test/vcf/parser_v43_test.cpp)
set (V44_TESTS test/vcf/parser_v44_test.cpp)
set (ALL_TESTS
        test/assembly_report/assembly_report_test.cpp
        test/fasta/faidx_test.cpp
        test/fasta/fasta_test.cpp
        test/vcf/assembly_checker_integration_test.cpp
        test/vcf/assembly_checker_test.cpp
        test/vcf/compressed_file_test.cpp
        test/vcf/metaentry_test.cpp
        test/vcf/normalize_test.cpp
        test/vcf/optional_policy_test.cpp
        test/vcf/parser_test_aux.hpp
        test/vcf/parser_v41_test.cpp
        test/vcf/parser_v42_test.cpp
        test/vcf/parser_v43_test.cpp
        test/vcf/parser_v44_test.cpp
        test/vcf/predefined_info_tags_test.cpp
        test/vcf/predefined_format_tags_test.cpp
        test/vcf/record_cache_test.cpp
        test/vcf/record_test.cpp
        test/vcf/report_writer_test.cpp
        test/vcf/test_utils.hpp
        )

add_executable (test_validator_v41 test/main_test.cpp ${V41_TESTS})
target_link_libraries (test_validator_v41 ${LIBRARIES_TO_LINK})
enable_testing ()
add_test (NAME ValidatorTests_v41 COMMAND test_validator_v41)

add_executable (test_validator_v42 test/main_test.cpp ${V42_TESTS})
target_link_libraries (test_validator_v42 ${LIBRARIES_TO_LINK})
enable_testing ()
add_test (NAME ValidatorTests_v42 COMMAND test_validator_v42)

add_executable (test_validator_v43 test/main_test.cpp ${V43_TESTS})
target_link_libraries (test_validator_v43 ${LIBRARIES_TO_LINK})
enable_testing ()
add_test (NAME ValidatorTests_v43 COMMAND test_validator_v43)


add_executable (test_validator_v44 test/main_test.cpp ${V44_TESTS})
target_link_libraries (test_validator_v44 ${LIBRARIES_TO_LINK})
enable_testing ()
add_test (NAME ValidatorTests_v44 COMMAND test_validator_v44)

add_executable (test_validation_suite test/main_test.cpp ${ALL_TESTS})
target_link_libraries (test_validation_suite ${LIBRARIES_TO_LINK})
enable_testing ()
add_test (NAME ValidatorTests COMMAND test_validation_suite)

# Build application binaries
add_executable (vcf_validator src/validator_main.cpp)
target_link_libraries (vcf_validator ${LIBRARIES_TO_LINK})

add_executable (vcf_assembly_checker src/assembly_checker_main.cpp)
target_link_libraries (vcf_assembly_checker ${LIBRARIES_TO_LINK})
