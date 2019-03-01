//
// Created by bear on 26.02.19.
//

#ifndef UNTITLED2_MATRIX_H
#define UNTITLED2_MATRIX_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include "../Program/Program.h"

class Program;

using namespace glm;

class ModelViewProjection
{
private:
    inline static const GLfloat perspective_default_angle = 45.0f;
    inline static const GLfloat perspective_default_near_clip = 0.1f;
    inline static const GLfloat perspective_default_far_clip = 2000.0f;
    int width;
    int height;
    GLfloat perspective_angle = perspective_default_angle;
    GLfloat perspective_near_clip = perspective_default_near_clip;
    GLfloat perspective_far_clip = perspective_default_far_clip;
    mat4 model;
    mat4 view;
    mat4 projection;
public:
    ModelViewProjection(const mat4 &model, const mat4 &view, const mat4 &projection);
    ModelViewProjection(int width, int height);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    const mat4 &getModel() const;

    void setModel(const mat4 &model);

    const mat4 &getView() const;

    void setView(const mat4 &view);

    const mat4 &getProjection() const;

    void setProjection(const mat4 &projection);

    void resetPerspectiveMatrix();

    void resetPerspectiveMatrix(int width, int height);

    void resetPerspectiveMatrix(int width, int height, GLfloat angle);

    void resetPerspectiveMatrix(int width, int height, GLfloat angle, GLfloat near_clip, GLfloat far_clip);
};


#endif //UNTITLED2_MATRIX_H
