//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_VBOABSTRACT_H
#define UNTITLED2_VBOABSTRACT_H


#include "../Buffer.h"
#include "../VAO/VAO.h"
#include <vector>

class VBOAbstract : public Buffer
{
public:
    VBOAbstract(const string &name);

    virtual void fillBuffer(const void* data, GLsizeiptr size) = 0;
    virtual void fillBuffer(const vector<GLfloat> &vertices) = 0;
    virtual void configure(VAO &vao) = 0;
    virtual void deleteBuffer() = 0;
};


#endif //UNTITLED2_VBOABSTRACT_H
