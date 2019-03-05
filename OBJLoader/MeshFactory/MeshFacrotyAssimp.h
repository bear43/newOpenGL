//
// Created by bear on 05.03.19.
//

#ifndef UNTITLED2_MESHFACROTYASSIMP_H
#define UNTITLED2_MESHFACROTYASSIMP_H

#include <assimp/mesh.h>
#include "../OBJ_Loader.h"
#include "../../Model/Model.h"
#include <vector>

using namespace std;

class Model;


class MeshFacrotyAssimp
{
private:
    void fillVNT(vector<objl::Vertex> &vertices, aiMesh *mesh);
    void fillIndices(vector<unsigned int> &indices, aiFace *face);
public:
    MeshFacrotyAssimp();
    ~MeshFacrotyAssimp();
    objl::Mesh createMesh(aiScene *scene, aiMesh *mesh);
    Model createModel(aiScene *scene);
};


#endif //UNTITLED2_MESHFACROTYASSIMP_H
