//
// Created by bear on 25.02.19.
//

#include "Texture2D.h"

Texture2D::Texture2D(const vector<GLfloat> &coordinates, unsigned int texture_wrap_s,
                 unsigned int texture_wrap_t, unsigned int texture_wrap_r, unsigned int texture_filter,
                 unsigned int texture_min_filter, unsigned int texture_mag_filter) : coordinates(coordinates),
                                                                                     texture_wrap_s(texture_wrap_s),
                                                                                     texture_wrap_t(texture_wrap_t),
                                                                                     texture_wrap_r(texture_wrap_r),
                                                                                     texture_filter(texture_filter),
                                                                                     texture_min_filter(
                                                                                             texture_min_filter),
                                                                                     texture_mag_filter(
                                                                                             texture_mag_filter)
{
    glGenTextures(1, &texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texture_min_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texture_mag_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texture_wrap_s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texture_wrap_t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, texture_wrap_r);
}

void Texture2D::init(const char *pixelsData, int width, int height)
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelsData);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::init(BMPFile file)
{
    if(file.load() != FILE_SUCCESSFUL) return;
    init(file.getData().data(), file.getHeader().Width, file.getHeader().Height);
}

void Texture2D::bind()
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
}


