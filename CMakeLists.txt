cmake_minimum_required (VERSION 2.6)
project (vcf-validator CXX)

set (vcf-validator_VERSION_MAJOR 0)
set (vcf-validator_VERSION_MINOR 1)

# set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -g")
set (CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -g")
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
find_package (Boost COMPONENTS regex program_options REQUIRED )
include_directories (${Boost_INCLUDE_DIR} )

# Application tests
file (GLOB ALL_TESTS "test/*/*")
add_executable (test_validator test/main_test.cpp ${ALL_TESTS})
target_link_libraries (test_validator mod_vcf ${Boost_LIBRARIES})
enable_testing ()
add_test (NAME ValidatorTests COMMAND test_validator)

# Build binary
add_executable (vcf_validator src/vcf/main.cpp)
target_link_libraries (vcf_validator mod_vcf ${Boost_LIBRARIES})
