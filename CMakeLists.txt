cmake_minimum_required(VERSION 3.30)

project(talib_vcpkg_example)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

## needed for vcpackage
set(CMAKE_OSX_ARCHITECTURES "arm64")
if(DEFINED ENV{VCPKG_ROOT})
    include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
else()
    message(FATAL_ERROR "VCPKG_ROOT environment variable is required for this project. Please set it and try again.")
endif()

find_package(talib CONFIG REQUIRED)

add_executable(talib_vcpkg_example talib_vcpkg_example.cpp)

target_include_directories(talib_vcpkg_example PUBLIC ${PROJECT_SOURCE_DIR}/include)


target_link_libraries(talib_vcpkg_example PRIVATE talib::talib)