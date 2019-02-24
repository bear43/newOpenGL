//
// Created by bear on 24.02.19.
//

#include "VBOColors.h"

VBOColors::VBOColors(const string &name) : VBODefault(name)
{}

VBOColors::~VBOColors()
{
    deleteBuffer();
}

void VBOColors::fillBuffer(const vector<GLfloat> &vertices, const vector<GLfloat> &colors)
{
    vector<GLfloat> data;
    for(int i = 0; i < vertices.size(); i+= 3)
    {
        data.insert(data.end(), vertices.begin()+i, vertices.begin()+i+3);
        data.insert(data.end(), colors.begin()+i, colors.begin()+i+3);
    }
    VBODefault::fillBuffer(data.data(), data.size()*sizeof(GLfloat));
}

void VBOColors::configure(VAO &vao)
{
    vao.bindBuffer();
    bindBuffer();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    unbindBuffer();
    VAO::unbindBuffer();
}
