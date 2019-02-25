//
// Created by bear on 24.02.19.
//

#include "IBO.h"

IBO::IBO(const string &name) : Buffer(name)
{
}

void IBO::unbindBuffer()
{
    __glewBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IBO::bindBuffer()
{
    if(buffer_created) __glewBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
}

void IBO::deleteBuffer()
{
    if(buffer_created) __glewDeleteBuffers(1, &buffer_id);
    buffer_created = false;
}

void IBO::fillBuffer(const void *data, GLsizeiptr size)
{
    if(!buffer_created) return;
    bindBuffer();
    __glewBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    unbindBuffer();
}

void IBO::fillBuffer(const vector<GLuint> &indices)
{
    fillBuffer(indices.data(), indices.size()*sizeof(GLuint));
}

void IBO::configure(VAO &vao)
{
    vao.bindBuffer();
    bindBuffer();
    VAO::unbindBuffer();
}

IBO::~IBO()
{
    deleteBuffer();
}
