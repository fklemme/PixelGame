cmake_minimum_required(VERSION 3.14)
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Project name
project(PixelGame)

# Define target
add_executable(${PROJECT_NAME})

# Set C++ standard
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Add sources and include directory
file(GLOB_RECURSE header CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE source CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(${PROJECT_NAME} PRIVATE ${header} PRIVATE ${source})

# For Visual Studio filters
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include PREFIX "Header Files" FILES ${header})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/source PREFIX "Source Files" FILES ${source})

# Enable more warnings
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

# --- Dependencies for olc::PixelGameEngine ---
if (MSVC)
    # Windows
    # No declarations needed!?
else()
    # Linux
    find_package(X11 REQUIRED)
    target_link_libraries(${PROJECT_NAME} X11)

    find_package(OpenGL COMPONENTS OpenGL GLX REQUIRED)
    target_link_libraries(${PROJECT_NAME} OpenGL GLX)

    find_package(Threads REQUIRED)
    target_link_libraries(${PROJECT_NAME} Threads::Threads)

    find_package(PNG REQUIRED)
    target_link_libraries(${PROJECT_NAME} ${PNG_LIBRARIES})
endif()

# Copy game resources to build directory.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
