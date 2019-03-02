//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_PROGRAM_H
#define UNTITLED2_PROGRAM_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include "VertexShader/VertexShader.h"
#include "FragmentShader/FragmentShader.h"
#include "../Matrix/ModelViewProjection.h"
#include "../../Object/LightSource.h"
#include "../../Object/Material.h"

class ModelViewProjection;
class LightSource;
class Material;

using namespace std;
using namespace glm;

class Shader
{
private:
    GLuint program;
    VertexShader *vertexShader = nullptr;
    FragmentShader *fragmentShader = nullptr;
public:
    Shader(const string &vertexShader, const string &fragmentShader);
    virtual ~Shader();

    void attachShaders();
    void link();
    void freeVertexShader();
    void freeFragmentShader();
    void use();
    void compile();
    void updateMatrices(const ModelViewProjection &mvp);
    void setUniformMatrix4(const string& fieldTitle, const mat4 &matrix);
    void setUniformMatrix3(const string& fieldTitle, const mat3 &matrix);
    void setUniformFloat(const string& fieldTitle, GLfloat value);
    void setUniformVec2(const string& fieldTitle, const vec2 &vector);
    void setUniformVec3(const string& fieldTitle, const vec3 &vector);
    void setModelMatrix(const mat4 &modelMatrix);
    void setViewMatrix(const mat4 &viewMatrix);
    void setProjectionMatrix(const mat4 &projectionMatrix);
    void setLightSource(const LightSource &source);
    void setMaterial(const Material &material);
    GLuint getProgramID() const;
};


#endif //UNTITLED2_PROGRAM_H
