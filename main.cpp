#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "OpenGL/Program/Program.h"
#include "OpenGL/Buffers/VAO/VAO.h"
#include "OpenGL/Buffers/IBO/IBO.h"
#include "OpenGL/Buffers/VBO/VBO.h"
#include "OpenGL/Matrix/ModelViewProjection.h"
#include "OpenGL/Camera/Camera.h"
#include "OpenGL/Texture/Texture.h"
#include "Object/Object3D.h"
#include "OBJLoader/OBJ_Loader.h"
#include "File/BMP/BMPFile.h"

using namespace objl;

GLFWwindow* window;
Camera *camera;
double deltaTime = 1.0;
double originX = 0, originY = 0;
GLfloat sensitivity = 0.05;
bool g_Keys[1024] = { false };
int width = 640, height = 480;
ModelViewProjection mvp(640, 480);
Loader loader;

void checkKeys()
{
        GLfloat cameraSpeed = 8.0f * (GLfloat) deltaTime;
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

void resize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    mvp.resetPerspectiveMatrix(width, height);
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

vector<GLfloat> datax;

bool init()
{
    glfwInit();
    window = glfwCreateWindow(1920, 1080, "LearnOpenGL", nullptr, nullptr);
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
    glfwSetWindowSizeCallback(window, resize);
    glfwSetCursorPos(window, originX, originY);
    camera = new Camera();
    return true;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    if(!init()) return 0;
    glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_DEPTH_TEST);
    Program program("vertexShader_texture_modelviewproj", "fragmentShader_texture");
    program.compile();
    BMPFile bmp("s.bmp");
    if(bmp.load() != FILE_SUCCESSFUL)
        throw runtime_error("Cannot read BMP");
    //Texture* texture = new Texture(GL_TEXTURE_2D);
    //texture->init(bmp.getData().data(), bmp.getHeader().Width, bmp.getHeader().Height, GL_RGB, GL_BGR, GL_UNSIGNED_BYTE);
    /*Object3D obj("test",
            {0.0f, 0.0f, -5.0f},
            {
            },
            {
            },
            {
            },
            {
            },
            texture,
            nullptr,
            {});*/
    Object3D obj;
    loader.LoadFile("test.obj");
    for(const Vertex &v : loader.LoadedVertices)
    {
        obj.getColors().emplace_back(1.0f, 1.0f, 1.0f);
        obj.getPoints().emplace_back(v.Position.X, v.Position.Y, v.Position.Z);
        obj.getTexCoords().emplace_back(v.TextureCoordinate.X, v.TextureCoordinate.Y);
    }
    obj.fillBuffers();
    double oldTime;
    //obj.getTransform()->rotate(radians(90.0f), {0.0f, 0.0f, 1.0f});
    program.use();
    obj.getTransform().scale({0.1f, 0.1f, 0.1f});
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        oldTime = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        program.updateMatrices(mvp);
        checkKeys();
        camera->updateCamera(mvp);
        //obj.getTransform()->rotate(radians(1.0f), {1.0f, 0.0f, 0.0f});
        obj.draw(mvp);
        glFlush();
        glfwSwapBuffers(window);
        deltaTime = glfwGetTime()-oldTime;
    }
    glfwTerminate();
    delete camera;
    return 0;
}