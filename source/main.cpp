// Author: oknauta
// License:
// File: main.cpp
// Date: 2024-11-19

#include <camera.hpp>
#include <logger.hpp>
#include <memory>
#include <object2d.hpp>
#include <object3d.hpp>
#include <window.hpp>

int main(void)
{
    Elenore::Core::Window main_window(800, 800);

    const char *source_vertex_shader = "#version 330 core\n"
                                       "layout(location = 0) in vec3 aPos;\n"
                                       "uniform mat4 model; \n"
                                       "uniform mat4 view; \n"
                                       "uniform mat4 projection;"
                                       "void main() {\n"
                                       "gl_Position = /*projection * view * */ model * vec4(aPos, 1.0);\n"
                                       "}\n";

    const char *source_fragment_shader = "#version 330 core\n"
                                         "out vec4 FragColor;\n"
                                         "void main()\n"
                                         "{FragColor = vec4(1.0, 1.0, 0.0, 1.0);}\n";

    Elenore::Graphics::Shader shader(source_vertex_shader, source_fragment_shader);

    // Elenore::Entity::Object2D triangle("Triangle");

    Elenore::Data::vertex vertices{
        0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f};

    Elenore::Data::index indices{
        0, 1, 2};

    auto mesh = std::make_shared<Elenore::Graphics::Mesh>(vertices, indices, shader);

    Elenore::Entity::Object3D square(mesh, "aaa");

    while (!main_window.shouldClose())
    {
        main_window.beginDraw();
        square.draw();
        // triangle.draw();
        main_window.endDraw();
    }

    return 0;
}

// int main(void)
// {
//     const int WINDOW_WIDTH = 800;
//     const int WINDOW_HEIGHT = 800;
//     const char *WINDOW_TITLE = "GL Elenore Engine";

//     Elenore::Window window(WINDOW_WIDTH, WINDOW_HEIGHT);

//     Elenore::vertex vertices_triangle = {
//         0.0f, 1.0f, 0.0f, // First vertex

//         -1.0f, -1.0f, 0.0f, // Second vertex

//         1.0f, -1.0f, 0.0f, // Third vertex
//     };

//     Elenore::index indices_triangle = {0, 1, 2};

//     const char *source_vertex_shader = "#version 330 core\n"
//                                        "layout(location = 0) in vec3 aPos;\n"
//                                        "uniform mat4 model; \n"
//                                        "uniform mat4 view; \n"
//                                        "uniform mat4 projection;"
//                                        "void main() {\n"
//                                        "gl_Position = /*projection * view * */ model * vec4(aPos, 1.0);\n"
//                                        "}\n";

//     const char *source_fragment_shader = "#version 330 core\n"
//                                          "out vec4 FragColor;\n"
//                                          "void main()\n"
//                                          "{FragColor = vec4(1.0, 1.0, 0.0, 1.0);}\n";

//     glm::vec3 camera_position{0.0f, 0.0f, 0.0f};
//     glm::vec3 camera_target{0.0f, 0.0f, 0.0f};
//     float camera_fov{45.0f};

//     Elenore::Camera3D camera(camera_position, camera_fov, float(WINDOW_WIDTH) / float(WINDOW_HEIGHT), 0.1f, 100.0f,
//                              camera_target);

//     Elenore::Shader yellow_shader(source_vertex_shader, source_fragment_shader);

//     auto mesh = std::make_shared<Elenore::Mesh>(vertices_triangle, indices_triangle, yellow_shader);

//     Elenore::Object3D triangle(mesh, "Triangle", glm::vec3(0.0f, 0.0f, 0.0f));

//     float rotation = 0.0f;

//     triangle.setScale(glm::vec3(1.0f / 2.0f, 1.0f / 2.0f, 1.0f / 2.0f));

//     Elenore::Object3D triangle_2(mesh, "Triangle 2", glm::vec3(0.1f, 0.1f, 0.1f));

//     while (!window.shouldClose())
//     {
//         window.beginDraw();
//         triangle.draw();

//         rotation += 0.5f;

//         triangle.setRotation(glm::vec3(rotation, rotation, 0));
//         window.endDraw();
//     }

//     return 0;
// }

// int main(void)
// {
//     const int WINDOW_WIDTH = 800;
//     const int WINDOW_HEIGHT = 600;
//     const char *WINDOW_TITLE = "Elenore Engine";

//     // Creating an window
//     Elenore::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

//     // Elenore::Text text("Hello, world!", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 20, 255, 255, 255);

//     std::vector<GLfloat>vertices =
//     {
//         0.5f, 0.5f, 0.5f,
//         -0.5f, 0.5f, 0.5f,
//         -0.5f, -0.5f, 0.5f,
//         0.5f, -0.5f, 0.5f,

//         0.5f, 0.5f, -0.5f,
//         -0.5f, 0.5f, -0.5f,
//         -0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f, -0.5f
//     };

//     std::vector<GLuint> indices =
//     {
//         // Frente
//         0, 1, 2,
//         0, 2, 3,

//         // Trás
//         4, 5, 6,
//         4, 6, 7,

//         // Esquerda
//         1, 5, 6,
//         1, 6, 2,

//         // Direita
//         0, 4, 7,
//         0, 7, 3,

//         // Topo
//         0, 1, 5,
//         0, 5, 4,

//         // Base
//         2, 6, 7,
//         2, 7, 3
//     };

//     const char *source_vertex_shader =
//     "#version 330 core\n"
//     "layout(location = 0) in vec3 aPos;\n"
//     "uniform mat4 model; \n"
//     "void main() {\n"
//     "gl_Position = model * vec4(aPos, 2.0);\n"
//     "}\n";

//     const char *source_fragment_shader =
//     "#version 330 core\n"
//     "out vec4 FragColor;\n"
//     "void main()\n"
//     "{FragColor = vec4(1.0, 1.0, 0.0, 1.0);}\n";

//     Elenore::Shader yellow_shader(source_vertex_shader, source_fragment_shader);

//     // Elenore::Mesh *mesh = new Elenore::Mesh(vertices, indices, yellow_shader);

//     // std::shared_ptr<Elenore::Mesh>mesh = std::make_unique<Elenore::Mesh>(vertices, indices, yellow_shader);

//     auto mesh = std::make_shared<Elenore::Mesh>(vertices, indices, yellow_shader);

//     Elenore::Object square(mesh, "Square", {1.0f, 0, 0});

//     square.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

//     square.setScale(glm::vec3(1.0f, 1.0f, 1.0f));

//     float rotation_x, rotation_y, rotation_z;

//     glm::vec4 background_color = {0.1f, 0.1f, 0.1f, 1.0f};

//     while(!window.shouldClose())
//     {
//         window.beginDraw(background_color);

//         rotation_z += .5f;

//         square.setRotation(glm::vec3(1.25f, 1.25f, rotation_z));

//         square.draw();

//         window.endDraw();
//     }

//     // delete mesh;

//     return 0;
// }
