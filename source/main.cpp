// Author: oknauta
// License:
// File: main.cpp
// Date: 2024-11-19

#include <camera.hpp>
#include <logger.hpp>
#include <object3d.hpp>
#include <window.hpp>

#include <memory>

int main(void)
{
    Elenore::Core::Window main_window(800, 600);

    Elenore::Data::vertex vertices{

        // Position      // Colors
        .0f, .5f, 0.0f, 1.0f, 0.0f, 0.0f, // RED
        -.5, -.5, 0.0f, 0.0f, 1.0f, 0.0f, // GREEN
        0.5, -.5, 0.0f, 0.0f, 0.0f, 1.0f};

    Elenore::Data::index indices{
        0, 1, 2};

    std::string vertex_shader, fragment_shader;

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

    Elenore::Graphics::Shader shader(vertex_shader.c_str(), fragment_shader.c_str());

    auto mesh = std::make_shared<Elenore::Graphics::Mesh>(vertices, indices, shader);

    Elenore::Entity::Object3D object(mesh, "Object");

    int x = 0;

    while (!main_window.shouldClose())
    {
        main_window.beginDraw();
        ++x;
        object.draw();
        object.setRotation(glm::vec3(0, 0, x));
        main_window.endDraw();
    }

    return 0;
}