enable_testing()

add_executable(triangle_test triangle_test.cpp)
add_executable(star_test star_test.cpp)

target_include_directories(triangle_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(star_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(triangle_test PRIVATE elib elog glfw GLEW GL)
target_link_libraries(star_test PRIVATE elib elog glfw GLEW GL)

add_test(NAME triangle_test COMMAND triangle_test)
add_test(NAME star_test COMMAND star_test)
