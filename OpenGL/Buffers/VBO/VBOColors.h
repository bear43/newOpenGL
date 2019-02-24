//
// Created by bear on 24.02.19.
//

#ifndef UNTITLED2_VBOCOLORS_H
#define UNTITLED2_VBOCOLORS_H


#include "VBODefault.h"

class VBOColors : public VBODefault
{
public:
    explicit VBOColors(const string &name);
    ~VBOColors() override;
    void fillBuffer(const vector<GLfloat> &vertices, const vector<GLfloat> &colors);

    void configure(VAO &vao) override;
};


#endif //UNTITLED2_VBOCOLORS_H
