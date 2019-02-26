//
// Created by bear on 26.02.19.
//

#include "Camera.h"

void Camera::updateCamera()
{
    if(needUpdate)
    {
        view = lookAt(position, position + direction, up);
        needUpdate = false;
    }
}

const vec3 &Camera::getPosition() const
{
    return position;
}

void Camera::setPosition(const vec3 &position)
{
    Camera::position = position;
    needUpdate = true;
}

const vec3 &Camera::getUp() const
{
    return up;
}

void Camera::setUp(const vec3 &up)
{
    Camera::up = up;
    needUpdate = true;
}

const vec3 &Camera::getDirection() const
{
    return direction;
}

void Camera::setDirection(const vec3 &direction)
{
    Camera::direction = direction;
    needUpdate = true;
}

const mat4 &Camera::getView() const
{
    return view;
}

void Camera::setView(const mat4 &view)
{
    Camera::view = view;
}

Camera::Camera(const vec3 &position, const vec3 &up, const vec3 &direction) : position(position), up(up),
                                                                              direction(direction)
{}

void Camera::moveForward(GLfloat speed)
{
    position += direction * speed;
}

void Camera::moveBack(GLfloat speed)
{
    moveForward(-speed);
}

void Camera::moveLeft(GLfloat speed)
{
    position -= glm::normalize(glm::cross(direction, up)) * speed;
}

void Camera::moveRight(GLfloat speed)
{
    moveLeft(-speed);
}

bool Camera::isNeedUpdate() const
{
    return needUpdate;
}

void Camera::setNeedUpdate(bool needUpdate)
{
    Camera::needUpdate = needUpdate;
}

void Camera::updateDirectionByDeltaXY(GLfloat deltaX, GLfloat deltaY)
{
    xAngle += deltaX;
    yAngle += deltaY;
    if(xAngle > 89.0f)
        xAngle =  89.0f;
    if(yAngle < -89.0f)
        yAngle = -89.0f;
    direction[0] = -cos(radians(xAngle))*cos(radians(yAngle));
    direction[1] = sin(radians(yAngle));
    direction[2] = sin(radians(xAngle))*cos(radians(yAngle));
    needUpdate = true;
}
