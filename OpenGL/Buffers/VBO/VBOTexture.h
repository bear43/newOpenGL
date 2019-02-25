//
// Created by bear on 25.02.19.
//

#ifndef UNTITLED2_VBOTEXTURE_H
#define UNTITLED2_VBOTEXTURE_H


#include "VBODefault.h"
#include "../../Texture/Texture2D.h"

class VBOTexture : VBODefault
{
public:
    VBOTexture(const string &name);

    void fillBuffer(const vector<GLfloat> &vertices, const vector<GLfloat> &colors, const vector<GLfloat> &texCoords);
    void fillBuffer(const vector<GLfloat> &vertices, const vector<GLfloat> &colors, const Texture2D &texture2D);
    void configure(VAO &vao) override;
};


#endif //UNTITLED2_VBOTEXTURE_H
