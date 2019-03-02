//
// Created by bear on 28.02.19.
//

#include <fmt/core.h>
#include "Object3D.h"
#include "../OpenGL/Util/NullPtrChecker.h"
#include "../OpenGL/Buffers/VBO/Util.h"

Object3D::Object3D(const string &name, const vec3 &position, const vector<vec3> &points, const vector<vec3> &colors,
                   const vector<vec3> &normals, const vector<vec2> &texCoords, const vector<u32vec3> &indices, Object3D *parent,
                   const vector<Object3D *> &children) : name(name), parent(parent),
                   vao(fmt::format("VAO | Object3D '{0}'", name)),
                   vbo(fmt::format("VBO | Object3D '{0}'", name), 11*sizeof(GLfloat)),
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
    this->vbo.addVertexAttribPointerFloat(this->vao, 2, GL_FALSE, 3);//normals
    this->vbo.addVertexAttribPointerFloat(this->vao, 3, GL_FALSE, 2);//texCoord
    this->vbo.configure(this->vao);
    this->ibo.configure(this->vao);
    fillBuffers();
    totalObjectsCount++;
}

Object3D::Object3D(const string &name, const vec3 &position, const vector<GLfloat> &points, const vector<GLfloat> &colors,
                   const vector<GLfloat> &normals, const vector<GLfloat> &texCoords, const vector<GLuint> &indices,
                   Object3D *parent, const vector<Object3D *> &children) :
          Object3D(name, position,
                   VecToVector::reverseDoubleVector3(points),
                   VecToVector::reverseDoubleVector3(colors),
                   VecToVector::reverseDoubleVector3(normals),
                   VecToVector::reverseDoubleVector2(texCoords),
                   VecToVector::reverseDoubleVector3(indices),
                   parent,
                   children)
{

}

Object3D::Object3D(const string& name) :
                       name(name),
                       vao(fmt::format("VAO | Object3D '{0}'", name)),
                       vbo(fmt::format("VBO | Object3D '{0}'", name), 11*sizeof(GLfloat)),
                       ibo(fmt::format("IBO | Object3D '{0}'", name))
{
    this->vbo.addVertexAttribPointerFloat(this->vao, 0, GL_FALSE, 3);//vertex
    this->vbo.addVertexAttribPointerFloat(this->vao, 1, GL_FALSE, 3);//color
    this->vbo.addVertexAttribPointerFloat(this->vao, 2, GL_FALSE, 3);//normals
    this->vbo.addVertexAttribPointerFloat(this->vao, 3, GL_FALSE, 2);//texCoord
    this->vbo.configure(this->vao);
    this->ibo.configure(this->vao);
    totalObjectsCount++;
}


Object3D::Object3D() : Object3D(fmt::format("Object3D {0}", totalObjectsCount))
{

}

Object3D::Object3D(const string &name, const vector<vec3> &points,
                   const vector<vec3> &colors,
                   const vector<vec3> &normals,
                   const vector<vec2> &texCoords,
                   const vector<u32vec3> &indices) : Object3D(name,
                                                              { 0.0f, 0.0f, 0.0f},
                                                              points, colors, normals, texCoords,
                                                              indices, nullptr, {})
{

}

Object3D::Object3D(const string &name, const vector<GLfloat> &vertices,
                   const vector<GLfloat> &colors,
                   const vector<GLfloat> &normals,
                   const vector<GLfloat> &texCoords,
                   const vector<GLuint> &indices) :
        Object3D(name,
                 VecToVector::reverseDoubleVector3(vertices),
                 VecToVector::reverseDoubleVector3(colors),
                 VecToVector::reverseDoubleVector3(normals),
                 VecToVector::reverseDoubleVector2(texCoords),
                 VecToVector::reverseDoubleVector3(indices))
{
}

Object3D::Object3D(const string &name, const objl::Mesh &mesh) : Object3D(name)
{
    for (const objl::Vertex &v : mesh.Vertices)
    {
        colors.emplace_back(1.0f, 1.0f, 1.0f);
        points.emplace_back(v.Position.X, v.Position.Y, v.Position.Z);
        normals.emplace_back(v.Normal.X, v.Normal.Y, v.Normal.Z);
        texCoords.emplace_back(v.TextureCoordinate.X, v.TextureCoordinate.Y);
    }
    indices = VecToVector::reverseDoubleVector3(mesh.Indices);
    fillBuffers();
}

Object3D::~Object3D()
{
    dispose();
    totalObjectsCount--;
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

void Object3D::draw(Shader& shader)
{
    vao.bindBuffer();
    shader.setModelMatrix(transform.getModelMatrix());
    if(!indices.empty())
    {
        glDrawElements(GL_TRIANGLES, (GLsizei)indices.size()*3, GL_UNSIGNED_INT, nullptr);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)points.size());
    }
    VAO::unbindBuffer();
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
            this->normals,
            this->texCoords
    );
    this->vbo.fillBuffer(data.data(), data.size()*sizeof(GLfloat), GL_DYNAMIC_DRAW);
    this->ibo.fillBuffer(VecToVector::transform3i(this->indices));
}
