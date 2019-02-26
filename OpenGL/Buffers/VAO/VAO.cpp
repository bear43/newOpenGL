//
// Created by bear on 24.02.19.
//

#include "VAO.h"

VAO::VAO(const string &name)
{
    this->name = name;
    glGenVertexArrays(1, &buffer_id);
    this->buffer_created = true;
}

void VAO::bindBuffer()
{
    if(buffer_created) __glewBindVertexArray(buffer_id);
}

void VAO::unbindBuffer()
{
    __glewBindVertexArray(0);
}

VAO::~VAO()
{
    deleteBuffer();
}

void VAO::deleteBuffer()
{
    if(buffer_created)
    {
        glDeleteVertexArrays(1, &buffer_id);
        buffer_created = false;
    }
}
