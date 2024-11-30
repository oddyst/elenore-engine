enable_testing()

add_executable(triangle_test triangle_test.cpp)
add_executable(star_test star_test.cpp)
add_executable(camera_test camera.cpp)
add_executable(window_test window.cpp)

target_include_directories(triangle_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(star_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(camera_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(window_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(triangle_test PRIVATE elib elog glfw GLEW GL)
target_link_libraries(star_test PRIVATE elib elog glfw GLEW GL)
target_link_libraries(camera_test PRIVATE elib elog glfw GLEW GL)
target_link_libraries(window_test PRIVATE elib elog glfw GLEW GL)

add_test(NAME triangle_test COMMAND triangle_test)
add_test(NAME star_test COMMAND star_test)
add_test(NAME camera_test COMMAND camera_test)
add_test(NAME window_test COMMAND window_test)
