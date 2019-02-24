//
// Created by bear on 24.02.19.
//

#include "Program.h"

Program::Program(const string &vertexShader, const string &fragmentShader)
{
    this->vertexShader = new VertexShader(vertexShader);
    this->fragmentShader = new FragmentShader(fragmentShader);
    program = glCreateProgram();
}

Program::~Program()
{
    freeVertexShader();
    freeFragmentShader();
}

void Program::attachShaders()
{
    glAttachShader(program, vertexShader->getShaderId());
    glAttachShader(program, fragmentShader->getShaderId());
}

void Program::link()
{
    GLint success;
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    GLchar msg[512];
    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, msg);
        cout << "Link program error!\n" << msg << endl;
    }
    else
    {
        freeVertexShader();
        freeFragmentShader();
    }
}

void Program::freeVertexShader()
{
    delete vertexShader;
    vertexShader = nullptr;
}

void Program::freeFragmentShader()
{
    delete fragmentShader;
    fragmentShader = nullptr;
}

void Program::use()
{
    glUseProgram(program);
}
