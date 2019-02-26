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
#include "OpenGL/Matrix/ModelViewProjection.h"
#include "OpenGL/Camera/Camera.h"

GLFWwindow* window;
Camera *camera;
double deltaTime = 1.0;
double originX = 0, originY = 0;
GLfloat sensitivity = 0.05;
bool g_Keys[1024] = { false };
int width = 640, height = 480;

void checkKeys()
{
        GLfloat cameraSpeed = 0.01f * (GLfloat) deltaTime;
        if (g_Keys[GLFW_KEY_W])
            camera->moveForward(cameraSpeed);
        if (g_Keys[GLFW_KEY_S])
            camera->moveBack(cameraSpeed);
        if (g_Keys[GLFW_KEY_A])
            camera->moveLeft(cameraSpeed);
        if (g_Keys[GLFW_KEY_D])
            camera->moveRight(cameraSpeed);
        camera->setNeedUpdate(true);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(action == GLFW_PRESS)
        g_Keys[key] = true;
    else if(action == GLFW_RELEASE)
        g_Keys[key] = false;
}

void cursor_callback(GLFWwindow *window, double x, double y)
{
    auto deltaX = (GLfloat)(originX - x);
    auto deltaY = (GLfloat)(originY - y);
    deltaX *= sensitivity;
    deltaY *= sensitivity;
    camera->updateDirectionByDeltaXY(deltaX, deltaY);
    originX = x;
    originY = y;
}

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
    glfwSetKeyCallback(window, key_callback);
    originX = (double)width/2;
    originY = (double)height/2;
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, cursor_callback);
    glfwSetCursorPos(window, originX, originY);
    camera = new Camera();
    return true;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    if(!init()) return 0;
    glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
    Program program("vertexShader_texture_modelviewproj", "fragmentShader_texture");
    program.compile();
    ModelViewProjection mat(640, 480);
    glEnableClientState(GL_VERTEX_ARRAY);
    Object2D obj("test", "s.bmp", {
            0.5f,  0.5f, -5.0f,
            0.5f, -0.5f, -5.0f,
            -0.5f, -0.5f, -5.0f,
            -0.5f,  0.5f, -5.0f
    }, {
                         1.0f, 0.0f, 0.0f,
                         0.0f, 1.0f, 0.0f,
                         0.0f, 0.0f, 1.0f,
                         1.0f, 1.0f, 1.0f
                 },{
                         0, 1, 3,
                         1, 2, 3
                 });
    double time;
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        time = glfwGetTime();
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        mat.resetPerspectiveMatrix(width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        program.use();
        checkKeys();
        camera->updateCamera();
        mat.setView(camera->getView());
        mat.setMatrices(program);
        obj.translate({0.0f, 0.0f, 5.0f});
        obj.rotate(0.01f, {0.1f, 0.0f, 0.0f});
        obj.translate({0.0f, 0.0f, -5.0f});
        obj.draw();
        glfwSwapBuffers(window);
        deltaTime = time-deltaTime;
    }
    glfwTerminate();
    delete camera;
    return 0;
}