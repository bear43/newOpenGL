#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "OpenGL/Shader/Shader.h"
#include "OpenGL/Buffers/VAO/VAO.h"
#include "OpenGL/Buffers/IBO/IBO.h"
#include "OpenGL/Buffers/VBO/VBO.h"
#include "OpenGL/Matrix/ModelViewProjection.h"
#include "OpenGL/Camera/Camera.h"
#include "OpenGL/Texture/Texture.h"
#include "Object/Object3D.h"
#include "File/BMP/BMPFile.h"
#include "OpenGL/Util/VecToVector.h"
#include "System.h"
#include "Model/Model.h"

double deltaTime = 1.0;
bool g_Keys[1024] = { false };

void checkKeys()
{
    static GLfloat distanceChangeValue = 10.0f;
        GLfloat cameraSpeed = 8.0f * (GLfloat) deltaTime;
        if (g_Keys[GLFW_KEY_W])
            System::camera->moveForward(cameraSpeed);
        if (g_Keys[GLFW_KEY_S])
            System::camera->moveBack(cameraSpeed);
        if (g_Keys[GLFW_KEY_A])
            System::camera->moveLeft(cameraSpeed);
        if (g_Keys[GLFW_KEY_D])
            System::camera->moveRight(cameraSpeed);
        if(g_Keys[GLFW_KEY_P])
            System::lightSource.addDistance(distanceChangeValue);
        if(g_Keys[GLFW_KEY_M])
            System::lightSource.subDistance(distanceChangeValue);
}

void resize(GLFWwindow* window, int width, int height)
{
    System::onResize(width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(action == GLFW_PRESS)
        g_Keys[key] = true;
    else if(action == GLFW_RELEASE)
        g_Keys[key] = false;
    System::camera->setNeedUpdate(true);
}

void cursor_callback(GLFWwindow *window, double x, double y)
{
    static GLfloat originX = System::WIDTH;
    static GLfloat originY = System::HEIGHT;
    GLfloat deltaX = (originX - (GLfloat)x);
    GLfloat deltaY = (originY - (GLfloat)y);
    System::camera->updateDirectionByDeltaXY(deltaX, deltaY);
    originX = (GLfloat)x;
    originY = (GLfloat)y;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    System::setFunctions(key_callback, cursor_callback, resize);
    if(!System::init()) return 0;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    Shader program("vertexShader_texture_modelviewproj", "fragmentShader_texture");
    program.compile();
    BMPFile bmp("s.bmp");
    if(bmp.load() != FILE_SUCCESSFUL)
        throw runtime_error("Cannot read BMP");
    Texture* texture = new Texture(GL_TEXTURE_2D);
    texture->init(bmp.getData().data(), bmp.getHeader().Width, bmp.getHeader().Height, GL_RGB, GL_BGR, GL_UNSIGNED_BYTE);
    Model testModel("testModel", "test.obj");
    double oldTime;
    program.use();
    int counter = 0;
    while(!glfwWindowShouldClose(System::window))
    {
        glfwPollEvents();
        oldTime = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        checkKeys();
        System::camera->updateCamera(System::mvp);
        program.setViewMatrix(System::camera->getView());
        program.setProjectionMatrix(System::mvp.getProjection());
        System::lightSource.setPosition(System::camera->getPosition());
        program.setLightSource(System::lightSource);
        testModel.getTransform().identityAllMatrix();
        //testModel.getTransform().scale({0.1f, 0.1f, 0.1f});
        testModel.getTransform().translate({0.0f, 0.0f, -50.0f});
        testModel.draw(program);
        glFlush();
        glfwSwapBuffers(System::window);
        deltaTime = glfwGetTime()-oldTime;
        counter++;
    }
    glfwTerminate();
    delete System::camera;
    return 0;
}