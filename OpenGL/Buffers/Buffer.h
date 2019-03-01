//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_BUFFER_H
#define UNTITLED2_BUFFER_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <string>

using namespace std;

class Buffer
{
protected:
    GLuint buffer_id = 0;
    bool buffer_created = false;
    string name;
    explicit Buffer(const string &name)
    {
        this->name = name;
        this->buffer_id = 0;
        glGenBuffers(1, &buffer_id);
        buffer_created = true;
    }
    Buffer() = default;
public:
    virtual void bindBuffer() = 0;
    static void unbindBuffer()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    GLuint getBufferID()
    {
        return buffer_id;
    }
};

#endif //UNTITLED2_BUFFER_H
