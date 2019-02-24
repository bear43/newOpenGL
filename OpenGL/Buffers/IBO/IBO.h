//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_IBO_H
#define UNTITLED2_IBO_H

#include "../Buffer.h"
#include <vector>

using namespace std;

class IBO : Buffer
{
public:
    explicit IBO(const string &name);
    void bindBuffer() override;
    void deleteBuffer();
    void fillBuffer(const void* data, GLsizeiptr size);
    void fillBuffer(const vector<GLuint> &indices);
    static void unbindBuffer();
};


#endif //UNTITLED2_IBO_H
