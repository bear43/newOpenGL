//
// Created by bear on 26.02.19.
//

#ifndef UNTITLED2_CAMERA_H
#define UNTITLED2_CAMERA_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/gl.h>

using namespace glm;

class Camera
{
private:
    vec3 position = { 0.0f, 0.0f, 3.0f};
    vec3 up = { 0.0f, 1.0f, 0.0f };
    vec3 direction = { 0.0f, 0.0f, -1.0f };
    mat4 view = lookAt(position, position + direction, up);
    GLfloat xAngle = -90.0f;
    GLfloat yAngle = 0.0f;
    bool needUpdate = false;
public:

    Camera(const vec3 &position, const vec3 &up, const vec3 &direction);

    Camera() = default;

    void updateCamera();

    const vec3 &getPosition() const;

    void setPosition(const vec3 &position);

    const vec3 &getUp() const;

    void setUp(const vec3 &up);

    const vec3 &getDirection() const;

    void setDirection(const vec3 &direction);

    const mat4 &getView() const;

    void setView(const mat4 &view);

    void moveForward(GLfloat speed);

    void moveBack(GLfloat speed);

    void moveLeft(GLfloat speed);

    void moveRight(GLfloat speed);

    bool isNeedUpdate() const;

    void setNeedUpdate(bool needUpdate);

    void updateDirectionByDeltaXY(GLfloat deltaX, GLfloat deltaY);
};


#endif //UNTITLED2_CAMERA_H
