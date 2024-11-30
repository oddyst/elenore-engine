// Author: oknauta, djalma
// License:
// File: star_test.cpp
// Date: 2024-11-29

#include "elenore/core/window.hpp"

#include "elenore/core/log.hpp"
#include "elenore/core/mesh3d.hpp"
#include "elenore/core/object3d.hpp"
#include "elenore/core/window.hpp"

int main(void)
{
    Elenore::Log::info("Hello, world!");

    Elenore::Core::Window window;

    std::vector<GLfloat> vertices{
        // vertice,
        3.0f,
        0.0f,
        0.0f,
        // colour,
        1.0f,
        0.0f,
        0.0f,

        // vertice,
        1.0f,
        0.0f,
        0.0f,
        // colour,
        1.0f,
        0.0f,
        0.0f,

        // vertice,
        0.0f,
        2.0f,
        0.0f,
        // colour,
        0.0f,
        1.0f,
        0.0f,

        // vertice,
        -1.0f,
        0.0f,
        0.0f,
        // colour,
        0.0f,
        1.0f,
        0.0f,

        // vertice,
        -3.0f,
        0.0f,
        0.0f,
        // colour,
        0.0f,
        1.0f,
        0.0f,

        // vertice,
        -1.50f,
        -1.50f,
        0.0f,
        // colour,
        0.0f,
        0.0f,
        1.0f,

        // vertice,
        -2.0f,
        -2.750f,
        0.0f,
        // colour,
        0.0f,
        0.0f,
        1.0f,

        // vertice,
        0.0f,
        -2.0f,
        0.0f,
        // colour,
        0.0f,
        0.0f,
        1.0f,

        // vertice,
        2.0f,
        -2.750f,
        0.0f,
        // colour,
        1.0f,
        1.0f,
        0.0f,

        // vertice,
        1.50f,
        -1.50f,
        0.0f,
        // colour,
        1.0f,
        0.0f,
        0.0f,
    };

    std::vector<GLuint> indices{
        0,
        1,
        9,

        1,
        2,
        3,

        1,
        3,
        7,

        3,
        5,
        7,

        3,
        4,
        5,

        7,
        5,
        6,

        9,
        7,
        8,

        9,
        1,
        7,
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

    object.setScale(glm::vec3(.25f, .25f, .25f));
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