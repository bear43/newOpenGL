//
// Created by bear on 25.02.19.
//

#ifndef UNTITLED2_OBJECT2D_H
#define UNTITLED2_OBJECT2D_H

#include <string>
#include <vector>
#include <algorithm>
#include <fmt/core.h>
#include "../../OpenGL/Texture/Texture2D.h"
#include "../../OpenGL/Buffers/VAO/VAO.h"
#include "../../OpenGL/Buffers/IBO/IBO.h"
#include "../../OpenGL/Buffers/VBO/VBOTexture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace glm;

class Object2D
{
private:
    static inline const vector<GLfloat> defTexCoords = {
            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f
    };
    string name;
    Object2D *parent = nullptr;
    vector<Object2D*> children;
    Texture2D *texture2D = nullptr;
    vector<GLfloat> points;
    vector<GLfloat> colors;
    vector<GLuint> indices;
    VAO *vao = nullptr;
    VBOTexture *dataBuffer = nullptr;
    IBO *indexBuffer = nullptr;
    mat4 modelMatrix = mat4(1.0);//Identity matrix for transformation model
    bool configured = false;
    bool useTexture = false;
    bool needUpdateBuffer = true;
    void disposeParentsInfoAboutIt();
    void disposeChildren();
public:
    Object2D(const string &name, Object2D *parent, const vector<Object2D *> &children, Texture2D *texture2D,
             const vector<GLfloat> &points, const vector<GLfloat> &colors, const vector<GLuint> &indices);

    Object2D(const string &name, Object2D *parent, const vector<Object2D *> &children, Texture2D *texture2D);

    Object2D(const string &name, BMPFile &&bmp, const vector<GLfloat> &points, const vector<GLfloat> &colors, const vector<GLuint> &indices);

    Object2D(const string &name, const string &bmpfile, const vector<GLfloat> &points, const vector<GLfloat> &colors,
             const vector<GLuint> &indices);

    Object2D(const string &name, Object2D *parent, const vector<Object2D *> &children);

    Object2D(const string &name);

    virtual ~Object2D();

    void dispose();

    void configure();

    void draw();

    const vector<GLfloat> &getPoints() const;

    void setPoints(const vector<GLfloat> &points);

    const vector<GLfloat> &getColors() const;

    void setColors(const vector<GLfloat> &colors);

    const vector<GLuint> &getIndices() const;

    void setIndices(const vector<GLuint> &indices);

    const string &getName() const;

    void setName(const string &name);

    Object2D *getParent() const;

    void setParent(Object2D *parent);

    const vector<Object2D *> &getChildren() const;

    void setChildren(const vector<Object2D *> &children);

    Texture2D *getTexture2D() const;

    void setTexture2D(Texture2D *texture2D);

    VAO *getVao() const;

    void setVao(VAO *vao);

    VBOTexture *getDataBuffer() const;

    void setDataBuffer(VBOTexture *dataBuffer);

    IBO *getIndexBuffer() const;

    void setIndexBuffer(IBO *indexBuffer);

    const mat4 &getModelMatrix() const;

    void setModelMatrix(const mat4 &modelMatrix);

    void rotate(GLfloat angle, const vec3 &axis);

    void translate(const vec3 &direction);

    void updatePoints();


};


#endif //UNTITLED2_OBJECT2D_H
