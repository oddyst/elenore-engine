// Author: oknauta
// License:
// File: test_file.cpp
// Date: 2024-11-29

#include "elenore/core/log.hpp"
#include "elenore/core/mesh3d.hpp"
#include "elenore/core/object3d.hpp"
#include "elenore/core/window.hpp"
#include "elenore/core/tools.hpp"

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
        
    const char *vertex_shader = Elenore::Tools::readTextFile("assets.pkg", "shaders/vertex.glsl");
    const char *fragment_shader = Elenore::Tools::readTextFile("assets.pkg", "shaders/fragment.glsl");
    

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