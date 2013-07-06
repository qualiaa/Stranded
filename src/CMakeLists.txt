file(GLOB sources "*.cpp")

add_subdirectory(Engine)

include_directories(${CMAKE_SOURCE_DIR}/src/Engine)
link_directories(${CMAKE_BINARY_DIR}/src/Engine)

add_executable(stranded ${sources})

target_link_libraries(stranded tank ${OPENGL_LIBRARIES} ${SFML_LIBRARIES}
    ${GLEW_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
if(Cotire)
    cotire(stranded)
endif(Cotire)
