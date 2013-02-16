CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

project(Stranded)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
endif(NOT MSVC)

set(CMAKE_BUILD_TYPE Debug)

if(NOT MSVC)
    option(Warn "Compile using all warnings" ON)
endif(NOT MSVC)

if(Warn)
    set (CMAKE_CXX_FLAGS "-Wall -Werror -Wno-padded ${CMAKE_CXX_FLAGS}")
endif(Warn)

set ( CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

add_subdirectory(src)
add_subdirectory(res)
