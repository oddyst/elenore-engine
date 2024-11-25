// Author: oknauta
// License: 
// File: buffer_object.hpp
// Date: 2024-11-23

#ifndef BUFFER_OBJECT
#define BUFFER_OBJECT

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace Buffer
{
    class VBO
    {
    public:
        VBO(std::vector<GLfloat>vertices);
        void bind() const { glBindBuffer(GL_ARRAY_BUFFER, _vbo); }
        void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        GLuint getVBO() { return _vbo; }
        ~VBO();
    private:
        GLuint _vbo;
    };
    
    class EBO
    {
    public:
        EBO(std::vector<GLuint>indices);
        void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo); }
        void unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); };
        ~EBO();
    private:
        GLuint _ebo;
    };
    
    class VAO
    {
    public:
        VAO();
        void bind() const { glBindVertexArray(_vao); }
        void unbind() const { glBindVertexArray(0); }
        GLuint getVAO() const { return _vao; }
        ~VAO();
    private:
        GLuint _vao;
    };
    
    
} // Elenore

#endif // BUFFER_OBJECT