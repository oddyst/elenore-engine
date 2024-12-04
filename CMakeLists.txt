cmake_minimum_required(VERSION 3.30.0)

project(elenore-engine CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)

add_library(elib SHARED
            source/elenore/logger.cpp
            source/elenore/window.cpp
            source/elenore/mesh3d.cpp
            source/elenore/buffer_object.cpp
            source/elenore/shader.cpp
            source/elenore/tools.cpp
)

target_include_directories(elib PUBLIC include)

add_executable(elenore-engine source/main.cpp)

target_include_directories(elenore-engine PUBLIC include)

target_link_libraries(elib glfw GLEW GL zip)

target_link_libraries(elenore-engine elib)

add_custom_target(pack_assets ALL
    COMMAND "7z" "a" "-tzip" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets.pkg" "${PROJECT_SOURCE_DIR}/assets/*"
)

add_dependencies(elenore-engine pack_assets)