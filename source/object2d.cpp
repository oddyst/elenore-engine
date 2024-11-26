// Author: oknauta
// License:
// File: object2d.cpp
// Date: 2024-11-26

#include <logger.hpp>
#include <object2d.hpp>

namespace Elenore::Entity
{
    Object2D::Object2D(std::string name, glm::vec3 color, glm::vec2 size)
        : _name(name), _size(size)
    {
        Log::info("Object in scene: " + _name);
    }

    void Object2D::draw()
    {
        // Hardcoded shader sources
        std::string vertex_shader_source = R"(
#version 330 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aColor;
out vec3 fragColor;
uniform mat4 model;
void main()
{
    fragColor = aColor;
    gl_Position = model * vec4(aPosition, 1.0f);
})";

        std::string fragment_shader_source = R"(
        #version 330 core
        in vec3 fragColor;
        out vec4 color;
        void main()
        {
            color = vec4(fragColor, 1.0f);
        })";

        // Create shader with hardcoded source
        Graphics::Shader shader(vertex_shader_source.c_str(), fragment_shader_source.c_str());
        shader.use();

        // Now, continue with the rest of the drawing code...
        // Setup buffers, VAO, and EBO for drawing the object.
        std::vector<GLfloat> vertices = {
            // positions       // colors
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // top right
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f   // top left
        };

        std::vector<GLuint> indices = {0, 1, 3, 1, 2, 3};

        Buffer::VBO vbo(vertices);
        Buffer::EBO ebo(indices);
        Buffer::VAO vao;

        // Set up vertex attributes
        Buffer::setupVertexAttrib(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)0);                     // positions
        Buffer::setupVertexAttrib(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat))); // colors

        // Draw the object
        Buffer::drawElements(vao.get(), indices);
    }

    void Object2D::setPosition(glm::vec2 position)
    {
        _position = position;
    }

    void Object2D::setRotation(glm::vec2 rotation)
    {
        _rotation = rotation;
    }

    void Object2D::setScale(glm::vec2 scale)
    {
        _scale = scale;
    }

} // Elenore::Entity