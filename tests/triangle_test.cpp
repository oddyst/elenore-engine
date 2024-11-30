// Author: oknauta
// License:
// File: test_file.cpp
// Date: 2024-11-29

#include "elenore/core/log.hpp"
#include "elenore/core/mesh3d.hpp"
#include "elenore/core/object3d.hpp"
#include "elenore/core/window.hpp"

int main(void)
{
    Elenore::Log::info("Hello, world!");

    Elenore::Core::Window window;

    std::vector<GLfloat> vertices =
        {
            1.0f,
            1.0f,
            0.0f,
            // color
            1.0f,
            0.0f,
            0.0f,

            -1.0f,
            1.0f,
            0.0f,
            // color
            0.0f,
            1.0f,
            0.0f,

            -1.0f,
            -1.0f,
            0.0f,
            // color
            0.0f,
            0.0f,
            1.0f,

            1.0f,
            -1.0f,
            0.0f,
            // color
            1.0f,
            1.0f,
            1.0f,

        };

    std::vector<GLuint> indices =
        {
            0,
            1,
            2,

            0,
            2,
            3,
        };

    const char *vertex_shader, *fragment_shader;

    vertex_shader = R"(
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

    fragment_shader = R"(
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

    Elenore::Entity::Object3D object("Triangle", mesh);

    object.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

    float x = 0.0f;

    object.setScale(glm::vec3(.5f, .5f, .5f));

    while (!window.shouldClose())
    {
        window.beginDraw();
        x += 1.0f;

        object.setRotation(glm::vec3(x, x, x));

        object.draw();
        window.endDraw();
    }

    return 0;
}