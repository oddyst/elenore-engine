// Author: oknauta
// License:
// File: main.cpp
// Date: 2024-11-26

#include <elenore/elenore.hpp>

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

int main(void)
{
    Elenore::Log::info("Hello, world");

    Elenore::Core::Window window;

    std::vector<GLfloat> vertices{
        0.0f,
        1.0f,
        0.0f,
        1.0f,
        0.0f,
        0.0f,

        -1.0f,
        -1.0f,
        0.0f,
        0.0f,
        1.0f,
        0.0f,

        1.0f,
        -1.0f,
        0.0f,
        0.0f,
        0.0f,
        1.0f,
    };

    std::vector<GLuint> indices{
        0, 1, 2};

    const char *vertex_shader_path = Elenore::Tools::readTextFromZip("assets.pkg", "shaders/vertex.glsl");
    const char *fragment_shader_path = Elenore::Tools::readTextFromZip("assets.pkg", "shaders/fragment.glsl");

    Elenore::Graphics::Shader shader(vertex_shader_path, fragment_shader_path);

    Elenore::Graphics::Mesh3D mesh(vertices, indices);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    float x = 0.0f;

    int window_width, window_height;

    while (!window.shouldClose())
    {
        glfwGetWindowSize(window.get(), &window_width, &window_height);

        x -= 0.01f;

        projection = glm::perspective(glm::radians(45.0f), (GLfloat)window_width / (GLfloat)window_height, 0.1f, 300.0f);
        view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        // model = glm::rotate(model, glm::radians(++x), glm::vec3(0.0f, 1.0f, 0.0f));

        window.draw();

        shader.use();

        shader.setUniform("model", model);
        shader.setUniform("view", view);
        shader.setUniform("projection", projection);

        mesh.draw();

        window.pollEvents();
    }

    return 0;
}