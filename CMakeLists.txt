cmake_minimum_required(VERSION 3.30.0)  # Set minimum CMake version.
project(elenore-engine VERSION 0.1.1 LANGUAGES CXX)  # Set project details.

# Set C++ standard and enforce it.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories globally.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

# Enable testing and add test subdirectory.
enable_testing()

# Find necessary packages.
find_package(PkgConfig REQUIRED)  # Find pkg-config.
pkg_check_modules(FREETYPE REQUIRED freetype2)  # Find freetype2.

# Add libraries.
add_library(elib SHARED
    source/elenore/core/buffer_object.cpp
    source/elenore/core/entity.cpp
    source/elenore/core/object3d.cpp
    source/elenore/core/window.cpp
    source/elenore/core/mesh3d.cpp
    source/elenore/core/shader.cpp
    source/elenore/core/tools.cpp
    source/elenore/core/camera3d.cpp
)

add_library(elog SHARED source/elenore/core/log.cpp)

# Add the executable.
add_executable(elenore-engine ${PROJECT_SOURCE_DIR}/source/main.cpp)

if(WIN32)

# Find dependencies using CMake's find_package if possible.
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Link libraries to the project.
target_link_libraries(elib PRIVATE zip glfw3 glew32 opengl32 elog)

# Link dependencies to the executable.
target_link_libraries(elenore-engine PRIVATE
    glfw3
    glew32
    opengl32
    elog
    elib
    ${FREETYPE_LIBRARIES}
)

elseif(LINUX)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Link libraries to the project.
target_link_libraries(elib PRIVATE zip glfw GLEW GL elog)

# Link dependencies to the executable.
target_link_libraries(elenore-engine PRIVATE
    glfw
    GLEW
    GL
    elog
    elib
    ${FREETYPE_LIBRARIES}
)

endif()

# Include directories.
target_include_directories(elib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${FREETYPE_INCLUDE_DIRS}
)

target_include_directories(elenore-engine PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${FREETYPE_INCLUDE_DIRS}
)

target_include_directories(elog PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${FREETYPE_INCLUDE_DIRS}
)

# Create custom target to pack assets into a zip file.
add_custom_target(pack_assets ALL
    COMMAND "7z" "a" "-tzip" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets.pkg" "${PROJECT_SOURCE_DIR}/assets/*"
)

# Ensure the executable depends on packing assets.
add_dependencies(elenore-engine pack_assets)
