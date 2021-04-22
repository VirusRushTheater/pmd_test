project ( pmd-engine)

set(pmg-engine_VERSION 0.1)

cmake_minimum_required( VERSION 3.6 )

# Sweeps for all the .c files it can find in the src and subfolders.
FILE (GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/**.c")

message(STATUS --)
message(STATUS ${GLEW_LIBRARIES})
message(STATUS --)

# And wrap everything on the main executable.
add_executable( pmd-engine ${SOURCES} )

# Choose a proper threading library
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Some hardware libraries and codecs
if(NOT WIN32)
    find_package(OpenGL REQUIRED)
endif()
find_package(OpenAL REQUIRED)
find_package(Ogg REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)
find_package(SDL2 REQUIRED COMPONENTS main)
find_package(Vorbis REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/inc

    ${lodepng_SOURCE_DIR}
    ${iniparser_SOURCE_DIR}
    
    ${OPENAL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${OGG_INCLUDE_DIRS}
    ${VORBIS_INCLUDE_DIRS}

    ${OPENGL_INCLUDE_DIR}
)

target_link_libraries(pmd-engine
    m
    Threads::Threads

    ${OPENAL_LIBRARY}
    ${GLEW_LIBRARY}
    ${GLFW_glfw_LIBRARY}
    ${SDL2_LIBRARIES}
    ${OGG_LIBRARIES}
    ${VORBIS_LIBRARIES}
    ${OPENGL_LIBRARIES}

    lodepng
    iniparser
)