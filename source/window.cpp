// Author: oknauta
// License:
// File: window.cpp
// Date: 2024-11-22

#include <logger.hpp>
#include <window.hpp>

#include <glm/ext.hpp>

namespace Elenore::Core
{
    Window::Window(int window_width, int window_height, const char *window_title)
    {
        Log::info("Starting window...");

        glfwWindowHint(GLFW_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_FALSE);

        glEnable(GL_DEPTH_TEST);

        if (!glfwInit())
        {
            const char *description;
            glfwGetError(&description);
            Log::error(description);
        }

        _main_window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr);

        if (!_main_window)
        {
            // std::cerr << "Error while creating window.\n";
            Log::error("Failed to create window.");
            glfwTerminate();
        }

        glfwMakeContextCurrent(_main_window);
        glfwSetFramebufferSizeCallback(_main_window, framebufferSizeCallback);

        if (glewInit() != GLEW_OK)
        {
            // std::cerr << "Error GLEW -> " << glewGetErrorString(glewInit()) <<
            // "\n";

            Log::error("Failed to start glew.");

            glfwTerminate();
        }
    }

    void Window::beginDraw(const glm::vec4 &clear_color)
    {
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::endDraw()
    {
        glfwSwapBuffers(_main_window);
        glfwPollEvents();
    }

    void Window::framebufferSizeCallback(GLFWwindow *window, int w, int h)
    {
        glViewport(0, 0, w, h);
    }

    Window::~Window()
    {
        Log::info("Destroying window...");
        glfwDestroyWindow(_main_window);
        glfwTerminate();
    }
} // Elenore::Core