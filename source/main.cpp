// Author: oknauta
// License: 
// File: main.cpp
// Date: 2024-11-19

#include <window.hpp>
#include <shader.hpp>
#include <mesh.hpp>
#include <object.hpp>
// #include <text.hpp>

int main(void)
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const char *WINDOW_TITLE = "Elenore Engine";
    
    // Creating an window 
    Elenore::Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    
    // Elenore::Text text("Hello, world!", WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 20, 255, 255, 255);
    
    std::vector<GLfloat>vertices =
    {
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };
    
    std::vector<GLuint>indices =
    {
        0, 1, 2,
        0, 2, 3
    };
    
    const char *source_vertex_shader =
    "#version 330 core\n"
    "layout(location = 0) in vec3 aPos;\n"
    "void main() {\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "}\n";
    
    const char *source_fragment_shader =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{FragColor = vec4(1.0, 1.0, 0.0, 1.0);}\n";

    
    Elenore::Shader yellow_shader(source_vertex_shader, source_fragment_shader);
    
    // Elenore::Mesh *mesh = new Elenore::Mesh(vertices, indices, yellow_shader);
    
    std::shared_ptr<Elenore::Mesh>mesh = std::make_unique<Elenore::Mesh>(vertices, indices, yellow_shader);
    
    Elenore::Object square(mesh, "Square", {0, 0, 0});
    
    while(!window.shouldClose())
    {
        window.beginDraw();
        
        square.draw();
        
        window.endDraw();
    }
    
    // delete mesh;
    
    return 0;
}
