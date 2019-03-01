//
// Created by bear on 26.02.19.
//

#include "ModelViewProjection.h"

ModelViewProjection::ModelViewProjection(const mat4 &model, const mat4 &view, const mat4 &projection) : model(model), view(view),
                                                                              projection(projection)
{}

ModelViewProjection::ModelViewProjection(int width, int height) : ModelViewProjection(mat4(1.0), mat4(1.0), mat4(1.0))
{
    resetPerspectiveMatrix(width, height);
}

int ModelViewProjection::getWidth() const
{
    return width;
}

void ModelViewProjection::setWidth(int width)
{
    ModelViewProjection::width = width;
}

int ModelViewProjection::getHeight() const
{
    return height;
}

void ModelViewProjection::setHeight(int height)
{
    ModelViewProjection::height = height;
}

const mat4 &ModelViewProjection::getModel() const
{
    return model;
}

void ModelViewProjection::setModel(const mat4 &model)
{
    ModelViewProjection::model = model;
}

const mat4 &ModelViewProjection::getView() const
{
    return view;
}

void ModelViewProjection::setView(const mat4 &view)
{
    ModelViewProjection::view = view;
}

const mat4 &ModelViewProjection::getProjection() const
{
    return projection;
}

void ModelViewProjection::setProjection(const mat4 &projection)
{
    ModelViewProjection::projection = projection;
}

void ModelViewProjection::resetPerspectiveMatrix()
{
    projection = perspective(perspective_angle, (float)(width)/(float)(height), perspective_near_clip, perspective_far_clip);
}

void ModelViewProjection::resetPerspectiveMatrix(int width, int height, GLfloat angle, GLfloat near_clip, GLfloat far_clip)
{
    this->width = width;
    this->height = height;
    this->perspective_angle = angle;
    this->perspective_near_clip = near_clip;
    this->perspective_far_clip = far_clip;
    resetPerspectiveMatrix();
}

void ModelViewProjection::resetPerspectiveMatrix(int width, int height, GLfloat angle)
{
    resetPerspectiveMatrix(width, height, angle, perspective_near_clip, perspective_far_clip);
}

void ModelViewProjection::resetPerspectiveMatrix(int width, int height)
{
    resetPerspectiveMatrix(width, height, perspective_angle);
}

