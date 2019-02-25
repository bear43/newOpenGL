//
// Created by bear on 25.02.19.
//

#ifndef UNTITLED2_TEXTURE_H
#define UNTITLED2_TEXTURE_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <vector>
#include "../../File/BMP/BMPFile.h"

using namespace std;

class Texture2D
{
private:
    GLuint texture_id;
    vector<GLfloat> coordinates;
    unsigned int texture_wrap_s;
    unsigned int texture_wrap_t;
    unsigned int texture_wrap_r;
    unsigned int texture_filter;
    unsigned int texture_min_filter;
    unsigned int texture_mag_filter;
public:
    Texture2D(const vector<GLfloat> &coordinates, unsigned int texture_wrap_s,
            unsigned int texture_wrap_t, unsigned int texture_wrap_r, unsigned int texture_filter,
            unsigned int texture_min_filter, unsigned int texture_mag_filter);
    void init(const char* pixelsData, int width, int height);
    void init(BMPFile file);
    void bind();
};


#endif //UNTITLED2_TEXTURE_H
