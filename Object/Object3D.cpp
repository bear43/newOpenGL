//
// Created by bear on 28.02.19.
//

#include <fmt/core.h>
#include "Object3D.h"
#include "../OpenGL/Util/NullPtrChecker.h"
#include "../OpenGL/Buffers/VBO/Util.h"

Object3D::Object3D(const string &name, const vec3 &position, const vector<vec3> &points, const vector<vec3> &colors,
                   const vector<vec2> &texCoords, const vector<u32vec3> &indices, Texture *texture, Object3D *parent,
                   const vector<Object3D *> &children) : name(name), parent(parent), texture(texture),
                   vao(fmt::format("VAO | Object3D '{0}'", name)),
                   vbo(fmt::format("VBO | Object3D '{0}'", name), 8*sizeof(GLfloat)),
                   ibo(fmt::format("IBO | Object3D '{0}'", name))
{
    this->points = points;
    this->colors = colors;
    this->texCoords = texCoords;
    this->indices = indices;
    this->children = children;
    this->transform = Transform(position);
    this->vbo.addVertexAttribPointerFloat(this->vao, 0, GL_FALSE, 3);//vertex
    this->vbo.addVertexAttribPointerFloat(this->vao, 1, GL_FALSE, 3);//color
    this->vbo.addVertexAttribPointerFloat(this->vao, 2, GL_FALSE, 2);//texCoord
    vector<GLfloat> data = Util::toVector(
            this->points,
            this->colors,
            this->texCoords
    );
    this->vbo.fillBuffer(data.data(), data.size()*sizeof(GLfloat), GL_DYNAMIC_DRAW);
    this->vbo.configure(this->vao);
    this->ibo.fillBuffer(VecToVector::transform3i(this->indices));
    this->ibo.configure(this->vao);
}

Object3D::Object3D(const string &name, const vec3 &position, const vector<GLfloat> &points, const vector<GLfloat> &colors,
         const vector<GLfloat> &texCoords, const vector<GLuint> &indices, Texture *texture,
         Object3D *parent, const vector<Object3D *> &children) :
         Object3D(name, position,
                 VecToVector::reverseDoubleVector3(points),
                 VecToVector::reverseDoubleVector3(colors),
                 VecToVector::reverseDoubleVector2(texCoords),
                 VecToVector::reverseDoubleVector3(indices),
                 texture,
                 parent,
                 children)
{

}

Object3D::Object3D() : vao(fmt::format("VAO | Object3D '{0}'", name)),
                       vbo(fmt::format("VBO | Object3D '{0}'", name), 8*sizeof(GLfloat)),
                       ibo(fmt::format("IBO | Object3D '{0}'", name))
{
    this->vbo.addVertexAttribPointerFloat(this->vao, 0, GL_FALSE, 3);//vertex
    this->vbo.addVertexAttribPointerFloat(this->vao, 1, GL_FALSE, 3);//color
    this->vbo.addVertexAttribPointerFloat(this->vao, 2, GL_FALSE, 2);//texCoord
    this->vbo.configure(this->vao);
    this->ibo.configure(this->vao);
}

Object3D::~Object3D()
{
    dispose();
}

const string &Object3D::getName() const
{
    return name;
}

void Object3D::setName(const string &name)
{
    Object3D::name = name;
}

mat4 Object3D::getModelMatrix()
{
    return transform.getModelMatrix();
}

Transform &Object3D::getTransform()
{
    return transform;
}

void Object3D::dispose()
{
    NullPtrChecker::_delete(&texture);
    for(Object3D *obj : children)
        NullPtrChecker::_delete(&obj);
}

vector<u32vec3> &Object3D::getIndices()
{
    return indices;
}

void Object3D::setIndices(const vector<u32vec3> &indices)
{
    Object3D::indices = indices;
}

void Object3D::draw(ModelViewProjection &mvp)
{
    vao.bindBuffer();
    if(texture != nullptr)
        texture->bind();
    mvp.setModel(getModelMatrix());
    if(!indices.empty())
    {
        glDrawElements(GL_TRIANGLES, (GLsizei)indices.size()*3, GL_UNSIGNED_INT, nullptr);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)points.size());
    }
    VAO::unbindBuffer();
    if(texture != nullptr)
    texture->unbind();
}

VAO &Object3D::getVao()
{
    return vao;
}

VBO &Object3D::getVbo()
{
    return vbo;
}

IBO &Object3D::getIbo()
{
    return ibo;
}

vector<vec3> &Object3D::getPoints()
{
    return points;
}

vector<vec3> &Object3D::getColors()
{
    return colors;
}

vector<vec2> &Object3D::getTexCoords()
{
    return texCoords;
}

Texture *Object3D::getTexture()
{
    return texture;
}

Object3D *Object3D::getParent()
{
    return parent;
}

vector<Object3D *> &Object3D::getChildren()
{
    return children;
}

void Object3D::fillBuffers()
{
    vector<GLfloat> data = Util::toVector(
            this->points,
            this->colors,
            this->texCoords
    );
    this->vbo.fillBuffer(data.data(), data.size()*sizeof(GLfloat), GL_DYNAMIC_DRAW);
    this->ibo.fillBuffer(VecToVector::transform3i(this->indices));
}
