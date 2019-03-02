//
// Created by bear on 02.03.19.
//

#ifndef UNTITLED2_LIGHTSOURCE_H
#define UNTITLED2_LIGHTSOURCE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../OpenGL/Matrix/Transform/Transform.h"
#include "../OpenGL/Shader/Shader.h"

class Shader;

class LightSource
{
private:
    static constexpr vec3 DEFAULT_COLOR = { 1.0f, 1.0f, 1.0f };
    static constexpr vec3 DEFAULT_POSITION = { 0.0f, 0.0f, 0.0f };
    static constexpr GLfloat DEFAULT_MAX_DISTANCE = 40.0f;
    vec3 position;
    vec3 color;
    GLfloat maxDistance;
public:
    LightSource(const vec3 &position, const vec3& color, GLfloat maxDistance);
    LightSource(const vec3 &color, const GLfloat maxDistance);
    LightSource(const vec3 &position, const vec3 &color);
    explicit LightSource(const vec3 &color);
    LightSource();

    const vec3 &getPosition() const;

    void setPosition(const vec3 &position);

    const vec3 &getColor() const;

    void setColor(const vec3 &color);

    GLfloat getMaxDistance() const;

    void setMaxDistance(GLfloat maxDistance);

    void draw(Shader &shader);

    void addDistance(GLfloat add);

    void subDistance(GLfloat sub);
};


#endif //UNTITLED2_LIGHTSOURCE_H
