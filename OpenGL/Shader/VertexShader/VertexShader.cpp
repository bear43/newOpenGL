//
// Created by bear on 24.02.19.
//

#include "VertexShader.h"

VertexShader::VertexShader(const string &name) : FileInput(name)
{
    shader = glCreateShader(GL_VERTEX_SHADER);
    shaderCode = readAll();
    const GLchar* code = shaderCode.c_str();
    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    GLchar msg[512];
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, msg);
        cout << "Vertex shader has not been compiled!\n" << msg << endl;
    }
}

bool VertexShader::getStatus()
{
    return success != 0;
}

GLuint VertexShader::getShaderId()
{
    return shader;
}

VertexShader::~VertexShader()
{
    glDeleteShader(shader);
}
