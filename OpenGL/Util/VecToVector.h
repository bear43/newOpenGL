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
//#include "../../OBJLoader/OBJ_Loader.h"
//#include "../../OBJLoader/OBJ_Loader.h"

using namespace std;
using namespace glm;

class VecToVector
{
public:
    static vector<GLfloat> transform3(const vec3 &_vec3);
    static vec3 reverse3(const vector<GLfloat> &_vector);
    static u32vec3 reverse3(const vector<GLuint> &_vector);
    static vector<GLfloat> transform3(const vector<vec3> &_vecs3);
    static vector<vec3> reverseDoubleVector3(const vector<GLfloat> &_vector);
    static vector<u32vec3> reverseDoubleVector3(const vector<GLuint> &_vector);
    static vector<GLfloat> transform4(const vec4 &_vec4);
    static vector<GLfloat> transform4(const vector<vec4> &_vecs4);
    static vector<GLuint> transform3i(const u32vec3 &_vec3);
    static vector<GLuint> transform3i(const vector<u32vec3> &_vecs3);
    static vector<GLfloat> transform2(const vec2 &_vec2);
    static vector<GLfloat> transform2(const vector<vec2> &_vecs2);
    static vector<vec2> reverseDoubleVector2(const vector<GLfloat> &_vector);
    static vec2 reverse2(const vector<GLfloat> &_vector);
    static vector<GLfloat> uniteVertColTexToVector(const vector<GLfloat> &vertices,
                                                   const vector<GLfloat> &colors,
                                                   const vector<GLfloat> &texCoords);
    static vector<GLfloat> uniteVertColNormTexToVector(const vector<GLfloat> &vertices,
                                                       const vector<GLfloat> &colors,
                                                       const vector<GLfloat> &normals,
                                                       const vector<GLfloat> &texCoords);
    //static vector<vec3> fromObjVertexToVec_Pos(const vector<objl::Vertex> &vertices);
    //static vector<vec3> fromObjVertexToVec_Tex(const vector<objl::Vertex> &vertices);
    //static void fromObjToVBO(const vector<objl::Vertex> &vertices);
};


#endif //UNTITLED2_VEC3TOVECTOR_H
