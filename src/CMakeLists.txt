file(GLOB sources "*.cpp")
add_executable("stranded" ${sources})

find_package(SDL REQUIRED) 
find_package(SDL_image REQUIRED) 
find_package(SDL_mixer REQUIRED) 

if(SDL_FOUND)
    include_directories(${SDL_INCLUDE_DIRS})
    target_link_libraries("stranded" ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY})
endif(SDL_FOUND)

if(NOT SDL_FOUND)
    message( FATAL ERROR "SDL not found!")
endif(NOT SDL_FOUND)
