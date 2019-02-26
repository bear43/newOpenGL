//
// Created by bear on 25.02.19.
//

#include "VBOTexture.h"

VBOTexture::VBOTexture(const string &name) : VBODefault(name)
{}

void VBOTexture::fillBuffer(const vector<GLfloat> &vertices, const vector<GLfloat> &colors, const vector<GLfloat> &texCoords)
{
    vector<GLfloat> &&data = configureData(vertices, colors, texCoords);
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

void VBOTexture::fillBuffer(const vector<GLfloat> &points, const vector<GLfloat> &colors, const Texture2D &texture2D)
{
    fillBuffer(points, colors, texture2D.getCoordinates());
}

void VBOTexture::updateBuffer(const vector<vec3> &points, const vector<vec3> &colors, const Texture2D &texture2D)
{
    vector<GLfloat> vertices, v_colors;
    vector<GLfloat> currentPoint;
    for(const vec3 &point : points)
    {
        currentPoint = Vec3toVector::transform(point);
        vertices.insert(vertices.end(), currentPoint.begin(), currentPoint.end());
    }
    for(const vec3 &color : colors)
    {
        currentPoint = Vec3toVector::transform(color);
        v_colors.insert(v_colors.end(), currentPoint.begin(), currentPoint.end());
    }
    vector<GLfloat> &&data = configureData(vertices, v_colors, texture2D.getCoordinates());
    updateBuffer(0, data.size()*sizeof(GLfloat), data.data());
}

void VBOTexture::updateBuffer(GLintptr offset, GLsizeiptr size, GLvoid *data)
{
    bindBuffer();
    glNamedBufferSubData(buffer_id, offset, size, data);
    unbindBuffer();
}

vector<GLfloat> VBOTexture::configureData(const vector<GLfloat> &vertices, const vector<GLfloat> &colors,
                                          const vector<GLfloat> &texCoords)
{
    vector<GLfloat> data;
    for(int i = 0, j = 0; i < vertices.size(); i+= 3, j+= 2)
    {
        data.insert(data.end(), vertices.begin()+i, vertices.begin()+i+3);
        data.insert(data.end(), colors.begin()+i, colors.begin()+i+3);
        data.insert(data.end(), texCoords.begin()+j, texCoords.begin()+j+2);
    }
    return data;
}

void VBOTexture::updateBuffer(const vector<vec3> &points, const vector<vec3> &colors)
{
    vector<GLfloat> texCoords;
    for(int i = 0 ; i < points.size(); i++)
    {
        texCoords.push_back(0.0f);
        texCoords.push_back(0.0f);
    }
    Texture2D tex(texCoords, 0, 0, 0, 0, 0, 0);
    updateBuffer(points, colors, tex);
}

void VBOTexture::updateBuffer(const vector<vec3> &points)
{
    vector<vec3> colors;
    for(int i = 0 ; i < points.size(); i++)
        colors.emplace_back(0.0f, 0.0f, 0.0f);
    updateBuffer(points, colors);
}
