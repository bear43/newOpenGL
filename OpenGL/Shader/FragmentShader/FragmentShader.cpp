//
// Created by bear on 24.02.19.
//

#include "FragmentShader.h"

FragmentShader::FragmentShader(const string &name) : FileStringInput(name)
{
    shader = glCreateShader(GL_FRAGMENT_SHADER);
    shaderCode = readAll();
    const GLchar* code = shaderCode.c_str();
    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    GLchar msg[512];
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, msg);
        cout << "Fragment shader has not been compiled!\n" << msg << endl;
    }
}

bool FragmentShader::getStatus()
{
    return success != 0;
}

GLuint FragmentShader::getShaderId()
{
    return shader;
}

FragmentShader::~FragmentShader()
{
    glDeleteShader(shader);
}
