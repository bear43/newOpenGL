//
// Created by bear on 26.02.19.
//

#include "VecToVector.h"

vector<GLfloat> VecToVector::transform3(const vec3 &_vec3)
{
    vector<GLfloat> _vec;
    _vec.push_back(_vec3[0]);
    _vec.push_back(_vec3[1]);
    _vec.push_back(_vec3[2]);
    return _vec;
}

vec3 VecToVector::reverse3(const vector<GLfloat> &_vector)
{
    return vec3(_vector[0], _vector[1], _vector[2]);
}

vector<GLfloat> VecToVector::transform3(const vector<vec3> &_vecs3)
{
    vector<GLfloat> _vector;
    for(const vec3 &_vec : _vecs3)
    {
        vector<GLfloat> &&current = transform3(_vec);
        _vector.insert(_vector.end(), current.begin(), current.end());
    }
    return _vector;
}

vector<vec3> VecToVector::reverseDoubleVector3(const vector<GLfloat> &_vector)
{
    vector<GLfloat> *current;
    vector<vec3> _vec;
    for(int i = 0; i < _vector.size(); i+=3)
    {
        current = new vector<GLfloat>{ _vector[i], _vector[i+1], _vector[i+2] };
        _vec.push_back(reverse3(*current));
        delete current;
    }
    return _vec;
}

vector<GLfloat> VecToVector::transform4(const vec4 &_vec4)
{
    vector<GLfloat> _vec;
    _vec.push_back(_vec4[0]);
    _vec.push_back(_vec4[1]);
    _vec.push_back(_vec4[2]);
    _vec.push_back(_vec4[3]);
    return _vec;
}

vector<GLfloat> VecToVector::transform4(const vector<vec4> &_vecs4)
{
    vector<GLfloat> _vector;
    for(const vec4 &_vec : _vecs4)
    {
        vector<GLfloat> &&current = transform4(_vec);
        _vector.insert(_vector.end(), current.begin(), current.end());
    }
    return _vector;
}

vector<GLuint> VecToVector::transform3i(const u32vec3 &_vec3)
{
    vector<GLuint> _vec;
    _vec.push_back(_vec3[0]);
    _vec.push_back(_vec3[1]);
    _vec.push_back(_vec3[2]);
    return _vec;
}

vector<GLuint> VecToVector::transform3i(const vector<u32vec3> &_vecs3)
{
    vector<GLuint> _vector;
    for(const u32vec3 &_vec : _vecs3)
    {
        vector<GLuint> &&current = transform3i(_vec);
        _vector.insert(_vector.end(), current.begin(), current.end());
    }
    return _vector;
}

vector<GLfloat> VecToVector::transform2(const vec2 &_vec2)
{
    vector<GLfloat> _vec;
    _vec.push_back(_vec2[0]);
    _vec.push_back(_vec2[1]);
    return _vec;
}

vector<GLfloat> VecToVector::transform2(const vector<vec2> &_vecs2)
{
    vector<GLfloat> _vector;
    for(const vec2 &_vec : _vecs2)
    {
        vector<GLfloat> &&current = transform2(_vec);
        _vector.insert(_vector.end(), current.begin(), current.end());
    }
    return _vector;
}

vector<vec2> VecToVector::reverseDoubleVector2(const vector<GLfloat> &_vector)
{
    vector<GLfloat> *current;
    vector<vec2> _vec;
    for(int i = 0; i < _vector.size(); i+=2)
    {
        current = new vector<GLfloat>{ _vector[i], _vector[i+1] };
        _vec.push_back(reverse2(*current));
        delete current;
    }
    return _vec;
}

vec2 VecToVector::reverse2(const vector<GLfloat> &_vector)
{
    return vec2(_vector[0], _vector[1]);
}

vector<u32vec3> VecToVector::reverseDoubleVector3(const vector<GLuint> &_vector)
{
    vector<GLuint> *current;
    vector<u32vec3> _vec;
    for(int i = 0; i < _vector.size(); i+=3)
    {
        current = new vector<GLuint>{ _vector[i], _vector[i+1], _vector[i+2] };
        _vec.push_back(reverse3(*current));
        delete current;
    }
    return _vec;
}

u32vec3 VecToVector::reverse3(const vector<GLuint> &_vector)
{
    return u32vec3(_vector[0], _vector[1], _vector[2]);
}
