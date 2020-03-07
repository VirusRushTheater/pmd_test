# Copyright 2019 VirusRushTheater
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# \to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

# PackageOrGit
# ------------------------------------
# This function lets you grant the option to use a Git submodule on your project
# so it will be compiled together as a library for your project to use it later.
#
# This can be used as an extension of the find_package() command, setting the
# same variables:
# * <PACKAGE_NAME>_FOUND -> True or False
# * <PACKAGE_NAME>_INCLUDE_DIRS
# * <PACKAGE_NAME>_LIBRARIES

# How to use it
# ------------------------------------
# PackageOrGit (PACKAGE_NAME    GIT_SUBMODULE_NAME)
# You need to invoke the method PackageOrGit in the same folder your submodule
# is.

function (PackageOrGit PACKAGE_NAME GIT_SUBMODULE_NAME)
    find_package(${PACKAGE_NAME})
    if (${PACKAGE_NAME}_FOUND)
        message (STATUS "${PACKAGE_NAME} is installed your system. Using that version.")
    else ()
        message (STATUS "${PACKAGE_NAME} is not installed in your system. Retrieving source from Git submodule ${GIT_SUBMODULE_NAME}.")
        execute_process (
            COMMAND git submodule update ${GIT_SUBMODULE_NAME}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE ${PACKAGE_NAME}_GIT_SUBMODULE_CLONED
        )

        if (NOT ${PACKAGE_NAME}_GIT_SUBMODULE_CLONED)
            message (STATUS "Repository for library ${PACKAGE_NAME} cloned. Trying to include it...")
            file (GLOB ${PACKAGE_NAME}_IS_CMAKE_PROJ "${CMAKE_CURRENT_SOURCE_DIR}/${GIT_SUBMODULE_NAME}/CMakeLists.txt")
            if (${PACKAGE_NAME}_IS_CMAKE_PROJ)
                message(STATUS "${PACKAGE_NAME} is CMake project. Recursing...")
                add_subdirectory (${GIT_SUBMODULE_NAME})
            else()
                message(STATUS "${PACKAGE_NAME} is not a CMake project. Trying to include it, assuming it's a only-lib project.")
                # Todo...
            endif()

            file (GLOB __${PACKAGE_NAME}_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/${GIT_SUBMODULE_NAME}/include")
            set (${PACKAGE_NAME}_INCLUDE_DIRS
                ${__${PACKAGE_NAME}_INCLUDE_DIRS}
                PARENT_SCOPE
            )

            set(${PACKAGE_NAME}_FOUND True PARENT_SCOPE)
            
            file(RELATIVE_PATH __${PACKAGE_NAME}_LIB_FOLDER ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
            set(${PACKAGE_NAME}_LIBRARIES
                ${LIBRARY_OUTPUT_PATH}/__${PACKAGE_NAME}_LIB_FOLDER/${GIT_SUBMODULE_NAME}
                PARENT_SCOPE)
            
        else ()
            message (FATAL_ERROR "Repository for library ${PACKAGE_NAME} could not be cloned.")
        endif ()
    endif ()
endfunction (PackageOrGit)