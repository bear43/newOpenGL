//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_VERTEXSHADER_H
#define UNTITLED2_VERTEXSHADER_H


#include "../../../File/Input/FileInput.h"
#include <GL/glew.h>
#include <GL/gl.h>

class VertexShader : FileInput
{
private:
    GLuint shader;
    GLint success;
    string shaderCode;
public:
    explicit VertexShader(const string &name);

    virtual ~VertexShader();

    bool getStatus();
    GLuint getShaderId();
};


#endif //UNTITLED2_VERTEXSHADER_H
