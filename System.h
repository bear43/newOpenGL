//
// Created by bear on 02.03.19.
//

#ifndef UNTITLED2_INIT_H
#define UNTITLED2_INIT_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "OpenGL/Camera/Camera.h"

using namespace std;


namespace System
{
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    int width = WIDTH;
    int height = HEIGHT;
    GLFWwindow *window;
    GLFWkeyfun key_callback;
    GLFWcursorposfun cursor_callback;
    GLFWwindowsizefun resize_callback;
    Camera *camera;
    ModelViewProjection mvp(width, height);
    LightSource lightSource({1.0f, 1.0f, 1.0f});


    bool init()
    {
        glfwInit();
        window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
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
        glfwSetKeyCallback(window, key_callback);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetCursorPosCallback(window, cursor_callback);
        glfwSetWindowSizeCallback(window, resize_callback);
        glfwSetCursorPos(window, WIDTH/2.0f, HEIGHT/2.0f);
        camera = new Camera();
        return true;
    }

    void onResize(int width, int height)
    {
        glViewport(0, 0, width, height);
        mvp.resetPerspectiveMatrix(width, height);
        System::width = width;
        System::height = height;
    }

    void setFunctions(GLFWkeyfun key_callback, GLFWcursorposfun cursor_callback, GLFWwindowsizefun resize_callback)
    {
        System::key_callback = key_callback;
        System::cursor_callback = cursor_callback;
        System::resize_callback = resize_callback;
    }
};


#endif //UNTITLED2_INIT_H
