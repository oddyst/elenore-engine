// Author: oknauta
// License:
// File: main.cpp
// Date: 2024-11-26

#include <elenore/elenore.hpp>

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

glm::vec3 camera_position = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 camera_target = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f);

float camera_speed = .1f;
float yaw = -90.0f;
float pitch = 0.0f;
float last_x = 400, last_y = 300;
bool first_mouse = false;

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera_position -= camera_speed * camera_front;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera_position += camera_speed * camera_front;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera_position += glm::cross(camera_up, camera_front) * camera_speed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera_position -= glm::cross(camera_up, camera_front) * camera_speed;
    }
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
};

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (first_mouse)
    {
        last_x = xpos;
        last_y = ypos;
        first_mouse = false;
    }

    float xoffset = xpos - last_x;
    float yoffset = last_y - ypos; // Inverter o eixo Y, pois a coordenada Y do mouse cresce para baixo
    last_x = xpos;
    last_y = ypos;

    float sensitivity = 0.1f; // Sensibilidade do mouse
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // Limitar o pitch para evitar virar a câmera para cima ou para baixo de forma extrema
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    // Atualizar a direção da câmera com base nos ângulos de yaw e pitch
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camera_front = glm::normalize(front);
}

int main(void)
{
    Elenore::Log::info("Hello, world");

    Elenore::Core::Window window;

    std::vector<GLfloat> vertices{
        0.0f,
        1.0f,
        0.0f,
        1.0f,
        0.0f,
        0.0f,

        -1.0f,
        -1.0f,
        0.0f,
        0.0f,
        1.0f,
        0.0f,

        1.0f,
        -1.0f,
        0.0f,
        0.0f,
        0.0f,
        1.0f,
    };

    std::vector<GLuint> indices{
        0, 1, 2};

    const char *vertex_shader_path = Elenore::Tools::readTextFromZip("assets.pkg", "shaders/vertex.glsl");
    const char *fragment_shader_path = Elenore::Tools::readTextFromZip("assets.pkg", "shaders/fragment.glsl");

    Elenore::Graphics::Shader shader(vertex_shader_path, fragment_shader_path);

    Elenore::Graphics::Mesh3D mesh(vertices, indices);

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    float x = 0.0f;

    int window_width, window_height;

    glfwSetInputMode(window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    while (!window.shouldClose())
    {
        glfwGetWindowSize(window.get(), &window_width, &window_height);
        processInput(window.get());
        glfwSetCursorPosCallback(window.get(), mouse_callback);
        x -= 0.01f;

        projection = glm::perspective(glm::radians(45.0f), (GLfloat)window_width / (GLfloat)window_height, 0.1f, 300.0f);
        view = glm::lookAt(camera_position, camera_position + camera_front, camera_up);
        // model = glm::rotate(model, glm::radians(x), glm::vec3(0.0f, 1.0f, 0.0f));

        window.draw();

        shader.use();

        shader.setUniform("model", model);
        shader.setUniform("view", view);
        shader.setUniform("projection", projection);

        mesh.draw();

        window.pollEvents();
    }

    return 0;
}