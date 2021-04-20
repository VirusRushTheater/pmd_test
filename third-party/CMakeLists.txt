find_library (OpenGL     REQUIRED)

# Legacy "everything as a submodule way of thinking"
# PackageOrGit (OpenAL     openal-soft)
# PackageOrGit (OGG        ogg)
# PackageOrGit (GLEW       glew-cmake)
# PackageOrGit (GLFW       glfw)
# PackageOrGit (SDL2       SDL)
# PackageOrGit (Vorbis     vorbis)

# Some hardware libraries and codecs
find_package(OpenAL)
find_package(OGG)
find_package(GLEW)
find_package(GLFW)
find_package(SDL2)
find_package(Vorbis)

# Requires iniparser and lodepng
set(INIPARSER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/iniparser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/iniparser.c
    ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/dictionary.h
    ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src/dictionary.c
)

add_library( iniparser ${BUILD_STATIC_OR_DYNAMIC} ${INIPARSER_SOURCES} )
target_include_directories (iniparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/iniparser/src)