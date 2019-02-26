//
// Created by bear on 25.02.19.
//

#ifndef UNTITLED2_VBOTEXTURE_H
#define UNTITLED2_VBOTEXTURE_H


#include "VBODefault.h"
#include "../../Texture/Texture2D.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Util/Vec3toVector.h"

using namespace glm;

class VBOTexture : public VBODefault
{
private:
    vector<GLfloat> configureData(const vector<GLfloat> &vertices,
                                  const vector<GLfloat> &colors,
                                  const vector<GLfloat> &texCoords);
public:
    VBOTexture(const string &name);

    void fillBuffer(const vector<GLfloat> &vertices, const vector<GLfloat> &colors, const vector<GLfloat> &texCoords);
    void fillBuffer(const vector<GLfloat> &points, const vector<GLfloat> &colors, const Texture2D &texture2D);
    void updateBuffer(GLintptr offset, GLsizeiptr size, GLvoid* data);
    void updateBuffer(const vector<vec3> &points, const vector<vec3> &colors, const Texture2D &texture2D);
    void updateBuffer(const vector<vec3> &points, const vector<vec3> &colors);
    void updateBuffer(const vector<vec3> &points);
    void configure(VAO &vao) override;
};


#endif //UNTITLED2_VBOTEXTURE_H
