//
// Created by bear on 28.02.19.
//

#ifndef UNTITLED2_TEXTURE3D_H
#define UNTITLED2_TEXTURE3D_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <vector>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Texture
{
private:
    GLuint texture_id;
    vector<vec3> coordinates;
    unsigned int texture_wrap_s;
    unsigned int texture_wrap_t;
    unsigned int texture_wrap_r;
    unsigned int texture_filter;
    unsigned int texture_min_filter;
    unsigned int texture_mag_filter;
    GLenum texture_type;
public:
    Texture(const vector<vec3> &coordinates, unsigned int texture_wrap_s, unsigned int texture_wrap_t,
            unsigned int texture_wrap_r, unsigned int texture_filter, unsigned int texture_min_filter,
            unsigned int texture_mag_filter, GLenum texture_type);

    Texture(unsigned int texture_wrap_s, unsigned int texture_wrap_t, unsigned int texture_wrap_r,
            unsigned int texture_filter, unsigned int texture_min_filter, unsigned int texture_mag_filter,
            GLenum texture_type);

    explicit Texture(GLenum texture_type);
    void init(const char* pixelsData, int width, int height, GLint internalFormat, GLenum format, GLenum type);
    void bind();
    void unbind();
    void dispose();
    const vector<vec3> &getCoordinates() const;
    void setCoordinates(const vector<vec3> &coordinates);
    vector<vec2> getCoordinates2();
    void setCoordinates2(const vector<vec2> &coordinates);
    unsigned int getTexture_wrap_s() const;
    void setTexture_wrap_s(unsigned int texture_wrap_s);
    unsigned int getTexture_wrap_t() const;
    void setTexture_wrap_t(unsigned int texture_wrap_t);
    unsigned int getTexture_wrap_r() const;
    void setTexture_wrap_r(unsigned int texture_wrap_r);
    unsigned int getTexture_filter() const;
    void setTexture_filter(unsigned int texture_filter);
    unsigned int getTexture_min_filter() const;
    void setTexture_min_filter(unsigned int texture_min_filter);
    unsigned int getTexture_mag_filter() const;
    void setTexture_mag_filter(unsigned int texture_mag_filter);
    GLenum getTexture_type() const;
    void setTexture_type(GLenum texture_type);
};


#endif //UNTITLED2_TEXTURE3D_H
