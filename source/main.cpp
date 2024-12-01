// Author: oknauta
// License:
// File: main.cpp
// Date: 2024-11-26

#include "elenore/core/log.hpp"
#include "elenore/core/mesh3d.hpp"
#include "elenore/core/object3d.hpp"
#include "elenore/core/tools.hpp"
#include "elenore/core/window.hpp"
#include <glm/ext.hpp>

int main(void)
{
    Elenore::Log::info("Hello, world!");

    Elenore::Core::Window window;

    std::vector<GLfloat> vertices =
        {
            0.0f,
            1.0f,
            0.0f,
            // Colour
            1.0f,
            0.0f,
            0.0,

            -1.0f,
            -1.0f,
            0.0f,
            // Colour
            0.0f,
            1.0f,
            0.0f,

            1.0f,
            -1.0f,
            0.0f,
            // Colour
            0.0f,
            0.0f,
            1.0f

        };

    std::vector<GLuint> indices =
        {
            0, 1, 2};

    const char *vertex_shader = Elenore::Tools::readTextFile("assets.pkg", "shaders/vertex.glsl");
    const char *fragment_shader = Elenore::Tools::readTextFile("assets.pkg", "shaders/fragment.glsl");

    Elenore::Graphics::Shader shader(vertex_shader, fragment_shader);

    auto mesh = std::make_shared<Elenore::Graphics::Mesh3D>(vertices, indices, shader);
    Elenore::Entity::Object3D object("Triangle", mesh);

    auto camera_position = glm::vec3(0.0f, 0.0f, 3.0f);
    auto camera_target = glm::vec3(0.0f, 0.0f, 0.0f);
    auto camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
    auto camera_forward = glm::normalize(camera_position - camera_target);
    auto camera_right = glm::normalize(glm::cross(camera_up, camera_forward));
    camera_up = glm::normalize(glm::cross(camera_forward, camera_right));

    object.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    object.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
    int width, height;

    glm::mat4 projection;
    glm::mat4 view;

    float x = 0.0f;

    while (!window.shouldClose())
    {
        glfwGetWindowSize(window.get(), &width, &height);
        window.beginDraw();

        // glm::mat4 projection = glm::mat4(1.0f);
        // glm::mat4 view = glm::mat4(1.0f);

        if (projection[0][0] != (float)width / (float)height)
        {
            projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
        }

        view = glm::lookAt(camera_position, camera_target, camera_up);
        // glm::mat4 projection = glm::ortho(0.f, 400.f, 0.f, 400.f, -1.f, 1.f);
        // glm::mat4 view = glm::lookAt(camera_position, camera_target, camera_up);

        glm::mat4 model = glm::mat4(1.0f);

        ++x;

        object.getShader().setUniform("projection", projection);
        object.getShader().setUniform("view", view);
        object.getShader().setUniform("model", object.getModel());

        // object.setPosition(glm::vec3(0.0f, 0.0f, -20.0f));

        object.setPosition(glm::vec3(0.0f, 0.0f, -2.0f));

        object.setRotation(glm::vec3(x, x, x));

        object.draw();

        window.endDraw();
    }

    return 0;
}