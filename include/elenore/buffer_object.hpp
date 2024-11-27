// Author: oknauta
// License:
// File: buffer_object.hpp
// Date: 2024-11-26

#ifndef BUFFER_OBJECT_HPP
#define BUFFER_OBJECT_HPP

#include <vector>

#include <GL/glew.h>

namespace Elenore::Graphics::Object
{
    /**
     * @brief Define an array of generic vertex attribute data
     * @param index Specifies the index of the generic vertex attribute to be modified.
     * @param size Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4. Additionally, the symbolic constant `GL_BGRA` is accepted by `glVertexAttribPointer`. The initial value is 4.
     * @param type Specifies the data type of each component in the array. The symbolic constants `GL_BYTE`, `GL_UNSIGNED_BYTE`, `GL_SHORT`, `GL_UNSIGNED_SHORT`, `GL_INT`, and `GL_UNSIGNED_INT` are accepted by `glVertexAttribPointer`. The initial value is `GL_FLOAT`.
     * @param normalized For `glVertexAttribPointer`, specifies whether fixed-point data values should be normalized (`GL_TRUE`) or converted directly as fixed-point values (`GL_FALSE`) when they are accessed.
     * @param stride Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
     * @param pointer Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the `GL_ARRAY_BUFFER` target. The initial value is 0.
     */
    void setupVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

    /**
     * @brief Draw the elements on the screen.
     * @param vao The vertex array object to bind and unbind.
     * @param indices The size to render.
     */
    void drawElements(GLuint vao, std::vector<GLuint> indices);

    class BufferObject
    {
    public:
        virtual void bind() = 0;
        virtual void unbind() const = 0;
        GLuint getID();

    protected:
        GLuint _data;
    };

    /// @brief Creates the vertex array object (VAO) to use with shaders.
    class VAO : public BufferObject
    {
    public:
        /// @param quantity The amount of VAOs.
        VAO();
        /// @brief Binds the VAO to the shader.
        void bind() override;
        /// @brief Unbinds the VAO.
        void unbind() const override;

    private:
    };

    /// @brief Creates the vertex buffer object (VBO) to use with shaders
    class VBO : public BufferObject
    {
    public:
        VBO(std::vector<GLfloat> &vertices);
        void bind() override;
        void unbind() const override;

    private:
        std::vector<GLfloat> _vertices;
    };

    class EBO : public BufferObject
    {
    public:
        EBO(std::vector<GLuint> &indices);
        void bind() override;
        void unbind() const override;

    private:
        std::vector<GLuint> _indices;
    };

} // namespace Elenore::Graphics::Object

#endif // BUFFER_OBJECT_HPP