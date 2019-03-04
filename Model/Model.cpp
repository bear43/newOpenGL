//
// Created by bear on 02.03.19.
//

#include "Model.h"
#include "../OpenGL/Util/VecToVector.h"

Model::Model(const string &name) : name(name)
{
    totalCount++;
}

Model::Model(const string &name, const string &sourceOBJfile) : Model(name)
{
    if(!loader.LoadFile(sourceOBJfile)) throw runtime_error(fmt::format("Fucked while load OBJ file {0}", sourceOBJfile));
    usedOBJ = true;
    loadMeshes();
}

Model::Model() : Model(fmt::format("Model #{0}", totalCount))
{

}

Model::~Model()
{
    totalCount--;
}

void Model::loadMeshes()
{
    if(!usedOBJ) throw runtime_error("Cannot load meshes because OBJ loader has been not used");
    Object3D *currentObject;
    for(const objl::Mesh &mesh : loader.LoadedMeshes)
    {
        currentObject = new Object3D(name, mesh);
        meshes.push_back(currentObject);
    }
}

void Model::draw(Shader& shader)
{
    for(Object3D *mesh : meshes)
    {
        //TODO Texture!
        Transform savedTransform(mesh->getTransform());
        mesh->getTransform().addTransformation(transform);
        mesh->draw(shader);
        mesh->getTransform().copy(savedTransform);
    }
}

Transform &Model::getTransform()
{
    return transform;
}

void Model::setTransform(const Transform &transform)
{
    Model::transform = transform;
}
