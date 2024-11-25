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
    class BufferObject
    {
    public:
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual GLuint get() = 0;
    };
    
    class VBO : BufferObject
    {
    public:
        VBO(std::vector<GLfloat>&vertexData);
        void bind() { glBindBuffer(GL_ARRAY_BUFFER, _vbo); }
        void unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        GLuint get() override { return _vbo; }
        ~VBO();
    private:
        GLuint _vbo;
    };
    
    class EBO : BufferObject
    {
    public:
        EBO(std::vector<GLuint>&indexData);
        void bind() override { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo); }
        void unbind() override { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); };
        GLuint get() override { return _ebo; }
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