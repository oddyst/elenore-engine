// Author: oknauta
// License:
// File: window.hpp
// Date: 2024-12-02

#ifndef ELN_WINDOW_HPP
#define ELN_WINDOW_HPP

#include <GLFW/glfw3.h>

namespace Elenore::Core
{
    class Window
    {
    public:
        Window(const char *title = "GL generic window", const int &width = 800, const int &height = 600);
        GLFWwindow *get() const;
        int shouldClose() const;
        void draw(const GLclampf &RED = 0.1f, const GLclampf &GREEN = 0.1f, const GLclampf &BLUE = 0.1f, const GLclampf &ALPHA = 1.0f) const;
        void pollEvents() const;
        ~Window();
    private:
        GLFWwindow *_window;
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    };
} // namespace Elenore::Core

#endif // ELN_WINDOW_HPP