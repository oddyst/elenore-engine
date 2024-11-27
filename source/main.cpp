// Author: oknauta
// License:
// File: main.cpp
// Date: 2024-11-26

#include <elenore/log.hpp>
#include <elenore/object3d.hpp>
#include <elenore/window.hpp>

int main(void)
{
    Elenore::Log::info("Hello, world!");

    Elenore::Log::warning("This is a pre-alpha version.");

    Elenore::Core::Window window(800, 600);

    std::vector<GLfloat> vertices{

        // Position
        0.5f,
        0.5f,
        0.0f,
        // Color
        1.0f,
        0.0f,
        0.0f,

        // Position
        -0.5f,
        0.5f,
        0.0f,
        // Color
        1.0f,
        1.0f,
        1.0f,

        // Position
        -0.5f,
        -0.5f,
        0.0f,
        // Color
        0.0f,
        1.0f,
        0.0f,

        // Position
        0.5f,
        -0.5f,
        0.0f,
        // Color
        0.0f,
        0.0f,
        1.0f,
    };

    std::vector<GLuint> indices{
        0, 2, 3,
        0, 1, 2};

    const char *vertex_shader = R"(
    #version 330 core
    layout(location = 0) in vec3 position;
    layout(location = 1) in vec3 color;
    out vec3 vertex_color;

    uniform mat4 model;

    void main()
    {
        gl_Position = model * vec4(position, 1.0);
        vertex_color = color;
    }
    )";

    const char *fragment_shader = R"(
    #version 330 core
    in vec3 vertex_color;
    out vec4 frag_color;

    void main()
    {
        frag_color = vec4(vertex_color, 1.0f);
    }
    )";

    Elenore::Graphics::Shader shader(vertex_shader, fragment_shader);

    auto mesh = std::make_shared<Elenore::Graphics::Mesh3D>(vertices, indices, shader);

    Elenore::Entity::Object3D object(mesh, "Square");

    float x = 0.0f;

    while (!window.shouldClose())
    {
        ++x;
        window.beginDraw();
        object.draw();
        object.setRotation(glm::vec3(x, x, 0));
        window.endDraw();
    }

    return 0;
}