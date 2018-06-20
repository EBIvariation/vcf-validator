cmake_minimum_required (VERSION 2.8)
project (vcf-validator CXX C)

set (vcf-validator_VERSION_MAJOR 0)
set (vcf-validator_VERSION_MINOR 8)
set (vcf-validator_VERSION_PATCH 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/inc/cmake_config.hpp.in"
    "${PROJECT_SOURCE_DIR}/inc/cmake_config.hpp"
    )


# Include Directories
include_directories (inc)
include_directories (lib)

# Detect OS
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  message (STATUS "Operating System detected OSX")
  set (OSX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  message (STATUS "Operating System detected Linux")
  set (LINUX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  message (STATUS "Operating System detected Windows")
  set (WINDOWS TRUE)
else ()
  message (ERROR "Operating System not recognised")
endif ()

# Static Build Extra Flags for Linux Static Build
if (LINUX)
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
endif ()

# Mac build not fully static. include system libraries to be dynamic
if (OSX)
  set (CMAKE_EXE_LINKER_FLAGS)
  set (Boost_USE_STATIC_LIBS ON)             # only find static libs
endif ()


if (WINDOWS)
    include_directories (lib/sqlite)# windows specific
    include_directories (inc/windows_specific)# windows specific
    set (CMAKE_BUILD_TYPE  "Release" CACHE STRING "On windows we only support release mode" FORCE)
    set (Boost_USE_STATIC_LIBS ON)             # only find static libs instead of dlls
    set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT") # also requires boost with runtime-link=static
    set (CMAKE_C_FLAGS " -DSQLITE_ENABLE_UNLOCK_NOTIFY -DSQLITE_OMIT_LOAD_EXTENSION")
    set (EXT_LIB_PATH "${PROJECT_SOURCE_DIR}/lib/windows_specific" CACHE STRING "Absolute path to libraries")
else ()
    if (NOT CMAKE_BUILD_TYPE)
       set (CMAKE_BUILD_TYPE  "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
    endif ()
    # no unknown pragmas: ODB compiler uses some pragmas that the regular compiler doesn't need
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-unknown-pragmas")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fext-numeric-literals")
    # Needed to statically link ODB
    set (CMAKE_C_FLAGS " -DSQLITE_ENABLE_UNLOCK_NOTIFY -DSQLITE_OMIT_LOAD_EXTENSION")
    set (EXT_LIB_PATH "usr/local/lib" CACHE STRING "Absolute path to libraries installation folder.")
    find_package (Boost COMPONENTS filesystem iostreams program_options regex log thread system REQUIRED )
    include_directories (${Boost_INCLUDE_DIR} )
endif ()

find_package (Threads REQUIRED)


# Application modules
add_library (mod_sqlite3 STATIC lib/sqlite/sqlite3.c)

if (LINUX)
  set (THIRD_PARTY_LIBRARIES
      ${Boost_LIBRARIES}
      bz2
      z
      ${EXT_LIB_PATH}/libodb-sqlite.a
      ${EXT_LIB_PATH}/libodb.a
      mod_sqlite3
      ${CMAKE_THREAD_LIBS_INIT}
     )
elseif (OSX)
  set (THIRD_PARTY_LIBRARIES
      ${Boost_LIBRARIES}
      ${EXT_LIB_PATH}/libbz2.a
      ${EXT_LIB_PATH}/libz.a
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
      ${CMAKE_THREAD_LIBS_INIT}
     )
endif ()

set (MOD_ODB_SOURCES)
set (ODB_MAPPING_CLASSES inc/vcf/error.hpp)
foreach (_file ${ODB_MAPPING_CLASSES})
    string (REPLACE ".hpp" "-odb.cpp" gencppfile ${_file})
    string (REPLACE "inc" "src" right_place_gencppfile ${gencppfile})
    #add_custom_command (
            #OUTPUT ${CMAKE_HOME_DIRECTORY}/${right_place_gencppfile}
            #COMMAND cd ${CMAKE_HOME_DIRECTORY}/ && odb --include-prefix vcf --std c++11 -d sqlite --generate-query --generate-schema
            #--hxx-suffix .hpp --ixx-suffix .ipp --cxx-suffix .cpp
            #--output-dir ${CMAKE_HOME_DIRECTORY}/inc/vcf/ ${_file}
            #&& mv ${CMAKE_HOME_DIRECTORY}/${gencppfile} ${CMAKE_HOME_DIRECTORY}/${right_place_gencppfile}
            #DEPENDS ${_file}
            #COMMENT "Building odb for ${_file}"
    #)
    list (APPEND MOD_ODB_SOURCES ${right_place_gencppfile})
endforeach ()
add_library (mod_odb STATIC ${MOD_ODB_SOURCES})
target_link_libraries (mod_odb ${THIRD_PARTY_LIBRARIES})

set (MOD_VCF_SOURCES
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
        inc/vcf/validator.hpp

        src/vcf/abort_error_policy.cpp
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
      ${Boost_LIBRARIES}
      bz2
      z
      ${EXT_LIB_PATH}/libodb-sqlite.a
      ${EXT_LIB_PATH}/libodb.a
      mod_sqlite3
      ${CMAKE_THREAD_LIBS_INIT}
     )
elseif (OSX)
  set (LIBRARIES_TO_LINK
      mod_vcf
      mod_odb
      ${Boost_LIBRARIES}
      ${EXT_LIB_PATH}/libbz2.a
      ${EXT_LIB_PATH}/libz.a
      ${EXT_LIB_PATH}/libodb-sqlite.a
      ${EXT_LIB_PATH}/libodb.a
      mod_sqlite3
      ${CMAKE_THREAD_LIBS_INIT}
     )
elseif (WINDOWS)
  set (LIBRARIES_TO_LINK
      mod_vcf
      mod_odb
      ${EXT_LIB_PATH}/odb-sqlite.lib
      ${EXT_LIB_PATH}/odb.lib
      mod_sqlite3
      ${CMAKE_THREAD_LIBS_INIT}
     )
endif ()


# Application Tests
#set (V41_TESTS test/vcf/parser_v41_test.cpp)
#set (V42_TESTS test/vcf/parser_v42_test.cpp)
#set (V43_TESTS test/vcf/parser_v43_test.cpp)
#set (ALL_TESTS
        #test/vcf/compressed_file_test.cpp
        #test/vcf/debugulator_integration_test.cpp
        #test/vcf/debugulator_test.cpp
        #test/vcf/metaentry_test.cpp
        #test/vcf/normalize_test.cpp
        #test/vcf/optional_policy_test.cpp
        #test/vcf/parser_test_aux.hpp
        #test/vcf/parser_v41_test.cpp
        #test/vcf/parser_v42_test.cpp
        #test/vcf/parser_v43_test.cpp
        #test/vcf/predefined_info_tags_test.cpp
        #test/vcf/predefined_format_tags_test.cpp
        #test/vcf/record_cache_test.cpp
        #test/vcf/record_test.cpp
        #test/vcf/report_writer_test.cpp
        #test/vcf/test_utils.hpp
        #)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#add_executable (test_validator_v41 test/main_test.cpp ${V41_TESTS})
#target_link_libraries (test_validator_v41 ${LIBRARIES_TO_LINK})
#enable_testing ()
#add_test (NAME ValidatorTests_v41 COMMAND test_validator_v41)

#add_executable (test_validator_v42 test/main_test.cpp ${V42_TESTS})
#target_link_libraries (test_validator_v42 ${LIBRARIES_TO_LINK})
#enable_testing ()
#add_test (NAME ValidatorTests_v42 COMMAND test_validator_v42)

#add_executable (test_validator_v43 test/main_test.cpp ${V43_TESTS})
#target_link_libraries (test_validator_v43 ${LIBRARIES_TO_LINK})
#enable_testing ()
#add_test (NAME ValidatorTests_v43 COMMAND test_validator_v43)

#add_executable (test_validator test/main_test.cpp ${ALL_TESTS})
#target_link_libraries (test_validator ${LIBRARIES_TO_LINK})
#enable_testing ()
#add_test (NAME ValidatorTests COMMAND test_validator)


# Build Binaries
add_executable (vcf_validator src/validator_main.cpp)
target_link_libraries (vcf_validator ${LIBRARIES_TO_LINK})

#add_executable (vcf_debugulator src/debugulator_main.cpp)
#target_link_libraries (vcf_debugulator ${LIBRARIES_TO_LINK})
