// Author: oknauta
// License:
// File: window.cpp
// Date: 2024-11-26

#include <elenore/log.hpp>
#include <elenore/window.hpp>

namespace Elenore::Core
{
    Window::Window(const int &WIDTH, const int &HEIGHT, const char *TITLE)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        Log::info("Initializing window...");

        if (!glfwInit())
        {
            const char *description;
            glfwGetError(&description);
            Log::error(description);
            glfwTerminate();
            return;
        }
        _data = glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr);

        if (_data == nullptr)
        {
            Log::error("Failed to create window.");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(_data);
        if (glewInit() != GLEW_OK)
        {
            Log::error("Failed to load glew.");
            glfwTerminate();
            return;
        }

        Log::info("OpenGL version: " + std::string(reinterpret_cast<const char *>(glGetString(GL_VERSION))));

        glfwSetFramebufferSizeCallback(_data, framebuffer_size_callback);

        glfwSwapInterval(1);

        _previous_time = glfwGetTime();
        _delta_time = 0.0;
    }

    void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    GLFWwindow *Window::getID()
    {
        return _data;
    }
    int Window::shouldClose()
    {
        return glfwWindowShouldClose(_data);
    }

    double Window::getDeltaTime()
    {
        double current_time = glfwGetTime();
        _delta_time = current_time - _previous_time;
        _previous_time = current_time;
        return _delta_time;
    }

    void Window::beginDraw(const GLclampf RED, const GLclampf GREEN, const GLclampf BLUE, const GLclampf ALPHA)
    {
        glClearColor(RED, GREEN, BLUE, ALPHA);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::endDraw()
    {
        glfwSwapBuffers(_data);
        glfwPollEvents();
    }

    Window::~Window()
    {
        Log::info("Closing window...");
        glfwDestroyWindow(_data);
        glfwTerminate();
    }
} // namespace Elenore::Core