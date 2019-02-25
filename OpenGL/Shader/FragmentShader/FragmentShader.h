//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_FRAGMENTSHADER_H
#define UNTITLED2_FRAGMENTSHADER_H


#include "../../../File/Input/FileStringInput.h"
#include <GL/glew.h>
#include <GL/gl.h>

class FragmentShader : FileStringInput
{
private:
    GLuint shader;
    GLint success;
    string shaderCode;
public:
    explicit FragmentShader(const string &name);

    virtual ~FragmentShader();

    bool getStatus();
    GLuint getShaderId();
};


#endif //UNTITLED2_FRAGMENTSHADER_H
