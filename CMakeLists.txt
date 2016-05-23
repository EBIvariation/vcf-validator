cmake_minimum_required (VERSION 2.8)
project (vcf-validator CXX C)

set (vcf-validator_VERSION_MAJOR 0)
set (vcf-validator_VERSION_MINOR 2)

set (CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -g")
set (CMAKE_C_FLAGS " -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories (inc)
include_directories (lib)

macro (declare_mod MODNAME)
  file (GLOB MOD_${MODNAME}_INC "inc/${MODNAME}/*")
  file (GLOB MOD_${MODNAME}_SRC "src/${MODNAME}/*")
  set (MOD_${MODNAME}_ALL ${MOD_${MODNAME}_INC} ${MOD_${MODNAME}_SRC})
  add_library (mod_${MODNAME} ${MOD_${MODNAME}_ALL})
endmacro (declare_mod)

# Application modules
declare_mod (vcf)

# Dependency libraries
if (BUILD_STATIC)
  set(Boost_USE_STATIC_LIBS ON) # only find static libs
endif (BUILD_STATIC)
find_package (Boost COMPONENTS filesystem program_options regex system REQUIRED )
include_directories (${Boost_INCLUDE_DIR} )

add_library(sqlite3 lib/sqlite/sqlite3.c)

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
  find_package (Threads REQUIRED)
endif (BUILD_STATIC)

# Application tests
file (GLOB ALL_TESTS "test/*/*")
add_executable (test_validator test/main_test.cpp ${ALL_TESTS})
target_link_libraries (test_validator mod_vcf ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
enable_testing ()
add_test (NAME ValidatorTests COMMAND test_validator)

# Build binary
add_executable (vcf_validator src/main.cpp)
target_link_libraries (vcf_validator mod_vcf ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_executable (test_sqlite_write_read sqlitetest/write_read.cpp)
target_link_libraries (test_sqlite_write_read mod_vcf ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} sqlite3)

