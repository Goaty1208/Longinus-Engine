cmake_minimum_required(VERSION 3.14)

project(longinus)

# Detect the platform
if (WIN32)
    message(STATUS "Building for Windows")
elseif(UNIX AND NOT APPLE)
    message(STATUS "Building for Linux")
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# Set SDL paths
set(SDL_BUILD_DIR "${CMAKE_BINARY_DIR}/_deps/sdl-src")
set(SDL_INSTALL_DIR "${CMAKE_BINARY_DIR}/_deps/sdl-install")

# Check if SDL is already downloaded and built
if (NOT EXISTS "${SDL_BUILD_DIR}/CMakeLists.txt" OR NOT EXISTS "${SDL_INSTALL_DIR}")
    message(STATUS "SDL2 not found, downloading and building SDL2")

    # Fetch SDL only if not already downloaded
    include(FetchContent)
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.28.3 # Use the latest stable release or specify another tag
        SOURCE_DIR ${SDL_BUILD_DIR}
    )
    FetchContent_MakeAvailable(SDL2)

    # Build SDL for Linux or Windows
    if (WIN32)
        message(STATUS "Building SDL2 for Windows")
        execute_process(
            COMMAND ${CMAKE_COMMAND} --build ${SDL_BUILD_DIR} --config Release
            WORKING_DIRECTORY ${SDL_BUILD_DIR}/VisualC
        )
    elseif(UNIX)
        message(STATUS "Building SDL2 for Linux")
        execute_process(
            COMMAND ${CMAKE_COMMAND} -S ${SDL_BUILD_DIR} -B ${SDL_BUILD_DIR}/build -DCMAKE_INSTALL_PREFIX=${SDL_INSTALL_DIR}
        )
        execute_process(
            COMMAND ${CMAKE_COMMAND} --build ${SDL_BUILD_DIR}/build --target install
        )
    endif()
else()
    message(STATUS "SDL2 already exists, skipping download and build")
endif()

# Set SDL include directories and libraries based on the platform
if (WIN32)
    set(SDL_INCLUDE_DIR "${SDL_BUILD_DIR}/include")
    set(SDL_LIBRARY_DIR "${SDL_BUILD_DIR}/VisualC/Release") # Adjust for MSVC
    set(SDL_LIBRARIES SDL2main SDL2)
elseif(UNIX)
    set(SDL_INCLUDE_DIR "${SDL_BUILD_DIR}/include")
    set(SDL_LIBRARY_DIR "${SDL_INSTALL_DIR}/lib")
    set(SDL_LIBRARIES SDL2)
endif()

# Add your source files
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")

# Add executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Include SDL and link it to the executable
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${SDL_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL_LIBRARIES})
