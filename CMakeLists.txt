cmake_minimum_required (VERSION 2.8)
project (vcf-validator CXX C)

set (vcf-validator_VERSION_MAJOR 0)
set (vcf-validator_VERSION_MINOR 9)
set (vcf-validator_VERSION_PATCH 6)

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
include_directories (inc)
include_directories (lib)

if (DEFINED EXT_LIB_PATH AND NOT EXISTS "${EXT_LIB_PATH}")
  message (FATAL_ERROR "The provided folder for dependencies (EXT_LIB_PATH=${EXT_LIB_PATH}) doesn't exist. Please, either provide a correct folder or don't provide it (and remove cmake cache) to search in default folders.")
endif()

# default folder for dependencies (written by install_dependencies.sh), unless provided by the user
if (LINUX)
  set (DEFAULT_EXT_LIB_PATH "${PROJECT_SOURCE_DIR}/linux_dependencies")
  if (NOT EXISTS "${DEFAULT_EXT_LIB_PATH}")
    set (EXT_LIB_PATH "/usr/local/bin" CACHE STRING "Absolute path to libraries")
  else()
    set (EXT_LIB_PATH "${DEFAULT_EXT_LIB_PATH}" CACHE STRING "Absolute path to libraries") # cached: this instruction is ignored if the user provided the variable
    set (ODB_PATH "${EXT_LIB_PATH}/odb-2.4.0-x86_64-linux-gnu/bin/" CACHE STRING "Path to odb binaries")
    if (EXISTS "${EXT_LIB_PATH}/boost")
      set (SELF_COMPILED_BOOST TRUE)
    else ()
      set (SELF_COMPILED_BOOST FALSE)
    endif()
  endif()
elseif (OSX)
  set (EXT_LIB_PATH "${PROJECT_SOURCE_DIR}/osx_dependencies" CACHE STRING "Absolute path to libraries")
  set (ODB_PATH "${EXT_LIB_PATH}/odb-2.4.0-i686-macosx/bin/" CACHE STRING "Path to odb binaries")
  if (NOT EXISTS "${EXT_LIB_PATH}")
    message(FATAL_ERROR "Please run first install_dependencies.sh osx")
  endif()
elseif (WINDOWS)
  include_directories (lib/sqlite)            # Windows specific
  set (EXT_LIB_PATH "${PROJECT_SOURCE_DIR}/lib/windows_specific" CACHE STRING "Absolute path to libraries")
  if (NOT EXISTS "${PROJECT_SOURCE_DIR}/windows_dependencies")
    message(FATAL_ERROR "Please run first install_dependencies.bat")
  endif ()
  include_directories (windows_dependencies)
  include_directories (windows_dependencies/curl/include)
endif ()

include_directories ("${EXT_LIB_PATH}")
if (NOT OSX)
  include_directories ("${EXT_LIB_PATH}/curl/include")
endif ()

# Compiler and linkers flags
if (LINUX)
  # Static Build Extra Flags for Linux Static Build
  set (BUILD_SHARED_LIBS OFF)
  set (CMAKE_EXE_LINKER_FLAGS "-static")
  set (CMAKE_FIND_LIBRARY_SUFFIXES .a)
  set (CMAKE_EXE_LINK_DYNAMIC_C_FLAGS)       # remove -Wl,-Bdynamic
  set (CMAKE_EXE_LINK_DYNAMIC_CXX_FLAGS)
  set (CMAKE_SHARED_LIBRARY_C_FLAGS)         # remove -fPIC
  set (CMAKE_SHARED_LIBRARY_CXX_FLAGS)
  set (CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)    # remove -rdynamic
  set (CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
  set (Boost_USE_STATIC_LIBS ON)             # only find static libs
elseif (OSX)
  # Mac build not fully static. include system libraries to be dynamic
  set (CMAKE_EXE_LINKER_FLAGS)
  set (Boost_USE_STATIC_LIBS ON)             # only find static libs
elseif (WINDOWS)
  set (Boost_USE_STATIC_LIBS ON)             # only find static libs
  set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT") # also requires boost with runtime-link=static
  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd") # also requires boost with runtime-link=static
endif ()

# Build type
if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE  "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

message(STATUS "Build type is ${CMAKE_BUILD_TYPE}")
find_package (Threads REQUIRED)

# Flags

if (LINUX OR OSX)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-unknown-pragmas") # No unknown pragmas: it's ok that gcc doesn't know about ODB's pragmas
  set (CMAKE_C_FLAGS " -DSQLITE_ENABLE_UNLOCK_NOTIFY -DSQLITE_OMIT_LOAD_EXTENSION") # Needed to statically link ODB
  if (LINUX AND SELF_COMPILED_BOOST)
    set (BOOST_CUSTOM_INCLUDE_DIR ${EXT_LIB_PATH}/boost)
    include_directories (${BOOST_CUSTOM_INCLUDE_DIR} )
    set (BOOST_LIBS_DIR ${BOOST_CUSTOM_INCLUDE_DIR}/stage/lib)
    set (Boost_LIBRARIES
            ${BOOST_LIBS_DIR}/libboost_atomic.a
            ${BOOST_LIBS_DIR}/libboost_chrono.a
            ${BOOST_LIBS_DIR}/libboost_date_time.a
            ${BOOST_LIBS_DIR}/libboost_filesystem.a
            ${BOOST_LIBS_DIR}/libboost_iostreams.a
            ${BOOST_LIBS_DIR}/libboost_log.a
            ${BOOST_LIBS_DIR}/libboost_log_setup.a
            ${BOOST_LIBS_DIR}/libboost_program_options.a
            ${BOOST_LIBS_DIR}/libboost_regex.a
            ${BOOST_LIBS_DIR}/libboost_thread.a
            )
  else ()
    find_package (Boost COMPONENTS filesystem iostreams program_options regex log thread system REQUIRED )
    include_directories (${Boost_INCLUDE_DIR} )
  endif()
elseif (WINDOWS)
  add_definitions(-DCURL_STATICLIB) # Needed to statically link libcurl
  add_definitions(-DNOMINMAX) # Needed to suppress min and max definitions by Windows
endif ()


# Application modules
add_library (mod_sqlite3 STATIC lib/sqlite/sqlite3.c)

if (LINUX)
  set (THIRD_PARTY_LIBRARIES
    ${Boost_LIBRARIES}
    ${EXT_LIB_PATH}/curl/lib/libcurl.a
    ${EXT_LIB_PATH}/c-ares/lib/libcares.a
    ${EXT_LIB_PATH}/openssl/lib/libssl.a
    ${EXT_LIB_PATH}/openssl/lib/libcrypto.a
    ${EXT_LIB_PATH}/libbz2.a
    ${EXT_LIB_PATH}/libz.a
    ${EXT_LIB_PATH}/libodb-sqlite.a
    ${EXT_LIB_PATH}/libodb.a
    mod_sqlite3
    ${CMAKE_THREAD_LIBS_INIT}
  )
elseif (OSX)
  set (THIRD_PARTY_LIBRARIES
    ${Boost_LIBRARIES}
    libcurl.a
    ${EXT_LIB_PATH}/libodb-sqlite.a
    ${EXT_LIB_PATH}/libodb.a
    mod_sqlite3
    ${CMAKE_THREAD_LIBS_INIT}
  )
elseif (WINDOWS)
  set (THIRD_PARTY_LIBRARIES
    ${EXT_LIB_PATH}/odb-sqlite.lib
    ${EXT_LIB_PATH}/odb.lib
    mod_sqlite3
    windows_dependencies/curl/lib/libcurl
    ${CMAKE_THREAD_LIBS_INIT}
  )
endif ()

set (MOD_ODB_SOURCES)
set (ODB_MAPPING_CLASSES inc/vcf/error.hpp)
foreach (_file ${ODB_MAPPING_CLASSES})
  string (REPLACE ".hpp" "-odb.cpp" gencppfile ${_file})
  string (REPLACE "inc" "src" right_place_gencppfile ${gencppfile})
  if (LINUX OR OSX)
    add_custom_command (
      OUTPUT ${CMAKE_HOME_DIRECTORY}/${right_place_gencppfile}
      COMMAND cd ${CMAKE_HOME_DIRECTORY}/ && ${ODB_PATH}odb --include-prefix vcf --std c++11 -d sqlite --generate-query --generate-schema
      --hxx-suffix .hpp --ixx-suffix .ipp --cxx-suffix .cpp
      --output-dir ${CMAKE_HOME_DIRECTORY}/inc/vcf/ ${_file}
      && mv ${CMAKE_HOME_DIRECTORY}/${gencppfile} ${CMAKE_HOME_DIRECTORY}/${right_place_gencppfile}
      DEPENDS ${_file}
      COMMENT "Building odb for ${_file}"
    )
  endif ()
  list (APPEND MOD_ODB_SOURCES ${right_place_gencppfile})
endforeach ()
add_library (mod_odb STATIC ${MOD_ODB_SOURCES})
target_link_libraries (mod_odb ${THIRD_PARTY_LIBRARIES})

set (MOD_VCF_SOURCES
  inc/fasta/faidx.hpp
  inc/fasta/fasta.hpp
  inc/util/curl_easy.hpp
  inc/vcf/assembly_checker.hpp
  inc/vcf/assembly_check_report_writer.hpp
  inc/vcf/compression.hpp
  inc/vcf/debugulator.hpp
  inc/vcf/error_policy.hpp
  inc/vcf/file_structure.hpp
  inc/vcf/fixer.hpp
  inc/vcf/meta_entry_visitor.hpp
  inc/vcf/normalizer.hpp
  inc/vcf/odb_report.hpp
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
  src/vcf/debugulator.cpp
  src/vcf/fixer.cpp
  src/vcf/meta_entry.cpp
  src/vcf/normalizer.cpp
  src/vcf/odb_report.cpp
  src/vcf/parsing_state.cpp
  src/vcf/record.cpp
  src/vcf/report_error_policy.cpp
  src/vcf/source.cpp
  src/vcf/store_parse_policy.cpp
  src/vcf/validate_optional_policy.cpp
  src/vcf/validator.cpp
)
add_library (mod_vcf STATIC ${MOD_VCF_SOURCES})
add_dependencies (mod_vcf mod_odb) # works even without this if we add mod_vcf as target_link_libraries
target_link_libraries (mod_vcf ${THIRD_PARTY_LIBRARIES} mod_odb)


# Libraries to link with executables
if (LINUX)
  set (LIBRARIES_TO_LINK
    mod_vcf
    mod_odb
    ${EXT_LIB_PATH}/curl/lib/libcurl.a
    ${EXT_LIB_PATH}/c-ares/lib/libcares.a
    ${EXT_LIB_PATH}/openssl/lib/libssl.a
    ${EXT_LIB_PATH}/openssl/lib/libcrypto.a
    ${Boost_LIBRARIES}
    ${EXT_LIB_PATH}/libbz2.a
    ${EXT_LIB_PATH}/libz.a
    ${EXT_LIB_PATH}/libodb-sqlite.a
    ${EXT_LIB_PATH}/libodb.a
    mod_sqlite3
    dl
    ${CMAKE_THREAD_LIBS_INIT}
  )
elseif (OSX)
  set (LIBRARIES_TO_LINK
    mod_vcf
    mod_odb
    libcurl.a
    ${Boost_LIBRARIES}
    ${EXT_LIB_PATH}/libodb-sqlite.a
    ${EXT_LIB_PATH}/libodb.a
    mod_sqlite3
    dl
    ${CMAKE_THREAD_LIBS_INIT}
  )
elseif (WINDOWS)
  set (LIBRARIES_TO_LINK
    mod_vcf
    mod_odb
    ${EXT_LIB_PATH}/odb-sqlite.lib
    ${EXT_LIB_PATH}/odb.lib
    mod_sqlite3
    windows_dependencies/curl/lib/libcurl
    ws2_32
    crypt32
    Wldap32
    Normaliz
    ${CMAKE_THREAD_LIBS_INIT}
  )
endif ()


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
  test/vcf/debugulator_integration_test.cpp
  test/vcf/debugulator_test.cpp
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

add_executable (vcf_debugulator src/debugulator_main.cpp)
target_link_libraries (vcf_debugulator ${LIBRARIES_TO_LINK})

add_executable (vcf_assembly_checker src/assembly_checker_main.cpp)
target_link_libraries (vcf_assembly_checker ${LIBRARIES_TO_LINK})
