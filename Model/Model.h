//
// Created by bear on 02.03.19.
//

#ifndef UNTITLED2_MODEL_H
#define UNTITLED2_MODEL_H

#include "../Object/Object3D.h"
//#include "../OBJLoader/OBJ_Loader.h"
#include <fmt/core.h>

class Model
{
private:
    static inline GLuint totalCount = 0;
    string name;
    objl::Loader loader;
    Transform transform;
    vector<Object3D*> meshes;
    bool usedOBJ = false;//OBJ
public:
    explicit Model(const string &name);
    Model();

    virtual ~Model();

    //------------------------------------------------------------------------------------------------------------------
    //OBJ
    Model(const string &name, const string& sourceOBJfile);
    void loadMeshes();
    //------------------------------------------------------------------------------------------------------------------

    void draw(Program& shader, ModelViewProjection &mvp);

    Transform &getTransform();

    void setTransform(const Transform &transform);
};


#endif //UNTITLED2_MODEL_H
