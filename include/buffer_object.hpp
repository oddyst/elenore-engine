// Author: oknauta
// License:
// File: buffer_object.hpp
// Date: 2024-11-23

#ifndef BUFFER_OBJECT
#define BUFFER_OBJECT

#include <iostream>
#include <vector>

#include <GL/glew.h>

namespace Elenore::Buffer
{
    class bufferObject
    {
    public:
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual GLuint get() = 0;
    };

    class VBO : bufferObject
    {
    public:
        VBO(std::vector<GLfloat> &vertexData);
        void bind() { glBindBuffer(GL_ARRAY_BUFFER, _data); }
        void unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        GLuint get() override { return _data; }
        ~VBO();

    private:
        GLuint _data;
    };

    class EBO : bufferObject
    {
    public:
        EBO(std::vector<GLuint> &indexData);
        void bind() override { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _data); }
        void unbind() override { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); };
        GLuint get() override { return _data; }
        ~EBO();

    private:
        GLuint _data;
    };

    class VAO
    {
    public:
        VAO();
        void bind() const { glBindVertexArray(_data); }
        void unbind() const { glBindVertexArray(0); }
        GLuint get() const { return _data; }
        ~VAO();

    private:
        GLuint _data;
    };

    void drawElements(GLuint vao, std::vector<GLuint> indices);

    /**
     * @brief Setups the vertex attribution.
     * @param index Specifies the index of the generic vertex attribute to be modified.
     * @param size Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4. Additionally, the symbolic constant GL_BGRA is accepted by glVertexAttribPointer. The initial value is 4.
     * @param type Specifies the data type of each component in the array. The symbolic constants `GL_BYTE`, `GL_UNSIGNED_BYTE`, `GL_SHORT`, `GL_UNSIGNED_SHORT`, `GL_INT`, and `GL_UNSIGNED_INT` are accepted by `glVertexAttribPointer` and glVertexAttribIPointer. Additionally `GL_HALF_FLOAT`, `GL_FLOAT`, `GL_DOUBLE`, `GL_FIXED`, `GL_INT_2_10_10_10_REV`, `GL_UNSIGNED_INT_2_10_10_10_REV` and `GL_UNSIGNED_INT_10F_11F_11F_REV` are accepted by `glVertexAttribPointer`. `GL_DOUBLE` is also accepted by `glVertexAttribLPointer` and is the only token accepted by the type parameter for that function. The initial value is `GL_FLOAT`.
     * @param normalized For `glVertexAttribPointer`, specifies whether fixed-point data values should be normalized (`GL_TRUE`) or converted directly as fixed-point values (`GL_FALSE`) when they are accessed.
     * @param stride Specifies the byte offset between consecutive generic vertex attributes. If stride is 0, the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
     * @param pointer Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the `GL_ARRAY_BUFFER` target. The initial value is 0.
     */
    void setupVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

} // Elenore::Buffer

#endif // BUFFER_OBJECT