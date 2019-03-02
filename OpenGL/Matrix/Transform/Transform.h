//
// Created by bear on 28.02.19.
//

#ifndef UNTITLED2_TRANSFORM_H
#define UNTITLED2_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class Transform
{
private:
    vec4 position = { 0.0f, 0.0f, 0.0f, 1.0f };
    mat4 scaleMatrix = mat4(1.0);
    mat4 rotationMatrix = mat4(1.0);
    mat4 translationMatrix = mat4(1.0);
public:
    Transform(const vec4 &position, const mat4 &scaleMatrix, const mat4 &rotationMatrix, const mat4 &translationMatrix);
    Transform(const vec3 &position, const mat4 &scaleMatrix, const mat4 &rotationMatrix, const mat4 &translationMatrix);
    Transform(const mat4 &scaleMatrix, const mat4 &rotationMatrix, const mat4 &translationMatrix);
    Transform(const Transform &transform);
    explicit Transform(const vec4 &position);
    explicit Transform(const vec3 &position);
    Transform() = default;
    Transform& operator=(const Transform& transform);
    mat4 getModelMatrix();
    vec4 getVector4(const vec4 &vector);
    vec3 getVector3(const vec3 &vector, float w);
    vec3 getVector3(const vec3 &vector);
    vec3 getVector3();
    void scale(const vec3 &vector);
    void rotate(float angle, const vec3 &vector);
    void translate(const vec3 &vector);
    void identityScaleMatrix();
    void identityRotationMatrix();
    void identityTranslationMatrix();
    void identityAllMatrix();
    const mat4 &getScaleMatrix() const;
    void setScaleMatrix(const mat4 &scaleMatrix);
    const mat4 &getRotationMatrix() const;
    void setRotationMatrix(const mat4 &rotationMatrix);
    const mat4 &getTranslationMatrix() const;
    void setTranslationMatrix(const mat4 &translationMatrix);
    void copy(const Transform &transform);
    void addTransformation(const Transform &transform);


    const vec4 &getPosition() const;

    void setPosition(const vec4 &position);
};


#endif //UNTITLED2_TRANSFORM_H
