//
// Created by bear on 28.02.19.
//

#ifndef UNTITLED2_OBJECT3D_H
#define UNTITLED2_OBJECT3D_H
#include <string>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../OpenGL/Matrix/Transform/Transform.h"
#include "../OpenGL/Texture/Texture.h"
#include "../OpenGL/Buffers/VBO/VBO.h"
#include "../OpenGL/Buffers/VAO/VAO.h"
#include "../OpenGL/Buffers/IBO/IBO.h"
#include "../OpenGL/Matrix/ModelViewProjection.h"
#include <GL/gl.h>


using namespace std;
using namespace glm;

class VBO;

class Object3D
{
private:
    string name;
    vector<vec3> points = {};
    vector<vec3> colors = {};
    vector<vec2> texCoords = {};
    vector<u32vec3> indices = {};
    Transform transform ={};
    Texture *texture = nullptr;
    Object3D *parent = nullptr;
    vector<Object3D*> children = {};
    VAO vao;
    VBO vbo;
    IBO ibo;
public:
    Object3D(const string &name, const vec3 &position, const vector<vec3> &points, const vector<vec3> &colors,
            const vector<vec2> &texCoords, const vector<u32vec3> &indices, Texture *texture,
            Object3D *parent, const vector<Object3D *> &children);
    Object3D(const string &name, const vec3 &position, const vector<GLfloat> &points, const vector<GLfloat> &colors,
             const vector<GLfloat> &texCoords, const vector<GLuint> &indices, Texture *texture,
             Object3D *parent, const vector<Object3D *> &children);
    Object3D();

    virtual ~Object3D();
    void dispose();
    void draw(ModelViewProjection &mvp);
    const string &getName() const;
    void setName(const string &name);
    mat4 getModelMatrix();
    VAO &getVao();
    VBO &getVbo();
    IBO &getIbo();
    void setIndices(const vector<u32vec3> &indices);
    vector<u32vec3> &getIndices();
    Transform &getTransform();

    vector<vec3> &getPoints();

    vector<vec3> &getColors();

    vector<vec2> &getTexCoords();

    Texture *getTexture();

    Object3D *getParent();

    vector<Object3D *> &getChildren();

    void fillBuffers();
};


#endif //UNTITLED2_OBJECT3D_H
