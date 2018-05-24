cmake_minimum_required (VERSION 2.8)
project (vcf-validator CXX C)

set (vcf-validator_VERSION_MAJOR 0)
set (vcf-validator_VERSION_MINOR 7)
set (vcf-validator_VERSION_PATCH 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/inc/cmake_config.hpp.in"
    "${PROJECT_SOURCE_DIR}/inc/cmake_config.hpp"
    )

# Static build extra flags
if (BUILD_STATIC)
  set (BUILD_SHARED_LIBS OFF)
  #set (BUILD_SHARED_LIBRARIES OFF)
  set (CMAKE_EXE_LINKER_FLAGS "-static")
  set (CMAKE_FIND_LIBRARY_SUFFIXES .a)
  set (CMAKE_EXE_LINK_DYNAMIC_C_FLAGS)       # remove -Wl,-Bdynamic
  set (CMAKE_EXE_LINK_DYNAMIC_CXX_FLAGS)
  set (CMAKE_SHARED_LIBRARY_C_FLAGS)         # remove -fPIC
  set (CMAKE_SHARED_LIBRARY_CXX_FLAGS)
  set (CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)    # remove -rdynamic
  set (CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
  set(Boost_USE_STATIC_LIBS ON) # only find static libs
else (BUILD_STATIC)
  add_definitions (-DBOOST_ALL_DYN_LINK=1)
  set (BUILD_SHARED_LIBS ON)
  #set (BUILD_SHARED_LIBRARIES ON)
  set (CMAKE_EXE_LINKER_FLAGS)
endif (BUILD_STATIC)



find_package (Boost COMPONENTS filesystem iostreams program_options regex log thread system REQUIRED )
include_directories (${Boost_INCLUDE_DIR} )
find_package (Threads REQUIRED)
set (ODB_PATH "/usr/local/lib" CACHE STRING "Path to ODB libraries installation folder.")




# no unknown pragmas: ODB compiler uses some pragmas that the regular compiler doesn't need
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-unknown-pragmas")
# Needed to statically link ODB
set (CMAKE_C_FLAGS " -DSQLITE_ENABLE_UNLOCK_NOTIFY -DSQLITE_OMIT_LOAD_EXTENSION")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
if(NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE  "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)



include_directories (inc)
include_directories (lib)


# Application modules
add_library(mod_sqlite3 STATIC lib/sqlite/sqlite3.c)

if (BUILD_STATIC)
set (LIBRARIES_TO_LINK_TO_MOD
        ${Boost_LIBRARIES}
        bz2
        z
        mod_sqlite3
        ${ODB_PATH}/libodb-sqlite.a
        ${ODB_PATH}/libodb.a
        ${CMAKE_THREAD_LIBS_INIT}
       )
else (BUILD_STATIC)
  set (LIBRARIES_TO_LINK_TO_MOD
        ${Boost_LIBRARIES}
        bz2
        z
        mod_sqlite3
        ${ODB_PATH}/libodb-sqlite.a
        ${ODB_PATH}/libodb.a
        ${CMAKE_THREAD_LIBS_INIT}
       )
endif (BUILD_STATIC)

set (MOD_ODB_SOURCES)
set (ODB_MAPPING_CLASSES inc/vcf/error.hpp)
foreach(_file ${ODB_MAPPING_CLASSES})
    string(REPLACE ".hpp" "-odb.cpp" gencppfile ${_file})
    string(REPLACE "inc" "src" right_place_gencppfile ${gencppfile})
    add_custom_command(
            OUTPUT ${CMAKE_HOME_DIRECTORY}/${right_place_gencppfile}
            COMMAND cd ${CMAKE_HOME_DIRECTORY}/ && odb --include-prefix vcf --std c++11 -d sqlite --generate-query --generate-schema
            --hxx-suffix .hpp --ixx-suffix .ipp --cxx-suffix .cpp
            --output-dir ${CMAKE_HOME_DIRECTORY}/inc/vcf/ ${_file}
            && mv ${CMAKE_HOME_DIRECTORY}/${gencppfile} ${CMAKE_HOME_DIRECTORY}/${right_place_gencppfile}
            DEPENDS ${_file}
            COMMENT "Building odb for ${_file}"
    )
    list(APPEND MOD_ODB_SOURCES ${right_place_gencppfile})
endforeach()
add_library(mod_odb STATIC ${MOD_ODB_SOURCES})
#target_link_libraries(mod_odb ${LIBRARIES_TO_LINK_TO_MOD})



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
add_library(mod_vcf STATIC ${MOD_VCF_SOURCES})
add_dependencies(mod_vcf mod_odb)
#target_link_libraries(mod_vcf ${LIBRARIES_TO_LINK_TO_MOD} mod_odb)



# Build binary
if (BUILD_STATIC)
  set (LIBRARIES_TO_LINK
        mod_vcf
        mod_odb
        mod_sqlite3
        ${ODB_PATH}/libodb-sqlite.a
        ${ODB_PATH}/libodb.a
        ${Boost_LIBRARIES}
        bz2
        z
        ${CMAKE_THREAD_LIBS_INIT}
       )
else (BUILD_STATIC)
  set (LIBRARIES_TO_LINK
        mod_vcf
        mod_odb
        mod_sqlite3
        ${ODB_PATH}/libodb-sqlite.a
        ${ODB_PATH}/libodb.a
        ${Boost_LIBRARIES}
        bz2
        z
        ${CMAKE_THREAD_LIBS_INIT}
       )
endif (BUILD_STATIC)

add_executable (vcf_validator src/validator_main.cpp)
target_link_libraries (vcf_validator ${LIBRARIES_TO_LINK})
