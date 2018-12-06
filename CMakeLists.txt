cmake_minimum_required(VERSION 3.0)
project(codec)
set(target ${PROJECT_NAME})

file(GLOB sources
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
   ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h)

# options
option(BUILD_TESTING "for building unit tests" OFF)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Modules")

find_package(Boost REQUIRED
                   COMPONENTS
                       system
                       coroutine
                       filesystem
                       program_options)

add_executable(${target} ${sources})

target_link_libraries(${target}
    Boost::program_options
    Boost::filesystem
    Boost::coroutine)

if (BUILD_TESTING)
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()
