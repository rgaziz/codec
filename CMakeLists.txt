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
                       system)

add_executable(${target} ${sources})

target_link_libraries(${target} Boost::system)

target_include_directories(${target}
                             PUBLIC
                               ${CMAKE_CURRENT_SOURCE_DIR})

if (BUILD_TESTING)
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()
