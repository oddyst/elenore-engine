// Author: oknauta
// License: 
// File: engine.cpp
// Date: 2024-11-22

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <engine.hpp>

namespace Elenore
{
    Engine::Engine(int window_width, int window_height, const char *window_title)
    {
        glfwWindowHint(GLFW_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_VERSION_MINOR, 3);
        
        if(!glfwInit())
        {
            const char *description;
            std::cerr << "Error GLFW " << glfwGetError(&description) << "\n";
        }
        glViewport(0, 0, window_width, window_height);
        _main_window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr);
        glfwMakeContextCurrent(_main_window);
        if(glewInit() != GLEW_OK)
        {
            std::cerr << "Error GLEW -> " << glewGetErrorString(glewInit()) << "\n";
            glfwTerminate();
        }
    }
    
    void Engine::beginDraw()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    }
    
    void Engine::endDraw()
    {
        glfwSwapBuffers(_main_window);
        glfwPollEvents();
    }
    
    Engine::~Engine()
    {
        glfwDestroyWindow(_main_window);
        glfwTerminate();
    }
} // Elenore