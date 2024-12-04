// Author: oknauta
// License:
// File: window.cpp
// Date: 2024-12-02

#include <GL/glew.h>

#include "elenore/logger.hpp"
#include "elenore/window.hpp"

namespace Elenore::Core
{
    Window::Window(const char *title, const int &width, const int &height)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!glfwInit())
        {
            const char *description;
            glfwGetError(&description);
            Log::info(description);
            return;
        }

        _window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!_window)
        {
            Log::error("Failed to load window.");
            return;
        }

        glfwMakeContextCurrent(_window);

        if (glewInit() != GLEW_OK)
        {
            Log::error("Failed to load GLEW.");
            return;
        }

        glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

        Log::info("Window created");
    }

    void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    GLFWwindow *Window::get() const { return _window; }

    int Window::shouldClose() const { return glfwWindowShouldClose(_window); }

    void Window::draw(const GLclampf &RED, const GLclampf &GREEN, const GLclampf &BLUE, const GLclampf &ALPHA) const
    {
        glClearColor(RED, GREEN, BLUE, ALPHA);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::pollEvents() const
    {
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    Window::~Window()
    {
        if (!_window)
        {
            glfwDestroyWindow(_window);
            Log::info("Window destroyed");
        }
        glfwTerminate();
    }

} // namespace Elenore::Core
