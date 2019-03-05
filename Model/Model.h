//
// Created by bear on 02.03.19.
//

#ifndef UNTITLED2_MODEL_H
#define UNTITLED2_MODEL_H

#include "../Object/Object3D.h"
#include <fmt/core.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include "../OBJLoader/MeshFactory/MeshFacrotyAssimp.h"

class Model
{
private:
    static inline GLuint totalCount = 0;
    string name;
    Transform transform;
    vector<Object3D*> meshes;
public:
    Model(const string &name, const vector<Object3D*> &meshes);
    explicit Model(const string &name);
    Model();

    virtual ~Model();

    //------------------------------------------------------------------------------------------------------------------
    //OBJ
    Model(const string &name, const objl::Loader &loader);
    explicit Model(const objl::Loader &loader);
    //------------------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------
    //Assimp
    Model(const string &name, aiScene &scene);
    explicit Model(aiScene &scene);
    //------------------------------------------------------------------------------------------------------------------

    void draw(Shader& shader);

    Transform &getTransform();

    void setTransform(const Transform &transform);
    static GLuint getTotalCount();
};


#endif //UNTITLED2_MODEL_H
