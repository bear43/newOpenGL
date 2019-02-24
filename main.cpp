#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "OpenGL/Program/Program.h"
#include "OpenGL/Buffers/VAO/VAO.h"
#include "OpenGL/Buffers/VBO/VBODefault.h"
#include "OpenGL/Buffers/VBO/VBOColors.h"

GLFWwindow* window;

bool init()
{
    glfwInit();
    window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return false;
    }
    return true;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    if(!init()) return 0;
    int width, height;
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    Program program("vertexShader", "fragmentShader");
    program.attachShaders();
    program.link();
    VAO vao("vao");
    VBOColors vbo("vbo");
    vbo.fillBuffer({
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f},
                {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f});
    vbo.configure(vao);

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        program.use();
        vao.bindBuffer();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        VAO::unbindBuffer();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}