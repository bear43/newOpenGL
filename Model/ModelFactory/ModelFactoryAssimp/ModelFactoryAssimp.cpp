//
// Created by bear on 05.03.19.
//

#include "ModelFactoryAssimp.h"

ModelFactoryAssimp::ModelFactoryAssimp(bool autoFree) : autoFree(autoFree)
{}

ModelFactoryAssimp::ModelFactoryAssimp() : ModelFactoryAssimp(true)
{}

ModelFactoryAssimp::~ModelFactoryAssimp()
{

}

Model ModelFactoryAssimp::createModel(const string &name, const string &path)
{
    loadScene(path);
    Model model(name, *scene);
    if(autoFree) free();
    return model;
}

Model ModelFactoryAssimp::createModel(const string &path)
{
    loadScene(path);
    Model model(*scene);
    if(autoFree) free();
    return model;
}

void ModelFactoryAssimp::free()
{
    delete scene;
    scene = nullptr;
}

void ModelFactoryAssimp::loadScene(const string &path)
{
    Assimp::Importer importer;
    scene = (aiScene*)importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_OptimizeMeshes);
    if(scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        throw runtime_error(
                fmt::format("Assimp importer error while loads model {0}: {1}", path, importer.GetErrorString()));
}
