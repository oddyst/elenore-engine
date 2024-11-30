cmake_minimum_required(VERSION 3.30.0) # Checa a versão mínima do CMake.
set(CMAKE_CXX_STANDARD 23) # Configura a versão do C++.
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Se é necessário a versão padronizada do C++.
set(CMAKE_CXX_EXTENSIONS OFF) # Desativa as extensões do C++.

find_package(PkgConfig REQUIRED) # Procura o pkg-config no sistema.

pkg_check_modules(FREETYPE REQUIRED freetype2) # Procura no sistema o freetype2.

project(elenore-engine VERSION 0.1.1 LANGUAGES CXX) # Configurações do projeto.

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

enable_testing()
add_subdirectory(tests)

add_library( # Adiciona arquivos necessários à biblioteca dinâmica chamada de "libelenore.so".
            elib SHARED
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
            
add_executable(elenore-engine ${PROJECT_SOURCE_DIR}/source/main.cpp) # Linka os arquivos e faz o executável.

target_link_libraries(elib PRIVATE miniz)

target_link_libraries(elenore-engine PRIVATE glfw GLEW GL elib elog ${FREETYPE_LIBRARIES}) # Linka as bibliotecas do compilador ao executável.

target_include_directories(elib PRIVATE ${PROJECT_SOURCE_DIR}/include ${FREETYPE_INCLUDE_DIRS}) # Linka os cabeçalhos do projeto à biblioteca dinâmica. 
target_include_directories(elenore-engine PRIVATE ${PROJECT_SOURCE_DIR}/include ${FREETYPE_INCLUDE_DIRS}) # Linka os cabeçalhos do projeto ao executável. 
target_include_directories(elog PRIVATE ${PROJECT_SOURCE_DIR}/include ${FREETYPE_INCLUDE_DIRS}) # Linka os cabeçalhos do projeto ao executável. 

add_custom_target(pack_assets ALL COMMAND "7z" "a" "-tzip" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets.pkg" "${PROJECT_SOURCE_DIR}/assets/*")

add_dependencies(elenore-engine pack_assets)