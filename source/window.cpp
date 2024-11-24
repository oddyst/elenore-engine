// Author: oknauta
// License: 
// File: window.cpp
// Date: 2024-11-22

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <window.hpp>

namespace Elenore
{
    Window::Window(int window_width, int window_height, const char *window_title)
    {
        glfwWindowHint(GLFW_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_VERSION_MINOR, 3);
        
        if(!glfwInit())
        {
            const char *description;
            std::cerr << "Error GLFW " << glfwGetError(&description) << "\n";
        }
        
        _main_window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr);
        
        if(!_main_window)
        {
            std::cerr << "Error while creating window.\n";
            glfwTerminate();
        }
        
        glfwMakeContextCurrent(_main_window);
        glfwSetFramebufferSizeCallback(_main_window, framebufferSizeCallback);
        
        if(glewInit() != GLEW_OK)
        {
            std::cerr << "Error GLEW -> " << glewGetErrorString(glewInit()) << "\n";
            glfwTerminate();
        }
    }
    
    void Window::beginDraw()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
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
        glfwDestroyWindow(_main_window);
        glfwTerminate();
    }
} // Elenore