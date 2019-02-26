//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_PROGRAM_H
#define UNTITLED2_PROGRAM_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include "../Shader/VertexShader/VertexShader.h"
#include "../Shader/FragmentShader/FragmentShader.h"

using namespace std;

class Program
{
private:
    GLuint program;
    VertexShader *vertexShader = nullptr;
    FragmentShader *fragmentShader = nullptr;
public:
    Program(const string &vertexShader, const string &fragmentShader);
    virtual ~Program();

    void attachShaders();
    void link();
    void freeVertexShader();
    void freeFragmentShader();
    void use();
    void compile();

    GLuint getProgramID() const;
};


#endif //UNTITLED2_PROGRAM_H
