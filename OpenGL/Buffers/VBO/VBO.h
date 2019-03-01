//
// Created by bear on 28.02.19.
//

#ifndef UNTITLED2_VBO_H
#define UNTITLED2_VBO_H


#include "VBOAbstract.h"

class VBO : public VBOAbstract
{
private:
    /**
     * Total bytes used for a chunk of buffer data
     */
    GLuint totalStride = 0;
    /**
     * Offset to new available bytes in the buffer
     */
    GLuint totalOffset = 0;
    void checkOffsetAndStride();
public:
    VBO(const string &name, GLuint totalStride);

    VBO(const string &name);

    void bindBuffer() override;
    void deleteBuffer() override;
    void addVertexAttribPointerCustom(VAO &vao, GLuint index, GLboolean normalized, GLuint valuesCount, GLenum type, GLsizei valueSize);
    void addVertexAttribPointerFloat(VAO &vao, GLuint index, GLboolean normalized, GLuint valuesCount);
    void fillBuffer(const void *data, GLsizeiptr size, GLenum memoryUsageType);
    void updateBuffer(GLintptr offset, GLsizeiptr size, GLvoid *data);
    GLuint getTotalStride() const;
    void setTotalStride(GLuint totalStride);
    void configure(VAO &vao) override;
};


#endif //UNTITLED2_VBO_H
