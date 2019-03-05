//
// Created by bear on 02.03.19.
//

#include "Model.h"
#include "../OpenGL/Util/VecToVector.h"

Model::Model(const string &name, const vector<Object3D *> &meshes) : Model(name)
{
    if(!meshes.empty())
    {
        this->meshes = meshes;
    }
}

Model::Model(const string &name) : name(name)
{
    totalCount++;
#ifdef DEBUG
    cout << "Constructor for " << name << endl;
#endif
}

Model::Model(const string &name, const objl::Loader &loader) : Model(name)
{
    Object3D *currentObject;
    for(const objl::Mesh &mesh : loader.LoadedMeshes)
    {
        currentObject = new Object3D(fmt::format("{0} -> {1}", name, mesh.MeshName), mesh);
        meshes.push_back(currentObject);
    }
}

Model::Model(const objl::Loader &loader) : Model(fmt::format("Model #{0}", totalCount), loader)
{
}

Model::Model(const string &name, aiScene &scene) : Model(name)
{
    unsigned int totalChildren = scene.mRootNode->mNumChildren;
    unsigned int totalMeshes;
    MeshFacrotyAssimp *factoryAssimp = new MeshFacrotyAssimp();
    for(unsigned int i = 0; i < totalChildren; i++)
    {
        totalMeshes = scene.mRootNode->mChildren[i]->mNumMeshes;
        for(unsigned int j = 0; j < totalMeshes; j++)
        {
            objl::Mesh &&currentMesh = factoryAssimp->createMesh(&scene, scene.mMeshes[scene.mRootNode->mChildren[i]->mMeshes[j]]);
            meshes.push_back(new Object3D(currentMesh.MeshName, currentMesh));
        }
    }
    delete factoryAssimp;
}

Model::Model(aiScene &scene) : Model(fmt::format("Model #{0}", totalCount), scene)
{

}

Model::Model() : Model(fmt::format("Model #{0}", totalCount))
{

}

Model::~Model()
{
    totalCount--;
#ifdef DEBUG
    cout << "Destructor for " << name << endl;
#endif
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

GLuint Model::getTotalCount()
{
    return totalCount;
}
