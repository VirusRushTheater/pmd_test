# Legacy "everything as a submodule way of thinking"
# PackageOrGit (OpenAL     openal-soft)
# PackageOrGit (OGG        ogg)
# PackageOrGit (GLEW       glew-cmake)
# PackageOrGit (GLFW       glfw)
# PackageOrGit (SDL2       SDL)
# PackageOrGit (Vorbis     vorbis)

# Requires iniparser and lodepng

set(LODEPNG_BUILD_C_LIBRARY 1 CACHE BOOL "")
add_subdirectory (lodepng)

set(INIPARSER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/iniparser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/iniparser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/dictionary.h
    ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/dictionary.c
)

add_library( iniparser ${BUILD_STATIC_OR_DYNAMIC} ${INIPARSER_SOURCES} )
target_include_directories (iniparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src)