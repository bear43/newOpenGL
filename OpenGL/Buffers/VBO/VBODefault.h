//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_VBO_H
#define UNTITLED2_VBO_H

#include "../Buffer.h"
#include "VBOAbstract.h"
#include <vector>

using namespace std;

class VBODefault : public VBOAbstract
{
private:
    //GLuint buffer_id;
    //bool buffer_created;
    //string name;
public:
    VBODefault(const string &name);
    virtual ~VBODefault();

    void fillBuffer(const void* data, GLsizeiptr size);
    void fillBuffer(const vector<GLfloat> &vertices);
    void deleteBuffer();
    void bindBuffer();

    void configure(VAO &vao) override;
};


#endif //UNTITLED2_VBO_H
