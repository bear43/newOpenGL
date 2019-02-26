#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "OpenGL/Program/Program.h"
#include "OpenGL/Buffers/VAO/VAO.h"
#include "OpenGL/Buffers/VBO/VBODefault.h"
#include "OpenGL/Buffers/VBO/VBOColors.h"
#include "OpenGL/Buffers/VBO/VBOTexture.h"
#include "OpenGL/Texture/Texture2D.h"
#include "OpenGL/Buffers/IBO/IBO.h"
#include "Object/Object2D/Object2D.h"

GLFWwindow* window;

bool init()
{
    glfwInit();
    window = glfwCreateWindow(640, 480, "LearnOpenGL", nullptr, nullptr);
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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    Program program("vertexShader_texture", "fragmentShader_texture");
    program.attachShaders();
    program.link();
    glEnableClientState(GL_VERTEX_ARRAY);
    Object2D obj("test", "s.bmp", {
            0.8f,  0.5f, 0.0f,
            0.8f, -0.5f, 0.0f,
            0.6f, -0.5f, 0.0f,
            0.6f,  0.5f, 0.0f
    }, {
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 0.0f
    },{
            0, 1, 3,
            1, 2, 3
    });

    Object2D obj2("teswt", "s.bmp", {
            0.5f,  0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
    }, {
                         1.0f, 0.0f, 0.0f,
                         0.0f, 1.0f, 0.0f,
                         0.0f, 0.0f, 1.0f,
                         1.0f, 1.0f, 0.0f
                 },{
                         0, 1, 3,
                         1, 2, 3
                 });

    obj.configure();
    obj2.configure();
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        program.use();
        obj.draw();
        obj2.draw();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}