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

list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/dependencies/build")
link_directories("${PROJECT_SOURCE_DIR}/dependencies/build/lib")

# Specific to statically linked dependencies
set(BUILD_SHARED_LIBS OFF)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(CURL_STATICLIB ON)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(ENV{PKG_CONFIG_STATIC} "1")
set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${PROJECT_SOURCE_DIR}/dependencies/build/lib/pkgconfig")


# Use CMake to find dependencies in conda or system environments
find_package(Boost REQUIRED COMPONENTS filesystem iostreams program_options regex log thread system)
#find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)
find_package(BZip2 REQUIRED)
find_package(PkgConfig REQUIRED)

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
target_link_libraries(mod_vcf PRIVATE
        Boost::filesystem
        Boost::iostreams
        Boost::program_options
        Boost::regex
        Boost::log
        Boost::thread
        Boost::system
#        CURL::libcurl
        OpenSSL::Crypto
        OpenSSL::SSL
        Threads::Threads
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBCURL REQUIRED IMPORTED_TARGET libcurl)
pkg_check_modules(LIBCURL REQUIRED libcurl)

target_link_libraries(mod_vcf PRIVATE PkgConfig::LIBCURL)
# Add the include paths
target_include_directories(mod_vcf PRIVATE ${LIBCURL_INCLUDE_DIRS})
# Add *all* linker flags (includes private deps)
target_link_libraries(mod_vcf PRIVATE ${LIBCURL_STATIC_LIBRARIES})
message(STATUS "libcurl libraries: ${LIBCURL_LIBRARIES}")
message(STATUS "libcurl link flags: ${LIBCURL_LDFLAGS}")


#target_link_libraries(mod_vcf PRIVATE
#        ${Boost_LIBRARIES}
#        ${CURL_LIBRARIES}
#        ${OPENSSL_LIBRARIES}
#        Threads::Threads
#)

# Library that only exist in unix platform
if(WIN32)
  target_link_libraries(mod_vcf PRIVATE ws2_32 crypt32 Wldap32 Normaliz)
else ()
  target_link_libraries(mod_vcf PRIVATE ZLIB::ZLIB BZip2::BZip2 dl)
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