// Author: oknauta
// License:
// File: window.hpp
// Date: 2024-11-28

#ifndef ELN_WINDOW_HPP
#define ELN_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Elenore::Core
{
    class Window
    {
    public:
        Window(const int &width = 800, const int &height = 600, const char *title = "GL generic window");
        GLFWwindow *get();
        int shouldClose();
        void beginDraw(const GLclampf &RED = 0.0f, const GLclampf &GREEN = 0.0f, const GLclampf &BLUE = 0.05f);
        void endDraw();
        ~Window();
        static void framebufferSizeCallback(GLFWwindow *window, int w, int h);

    private:
        GLFWwindow *_window;
    };
} // namespace Elenore::Core

#endif // ELN_WINDOW_HPP