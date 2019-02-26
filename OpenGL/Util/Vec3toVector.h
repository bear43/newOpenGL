//
// Created by bear on 26.02.19.
//

#ifndef UNTITLED2_VEC3TOVECTOR_H
#define UNTITLED2_VEC3TOVECTOR_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/gl.h>

using namespace std;
using namespace glm;

class Vec3toVector
{
public:
    static vector<GLfloat> transform(const vec3 &_vec3);
    static vec3 reverse(const vector<GLfloat> &_vector);
    static vector<GLfloat> transform(const vector<vec3> &_vecs3);
    static vector<vec3> reverseDoubleVector(const vector<GLfloat> &_vector);
};


#endif //UNTITLED2_VEC3TOVECTOR_H
