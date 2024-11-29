// Author: oknauta
// License:
// File: window.cpp
// Date: 2024-11-28

#include "elenore/window.hpp"
#include "elenore/log.hpp"

namespace Elenore::Core
{
    Window::Window(const int &width, const int &height, const char *title)
    {
        glfwWindowHint(GLFW_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!glfwInit())
        {
            const char *error;
            glfwGetError(&error);
            Log::error(error);
            glfwTerminate();
            return;
        }

        _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (_window == nullptr)
        {
            Log::error("Failed to create window");
            return;
        }

        glfwMakeContextCurrent(_window);

        if (glewInit() != GLEW_OK)
        {
            Log::error("Failed to initialize glew");
            return;
        }

        glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);

        glfwSwapInterval(1);

        Log::info("Created window");
    }

    void Window::framebufferSizeCallback(GLFWwindow *window, int w, int h)
    {
        glViewport(0, 0, w, h);
    }

    void Window::beginDraw(const GLclampf &RED, const GLclampf &GREEN, const GLclampf &BLUE)
    {
        glClearColor(RED, GREEN, BLUE, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::endDraw()
    {
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    GLFWwindow *Window::get()
    {
        return _window;
    }

    int Window::shouldClose()
    {
        return glfwWindowShouldClose(_window);
    }

    Window::~Window()
    {
        glfwDestroyWindow(_window);
        glfwTerminate();
        Log::info("Destroyed window");
    }
} // namespace Elenore::Core