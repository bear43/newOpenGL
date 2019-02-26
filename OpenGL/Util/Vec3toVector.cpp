//
// Created by bear on 26.02.19.
//

#include "Vec3toVector.h"

vector<GLfloat> Vec3toVector::transform(const vec3 &_vec3)
{
    vector<GLfloat> _vec;
    _vec.push_back(_vec3[0]);
    _vec.push_back(_vec3[1]);
    _vec.push_back(_vec3[2]);
    return _vec;
}

vec3 Vec3toVector::reverse(const vector<GLfloat> &_vector)
{
    return vec3(_vector[0], _vector[1], _vector[2]);
}

vector<GLfloat> Vec3toVector::transform(const vector<vec3> &_vecs3)
{
    vector<GLfloat> _vector;
    for(const vec3 &_vec : _vecs3)
    {
        vector<GLfloat> &&current = transform(_vec);
        _vector.insert(_vector.end(), current.begin(), current.end());
    }
    return _vector;
}

vector<vec3> Vec3toVector::reverseDoubleVector(const vector<GLfloat> &_vector)
{
    vector<GLfloat> *current;
    vector<vec3> _vec;
    for(int i = 0; i < _vector.size(); i+=3)
    {
        current = new vector<GLfloat>{ _vector[i], _vector[i+1], _vector[i+2] };
        _vec.push_back(reverse(*current));
        delete current;
    }
    return _vec;
}
