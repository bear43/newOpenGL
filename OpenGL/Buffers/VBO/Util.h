//
// Created by bear on 28.02.19.
//

#ifndef UNTITLED2_UTIL_H
#define UNTITLED2_UTIL_H

#include <GL/gl.h>
#include <vector>
#include <glm/glm.hpp>
#include "../../Util/VecToVector.h"

using namespace glm;
using namespace std;

namespace Util
{
    vector<GLfloat> toVector(const vector<vec3> &points, const vector<vec4> &colors, const vector<vec3> &texCoords)
    {
        vector<GLfloat> vertices, v_colors, v_texCoords;
        vector<GLfloat> currentPoint;
        for(const vec3 &point : points)
        {
            currentPoint = VecToVector::transform3(point);
            vertices.insert(vertices.end(), currentPoint.begin(), currentPoint.end());
        }
        for(const vec4 &color : colors)
        {
            currentPoint = VecToVector::transform4(color);
            v_colors.insert(v_colors.end(), currentPoint.begin(), currentPoint.end());
        }
        for(const vec3 &texCoord : texCoords)
        {
            currentPoint = VecToVector::transform3(texCoord);
            v_texCoords.insert(v_texCoords.end(), currentPoint.begin(), currentPoint.end());
        }
        vector<GLfloat> data;
        for(int i = 0, j = 0; i < vertices.size(); i+= 3, j+= 4)
        {
            data.insert(data.end(), vertices.begin()+i, vertices.begin()+i+3);
            data.insert(data.end(), v_colors.begin()+j, v_colors.begin()+j+4);
            data.insert(data.end(), v_texCoords.begin()+i, v_texCoords.begin()+i+3);
        }
        return data;
    }
    vector<GLfloat> toVector(const vector<vec3> &points, const vector<vec3> &colors, const vector<vec2> &texCoords)
    {
        vector<GLfloat> vertices = VecToVector::transform3(points),
                        v_colors = VecToVector::transform3(colors),
                        v_texCoords = VecToVector::transform2(texCoords);
        return VecToVector::uniteVertColTexToVector(vertices, v_colors, v_texCoords);
    }
};


#endif //UNTITLED2_UTIL_H
