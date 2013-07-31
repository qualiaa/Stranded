file(GLOB sources *.cpp *.hpp)

include_directories(${CMAKE_SOURCE_DIR}/src/Engine)

add_executable(stranded ${sources})

target_link_libraries(stranded tank)
