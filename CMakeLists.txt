cmake_minimum_required(VERSION 3.5)

project(iscomp VERSION 1.0)


#       libflac options, for details see ext/flac/CMakeLists.txt

option(BUILD_CXXLIBS "Build libFLAC++" ON)
option(BUILD_PROGRAMS "Build and install programs" OFF)
option(BUILD_EXAMPLES "Build and install examples" OFF)
option(BUILD_DOCS "Build and install doxygen documents" OFF)
option(WITH_STACK_PROTECTOR "Enable GNU GCC stack smash protection" ON)
option(INSTALL_MANPAGES "Install MAN pages" OFF)
option(INSTALL_PKGCONFIG_MODULES "Install PkgConfig modules" OFF)
option(INSTALL_CMAKE_CONFIG_MODULE "Install CMake package-config module" OFF)
option(WITH_OGG "ogg support (default: test for libogg)" OFF)
option(BUILD_TESTING OFF)


#       libarchive options, for details see ext/archive/CMakeLists.txt

option(ENABLE_MBEDTLS "Enable use of mbed TLS" OFF)
option(ENABLE_NETTLE "Enable use of Nettle" OFF)
option(ENABLE_OPENSSL "Enable use of OpenSSL" OFF)
option(ENABLE_LIBB2 "Enable the use of the system LIBB2 library if found" OFF)
option(ENABLE_LZ4 "Enable the use of the system LZ4 library if found" OFF)
option(ENABLE_LZO "Enable the use of the system LZO library if found" OFF)
option(ENABLE_LZMA "Enable the use of the system LZMA library if found" OFF)
option(ENABLE_ZSTD "Enable the use of the system zstd library if found" OFF)
option(ENABLE_ZLIB "Enable the use of the system ZLIB library if found" OFF)
option(ENABLE_BZip2 "Enable the use of the system BZip2 library if found" OFF)
option(ENABLE_LIBXML2 "Enable the use of the system libxml2 library if found" OFF)
option(ENABLE_EXPAT "Enable the use of the system EXPAT library if found" OFF)
option(ENABLE_PCREPOSIX "Enable the use of the system PCREPOSIX library if found" OFF)
option(ENABLE_LibGCC "Enable the use of the system LibGCC library if found" OFF)
option(ENABLE_CNG "Enable the use of CNG(Crypto Next Generation)" OFF)

option(ENABLE_TAR "Enable tar building" OFF)
option(ENABLE_TAR_SHARED "Enable dynamic build of tar" FALSE)
option(ENABLE_CPIO "Enable cpio building" OFF)
option(ENABLE_CPIO_SHARED "Enable dynamic build of cpio" FALSE)
option(ENABLE_CAT "Enable cat building" OFF)
option(ENABLE_CAT_SHARED "Enable dynamic build of cat" FALSE)
option(ENABLE_XATTR "Enable extended attribute support" OFF)
option(ENABLE_ACL "Enable ACL support" OFF)
option(ENABLE_ICONV "Enable iconv support" OFF)
option(ENABLE_TEST "Enable unit and regression tests" OFF)
option(ENABLE_COVERAGE "Enable code coverage (GCC only, automatically sets ENABLE_TEST to ON)" FALSE)
option(ENABLE_INSTALL "Enable installing of libraries" OFF)


# add libflac
include_directories("ext/flac/include")
add_subdirectory("ext/flac")

# add libarchive
include_directories("ext/archive/libarchive_fe")
add_subdirectory("ext/archive")

# add iscomp executable
add_subdirectory("src")