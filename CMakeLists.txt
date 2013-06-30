CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

project(Stranded)

find_package(SFML 2.0 REQUIRED system window audio graphics)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(Threads REQUIRED)
find_package(Boost 1.53.0 REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${SFML_INCLUDE_DIRS})
include_directories(${OpenGL_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

option(COTIRE "Use Cotire" ON)
if(COTIRE)
    include(cotire)
endif(COTIRE)

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif(NOT MSVC)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ ${CMAKE_CXX_FLAGS}")
    set(CMAKE_LD_FLAGS "-stdlib=libc++ ${CMAKE_LD_FLAGS}")
endif(APPLE)

set(CMAKE_BUILD_TYPE Debug)

if(NOT MSVC)
    option(WARN "Compile using all warnings" ON)
endif(NOT MSVC)

if(WARN)
    set (CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS}")
endif(WARN)

set (CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

add_subdirectory(src)
file(COPY "res" DESTINATION ${CMAKE_BINARY_DIR})
