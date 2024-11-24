cmake_minimum_required(VERSION 3.31.0) # Checa a versão mínima do CMake.
set(CMAKE_CXX_STANDARD 23) # Configura a versão do C++.
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Se é necessário a versão padronizada do C++.
set(CMAKE_CXX_EXTENSIONS OFF) # Desativa as extensões do C++.

find_package(PkgConfig REQUIRED) # Procura o pkg-config no sistema.

pkg_check_modules(FREETYPE REQUIRED freetype2) # Procura no sistema o freetype2.

project(elenore-engine VERSION 0.1.0 LANGUAGES CXX) # Configurações do projeto.

add_library(elenore SHARED source/buffer_object.cpp source/engine.cpp source/mesh.cpp source/object.cpp source/shader.cpp source/text.cpp) # Adiciona arquivos necessários à biblioteca dinâmica chamada de "libelenore.so".

add_executable(elenore-engine ${PROJECT_SOURCE_DIR}/source/main.cpp) # Linka os arquivos e faz o executável.

target_link_libraries(elenore-engine PRIVATE glfw GLEW GL elenore ${FREETYPE_LIBRARIES}) # Linka as bibliotecas do compilador ao executável.

target_include_directories(elenore PRIVATE ${PROJECT_SOURCE_DIR}/include ${FREETYPE_INCLUDE_DIRS}) # Linka os cabeçalhos do projeto à biblioteca dinâmica. 
target_include_directories(elenore-engine PRIVATE ${PROJECT_SOURCE_DIR}/include ${FREETYPE_INCLUDE_DIRS}) # Linka os cabeçalhos do projeto ao executável. 


