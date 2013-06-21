CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

project(Stranded)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

find_package(SDL REQUIRED) 
find_package(SDL_image REQUIRED) 
include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDL_IMAGE_INCLUDE_DIRS})

if (NOT APPLE)
    option(Cotire "Use Cotire" ON)
endif(NOT APPLE)

if(Cotire)
    include(cotire)
endif(Cotire)

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif(NOT MSVC)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ ${CMAKE_CXX_FLAGS}")
    set(CMAKE_LD_FLAGS "-stdlib=libc++ ${CMAKE_LD_FLAGS}")
endif(APPLE)

set(CMAKE_BUILD_TYPE Debug)

option(Debug "Debug mode" ON)
if(NOT MSVC)
    option(Warn "Compile using all warnings" ON)
endif(NOT MSVC)

if(Warn)
    set (CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS}")
endif(Warn)

if(Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
endif(Debug)

set (CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

add_subdirectory(src)
file(COPY "res" DESTINATION ${CMAKE_BINARY_DIR})
