//
// Created by bear on 25.02.19.
//

#include "VBOTexture.h"

VBOTexture::VBOTexture(const string &name) : VBODefault(name)
{}

void VBOTexture::fillBuffer(const vector<GLfloat> &vertices, const vector<GLfloat> &colors, const vector<GLfloat> &texCoords)
{
    vector<GLfloat> data;
    for(int i = 0, j = 0; i < vertices.size(); i+= 3, j+= 2)
    {
        data.insert(data.end(), vertices.begin()+i, vertices.begin()+i+3);
        data.insert(data.end(), colors.begin()+i, colors.begin()+i+3);
        data.insert(data.end(), texCoords.begin()+j, texCoords.begin()+j+2);
    }
    VBODefault::fillBuffer(data.data(), data.size()*sizeof(GLfloat));
}

void VBOTexture::configure(VAO &vao)
{
    vao.bindBuffer();
    bindBuffer();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    unbindBuffer();
    VAO::unbindBuffer();
}

void VBOTexture::fillBuffer(const vector<GLfloat> &vertices, const vector<GLfloat> &colors, const Texture2D &texture2D)
{
    fillBuffer(vertices, colors, texture2D.getCoordinates());
}
