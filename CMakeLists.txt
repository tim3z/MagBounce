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
    include_directories(AFTER "lib/r2d/src")
endif()
include_directories(AFTER "lib/r2d/src")

find_library(R2D r2d PATHS lib "lib/r2d/build")
if (R2D-NOTFOUND)
    message(FATAL_ERROR "Aborting - R2D was not found.")
endif()

add_executable(Magbounce src/Model/Level/Standard/StandardTimeBehavior.cpp
                         src/Model/Level/Standard/StandardPhysics.cpp
                         src/Model/Level/Standard/StandardMagnetismBehavior.cpp
                         src/Model/Level/Standard/StandardGravityBehavior.cpp
                         src/Model/Level/MagnetismBehavior.cpp
                         src/Model/Level/GravityBehavior.cpp
                         src/Model/Level/ForceBehavior.cpp
                         src/Model/Level/PhysicalProperties.cpp
                         src/Model/Level/TimeBehavior.cpp
                        # src/Model/LevelBuilder.cpp
                         src/Model/Object.cpp
                         src/Model/PlayerObject.cpp
                         src/Model/Level.cpp
                         src/Model/RectangularLevelObject.cpp
                         src/Input.cpp
                         src/Sound.cpp
                         src/AppStates/Options.cpp
                         src/AppStates/Menu.cpp
                         src/AppStates/Game.cpp
                         src/GameState.cpp
                         src/main.cpp
                         src/Physics/Physics.cpp
                         src/Physics/Collision/CollisionHandler.cpp
                         src/Physics/Collision/Collision.cpp
                         src/Physics/Collision/CollisionShape.cpp
                         src/Physics/PhysicsAppliableObject.cpp
                         src/Input/EventHandler.cpp
                         src/Input/StateInputHandler/RunningInputHandler.cpp
                         src/Input/InputHandler.cpp
                         src/Input/InputEvent.cpp
                         src/AppState.cpp
                         src/MainThread.cpp
                         src/App.cpp
                         src/GameStates/Pause.cpp
                         src/GameStates/Running.cpp
                         src/Graphics/BallRenderer.cpp
                         src/Graphics/RectangularLevelObjectRenderer.cpp
                         src/Graphics/Renderer.cpp)
set_target_properties(Magbounce PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Magbounce ${ALLEGRO} ${R2D})