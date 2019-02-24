//
// Created by bear on 24.02.19.
//

#include "VBODefault.h"

VBODefault::VBODefault(const string &name) : VBOAbstract(name)
{}

VBODefault::~VBODefault()
{
    if(buffer_created) deleteBuffer();
}

void VBODefault::fillBuffer(const void *data, GLsizeiptr size)
{
    if(!buffer_created) return;
    __glewBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    __glewBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    __glewBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBODefault::fillBuffer(const vector<GLfloat> &vertices)
{
    fillBuffer(vertices.data(), vertices.size()*sizeof(GLfloat*));
}

void VBODefault::deleteBuffer()
{
    if(!buffer_created) return;
    __glewDeleteBuffers(1, &buffer_id);
    buffer_created = false;
}

void VBODefault::bindBuffer()
{
    if(buffer_created) __glewBindBuffer(GL_ARRAY_BUFFER, buffer_id);
}

void VBODefault::configure(VAO &vao)
{
    vao.bindBuffer();
    bindBuffer();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)nullptr);
    glEnableVertexAttribArray(0);
    unbindBuffer();
    VAO::unbindBuffer();
}
