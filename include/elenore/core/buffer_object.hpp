// Author: oknauta
// License:
// File: buffer_object.hpp
// Date: 2024-11-28

#ifndef ELN_BUFFER_OBJECT_HPP
#define ELN_BUFFER_OBJECT_HPP

#include <GL/glew.h>

#include <vector>

namespace Elenore::Graphics
{
    class BufferObject
    {
    public:
        virtual void bind() const;
        virtual void unbind() const;
        GLuint getData() const;
        virtual ~BufferObject() = 0;

    protected:
        GLuint _data;
    };

    class VAO : public BufferObject
    {
    public:
        VAO();
        void bind() const override;
        void unbind() const override;
        ~VAO() override;
    };

    class VBO : public BufferObject
    {
    public:
        VBO(std::vector<GLfloat> vertices);
        void bind() const override;
        void unbind() const override;
        ~VBO() override;

    private:
        std::vector<GLfloat> _vertices;
    };

    class EBO : public BufferObject
    {
    public:
        EBO(std::vector<GLuint> indices);
        void bind() const override;
        void unbind() const override;
        ~EBO() override;

    private:
        std::vector<GLuint> _indices;
    };
} // namespace Elenore::Graphics

#endif // ELN_BUFFER_OBJECT_HPP