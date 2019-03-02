//
// Created by bear on 28.02.19.
//

#include "Transform.h"


Transform::Transform(const mat4 &scaleMatrix, const mat4 &rotationMatrix, const mat4 &translationMatrix) : scaleMatrix(
        scaleMatrix), rotationMatrix(rotationMatrix), translationMatrix(translationMatrix)
{}

Transform::Transform(const Transform &transform)
{
    copy(transform);
}

vec4 Transform::getVector4(const vec4 &vector)
{
    return getModelMatrix() * vector;
}

vec3 Transform::getVector3(const vec3 &vector, float w)
{
    vec4 v = getVector4(vec4(vector, w));
    return vec3(v[0], v[1], v[2]);
}

vec3 Transform::getVector3(const vec3 &vector)
{
    return getVector3(vector, 1.0f);
}

void Transform::scale(const vec3 &vector)
{
    scaleMatrix = glm::scale(scaleMatrix, vector);
}

void Transform::rotate(float angle, const vec3 &vector)
{
    rotationMatrix = glm::rotate(rotationMatrix, angle, vector);
}

void Transform::translate(const vec3 &vector)
{
    translationMatrix = glm::translate(translationMatrix, vector);
}

void Transform::identityScaleMatrix()
{
    scaleMatrix = mat4(1.0);
}

void Transform::identityRotationMatrix()
{
    rotationMatrix = mat4(1.0);
}

void Transform::identityTranslationMatrix()
{
    translationMatrix = mat4(1.0);
}

void Transform::identityAllMatrix()
{
    identityScaleMatrix();
    identityRotationMatrix();
    identityTranslationMatrix();
}

const mat4 &Transform::getScaleMatrix() const
{
    return scaleMatrix;
}

void Transform::setScaleMatrix(const mat4 &scaleMatrix)
{
    Transform::scaleMatrix = scaleMatrix;
}

const mat4 &Transform::getRotationMatrix() const
{
    return rotationMatrix;
}

void Transform::setRotationMatrix(const mat4 &rotationMatrix)
{
    Transform::rotationMatrix = rotationMatrix;
}

const mat4 &Transform::getTranslationMatrix() const
{
    return translationMatrix;
}

void Transform::setTranslationMatrix(const mat4 &translationMatrix)
{
    Transform::translationMatrix = translationMatrix;
}

mat4 Transform::getModelMatrix()
{
    return translationMatrix * rotationMatrix * scaleMatrix;
}

const vec4 &Transform::getPosition() const
{
    return position;
}

void Transform::setPosition(const vec4 &position)
{
    Transform::position = position;
    identityTranslationMatrix();
    translate(position);
}

vec3 Transform::getVector3()
{
    return getVector4(position);
}

Transform::Transform(const vec4 &position) : position(position)
{
    translate(position);
}

Transform::Transform(const vec3 &position) : Transform({position, 1.0f})
{
    translate(position);
}

Transform::Transform(const vec4 &position, const mat4 &scaleMatrix, const mat4 &rotationMatrix,
                     const mat4 &translationMatrix)
{
    translate(position);
}

Transform::Transform(const vec3 &position, const mat4 &scaleMatrix, const mat4 &rotationMatrix,
                     const mat4 &translationMatrix) : Transform({position, 1.0f}, scaleMatrix, rotationMatrix, translationMatrix)
{
    translate(position);
}

void Transform::copy(const Transform &transform)
{
    this->scaleMatrix = transform.scaleMatrix;
    this->rotationMatrix = transform.rotationMatrix;
    this->translationMatrix = transform.translationMatrix;
    this->position = transform.position;
}

Transform &Transform::operator=(const Transform &transform)
{
    copy(transform);
    return *this;
}

void Transform::addTransformation(const Transform &transform)
{
    //this->position + transform.position;
    this->translationMatrix *= transform.translationMatrix;
    this->rotationMatrix *= transform.rotationMatrix;
    this->scaleMatrix *= transform.scaleMatrix;
}
