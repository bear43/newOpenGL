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
    glClearColor(0.3f, 0.5f, 0.9f, 1.0f);
    Program program("vertexShader_texture", "fragmentShader_texture");
    program.attachShaders();
    program.link();
    /*VAO vao("vao");
    VBOTexture vbo("vbo");
    IBO ibo("ibo");
    Texture2D texture2D({
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
        0.0f, 1.0f
        }, GL_REPEAT, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    BMPFile texFile("s.bmp");
    texFile.load();
    texture2D.init(texFile);
    vbo.fillBuffer({
            0.5f,  0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f,
        },{
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 0.0f
        }, texture2D);
    vbo.configure(vao);
    ibo.fillBuffer({
        0, 1, 3,
        1, 2, 3
    });
    ibo.configure(vao);*/

    Object2D obj("test", "s.bmp", {
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

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        program.use();
        /*texture2D.bind();
        vao.bindBuffer();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        VAO::unbindBuffer();*/
        obj.draw();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}