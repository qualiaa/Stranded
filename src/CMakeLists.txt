file(GLOB sources "*.cpp")

add_subdirectory( Engine )

include_directories( ${CMAKE_SOURCE_DIR}/src/Engine )
link_directories( ${CMAKE_BINARY_DIR}/src/Engine )
message("SFML SHIT ${SFML_LIBRARIES}")

add_executable("stranded" ${sources})

target_link_libraries("stranded" engine ${SFML_LIBRARIES})
if(Cotire)
    cotire(stranded)
endif(Cotire)
