//
// Created by bear on 24.02.19.
//

#include "Shader.h"

Shader::Shader(const string &vertexShader, const string &fragmentShader)
{
    this->vertexShader = new VertexShader(vertexShader);
    this->fragmentShader = new FragmentShader(fragmentShader);
    program = glCreateProgram();
}

Shader::~Shader()
{
    freeVertexShader();
    freeFragmentShader();
}

void Shader::attachShaders()
{
    glBindAttribLocation(program, 0, "position");
    glBindAttribLocation(program, 1, "color");
    glBindAttribLocation(program, 2, "normal");
    glBindAttribLocation(program, 3, "texCoord");
    glAttachShader(program, vertexShader->getShaderId());
    glAttachShader(program, fragmentShader->getShaderId());
}

void Shader::link()
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

void Shader::freeVertexShader()
{
    delete vertexShader;
    vertexShader = nullptr;
}

void Shader::freeFragmentShader()
{
    delete fragmentShader;
    fragmentShader = nullptr;
}

void Shader::use()
{
    glUseProgram(program);
}

GLuint Shader::getProgramID() const
{
    return program;
}

void Shader::compile()
{
    attachShaders();
    link();
}

void Shader::updateMatrices(const ModelViewProjection &mvp)
{
    setUniformMatrix4("model", mvp.getModel());
    setUniformMatrix4("view", mvp.getView());
    setUniformMatrix4("projection", mvp.getProjection());
    setUniformMatrix3("normalMatrix", mat3(transpose(inverse(mvp.getModel()))));
}

void Shader::setUniformVec3(const string &fieldTitle, const vec3 &vector)
{
    GLint field_id = glGetUniformLocation(program, fieldTitle.c_str());
    glUniform3fv(field_id, 1, value_ptr(vector));
}

void Shader::setUniformVec2(const string &fieldTitle, const vec2 &vector)
{
    GLint field_id = glGetUniformLocation(program, fieldTitle.c_str());
    glUniform2fv(field_id, 1, value_ptr(vector));
}

void Shader::setUniformFloat(const string &fieldTitle, GLfloat value)
{
    GLint field_id = glGetUniformLocation(program, fieldTitle.c_str());
    glUniform1f(field_id, value);
}

void Shader::setUniformMatrix3(const string &fieldTitle, const mat3 &matrix)
{
    GLint field_id = glGetUniformLocation(program, fieldTitle.c_str());
    glUniformMatrix3fv(field_id, 1, GL_FALSE, value_ptr(matrix));
}

void Shader::setUniformMatrix4(const string &fieldTitle, const mat4 &matrix)
{
    GLint field_id = glGetUniformLocation(program, fieldTitle.c_str());
    glUniformMatrix4fv(field_id, 1, GL_FALSE, value_ptr(matrix));
}

void Shader::setModelMatrix(const mat4 &modelMatrix)
{
    setUniformMatrix4("model", modelMatrix);
    setUniformMatrix3("normalMatrix", mat3(transpose(inverse(modelMatrix))));
}

void Shader::setViewMatrix(const mat4 &viewMatrix)
{
    setUniformMatrix4("view", viewMatrix);
}

void Shader::setProjectionMatrix(const mat4 &projectionMatrix)
{
    setUniformMatrix4("projection", projectionMatrix);
}

void Shader::setLightSource(const LightSource &source)
{
    setUniformVec3("lightPos", source.getPosition());
    setUniformVec3("lightColor", source.getColor());
    setUniformFloat("lightMaxDistance", source.getMaxDistance());
}

void Shader::setMaterial(const Material &material)
{
    setUniformVec3("material.ambient", material.getAmbient());
    setUniformVec3("material.diffuse", material.getDiffuse());
    setUniformVec3("material.specular", material.getSpecular());
    setUniformFloat("material.shininess", 32.0f);
}
