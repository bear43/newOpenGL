//
// Created by bear on 28.02.19.
//

#include "Texture.h"


Texture::Texture(const vector<vec3> &coordinates, unsigned int texture_wrap_s, unsigned int texture_wrap_t,
                 unsigned int texture_wrap_r, unsigned int texture_filter, unsigned int texture_min_filter,
                 unsigned int texture_mag_filter, GLenum texture_type) : coordinates(coordinates),
                                                                        texture_wrap_s(texture_wrap_s),
                                                                        texture_wrap_t(texture_wrap_t),
                                                                        texture_wrap_r(texture_wrap_r),
                                                                        texture_filter(texture_filter),
                                                                        texture_min_filter(texture_min_filter),
                                                                        texture_mag_filter(texture_mag_filter),
                                                                        texture_type(texture_type)
{
    glGenTextures(1, &texture_id);
    bind();
    glTexParameteri(texture_type, GL_TEXTURE_MIN_FILTER, texture_min_filter);
    glTexParameteri(texture_type, GL_TEXTURE_MAG_FILTER, texture_mag_filter);
    glTexParameteri(texture_type, GL_TEXTURE_WRAP_S, texture_wrap_s);
    glTexParameteri(texture_type, GL_TEXTURE_WRAP_T, texture_wrap_t);
    glTexParameteri(texture_type, GL_TEXTURE_WRAP_R, texture_wrap_r);
    unbind();
}

Texture::Texture(unsigned int texture_wrap_s, unsigned int texture_wrap_t, unsigned int texture_wrap_r,
                 unsigned int texture_filter, unsigned int texture_min_filter, unsigned int texture_mag_filter,
                 GLenum texture_type) : texture_wrap_s(texture_wrap_s), texture_wrap_t(texture_wrap_t),
                                        texture_wrap_r(texture_wrap_r), texture_filter(texture_filter),
                                        texture_min_filter(texture_min_filter), texture_mag_filter(texture_mag_filter),
                                        texture_type(texture_type)
{}

Texture::Texture(GLenum texture_type) : Texture(GL_REPEAT, GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, texture_type)
{

}

void Texture::bind()
{
    glBindTexture(texture_type, texture_id);
}

void Texture::unbind()
{
    glBindTexture(texture_type, 0);
}

void Texture::init(const char *pixelsData, int width, int height, GLint internalFormat, GLenum format, GLenum type)
{
    bind();
    glTexImage2D(texture_type, 0, internalFormat, width, height, 0, format, type, pixelsData);
    glGenerateMipmap(texture_type);
    unbind();
}

const vector<vec3> &Texture::getCoordinates() const
{
    return coordinates;
}

void Texture::setCoordinates(const vector<vec3> &coordinates)
{
    Texture::coordinates = coordinates;
}

unsigned int Texture::getTexture_wrap_s() const
{
    return texture_wrap_s;
}

void Texture::setTexture_wrap_s(unsigned int texture_wrap_s)
{
    Texture::texture_wrap_s = texture_wrap_s;
}

unsigned int Texture::getTexture_wrap_t() const
{
    return texture_wrap_t;
}

void Texture::setTexture_wrap_t(unsigned int texture_wrap_t)
{
    Texture::texture_wrap_t = texture_wrap_t;
}

unsigned int Texture::getTexture_wrap_r() const
{
    return texture_wrap_r;
}

void Texture::setTexture_wrap_r(unsigned int texture_wrap_r)
{
    Texture::texture_wrap_r = texture_wrap_r;
}

unsigned int Texture::getTexture_filter() const
{
    return texture_filter;
}

void Texture::setTexture_filter(unsigned int texture_filter)
{
    Texture::texture_filter = texture_filter;
}

unsigned int Texture::getTexture_min_filter() const
{
    return texture_min_filter;
}

void Texture::setTexture_min_filter(unsigned int texture_min_filter)
{
    Texture::texture_min_filter = texture_min_filter;
}

unsigned int Texture::getTexture_mag_filter() const
{
    return texture_mag_filter;
}

void Texture::setTexture_mag_filter(unsigned int texture_mag_filter)
{
    Texture::texture_mag_filter = texture_mag_filter;
}

GLenum Texture::getTexture_type() const
{
    return texture_type;
}

void Texture::setTexture_type(GLenum texture_type)
{
    Texture::texture_type = texture_type;
}

void Texture::dispose()
{
    if(texture_id != 0)
    {
        glDeleteTextures(1, &texture_id);
        texture_id = 0;
    }
}

vector<vec2> Texture::getCoordinates2()
{
    vector<vec2> vec;
    for(const vec3 &v : coordinates)
        vec.emplace_back(v[0], v[1]);
    return vec;
}

void Texture::setCoordinates2(const vector<vec2> &coordinates)
{
    this->coordinates.clear();
    for(const vec2 &v : coordinates)
        this->coordinates.emplace_back(v[0], v[1], 0.0f);
}
