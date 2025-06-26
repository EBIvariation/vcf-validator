cmake_minimum_required(VERSION 3.10)
project(vcf-validator CXX C)

# Version info
set(vcf-validator_VERSION_MAJOR 0)
set(vcf-validator_VERSION_MINOR 10)
set(vcf-validator_VERSION_PATCH 0)

# Build settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Configure header with version macros
configure_file(
        "${PROJECT_SOURCE_DIR}/inc/cmake_config.hpp.in"
        "${PROJECT_SOURCE_DIR}/inc/cmake_config.hpp"
)
# Output binaries to bin/ directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



# Compiler options (avoid GCC flags on MSVC)
if(MSVC)
  add_compile_options(/W3)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
  add_compile_options(-Wall -Wno-unknown-pragmas)
endif()

# ========== Dependencies ==========

# Manually locate CURL on Windows and set specific definitions
if(WIN32)
  set(CURL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/dependencies/curl/include")
  set(CURL_LIBRARY "${PROJECT_SOURCE_DIR}/dependencies/curl/lib/libcurl.lib")
  set(CURL_LIBRARIES ${CURL_LIBRARY})
  set(CURL_FOUND TRUE)
  add_definitions(-DCURL_STATICLIB)
  # std::max Conflicts with Macro max so disable the macros
  add_definitions(-DNOMINMAX)
  set(Boost_USE_STATIC_LIBS ON)
endif()

# Use CMake to find dependencies in conda or system environments
find_package(Boost REQUIRED COMPONENTS filesystem iostreams program_options regex log thread system)
find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

# Include paths
include_directories(
        ${Boost_INCLUDE_DIRS}
        ${CURL_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/lib
)

# ========== Library ==========

file(GLOB_RECURSE MOD_VCF_SOURCES
        inc/**/*.hpp
        src/**/*.cpp
)

add_library(mod_vcf STATIC ${MOD_VCF_SOURCES})
target_link_libraries(mod_vcf
        ${Boost_LIBRARIES}
        ${CURL_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        Threads::Threads
)

# Library that only exist in unix platform
if(WIN32)
  target_link_libraries(mod_vcf ws2_32 crypt32 Wldap32 Normaliz)
else ()
  target_link_libraries(mod_vcf bz2 z dl)
endif()

# ========== Executables ==========

add_executable(vcf_validator src/validator_main.cpp)
target_link_libraries(vcf_validator mod_vcf)

add_executable(vcf_assembly_checker src/assembly_checker_main.cpp)
target_link_libraries(vcf_assembly_checker mod_vcf)

# ========== Tests ==========

enable_testing()

file(GLOB_RECURSE VCF_TEST_SOURCES
        test/vcf/*_test.cpp
        test/fasta/*_test.cpp
        test/assembly_report/*_test.cpp
        test/vcf/parser_test_aux.hpp
        test/vcf/test_utils.hpp
)

set(TEST_VERSIONS 41 42 43 44)

foreach(ver IN LISTS TEST_VERSIONS)
  add_executable(test_validator_v${ver}
          test/main_test.cpp
          test/vcf/parser_v${ver}_test.cpp
  )
  target_link_libraries(test_validator_v${ver} mod_vcf)
  add_test(NAME ValidatorTests_v${ver} COMMAND test_validator_v${ver})
endforeach()

add_executable(test_validation_suite test/main_test.cpp ${VCF_TEST_SOURCES})
target_link_libraries(test_validation_suite mod_vcf)
add_test(NAME ValidatorTests COMMAND test_validation_suite)