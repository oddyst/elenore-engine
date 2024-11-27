// Author: oknauta
// License:
// File: window.hpp
// Date: 2024-11-26

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Elenore::Core
{
    class Window
    {
    public:
        Window(const int &width, const int &height, const char *window_title = "GL generic window");
        GLFWwindow *getID();
        int shouldClose();
        void beginDraw(const GLclampf RED = 0.1f, const GLclampf GREEN = 0.1f, const GLclampf BLUE = 0.1f, const GLclampf ALPHA = 1.0f);
        void endDraw();
        ~Window();

    private:
        GLFWwindow *_data;
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    };
} // namespace Elenore::Core

#endif // WINDOW_HPP