//
// Created by bear on 02.03.19.
//

#include "LightSource.h"

LightSource::LightSource(const vec3 &position, const vec3 &color, GLfloat maxDistance) : position(position),
                                                                                         color(color),
                                                                                         maxDistance(maxDistance)
{}

LightSource::LightSource(const vec3 &color, const GLfloat maxDistance) : LightSource(DEFAULT_POSITION, color, maxDistance)
{

}

LightSource::LightSource(const vec3 &position, const vec3 &color) : LightSource(position, color, DEFAULT_MAX_DISTANCE)
{}

LightSource::LightSource(const vec3 &color) : LightSource(DEFAULT_POSITION, color)
{}

LightSource::LightSource() : LightSource(DEFAULT_COLOR)
{}

const vec3 &LightSource::getPosition() const
{
    return position;
}

void LightSource::setPosition(const vec3 &position)
{
    LightSource::position = position;
}

const vec3 &LightSource::getColor() const
{
    return color;
}

void LightSource::setColor(const vec3 &color)
{
    LightSource::color = color;
}

void LightSource::draw(Shader &shader)
{
    shader.setLightSource(*this);
}

GLfloat LightSource::getMaxDistance() const
{
    return maxDistance;
}

void LightSource::setMaxDistance(GLfloat maxDistance)
{
    LightSource::maxDistance = maxDistance;
}

void LightSource::addDistance(GLfloat addition)
{
    maxDistance += addition;
}

void LightSource::subDistance(GLfloat sub)
{
    addDistance(-sub);
}
