project ( pmd-engine)

set(pmg-engine_VERSION 0.1)

cmake_minimum_required( VERSION 3.6 )

# Sweeps for all the .c files it can find in the src and subfolders.
FILE (GLOB SOURCES "${CMAKE_SOURCE_DIR}/*/**.c")

# And wrap everything on the main executable.
add_executable( pmd-engine ${SOURCES} )

include_directories(
    ${CMAKE_SOURCE_DIR}/inc

    ${lodepng_SOURCE_DIR}
    ${OPENAL_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${LIBOGG_INCLUDE_DIRS}
    ${LIBVORBIS_INCLUDE_DIRS}
)

# target_link_libraries(
#     pmd-engine
    
#     ${OPENAL_LIBRARY}
#     ${OPENGL_LIBRARIES}
#     ${GLEW_LIBRARIES}
#     ${GLFW_LIBRARIES}
#     ${SDL2_LIBRARIES}
#     ${LIBOGG_LIBRARIES}
#     ${LIBVORBIS_LIBRARIES}

#     m
#     Threads::Threads
#     lodepng
# )
