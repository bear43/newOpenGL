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
    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "color");
    glBindAttribLocation(program, 2, "normal");
    glBindAttribLocation(program, 3, "texCoord");
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

GLuint Program::getProgramID() const
{
    return program;
}

void Program::compile()
{
    attachShaders();
    link();
}

void Program::updateMatrices(const ModelViewProjection &mvp)
{
    GLint model_id = glGetUniformLocation(program, "model");
    GLint view_id = glGetUniformLocation(program, "view");
    GLint proj_id = glGetUniformLocation(program, "projection");
    glUniformMatrix4fv(model_id, 1, GL_FALSE, value_ptr(mvp.getModel()));
    glUniformMatrix4fv(view_id, 1, GL_FALSE, value_ptr(mvp.getView()));
    glUniformMatrix4fv(proj_id, 1, GL_FALSE, value_ptr(mvp.getProjection()));
}
