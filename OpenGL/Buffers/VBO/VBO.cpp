//
// Created by bear on 28.02.19.
//

#include <stdexcept>
#include <fmt/core.h>
#include "VBO.h"

VBO::VBO(const string &name) : VBOAbstract(name)
{}

VBO::VBO(const string &name, GLuint totalStride) : VBOAbstract(name), totalStride(totalStride)
{}

void VBO::bindBuffer()
{
    if(buffer_created) glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
}

void VBO::deleteBuffer()
{
    if(!buffer_created) return;
    glDeleteBuffers(1, &buffer_id);
    buffer_created = false;
}

void VBO::addVertexAttribPointerCustom(VAO &vao, GLuint index, GLboolean normalized, GLuint valuesCount, GLenum type, GLsizei valueSize)
{
    checkOffsetAndStride();
    vao.bindBuffer();
    bindBuffer();
    glVertexAttribPointer(index, valuesCount, type, normalized, totalStride, (GLvoid*)totalOffset);
    glEnableVertexAttribArray(index);
    totalOffset += valuesCount*valueSize;
    VAO::unbindBuffer();
    unbindBuffer();
}

void VBO::addVertexAttribPointerFloat(VAO &vao, GLuint index, GLboolean normalized, GLuint valuesCount)
{
    addVertexAttribPointerCustom(vao, index, normalized, valuesCount, GL_FLOAT, sizeof(GLfloat));
}

GLuint VBO::getTotalStride() const
{
    return totalStride;
}

void VBO::setTotalStride(GLuint totalStride)
{
    VBO::totalStride = totalStride;
}

void VBO::checkOffsetAndStride()
{
    if(totalOffset >= totalStride) throw runtime_error(fmt::format("Buffer {0} overflow! Not enough space for new data! size {1}, offset {2}", name, totalStride, totalOffset));
}

void VBO::fillBuffer(const void *data, GLsizeiptr size, GLenum memoryUsageType)
{
    bindBuffer();
    glBufferData(GL_ARRAY_BUFFER, size, data, memoryUsageType);
    unbindBuffer();
}

void VBO::updateBuffer(GLintptr offset, GLsizeiptr size, GLvoid *data)
{
    bindBuffer();
#ifdef NVIDIA_DRIVER
    glNamedBufferSubData(buffer_id, offset, size, data);
#else
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
#endif
    unbindBuffer();
}

void VBO::configure(VAO &vao)
{
    vao.bindBuffer();
    bindBuffer();
    VAO::unbindBuffer();
    unbindBuffer();
}
