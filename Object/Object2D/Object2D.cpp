//
// Created by bear on 25.02.19.
//

#include "Object2D.h"


Object2D::Object2D(const string &name) : Object2D(name, nullptr, {})
{}

Object2D::~Object2D()
{
    dispose();
}

Object2D::Object2D(const string &name, Object2D *parent, const vector<Object2D *> &children, Texture2D *texture2D,
                   const vector<GLfloat> &points, const vector<GLfloat> &colors, const vector<GLuint> &indices) :
                                                                                   name(name), parent(parent),
                                                                                   children(children),
                                                                                   texture2D(texture2D), points(points),
                                                                                   colors(colors), indices(indices)
{
    vao = new VAO(fmt::format("VAO {0}", name));
    dataBuffer = new VBOTexture(fmt::format("VBOTexture {0}", name));
    indexBuffer = new IBO(fmt::format("IBO {0}", name));
}

Object2D::Object2D(const string &name, Object2D *parent, const vector<Object2D *> &children, Texture2D *texture2D) :
Object2D(name, parent, children, texture2D, {}, {}, {})
{}

Object2D::Object2D(const string &name, Object2D *parent, const vector<Object2D *> &children) :
Object2D(name, parent, children, nullptr)
{}

void Object2D::disposeChildren()
{
    if(!children.empty())
    {
        for (Object2D *child : children)
        {
            if(child != nullptr)
            {
                delete child;
                child = nullptr;
            }
        }
        children.clear();
    }
}

void Object2D::disposeParentsInfoAboutIt()
{
    if(parent != nullptr)//If parent exists
    {
        auto it = find(parent->children.begin(), parent->children.end(), this);//Find this child in his children vector
        if(it != parent->children.end())//Found it!
        {
            this->parent->children.erase(it);//Erase this
        }
    }
}

void Object2D::dispose()
{
    disposeChildren();
    disposeParentsInfoAboutIt();
    delete parent;
    parent = nullptr;
    delete texture2D;
    texture2D = nullptr;
    delete indexBuffer;
    indexBuffer = nullptr;
    delete dataBuffer;
    dataBuffer = nullptr;
    delete vao;
    vao = nullptr;
}

void Object2D::configure()
{
    configured = false;
    if(points.size() == colors.size())
    {
        useTexture = texture2D != nullptr;
        if (useTexture)
        {
            dataBuffer->fillBuffer(points, colors, *texture2D);
            vao->bindBuffer();
            texture2D->bind();
            VAO::unbindBuffer();
        }
        else
        {
            dataBuffer->fillBuffer(points, colors, {
                0.0f, 0.0f,
                0.0f, 0.0f,
                0.0f, 0.0f,
                0.0f, 0.0f
                });
        }
        dataBuffer->configure(*vao);
    }
    if(!indices.empty())
    {
        indexBuffer->fillBuffer(indices);
        indexBuffer->configure(*vao);
    }
    configured = true;
}

void Object2D::draw()
{
    if(!configured) configure();
    vao->bindBuffer();
    if(useTexture)
    {
        glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, nullptr);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)points.size()/3);
    }
    VAO::unbindBuffer();
}

const vector<GLfloat> &Object2D::getPoints() const
{
    return points;
}

void Object2D::setPoints(const vector<GLfloat> &points)
{
    Object2D::points = points;
}

const vector<GLfloat> &Object2D::getColors() const
{
    return colors;
}

void Object2D::setColors(const vector<GLfloat> &colors)
{
    Object2D::colors = colors;
}

const vector<GLuint> &Object2D::getIndices() const
{
    return indices;
}

void Object2D::setIndices(const vector<GLuint> &indices)
{
    Object2D::indices = indices;
}

const string &Object2D::getName() const
{
    return name;
}

void Object2D::setName(const string &name)
{
    Object2D::name = name;
}

Object2D *Object2D::getParent() const
{
    return parent;
}

void Object2D::setParent(Object2D *parent)
{
    Object2D::parent = parent;
}

const vector<Object2D *> &Object2D::getChildren() const
{
    return children;
}

void Object2D::setChildren(const vector<Object2D *> &children)
{
    Object2D::children = children;
}

Texture2D *Object2D::getTexture2D() const
{
    return texture2D;
}

void Object2D::setTexture2D(Texture2D *texture2D)
{
    Object2D::texture2D = texture2D;
}

VAO *Object2D::getVao() const
{
    return vao;
}

void Object2D::setVao(VAO *vao)
{
    Object2D::vao = vao;
}

VBOTexture *Object2D::getDataBuffer() const
{
    return dataBuffer;
}

void Object2D::setDataBuffer(VBOTexture *dataBuffer)
{
    Object2D::dataBuffer = dataBuffer;
}

IBO *Object2D::getIndexBuffer() const
{
    return indexBuffer;
}

void Object2D::setIndexBuffer(IBO *indexBuffer)
{
    Object2D::indexBuffer = indexBuffer;
}

Object2D::Object2D(const string &name, BMPFile &&bmp, const vector<GLfloat> &points, const vector<GLfloat> &colors,
                   const vector<GLuint> &indices) : Object2D(name, nullptr, {}, nullptr, points, colors, indices)
{
    texture2D = new Texture2D(defTexCoords, GL_REPEAT, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    bmp.load();
    texture2D->init(bmp);
}

Object2D::Object2D(const string &name, const string &bmpfile, const vector<GLfloat> &points, const vector<GLfloat> &colors,
                   const vector<GLuint> &indices) : Object2D(name, BMPFile(bmpfile), points, colors, indices)
{}

