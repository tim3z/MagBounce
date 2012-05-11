cmake_minimum_required(VERSION 2.8)
project(MAGBOUNCE)

# Set g++ compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
    # Check g++ version
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                   OUTPUT_VARIABLE G++_VERSION)
    if(G++_VERSION VERSION_LESS 4.6)
        message(FATAL_ERROR "This project uses c++11 features your compiler does not support. Upgrade g++ to version 4.6 or above!")
    elseif(G++_VERSION VERSION_EQUAL 4.6)
        set(CMAKE_CXX_FLAGS "-Wall -pedantic -Weffc++ -std=c++0x")
    else()
        set(CMAKE_CXX_FLAGS "-Wall -pedantic -Weffc++ -std=c++11")
    endif()
endif()

include_directories(AFTER src)

find_library(ALLEGRO allegro PATHS lib)

IF(EXISTS "lib/r2d")
    add_subdirectory("lib/r2d")
endif()

find_library(R2D r2d PATHS lib "lib/r2d/build")
if (R2D-NOTFOUND)
    message(FATAL_ERROR "Aborting - R2D was not found.")
endif()

add_executable(Magbounce )
set_target_properties(Magbounce PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Magbounce ${ALLEGRO} ${R2D})