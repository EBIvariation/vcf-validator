cmake_minimum_required (VERSION 2.8)
project (vcf-validator CXX C)

set (vcf-validator_VERSION_MAJOR 0)
set (vcf-validator_VERSION_MINOR 2)

set (CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -g")
set (CMAKE_C_FLAGS " -DSQLITE_OMIT_LOAD_EXTENSION")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories (inc)
include_directories (lib)

# Application modules

set (MOD_VCF_SOURCES
        inc/vcf/error.hpp
        inc/vcf/error_policy.hpp
        inc/vcf/file_structure.hpp
        inc/vcf/fixer.hpp
        inc/vcf/meta_entry_visitor.hpp
        inc/vcf/normalizer.hpp
        inc/vcf/optional_policy.hpp
        inc/vcf/parse_policy.hpp
        inc/vcf/parsing_state.hpp
        inc/vcf/record.hpp
        inc/vcf/record_cache.hpp
        inc/vcf/report_reader.hpp
        inc/vcf/report_writer.hpp
        inc/vcf/sqlite_report.hpp
        inc/vcf/validator_detail_v41.hpp
        inc/vcf/validator_detail_v42.hpp
        inc/vcf/validator_detail_v43.hpp
        inc/vcf/validator.hpp
        
        src/vcf/abort_error_policy.cpp
        src/vcf/error.cpp
        src/vcf/meta_entry.cpp
        src/vcf/normalizer.cpp
        src/vcf/parsing_state.cpp
        src/vcf/record.cpp
        src/vcf/report_error_policy.cpp
        src/vcf/source.cpp
        src/vcf/sqlite_report.cpp
        src/vcf/store_parse_policy.cpp
        src/vcf/validate_optional_policy.cpp
        src/vcf/validator.cpp
        )
add_library(mod_vcf ${MOD_VCF_SOURCES})

set (V41_TESTS test/vcf/parser_v41_test.cpp)
set (V42_TESTS test/vcf/parser_v42_test.cpp)
set (V43_TESTS test/vcf/parser_v43_test.cpp)
set (ALL_TESTS
        test/vcf/metaentry_test.cpp
        test/vcf/normalize_test.cpp
        test/vcf/parser_test_aux.hpp
        test/vcf/parser_v41_test.cpp
        test/vcf/parser_v42_test.cpp
        test/vcf/parser_v43_test.cpp
        test/vcf/record_cache_test.cpp
        test/vcf/record_test.cpp
        test/vcf/report_writer_test.cpp
        test/vcf/test_utils.hpp
        )

# Static build extra flags
if (BUILD_STATIC)
  set (BUILD_SHARED_LIBRARIES OFF)
  set (CMAKE_EXE_LINKER_FLAGS "-static")
  set (CMAKE_FIND_LIBRARY_SUFFIXES .a)
  set (CMAKE_EXE_LINK_DYNAMIC_C_FLAGS)       # remove -Wl,-Bdynamic
  set (CMAKE_EXE_LINK_DYNAMIC_CXX_FLAGS)
  set (CMAKE_SHARED_LIBRARY_C_FLAGS)         # remove -fPIC
  set (CMAKE_SHARED_LIBRARY_CXX_FLAGS)
  set (CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)    # remove -rdynamic
  set (CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
  set(Boost_USE_STATIC_LIBS ON) # only find static libs
endif (BUILD_STATIC)

# Dependency libraries
find_package (Boost COMPONENTS filesystem program_options regex system REQUIRED )
include_directories (${Boost_INCLUDE_DIR} )

add_library(sqlite3 lib/sqlite/sqlite3.c)
find_package (Threads REQUIRED)

# Application tests
add_executable (test_validator_v41 test/main_test.cpp ${V41_TESTS})
target_link_libraries (test_validator_v41 mod_vcf ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
enable_testing ()
add_test (NAME ValidatorTests_v41 COMMAND test_validator_v41)

add_executable (test_validator_v42 test/main_test.cpp ${V42_TESTS})
target_link_libraries (test_validator_v42 mod_vcf ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
enable_testing ()
add_test (NAME ValidatorTests_v42 COMMAND test_validator_v42)

add_executable (test_validator_v43 test/main_test.cpp ${V43_TESTS})
target_link_libraries (test_validator_v43 mod_vcf ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
enable_testing ()
add_test (NAME ValidatorTests_v43 COMMAND test_validator_v43)

add_executable (test_validator test/main_test.cpp ${ALL_TESTS})
target_link_libraries (test_validator mod_vcf ${Boost_LIBRARIES} sqlite3 ${CMAKE_THREAD_LIBS_INIT})
enable_testing ()
add_test (NAME ValidatorTests COMMAND test_validator)


# Build binary
add_executable (vcf_validator src/main.cpp)
target_link_libraries (vcf_validator mod_vcf ${Boost_LIBRARIES} sqlite3 ${CMAKE_THREAD_LIBS_INIT})

add_executable (vcf_debugulator src/debugulator_main.cpp)
target_link_libraries (vcf_debugulator mod_vcf ${Boost_LIBRARIES} sqlite3 ${CMAKE_THREAD_LIBS_INIT})
